#include "capGit.h"
#include "ui_capGit.h"

//初始化单例指针
capGit* capGit::m_instance = nullptr;

capGit::capGit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::capGit)
{
    ui->setupUi(this);

    //调整窗口
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    QRect rect = QGuiApplication::primaryScreen()->availableGeometry();
    this->resize(rect.width() * 3 / 4, this->height());
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 2);

    //初始化
    ui->tvStandardGit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_standardTreeModel = new QStandardItemModel(this);
    m_standardDataModel = new QStandardItemModel(this);
    m_standardDataModel->setColumnCount(10);
    m_standardDataModel->setHeaderData(0, Qt::Horizontal, u8"选中状态");
    m_standardDataModel->setHeaderData(0, Qt::Horizontal, u8"选中状态");
    m_standardDataModel->setHeaderData(1, Qt::Horizontal, u8"物料编号");
    m_standardDataModel->setHeaderData(2, Qt::Horizontal, u8"物料名称");
    m_standardDataModel->setHeaderData(3, Qt::Horizontal, u8"描述");
    m_standardDataModel->setHeaderData(4, Qt::Horizontal, u8"检出人");
    m_standardDataModel->setHeaderData(5, Qt::Horizontal, u8"检出状态");
    m_standardDataModel->setHeaderData(6, Qt::Horizontal, u8"缩略图");

    m_standardDataModel->setHeaderData(7, Qt::Horizontal, "id");
    m_standardDataModel->setHeaderData(8, Qt::Horizontal, "graphTypeId");
    m_standardDataModel->setHeaderData(9, Qt::Horizontal, "isOutputGraph");

    ui->treeViewStandardGit->setModel(m_standardTreeModel);
    ui->treeViewStandardGit->header()->setVisible(false);

    ui->tvStandardGit->setEditTriggers(QAbstractItemView::AllEditTriggers);
    ui->tvStandardGit->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tvStandardGit->setModel(m_standardDataModel);
    ui->tvStandardGit->hideColumn(7);
    ui->tvStandardGit->hideColumn(8);
    ui->tvStandardGit->hideColumn(9);
    ui->tvStandardGit->setItemDelegateForColumn(0, &m_standardGitTableDelegate);
    ui->tvStandardGit->setItemDelegateForColumn(6, &m_standardGitTableDelegateImg);

    m_openModelTotal = 0;
    m_openModelCount = 0;
}

capGit::~capGit()
{
    m_instance= nullptr;
    delete ui;
}

capGit* capGit::getInstance()
{
    if(m_instance == nullptr)m_instance = new capGit();
    return m_instance;
}

void capGit::getModelTreeRequest()
{
   QNetworkRequest request;
   request.setUrl(QUrl(g_getBaseUrl() + g_getModeTreeUrl + "?productMappingId=3&schemeLibraryClass=3" ));
   request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
   request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
   request.setRawHeader("Authorization", g_userToken.toUtf8());

   QNetworkReply* reply = g_networkManager.get(request);
   reply->setParent(this);
   connect(reply, SIGNAL(finished()), this, SLOT(onGetModelTreeFinished()));
}

void capGit::makeStandardGitTree(StandardGitTreeItem* root, QJsonObject jObj)
{
    if (jObj.isEmpty())return;
    StandardGitTreeItem* item = new StandardGitTreeItem();
    assignForItemByJobject(item, jObj);
    root->setChild(root->rowCount(), item);
    QJsonArray jArray = jObj.value("children").toArray();
    for (int i = 0; i < jArray.size(); ++i) {
        QJsonObject tmpObj = jArray.at(i).toObject();
        makeStandardGitTree(item, tmpObj);
    }
}

