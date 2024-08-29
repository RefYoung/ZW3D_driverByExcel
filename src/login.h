#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "global.h"
#include <QCloseEvent>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>
#include <QShowEvent>
#include "FunCore.h"
#include <qtimer.h>

namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    
    ~LogIn();

    void setAutoLoginChecked(bool checked);

    static LogIn* getInstance();

signals:
    void postLogInFinished();

private slots:
    void on_editCancel_clicked();

    void on_btnLogIn_clicked();

    void on_editName_textChanged(const QString& arg1);

    void on_editPswd_textChanged(const QString& arg1);

    void on_cheAutoLogin_stateChanged(int arg1);

    void on_cheRemeberPswd_stateChanged(int arg1);

    void onPostLogInFinished();

private:
    //禁止外部实例化
    explicit LogIn(QWidget* parent = nullptr);

    Ui::LogIn *ui;

    //私有变量部分
    static LogIn* m_instance;

    //私有方法部分
    void init();//程序初始化函数,请不要在此方法前调用任何其自定义方法
    bool inputOk();//检测输入是否合理,合理返回true,否则返回false

protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent* event);


};

#endif // LOGIN_H
