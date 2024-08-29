#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include <qscreen.h>
#include <QGuiApplication>
#include <VxApi.h>
#include <QStandardItemModel>
#include <QShowEvent>
#include <qnetworkreply.h>
#include <qnetworkrequest.h>
#include "global.h"
#include <qcombobox.h>
#include <QHttpMultiPart>
#include <QCloseEvent>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    static edit* getInstance();//获取单例
    ~edit();

private:
    //禁止外部实例化
    explicit edit(QWidget* parent = nullptr);

    Ui::edit *ui;

    //私有成员变量
    static edit* m_instance;//单例指针
    QStandardItemModel* m_editTreeModel;//编辑界面的树结构模型
    QStandardItemModel* m_editDataModel;//编辑界面的数据模型
    StandardGitTreeItem* rootItem;//树结构根节点
    int m_2Dtotal;//上传的二维图总数量
    int m_2Dcount;//上传的二维图数量

    //私有方法
    void getModelTreeRequest();//获取模型树请求,标准库
    void getModelTreeRequestCap();//获取模型树请求,元器件库
    void makeStandardGitTree(StandardGitTreeItem* root, QJsonObject jObj);//将json对象转换为树结构
    void assignForItemByJobject(StandardGitTreeItem* item, QJsonObject jObject);//将json对象赋值给树节点
    StandardGitTreeItem* findItemInEditTreeView(StandardGitTreeItem* rootItem, QString targetId);//在编辑界面的树结构中查找指定id的节点
    void makeCapGitTree(StandardGitTreeItem* root, QJsonArray arr);//创建capgit树
    void postCheckIn(QUrl url, QMap<QString, QString> head, QString graphTypeId, QString materialNo, char* filePath, QString desc, QString graphName);//提交入库请求
    void postCheckOut(QUrl url, QMap<QString, QString> head, QString graphId, QString graphTypeId);//检出

private slots:

    void on_btnCheckInEdit_clicked();

    void on_btnCheckOutEdit_clicked();

    void on_btnUpdateEdit_clicked();

    void on_btnSaveEdit_clicked();//当编辑界面的保存按钮按下时调用此槽函数

    void on_btnGenDwg_clicked();

    void onGetModelTreeFinished();//获取模型树请求完成时调用此槽函数,标准库

    void onGetModelTreeFinishedCap();//获取模型树请求完成时调用此槽函数,元器件库

    void on_combGitChoiceEdit_currentIndexChanged(int index);

    void onPostCheckInFinished();//提交入库请求完成时调用此槽函数

    void onPostCheckOutFinished();

    void onPutFtpFileFinished();

    void onPostUpload2DPicFinished();//上传二维图完成时调用此槽函数

protected:
    void showEvent(QShowEvent* event);
    void closeEvent(QCloseEvent* event);
};

#endif // EDIT_H