void capGit::assignForItemByJobject(StandardGitTreeItem* item, QJsonObject jObject)
{
    item->id = jObject.value("id").toString();
    item->plmId = jObject.value("plmId").toString();
    item->code = jObject.value("code").toString();
    item->label = jObject.value("label").toString();
    item->typeEnum = jObject.value("typeEnum").toString();
    item->mediumTypeEnum = jObject.value("mediumTypeEnum").toString();
    item->attrTypeId = jObject.value("attrTypeId").toString();
    item->isLibrary = jObject.value("isLibrary").toString();
    item->realType = QString::number(jObject.value("realType").toInt());
    item->codeAutoFlag = jObject.value("codeAutoFlag").toString();
    item->productMappingId = jObject.value("productMappingId").toString();
    item->schemeLibraryClass = jObject.value("schemeLibraryClass").toString();
    item->setText(item->label);
}

void capGit::getQuery3DTPGitMapList()
{
    QNetworkRequest request;
    request.setUrl(QUrl(g_getBaseUrl()+g_query3DTPGitMapListUrl+"?pageNum=1&pageSize=255&graphTypeId=" + m_currentTreeItem->id));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    
    request.setRawHeader("Authorization", g_userToken.toUtf8());
    QNetworkReply* reply = g_networkManager.get(request);
    reply->setParent(this);
    connect(reply, SIGNAL(finished()), this, SLOT(onGetQuery3DTPGitMaplistFinished()));
}

void capGit::getFile(QUrl url, int row)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setRawHeader("Authorization", g_userToken.toUtf8());
    QNetworkReply* reply = g_networkManager.get(request);
    reply->setParent(this);
    reply->setProperty("row", row);
    connect(reply, SIGNAL(finished()), this, SLOT(onGetFileFinished()));
}

void capGit::getOpenModel(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setRawHeader("Authorization", g_userToken.toUtf8());
    
    QNetworkReply* reply = g_networkManager.get(request);
    reply->setParent(this);
    connect(reply, SIGNAL(finished()), this, SLOT(onGetOpenModelFinshed()));
}

void capGit::getOpenModeFile(QUrl u, QJsonObject obj)
{
    QStringList _list = obj.value("graphFile").toString().split('/', QString::SkipEmptyParts);
    if (_list.count() < 2)return;

    openModelItem item;
    item.fileName = _list.at(_list.count() - 1);
    item.graphId = obj.value("id").toString();
    item.graphTypeId = obj.value("graphTypeId").toString();
    item.graphName = obj.value("graphName").toString();
    item.materialNo = obj.value("graphCode").toString();
    item.detector = obj.value("updateBy").toString();
    item.remark = obj.value("remark").toString();
    item.isOutPutGraph = obj.value("isOutputGraph").toString();

    QNetworkRequest request;
    QUrl url(u);
    url.setUserName(g_ftpUserName);
    url.setPassword(g_ftpUserPswd);
    request.setUrl(url);
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

    QNetworkReply* reply = g_networkManager.get(request);
    reply->setParent(this);
    m_omItemsMap[reply] = item;//添加零件item映射
    //QNetworkReply* reply=m_manager->get(request);
    reply->setProperty("fileName", item.fileName);
    m_openModelFileNames << item.fileName;
    connect(reply, SIGNAL(finished()), this, SLOT(onGetOpenModelFileFinished()));
}

void capGit::postCheckOut(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    request.setRawHeader("Authorization", g_userToken.toUtf8());
    QByteArray arr;
    QNetworkReply* reply = g_networkManager.post(request, arr);
    reply->setParent(this);
    connect(reply, SIGNAL(finished()), this, SLOT(onPostCheckOutFinished()));
}

void capGit::makeCapGitTree(StandardGitTreeItem* root, QJsonArray arr)
{
    if (arr.isEmpty())return;
    for (int i = 0; i < arr.count(); ++i) {
        StandardGitTreeItem* item = new StandardGitTreeItem();
        assignForItemByJobject(item, arr.at(i).toObject());
        root->setChild(root->rowCount(), item);
    }
}

