/********************************************************************************
** Form generated from reading UI file 'capgit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPGIT_H
#define UI_CAPGIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_capGit
{
public:
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTreeView *treeViewStandardGit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTableView *tvStandardGit;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnNewDIr;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cheCheOutStandardGit;
    QPushButton *btnOpenModel;

    void setupUi(QDialog *capGit)
    {
        if (capGit->objectName().isEmpty())
            capGit->setObjectName(QStringLiteral("capGit"));
        capGit->resize(688, 634);
        gridLayout_2 = new QGridLayout(capGit);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter = new QSplitter(capGit);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        treeViewStandardGit = new QTreeView(groupBox);
        treeViewStandardGit->setObjectName(QStringLiteral("treeViewStandardGit"));
        treeViewStandardGit->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        treeViewStandardGit->setIndentation(20);
        treeViewStandardGit->setRootIsDecorated(true);
        treeViewStandardGit->setUniformRowHeights(false);
        treeViewStandardGit->setItemsExpandable(true);
        treeViewStandardGit->header()->setVisible(false);

        gridLayout->addWidget(treeViewStandardGit, 0, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tvStandardGit = new QTableView(groupBox_2);
        tvStandardGit->setObjectName(QStringLiteral("tvStandardGit"));

        verticalLayout->addWidget(tvStandardGit);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnNewDIr = new QPushButton(groupBox_4);
        btnNewDIr->setObjectName(QStringLiteral("btnNewDIr"));

        horizontalLayout->addWidget(btnNewDIr);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cheCheOutStandardGit = new QCheckBox(groupBox_4);
        cheCheOutStandardGit->setObjectName(QStringLiteral("cheCheOutStandardGit"));
        sizePolicy.setHeightForWidth(cheCheOutStandardGit->sizePolicy().hasHeightForWidth());
        cheCheOutStandardGit->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        cheCheOutStandardGit->setFont(font);
        cheCheOutStandardGit->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        cheCheOutStandardGit->setAutoRepeat(false);
        cheCheOutStandardGit->setAutoExclusive(false);

        horizontalLayout->addWidget(cheCheOutStandardGit);

        btnOpenModel = new QPushButton(groupBox_4);
        btnOpenModel->setObjectName(QStringLiteral("btnOpenModel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnOpenModel->sizePolicy().hasHeightForWidth());
        btnOpenModel->setSizePolicy(sizePolicy1);
        btnOpenModel->setMinimumSize(QSize(150, 0));
        btnOpenModel->setFont(font);

        horizontalLayout->addWidget(btnOpenModel);


        verticalLayout->addWidget(groupBox_4);

        splitter->addWidget(groupBox_2);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(capGit);

        QMetaObject::connectSlotsByName(capGit);
    } // setupUi

    void retranslateUi(QDialog *capGit)
    {
        capGit->setWindowTitle(QApplication::translate("capGit", "\345\205\203\345\231\250\344\273\266\345\272\223", Q_NULLPTR));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QString());
        groupBox_4->setTitle(QString());
        btnNewDIr->setText(QApplication::translate("capGit", "\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        cheCheOutStandardGit->setText(QApplication::translate("capGit", "\346\243\200\345\207\272", Q_NULLPTR));
        btnOpenModel->setText(QApplication::translate("capGit", "\346\211\223\345\274\200\346\250\241\345\236\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class capGit: public Ui_capGit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPGIT_H
