/********************************************************************************
** Form generated from reading UI file 'edit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_H
#define UI_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_17;
    QPushButton *btnSaveEdit;
    QPushButton *btnCheckInEdit;
    QPushButton *btnUpdateEdit;
    QPushButton *btnGenDwg;
    QPushButton *btnCheckOutEdit;
    QSplitter *splitter_3;
    QStackedWidget *stackedWidgetEdit;
    QWidget *pagCheckInEdit;
    QGridLayout *gridLayout_19;
    QGroupBox *groupEditTreeView;
    QGridLayout *gridLayout_18;
    QTreeView *treeViewEdit;
    QComboBox *combGitChoiceEdit;
    QTableView *tvEdit;

    void setupUi(QDialog *edit)
    {
        if (edit->objectName().isEmpty())
            edit->setObjectName(QStringLiteral("edit"));
        edit->resize(499, 442);
        gridLayout = new QGridLayout(edit);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_10 = new QGroupBox(edit);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setMaximumSize(QSize(16777215, 50));
        gridLayout_17 = new QGridLayout(groupBox_10);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        btnSaveEdit = new QPushButton(groupBox_10);
        btnSaveEdit->setObjectName(QStringLiteral("btnSaveEdit"));

        gridLayout_17->addWidget(btnSaveEdit, 0, 0, 1, 1);

        btnCheckInEdit = new QPushButton(groupBox_10);
        btnCheckInEdit->setObjectName(QStringLiteral("btnCheckInEdit"));

        gridLayout_17->addWidget(btnCheckInEdit, 0, 2, 1, 1);

        btnUpdateEdit = new QPushButton(groupBox_10);
        btnUpdateEdit->setObjectName(QStringLiteral("btnUpdateEdit"));

        gridLayout_17->addWidget(btnUpdateEdit, 0, 1, 1, 1);

        btnGenDwg = new QPushButton(groupBox_10);
        btnGenDwg->setObjectName(QStringLiteral("btnGenDwg"));

        gridLayout_17->addWidget(btnGenDwg, 0, 4, 1, 1);

        btnCheckOutEdit = new QPushButton(groupBox_10);
        btnCheckOutEdit->setObjectName(QStringLiteral("btnCheckOutEdit"));

        gridLayout_17->addWidget(btnCheckOutEdit, 0, 3, 1, 1);


        gridLayout->addWidget(groupBox_10, 0, 0, 1, 1);

        splitter_3 = new QSplitter(edit);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Orientation::Horizontal);
        stackedWidgetEdit = new QStackedWidget(splitter_3);
        stackedWidgetEdit->setObjectName(QStringLiteral("stackedWidgetEdit"));
        pagCheckInEdit = new QWidget();
        pagCheckInEdit->setObjectName(QStringLiteral("pagCheckInEdit"));
        gridLayout_19 = new QGridLayout(pagCheckInEdit);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        groupEditTreeView = new QGroupBox(pagCheckInEdit);
        groupEditTreeView->setObjectName(QStringLiteral("groupEditTreeView"));
        gridLayout_18 = new QGridLayout(groupEditTreeView);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        treeViewEdit = new QTreeView(groupEditTreeView);
        treeViewEdit->setObjectName(QStringLiteral("treeViewEdit"));
        treeViewEdit->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        treeViewEdit->header()->setVisible(false);

        gridLayout_18->addWidget(treeViewEdit, 1, 0, 1, 1);

        combGitChoiceEdit = new QComboBox(groupEditTreeView);
        combGitChoiceEdit->setObjectName(QStringLiteral("combGitChoiceEdit"));

        gridLayout_18->addWidget(combGitChoiceEdit, 0, 0, 1, 1);


        gridLayout_19->addWidget(groupEditTreeView, 0, 0, 1, 1);

        stackedWidgetEdit->addWidget(pagCheckInEdit);
        splitter_3->addWidget(stackedWidgetEdit);
        tvEdit = new QTableView(splitter_3);
        tvEdit->setObjectName(QStringLiteral("tvEdit"));
        splitter_3->addWidget(tvEdit);

        gridLayout->addWidget(splitter_3, 1, 0, 1, 1);


        retranslateUi(edit);

        QMetaObject::connectSlotsByName(edit);
    } // setupUi

    void retranslateUi(QDialog *edit)
    {
        edit->setWindowTitle(QApplication::translate("edit", "\347\274\226\350\276\221", Q_NULLPTR));
        groupBox_10->setTitle(QString());
        btnSaveEdit->setText(QApplication::translate("edit", "\344\277\235\345\255\230", Q_NULLPTR));
        btnCheckInEdit->setText(QApplication::translate("edit", "\346\243\200\345\205\245", Q_NULLPTR));
        btnUpdateEdit->setText(QApplication::translate("edit", "\345\210\267\346\226\260", Q_NULLPTR));
        btnGenDwg->setText(QApplication::translate("edit", "\350\275\254DWG", Q_NULLPTR));
        btnCheckOutEdit->setText(QApplication::translate("edit", "\346\243\200\345\207\272", Q_NULLPTR));
        groupEditTreeView->setTitle(QApplication::translate("edit", "\346\243\200\345\205\245\344\275\215\347\275\256", Q_NULLPTR));
        combGitChoiceEdit->clear();
        combGitChoiceEdit->insertItems(0, QStringList()
         << QApplication::translate("edit", "\346\240\207\345\207\206\345\272\223", Q_NULLPTR)
         << QApplication::translate("edit", "\345\205\203\345\231\250\344\273\266\345\272\223", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class edit: public Ui_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_H