void capGit::showEvent(QShowEvent *event)
{
    //先获取目录树
    getModelTreeRequest();

    //清除data表格
    m_standardDataModel->removeRows(0, m_standardDataModel->rowCount());

    //调用父类显示函数
    QDialog::showEvent(event);

}

void capGit::closeEvent(QCloseEvent *event)
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

void capGit::onGetModelTreeFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply != nullptr) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        int code = -1;
        code = doc.object().value("code").toInt();

        if (reply->error() || code != 200) {
            QString note = u8"获取目录树信息时发生错误,请重新登陆.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode);
            QMessageBox::warning(this, u8"警告", note);
            cvxMsgDisp2(note.toLocal8Bit(), 4);
            
        }
        //如果是200，则说明请求成功
        else if (statusCode == 200) {
            
            m_standardTreeModel->removeRows(0, m_standardTreeModel->rowCount());
            rootItem = new StandardGitTreeItem();
            QJsonArray arr = doc.object().value("data").toArray();
            makeCapGitTree(rootItem, arr);
            m_standardTreeModel->appendRow(rootItem);
            
            ui->treeViewStandardGit->setExpanded(rootItem->index(), true);
            ui->treeViewStandardGit->setRootIndex(rootItem->index());
        }
    }
    reply->deleteLater();
    reply = nullptr;
}


void capGit::on_btnOpenModel_clicked()
{
    this->setEnabled(false);
  
    //获取选中的行
    int index = -1;
    for (int i = 0; i < m_standardDataModel->rowCount(); ++i) {
        if (m_standardDataModel->data(m_standardDataModel->index(i, 0)).toInt() == 1) {
            index = i;
            break;
        }
    }
    //没有选中行
    if (index==-1) {
        this->setEnabled(true);
        return;
    }

    //选中了某行
    if (ui->cheCheOutStandardGit->isChecked()) {//勾选了检出单选框
        postCheckOut(QUrl(g_getBaseUrl() + g_projectCheckOutUrl + "?graphId=" + m_standardDataModel->data(m_standardDataModel->index(index, 7)).toString() + "&graphTypeId=" + m_standardDataModel->data(m_standardDataModel->index(index, 8)).toString()));
    }
    else {//没有勾选检出单选框
        getOpenModel(QUrl(g_getBaseUrl() +g_openModelUrl +"/"+ m_standardDataModel->data(m_standardDataModel->index(index, 8)).toString() + "/" + m_standardDataModel->data(m_standardDataModel->index(index, 7)).toString()));
    }
}


void capGit::on_treeViewStandardGit_doubleClicked(const QModelIndex &index)
{
    StandardGitTreeItem* item = static_cast<StandardGitTreeItem*>(m_standardTreeModel->itemFromIndex(index));
    m_currentTreeItem = item;
    getQuery3DTPGitMapList();
}

