#ifndef EXCELTOPRT_H
#define EXCELTOPRT_H

#include <QDialog>
#include <qguiapplication.h>
#include <qdesktopwidget.h>
#include "global.h"
#include <QShowEvent>
#include <QCloseEvent>
#include <qstandarditemmodel.h>

namespace Ui {
class excelToPrt;
}

class excelToPrt : public QDialog
{
    Q_OBJECT

public:
    static excelToPrt* getInstance();

    ~excelToPrt();

private slots:
    void on_btnBroese_clicked();

    void on_btnGen_clicked();

    void on_btnSave_clicked();

    void on_btnCancel_clicked();

private:
    Ui::excelToPrt *ui;
    explicit excelToPrt(QWidget *parent = nullptr);

    //к╫спЁит╠
    static excelToPrt* m_instance;
    QStandardItemModel* m_model;
 

protected:
    void showEvent(QShowEvent* event);
    void closeEvent(QCloseEvent* event);
};

#endif // EXCELTOPRT_H
