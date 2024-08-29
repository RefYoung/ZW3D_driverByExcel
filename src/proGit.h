#ifndef PROGIT_H
#define PROGIT_H

#include <QDialog>
#include <QShowEvent>
#include <qstandarditemmodel.h>
#include "standardgittabledelegate.h"
#include "standardgittabledelegateimg.h"
#include <QGuiApplication>
#include <QScreen>
#include <qnetworkrequest.h>
#include <qnetworkreply.h>
#include "global.h"
#include "standardgittreeitem.h"
#include <qjsonarray.h>
#include <QShowEvent>
#include <qmap.h>
#include <QCloseEvent>
#include <QMessageBox>
#include "stdgit.h"
#include "PRT.h"

namespace Ui {
class proGit;
}

class proGit : public QDialog
{
    Q_OBJECT

public:
    ~proGit();

    //公有成员部分
    static proGit* getInstance();

private:
    //禁止从外部实例化
    explicit proGit(QWidget* parent = nullptr);

    Ui::proGit*ui;

    //单例指针
    static proGit* m_instance;

    //私有成员部分
    QStandardItemModel* m_standardTreeModel;//标准库管理的树结构模型
    QStandardItemModel* m_standardDataModel;//标准库管理的数据模型
    standardGitTableDelegate m_standardGitTableDelegate;//标准库管理的代理
    standardGitTableDelegateImg m_standardGitTableDelegateImg;//标准库缩略图代理
    StandardGitTreeItem* rootItem;//根节点
    StandardGitTreeItem* m_currentTreeItem;//当前库界面最后双击的节点
    int m_openModelTotal;//打开模型需要下载的零件总数
    int m_openModelCount;//打开模型已经下载的零件总数
    QStringList m_openModelFileNames;//打开模型的零件名
    QMap<QNetworkReply*,struct openModelItem> m_omItemsMap;//用于打开模型的零件图
    QString m_detector;//最后一个检出文件的检出人姓名

    //私有方法部分
    void getModelTreeRequest();//获取模型树请求
    void makeStandardGitTree(StandardGitTreeItem* root, QJsonObject jObj);//创建标准库树
    void assignForItemByJobject(StandardGitTreeItem* item, QJsonObject jObject);//根据json对象为item赋值
    void getQuery3DTPGitMapList();//查询3D铜排列表
    void getFile(QUrl url, int row);//获取文件
    void getOpenModel(QUrl url);//打开模型
    void getOpenModeFile(QUrl u, QJsonObject obj);//获取打开模型文件
    void postCheckOut(QUrl url);//检出零件
    void makeCapGitTree(StandardGitTreeItem* root, QJsonArray arr);//创建capgit树

protected:
    void showEvent(QShowEvent* event);
    void closeEvent(QCloseEvent* event);
private slots:
    void on_btnOpenModel_clicked();
    void on_btnDetail_clicked();

    void onGetModelTreeFinished();
    void on_treeViewStandardGit_doubleClicked(const QModelIndex &index);
    void onGetQuery3DTPGitMaplistFinished();
    void onGetFileFinished();
    void onGetOpenModelFinshed();
    void onGetOpenModelFileFinished();
    void onPostCheckOutFinished();
    
};

#endif // STDGIT_H