void capGit::onGetQuery3DTPGitMaplistFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply != nullptr) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        int code = -1;
        code = doc.object().value("code").toInt();

        if (reply->error() || code != 200) {
            QString note = u8"查询3D铜排库图列表信息时发生错误,请重新登陆.\n错误代码:" + QString::number(code)+u8" http状态码:" + QString::number(statusCode);
            QMessageBox::warning(this, u8"警告", note);
            cvxMsgDisp2(note.toLocal8Bit(), 4);

            reply->deleteLater();
            reply = nullptr;
            return;
        }else if(statusCode == 200) {

            QStandardItemModel* _model = m_standardDataModel;
            _model->removeRows(0, _model->rowCount());

            QJsonObject obj = doc.object();
            int count = -1;
            count = obj.value("total").toInt();
            if (count > 0) {
                QJsonArray array = obj.value("rows").toArray();
                for (int i = 0; i < array.count(); ++i) {
                    _model->insertRow(_model->rowCount());
                    ui->tvStandardGit->setRowHeight(_model->rowCount() - 1, 80);

                    QJsonObject rowObj = array.at(i).toObject();
                    _model->setData(_model->index(_model->rowCount() - 1, 1), rowObj.value("graphCode"));
                    _model->setData(_model->index(_model->rowCount() - 1, 2), rowObj.value("graphName"));
                    _model->setData(_model->index(_model->rowCount() - 1, 3), rowObj.value("remark"));
                    // _model->setData(_model->index(_model->rowCount()-1,4),rowObj.value("graphCode"));
                    if (rowObj.value("checkInOutStatus").toString() == "2") {
                        _model->setData(_model->index(_model->rowCount() - 1, 4), rowObj.value("updateBy"));
                        _model->setData(_model->index(_model->rowCount() - 1, 5), u8"已检出");

                    }
                    else if (rowObj.value("checkInOutStatus").toString() == "1") {
                        _model->setData(_model->index(_model->rowCount() - 1, 5), u8"已检入");
                    }

                    _model->setData(_model->index(_model->rowCount() - 1, 7), rowObj.value("id"));
                    _model->setData(_model->index(_model->rowCount() - 1, 8), rowObj.value("graphTypeId"));
                    _model->setData(_model->index(_model->rowCount() - 1, 9), rowObj.value("isOutputGraph"));


                    QMap<QString, QString> head;
                    head["Authorization"] = g_userToken;
                    //cvxMsgDisp("123:" + rowObj.value("graphPicture").toString().toLocal8Bit());
                    getFile(QUrl(rowObj.value("graphJpgFile").toString()), _model->rowCount() - 1);

                    for (int k = 1; k < 6; ++k) {
                        QStandardItem* item = _model->item(_model->rowCount() - 1, k);
                        if (item != NULL) {
                            item->setTextAlignment(Qt::AlignCenter);
                            item->setFlags(item->flags() & ~Qt::ItemIsEditable);

                        }
                    }

                    
                }
            }
            for (int i = 0; i < 7; ++i) {
                ui->tvStandardGit->setColumnWidth(i, ui->tvStandardGit->width() / 7);
            }

            reply->deleteLater();
            reply = nullptr;

        }
    }
}

void capGit::onGetFileFinished()
{
    QNetworkReply* reply = static_cast<QNetworkReply*>(sender());
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (statusCode != 200)return;
    QPixmap pix;
    pix.loadFromData(reply->readAll());
    m_standardDataModel->setData(ui->tvStandardGit->model()->index(reply->property("row").toInt(), 6), QVariant::fromValue(pix));
}

void capGit::onGetOpenModelFinshed()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (reply != nullptr) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        int code = -1;
        code = doc.object().value("code").toInt();

        if (reply->error() || code != 200) {
            QString errString = doc.object().value("msg").toString();
            QString note = u8"打开模型出错.\n出错代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode) + u8" 错误信息:" + errString;
            QMessageBox::warning(this, u8"警告", note);
            cvxMsgDisp2(note.toLocal8Bit(), 4);

            this->setEnabled(true);
            reply->deleteLater();
            reply = nullptr;
            return;
        }

        if (statusCode == 200) {
            cvxFileSaveAll();
            cvxSessionClear();

            QJsonArray array = doc.object().value("data").toArray();

            m_openModelTotal = array.count();

            for (int i = 0; i < array.count(); ++i) {
                QJsonObject obj = array[i].toObject();

                if (obj.value("graphFile").toString().isEmpty()) {
                    QString note = u8"打开模型出错,零件下载地址不存在..\n出错零件物料号:" + obj.value("graphCode").toString().toUtf8() + u8" 出错零件物名称:" + obj.value("graphName").toString().toUtf8();
                    QMessageBox::warning(this, u8"警告", note);
                    cvxMsgDisp2(note.toLocal8Bit(), 4);
                    this->setEnabled(true);
                    return;
                }

            }

            m_openModelCount = 0;
            if (m_openModelTotal == 0) {
                cvxMsgDisp(QString::fromUtf8(u8"没有需要下载的零件.").toLocal8Bit());
                this->setEnabled(true);
            }
            else cvxMsgDisp(QString::fromUtf8(u8"开始下载模型所需零件,一共" + QString::number(m_openModelTotal).toUtf8() + u8"个").toLocal8Bit());
            m_openModelFileNames.clear();
            m_omItemsMap.clear();
            QMap<QString, QString> map;
            for (int i = 0; i < array.count(); ++i) {
                QJsonObject obj = array[i].toObject();

                getOpenModeFile(QUrl(obj.value("graphFile").toString()),  obj);
            }
            reply->deleteLater();
            reply = nullptr;
        }
    }
}

