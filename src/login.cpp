#include "login.h"
#include "ui_login.h"

//ȫ�ִ���ָ��
LogIn* LogIn::m_instance= nullptr;//��¼����

LogIn::LogIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);

    init();//���ó����ʼ������,�벻Ҫ�ڴ˷���ǰ�����κ���������
}

LogIn::~LogIn()
{
    m_instance = nullptr;
    delete ui;
}

void LogIn::setAutoLoginChecked(bool checked)
{
    ui->cheAutoLogin->setChecked(checked);
}

LogIn* LogIn::getInstance()
{
    if (m_instance == nullptr) {
        m_instance = new LogIn();
    }
    return m_instance;
}

void LogIn::on_btnLogIn_clicked()
{
    //��ȡ�û�������˺�����
    QString account = ui->editName->text();
    QString pswd = ui->editPswd->text();

    //�����޸İ�ť
    ui->btnLogIn->setEnabled(false);
    ui->groupBox->setEnabled(false);

    //���json����
    QJsonObject json;
    QJsonDocument jsonDoc;
    json["username"] = account;
    json["password"] = pswd;
    jsonDoc.setObject(json);
    QByteArray dataArray = jsonDoc.toJson(QJsonDocument::Compact);

    //������������
    QNetworkRequest request;
    request.setUrl(QUrl(g_getBaseUrl() + g_loginUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    QNetworkReply* reply = g_networkManager.post(request, dataArray);
    QTimer::singleShot(5000, reply, [=]() {
        if (reply->isRunning()) {
            reply->abort();
            ui->btnLogIn->setEnabled(true);
            ui->groupBox->setEnabled(true);
            }
        });
    connect(reply, SIGNAL(finished()),this,SLOT(onPostLogInFinished()));
}

void LogIn::on_editName_textChanged(const QString& arg1)
{
    Q_UNUSED(arg1);
    if (!inputOk()) {
        ui->btnLogIn->setEnabled(false);
    }
    else {
        ui->btnLogIn->setEnabled(true);
    }
}

void LogIn::on_editPswd_textChanged(const QString& arg1)
{
    Q_UNUSED(arg1);
    if (!inputOk()) {
        ui->btnLogIn->setEnabled(false);
    }
    else {
        ui->btnLogIn->setEnabled(true);
    }
}

void LogIn::on_cheAutoLogin_stateChanged(int arg1)
{
    //��Ҫ��ѡ�Զ���½��ѡ������ȹ�ѡ��ס���뵥ѡ��
    if (arg1 == 2) {
        ui->cheRemeberPswd->setChecked(true);
    }
}

void LogIn::on_cheRemeberPswd_stateChanged(int arg1)
{
    //�����ס����ȡ��ѡ��,��ô�Զ���½Ҳȡ��ѡ��
    if (arg1 == 0) {
        ui->cheAutoLogin->setChecked(false);
    }
}

void LogIn::onPostLogInFinished()
{
    QNetworkReply* reply = (qobject_cast<QNetworkReply*>(sender()));
    if (reply != nullptr) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jsObject = jsonDoc.object();
        int code = -1;
        code = jsObject.value("code").toInt();
        if (reply->error() != QNetworkReply::NoError || code != 200) {
            cvxMsgDisp2(QString::fromUtf8(u8"[TGP]��¼ʧ��.").toLocal8Bit(),4);
            QMessageBox::warning(this, u8"����", u8"��ȡTokenʱ��������.\n�������:" + QString::number(code) + u8" http״̬��:" + QString::number(statusCode));
            
            //ȡ���Զ���½
            ui->cheAutoLogin->setChecked(false);
        }else if(statusCode == 200) {
           //��ȡtoken
            g_userToken = jsObject.value("token").toString();

            //���µ��ļ�
            g_configSettings->setValue("user/token", g_userToken);
            //�رյ�¼����
            this->close();
            cvxMsgDisp2(QString::fromUtf8(u8"[TGP]��¼�ɹ�!").toLocal8Bit(),1);
        }
        //�ͷ�    
        reply->deleteLater();
        reply = nullptr;
    }
    //���µ�½��ť�Ƿ����
    ui->btnLogIn->setEnabled(true);
    ui->groupBox->setEnabled(true);
}

void LogIn::init()
{
    //�Ƴ������͹رհ�ť
    this->setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
    ui->label->setPixmap(QPixmap(":/imgs/loginLogo.png").scaled(ui->label->width() * 2, ui->label->height() * 2));
}

bool LogIn::inputOk()
{
    QString name = ui->editName->text();
    QString pswd = ui->editPswd->text();
    if (name.isEmpty() || pswd.isEmpty()) {
        return false;
    }
    return true;
}

void LogIn::closeEvent(QCloseEvent* event)
{
    //��������ļ��Ƿ����,�����������ȡ��д��
    if (!QFile::exists(g_configSettings->fileName()))return;

    //д�������ļ�
    g_configSettings->setValue("logInConfig/autoLogInChecked", ui->cheAutoLogin->checkState());
    g_configSettings->setValue("logInConfig/remeberPswd", ui->cheRemeberPswd->checkState());
    g_configSettings->setValue("user/name", ui->editName->text());
    //�����ѡ�˼�ס�����д������
    if (!ui->cheRemeberPswd->isChecked())g_configSettings->setValue("user/pswd", "");
    else g_configSettings->setValue("user/pswd", ui->editPswd->text());

    this->hide();
    event->ignore();
}

void LogIn::showEvent(QShowEvent *event)
{
    //��������
    ui->editName->setText(g_configSettings->value("user/name").toString());
    ui->editPswd->setText(g_configSettings->value("user/pswd").toString());
    ui->cheAutoLogin->setCheckState((Qt::CheckState)g_configSettings->value("logInConfig/autoLogInChecked").toInt());
    ui->cheRemeberPswd->setCheckState((Qt::CheckState)g_configSettings->value("logInConfig/remeberPswd").toInt());

    //���µ�½��ť�Ƿ����
    if (!inputOk())ui->btnLogIn->setEnabled(false);
    else ui->btnLogIn->setEnabled(true);


    //���ø�����ʾ����
    QDialog::showEvent(event);
    //�Զ���½
    if (ui->cheAutoLogin->isChecked() && ui->btnLogIn->isEnabled()) {
        ui->btnLogIn->click();
    }
}

void LogIn::on_editCancel_clicked()
{
    this->close();
}

