#include "login.h"
#include "ui_login.h"

//全局窗体指针
LogIn* LogIn::m_instance= nullptr;//登录窗体

LogIn::LogIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogIn)
{
    ui->setupUi(this);

    init();//调用程序初始化函数,请不要在此方法前调用任何其他方法
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
    //获取用户输入的账号密码
    QString account = ui->editName->text();
    QString pswd = ui->editPswd->text();

    //禁用修改按钮
    ui->btnLogIn->setEnabled(false);
    ui->groupBox->setEnabled(false);

    //打包json数据
    QJsonObject json;
    QJsonDocument jsonDoc;
    json["username"] = account;
    json["password"] = pswd;
    jsonDoc.setObject(json);
    QByteArray dataArray = jsonDoc.toJson(QJsonDocument::Compact);

    //发送网络请求
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
    //想要勾选自动登陆单选框必须先勾选记住密码单选框
    if (arg1 == 2) {
        ui->cheRemeberPswd->setChecked(true);
    }
}

void LogIn::on_cheRemeberPswd_stateChanged(int arg1)
{
    //如果记住密码取消选中,那么自动登陆也取消选中
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
            cvxMsgDisp2(QString::fromUtf8(u8"[TGP]登录失败.").toLocal8Bit(),4);
            QMessageBox::warning(this, u8"警告", u8"获取Token时发生错误.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode));
            
            //取消自动登陆
            ui->cheAutoLogin->setChecked(false);
        }else if(statusCode == 200) {
           //获取token
            g_userToken = jsObject.value("token").toString();

            //更新到文件
            g_configSettings->setValue("user/token", g_userToken);
            //关闭登录窗口
            this->close();
            cvxMsgDisp2(QString::fromUtf8(u8"[TGP]登录成功!").toLocal8Bit(),1);
        }
        //释放    
        reply->deleteLater();
        reply = nullptr;
    }
    //更新登陆按钮是否可用
    ui->btnLogIn->setEnabled(true);
    ui->groupBox->setEnabled(true);
}

void LogIn::init()
{
    //移除帮助和关闭按钮
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
    //检测配置文件是否存在,如果不存在则取消写入
    if (!QFile::exists(g_configSettings->fileName()))return;

    //写入配置文件
    g_configSettings->setValue("logInConfig/autoLogInChecked", ui->cheAutoLogin->checkState());
    g_configSettings->setValue("logInConfig/remeberPswd", ui->cheRemeberPswd->checkState());
    g_configSettings->setValue("user/name", ui->editName->text());
    //如果勾选了记住密码才写入密码
    if (!ui->cheRemeberPswd->isChecked())g_configSettings->setValue("user/pswd", "");
    else g_configSettings->setValue("user/pswd", ui->editPswd->text());

    this->hide();
    event->ignore();
}

void LogIn::showEvent(QShowEvent *event)
{
    //加载配置
    ui->editName->setText(g_configSettings->value("user/name").toString());
    ui->editPswd->setText(g_configSettings->value("user/pswd").toString());
    ui->cheAutoLogin->setCheckState((Qt::CheckState)g_configSettings->value("logInConfig/autoLogInChecked").toInt());
    ui->cheRemeberPswd->setCheckState((Qt::CheckState)g_configSettings->value("logInConfig/remeberPswd").toInt());

    //更新登陆按钮是否可用
    if (!inputOk())ui->btnLogIn->setEnabled(false);
    else ui->btnLogIn->setEnabled(true);


    //调用父类显示函数
    QDialog::showEvent(event);
    //自动登陆
    if (ui->cheAutoLogin->isChecked() && ui->btnLogIn->isEnabled()) {
        ui->btnLogIn->click();
    }
}

void LogIn::on_editCancel_clicked()
{
    this->close();
}