void capGit::onGetOpenModelFileFinished()
{
    bool flag = false;
    m_openModelCount++;
    cvxMsgDisp(QString::fromUtf8(u8"已下载" + QString::number(m_openModelCount).toUtf8() + u8"个,还差" + QString::number(m_openModelTotal - m_openModelCount).toUtf8() + u8"个.").toLocal8Bit());
    if (m_openModelCount >= m_openModelTotal) {
        flag = true;
        m_openModelCount = 0;
        m_openModelTotal = 0;
    }
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply == nullptr)return;

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if (reply->error() != QNetworkReply::NoError) {
        QString note = u8"下载零件失败,错误代码: " + QString::number(reply->error()).toUtf8() + u8"错误原因:" + reply->errorString().toUtf8();
        QMessageBox::warning(this, u8"警告",note );
        cvxMsgDisp2(note.toLocal8Bit(), 4);
    }
    else {
        QFile file;
        QString fileDir = g_capGitDirPath + "/" + m_currentTreeItem->text();
        QDir dir(fileDir);
        if (!dir.exists()) dir.mkpath(fileDir);
        file.setFileName(fileDir + "\\" + reply->property("fileName").toString());
        
        file.open(QIODevice::WriteOnly);
        file.write(reply->readAll());
        file.close();
    }

    //下载完成
    if (flag == false)return;

    //为每个零件写入用户信息
    for (auto i = m_omItemsMap.begin(); i != m_omItemsMap.end(); ++i) {
        openModelItem item = i.value();
        QString filePath;
        if (g_currentWorkDir.isEmpty()) {
            filePath = i.value().fileName;
        }
        else {
            filePath = g_currentWorkDir + "\\" + i.value().fileName;
        }
        if (filePath.endsWith("Z3PRT", Qt::CaseInsensitive) || filePath.endsWith("Z3ASM", Qt::CaseInsensitive)) {

            int result = cvxFileOpen(QString::fromUtf8(filePath.toUtf8()).toLocal8Bit());
            if (result == ZW_API_NO_ERROR) {
                int AttCnt = 0;
                svxAttribute* UserAt = NULL;
                cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt);
                QString _desc;
                bool flag = false;
                bool flag2 = false;
                bool flag3 = false;
                bool flag4 = false;
                bool flag5 = false;
                bool flag6 = false;
                bool flag7 = false;//internationalName

                for (int i = 0; i < AttCnt; ++i) {

                    if (QString::fromLocal8Bit(UserAt[i].label) == g_graphTypeId) {

                        strcpy_s(UserAt[i].data, item.graphTypeId.toLocal8Bit());
                        cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                        //cvxFileSave3(0, 1, 0);
                        flag = true;
                    }

                    //����detector
                    if (QString::fromLocal8Bit(UserAt[i].label) == g_detector) {

                        strcpy_s(UserAt[i].data, item.detector.toLocal8Bit());
                        cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                        //cvxFileSave3(0, 1, 0);
                        flag2 = true;
                    }

                    //����graphId
                    if (QString::fromLocal8Bit(UserAt[i].label) == g_graphId) {

                        strcpy_s(UserAt[i].data, item.graphId.toLocal8Bit());
                        cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                        //cvxFileSave3(0, 1, 0);
                        flag3 = true;
                    }

                    //����materialNo
                    if (QString::fromLocal8Bit(UserAt[i].label) == g_materialNo) {

                        strcpy_s(UserAt[i].data, item.materialNo.toLocal8Bit());
                        cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                        //cvxFileSave3(0, 1, 0);
                        flag4 = true;
                    }

                    //����graphName
                    if (QString::fromLocal8Bit(UserAt[i].label) == g_graphName) {

                        strcpy_s(UserAt[i].data, item.graphName.toLocal8Bit());
                        cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                        //cvxFileSave3(0, 1, 0);
                        flag5 = true;
                    }

                    //����remark
                    if (QString::fromLocal8Bit(UserAt[i].label) == g_remark) {

                        strcpy_s(UserAt[i].data, item.remark.toLocal8Bit());
                        cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                        //cvxFileSave3(0, 1, 0);
                        flag6 = true;
                    }

                    //����isOutputGraph
                    if (QString::fromLocal8Bit(UserAt[i].label) == g_isOutputGraph) {

                        strcpy_s(UserAt[i].data, item.isOutPutGraph.toLocal8Bit());
                        cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                        //cvxFileSave3(0, 1, 0);
                        flag7 = true;
                    }
                }


                if (flag == false) {

                    svxAttribute userAttrs[1] = { 0 };
                    strcpy_s(userAttrs[0].label, g_graphTypeId.toLocal8Bit());
                    userAttrs[0].type = VX_ATTR_STRING;
                    strcpy_s(userAttrs[0].data, item.graphTypeId.toLocal8Bit());
                    cvxPartUserAtSet(0, 0, false, 1, userAttrs);
                    //cvxFileSave3(0, 1, 0);
                }

                //��������û��detector����,������detector����
                if (flag2 == false) {

                    svxAttribute userAttrs[1] = { 0 };
                    strcpy_s(userAttrs[0].label, g_detector.toLocal8Bit());
                    userAttrs[0].type = VX_ATTR_STRING;
                    strcpy_s(userAttrs[0].data, item.detector.toLocal8Bit());
                    cvxPartUserAtSet(0, 0, false, 1, userAttrs);
                    //cvxFileSave3(0, 1, 0);
                }

                //��������û��graphId����,������graphId����
                if (flag3 == false) {

                    svxAttribute userAttrs[1] = { 0 };
                    strcpy_s(userAttrs[0].label, g_graphId.toLocal8Bit());
                    userAttrs[0].type = VX_ATTR_STRING;
                    strcpy_s(userAttrs[0].data, item.graphId.toLocal8Bit());
                    cvxPartUserAtSet(0, 0, false, 1, userAttrs);
                    //cvxFileSave3(0, 1, 0);
                }

                //��������û��materialNo����,������materialNo����
                if (flag4 == false) {

                    svxAttribute userAttrs[1] = { 0 };
                    strcpy_s(userAttrs[0].label, g_materialNo.toLocal8Bit());
                    userAttrs[0].type = VX_ATTR_STRING;
                    strcpy_s(userAttrs[0].data, item.materialNo.toLocal8Bit());
                    cvxPartUserAtSet(0, 0, false, 1, userAttrs);
                    //cvxFileSave3(0, 1, 0);
                }

                //��������û��graphName����,������graphName����
                if (flag5 == false) {

                    svxAttribute userAttrs[1] = { 0 };
                    strcpy_s(userAttrs[0].label, g_graphName.toLocal8Bit());
                    userAttrs[0].type = VX_ATTR_STRING;
                    strcpy_s(userAttrs[0].data, item.graphName.toLocal8Bit());
                    cvxPartUserAtSet(0, 0, false, 1, userAttrs);
                    //cvxFileSave3(0, 1, 0);
                }

                //��������û��remark����,������remark����
                if (flag6 == false) {

                    svxAttribute userAttrs[1] = { 0 };
                    strcpy_s(userAttrs[0].label, g_remark.toLocal8Bit());
                    userAttrs[0].type = VX_ATTR_STRING;
                    strcpy_s(userAttrs[0].data, item.remark.toLocal8Bit());
                    cvxPartUserAtSet(0, 0, false, 1, userAttrs);
                    //cvxFileSave3(0, 1, 0);
                }

                //��������û��isOutputGraph����,������isOutputGraph����
                if (flag7 == false) {

                    svxAttribute userAttrs[1] = { 0 };
                    strcpy_s(userAttrs[0].label, g_isOutputGraph.toLocal8Bit());
                    userAttrs[0].type = VX_ATTR_STRING;
                    strcpy_s(userAttrs[0].data, item.isOutPutGraph.toLocal8Bit());
                    cvxPartUserAtSet(0, 0, false, 1, userAttrs);
                    //cvxFileSave3(0, 1, 0);
                }

                cvxFileSave3(1, 1, 1);
            }
        }
    }
    if (m_openModelFileNames.count() < 1)return;
    QString fileName = m_openModelFileNames[0];
    for (int i = 1; i < m_openModelFileNames.count(); ++i) {
        if (m_openModelFileNames[i].endsWith("Z3ASM", Qt::CaseInsensitive)) {
            fileName = m_openModelFileNames[i];
        }
        else if (m_openModelFileNames[i].endsWith("Z3DRW", Qt::CaseInsensitive)) {
            fileName = m_openModelFileNames[i];
            break;
        }
    }

    cvxFileOpen(QString::fromUtf8(g_currentWorkDir.toUtf8() + u8"/" + fileName.toUtf8()).toLocal8Bit());

    this->setEnabled(true);
}

