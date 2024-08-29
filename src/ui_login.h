/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *btnLogIn;
    QPushButton *editCancel;
    QLabel *label_3;
    QLineEdit *editName;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QCheckBox *cheRemeberPswd;
    QCheckBox *cheAutoLogin;
    QLineEdit *editPswd;
    QLabel *label_2;

    void setupUi(QDialog *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName(QStringLiteral("LogIn"));
        LogIn->resize(267, 353);
        gridLayout_5 = new QGridLayout(LogIn);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(LogIn);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        groupBox = new QGroupBox(LogIn);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 30));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnLogIn = new QPushButton(groupBox_2);
        btnLogIn->setObjectName(QStringLiteral("btnLogIn"));

        gridLayout->addWidget(btnLogIn, 0, 0, 1, 1);

        editCancel = new QPushButton(groupBox_2);
        editCancel->setObjectName(QStringLiteral("editCancel"));

        gridLayout->addWidget(editCancel, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 3, 0, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        editName = new QLineEdit(groupBox);
        editName->setObjectName(QStringLiteral("editName"));

        gridLayout_4->addWidget(editName, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 30));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        cheRemeberPswd = new QCheckBox(groupBox_3);
        cheRemeberPswd->setObjectName(QStringLiteral("cheRemeberPswd"));

        gridLayout_3->addWidget(cheRemeberPswd, 0, 0, 1, 1);

        cheAutoLogin = new QCheckBox(groupBox_3);
        cheAutoLogin->setObjectName(QStringLiteral("cheAutoLogin"));

        gridLayout_3->addWidget(cheAutoLogin, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 2);

        editPswd = new QLineEdit(groupBox);
        editPswd->setObjectName(QStringLiteral("editPswd"));
        editPswd->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_4->addWidget(editPswd, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(LogIn);

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QDialog *LogIn)
    {
        LogIn->setWindowTitle(QApplication::translate("LogIn", "\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QString());
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        btnLogIn->setText(QApplication::translate("LogIn", "\347\231\273\351\231\206", Q_NULLPTR));
        editCancel->setText(QApplication::translate("LogIn", "\345\217\226\346\266\210", Q_NULLPTR));
        label_3->setText(QApplication::translate("LogIn", "\345\257\206\347\240\201", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        cheRemeberPswd->setText(QApplication::translate("LogIn", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        cheAutoLogin->setText(QApplication::translate("LogIn", "\350\207\252\345\212\250\347\231\273\351\231\206", Q_NULLPTR));
        label_2->setText(QApplication::translate("LogIn", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
