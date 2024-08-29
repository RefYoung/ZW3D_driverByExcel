/********************************************************************************
** Form generated from reading UI file 'PRT.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRT_H
#define UI_PRT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PRTClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_5;
    QGroupBox *groupBox_15;
    QGridLayout *gridLayout_27;
    QListView *tvListProjectGit;
    QGroupBox *groupBox_16;
    QGridLayout *gridLayout_28;
    QTableView *tvProjectGit_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PRTClass)
    {
        if (PRTClass->objectName().isEmpty())
            PRTClass->setObjectName(QStringLiteral("PRTClass"));
        PRTClass->resize(667, 513);
        centralWidget = new QWidget(PRTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter_5 = new QSplitter(centralWidget);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        groupBox_15 = new QGroupBox(splitter_5);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        gridLayout_27 = new QGridLayout(groupBox_15);
        gridLayout_27->setSpacing(0);
        gridLayout_27->setContentsMargins(11, 11, 11, 11);
        gridLayout_27->setObjectName(QStringLiteral("gridLayout_27"));
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        tvListProjectGit = new QListView(groupBox_15);
        tvListProjectGit->setObjectName(QStringLiteral("tvListProjectGit"));

        gridLayout_27->addWidget(tvListProjectGit, 0, 0, 1, 1);

        splitter_5->addWidget(groupBox_15);
        groupBox_16 = new QGroupBox(splitter_5);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        gridLayout_28 = new QGridLayout(groupBox_16);
        gridLayout_28->setSpacing(0);
        gridLayout_28->setContentsMargins(11, 11, 11, 11);
        gridLayout_28->setObjectName(QStringLiteral("gridLayout_28"));
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        tvProjectGit_2 = new QTableView(groupBox_16);
        tvProjectGit_2->setObjectName(QStringLiteral("tvProjectGit_2"));

        gridLayout_28->addWidget(tvProjectGit_2, 0, 0, 1, 1);

        splitter_5->addWidget(groupBox_16);

        gridLayout_4->addWidget(splitter_5, 0, 0, 1, 1);

        PRTClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PRTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PRTClass->setStatusBar(statusBar);

        retranslateUi(PRTClass);

        QMetaObject::connectSlotsByName(PRTClass);
    } // setupUi

    void retranslateUi(QMainWindow *PRTClass)
    {
        PRTClass->setWindowTitle(QApplication::translate("PRTClass", "\346\226\271\346\241\210\351\233\266\344\273\266", Q_NULLPTR));
        groupBox_15->setTitle(QString());
        groupBox_16->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class PRTClass: public Ui_PRTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRT_H
