#include "exceltoprt.h"
#include "ui_exceltoprt.h"

excelToPrt* excelToPrt::m_instance=nullptr;

excelToPrt::excelToPrt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::excelToPrt)
{
    ui->setupUi(this);

    //调整窗口
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    QRect rect = QGuiApplication::primaryScreen()->availableGeometry();
    this->resize(rect.width() * 3 / 4, this->height());

    //初始化表格
    m_model = new QStandardItemModel(this);
}

void excelToPrt::showEvent(QShowEvent *event)
{
    this->setEnabled(true);
}

void excelToPrt::closeEvent(QCloseEvent *event)
{
    if (!this->isEnabled()) {
        if (QMessageBox::Yes == QMessageBox::question(this, u8"询问", u8"当前有正在进行的功能,是否强制退出?")) {
            delete this;
        }
        else event->ignore();
    }
    else this->hide();

    event->ignore();
}

excelToPrt* excelToPrt::getInstance()
{
    if(m_instance==nullptr)m_instance=new excelToPrt();
    return m_instance;
}

excelToPrt::~excelToPrt()
{
    m_instance = nullptr;
    delete ui;
}

void excelToPrt::on_btnBroese_clicked()
{
    QString filePath= QFileDialog::getOpenFileName(this, u8"选择文件",g_currentWorkDir+"/"+ g_projectDirName,"excel file(*.xlsx) (*.xls)");
    if (!filePath.isEmpty()) {
        ui->editFilePath->setText(filePath);

    }
}


void excelToPrt::on_btnGen_clicked()
{

}


void excelToPrt::on_btnSave_clicked()
{

}


void excelToPrt::on_btnCancel_clicked()
{

}