void capGit::onPostCheckOutFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply == nullptr)return;
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    int code = -1;
    code = doc.object().value("code").toInt();

    if (reply->error() || code != 200) {
        QString errString = doc.object().value("msg").toString();
        QString note = u8"检出文件时发生错误,请重新登陆.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode) + u8" 错误信息:" + errString;
        QMessageBox::warning(this, u8"警告", note);
        cvxMsgDisp2(note.toLocal8Bit(), 4);

        this->setEnabled(true);

        reply->deleteLater();
        reply = nullptr;
    }else if (statusCode == 200) {
        m_detector = doc.object().value("data").toObject().value("detector").toString();
       
		int i = -1;
		for (int j = 0; j < m_standardDataModel->rowCount(); ++j) {
			if (m_standardDataModel->data(m_standardDataModel->index(j, 0)).toInt() == 1) {
				i = j;
				break;
			}
		}

		m_standardDataModel->setData(m_standardDataModel->index(i, 4), m_detector);
        m_standardDataModel->setData(m_standardDataModel->index(i, 5), u8"已检出");
        
		QStandardItem* item = m_standardDataModel->item(i, 4);
		if (item != NULL) {
			item->setTextAlignment(Qt::AlignCenter);
		}
        
        getOpenModel(QUrl(g_getBaseUrl() + g_openModelUrl + "/" + m_standardDataModel->data(m_standardDataModel->index(i, 8)).toString() + "/" + m_standardDataModel->data(m_standardDataModel->index(i, 7)).toString()));
		
        reply->deleteLater();
		reply = nullptr;
    }
}


void capGit::on_btnNewDIr_clicked()
{
    bool ok=false;
    QString input=QInputDialog::getText(this,u8"新建文件夹",u8"请输入文件夹名:",QLineEdit::Normal,"",&ok);
   
	if (ok) {
		StandardGitTreeItem* item = new StandardGitTreeItem;
		item->setText(input);
		item->label = input;
        rootItem->appendRow(item);
        QString dirPath=g_capGitDirPath + "/" + input;
        QDir dir(dirPath);
        if(!dir.exists())dir.mkpath(dirPath);
	}
}

