/********************************************************************************
** Form generated from reading UI file 'exceltoprt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCELTOPRT_H
#define UI_EXCELTOPRT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_excelToPrt
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnSave;
    QPushButton *btnGen;
    QLineEdit *editFilePath;
    QPushButton *btnBroese;
    QPushButton *btnCancel;

    void setupUi(QDialog *excelToPrt)
    {
        if (excelToPrt->objectName().isEmpty())
            excelToPrt->setObjectName(QStringLiteral("excelToPrt"));
        excelToPrt->resize(607, 583);
        gridLayout = new QGridLayout(excelToPrt);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(excelToPrt);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btnSave = new QPushButton(groupBox_3);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        gridLayout_3->addWidget(btnSave, 0, 3, 1, 1);

        btnGen = new QPushButton(groupBox_3);
        btnGen->setObjectName(QStringLiteral("btnGen"));

        gridLayout_3->addWidget(btnGen, 0, 2, 1, 1);

        editFilePath = new QLineEdit(groupBox_3);
        editFilePath->setObjectName(QStringLiteral("editFilePath"));
        editFilePath->setReadOnly(true);

        gridLayout_3->addWidget(editFilePath, 0, 0, 1, 1);

        btnBroese = new QPushButton(groupBox_3);
        btnBroese->setObjectName(QStringLiteral("btnBroese"));

        gridLayout_3->addWidget(btnBroese, 0, 1, 1, 1);

        btnCancel = new QPushButton(groupBox_3);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        gridLayout_3->addWidget(btnCancel, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(excelToPrt);

        QMetaObject::connectSlotsByName(excelToPrt);
    } // setupUi

    void retranslateUi(QDialog *excelToPrt)
    {
        excelToPrt->setWindowTitle(QApplication::translate("excelToPrt", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("excelToPrt", "\350\241\250\346\240\274\345\206\205\345\256\271", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("excelToPrt", "\346\223\215\344\275\234\346\240\217", Q_NULLPTR));
        btnSave->setText(QApplication::translate("excelToPrt", "\344\277\235\345\255\230", Q_NULLPTR));
        btnGen->setText(QApplication::translate("excelToPrt", "\347\224\237\346\210\220", Q_NULLPTR));
        btnBroese->setText(QApplication::translate("excelToPrt", "\346\265\217\350\247\210", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("excelToPrt", "\345\217\226\346\266\210'", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class excelToPrt: public Ui_excelToPrt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCELTOPRT_H
