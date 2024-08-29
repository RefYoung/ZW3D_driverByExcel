#include "edit.h"
#include "ui_edit.h"

edit* edit::m_instance = nullptr;

edit::edit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::edit)
{
    ui->setupUi(this);

    //设置窗口属性
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
    QRect rect = QGuiApplication::primaryScreen()->availableGeometry();
    this->resize(rect.width() / 2, this->height());

    //初始化
    m_editTreeModel = new QStandardItemModel(this);
    m_editDataModel = new QStandardItemModel(this);
    m_editDataModel->setColumnCount(5);
    m_editDataModel->setHeaderData(0, Qt::Horizontal, u8"编号");
    m_editDataModel->setHeaderData(1, Qt::Horizontal, u8"名称");
    m_editDataModel->setHeaderData(2, Qt::Horizontal, u8"输出工程图");
    m_editDataModel->setHeaderData(3, Qt::Horizontal, u8"检出人");
    m_editDataModel->setHeaderData(4, Qt::Horizontal, u8"数量");
    ui->tvEdit->setModel(m_editDataModel);
    ui->treeViewEdit->setModel(m_editTreeModel);
    ui->treeViewEdit->header()->setVisible(false);
    ui->tvEdit->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tvEdit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tvEdit->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->splitter_3->setStretchFactor(0, 1);
    ui->splitter_3->setStretchFactor(1, 2);
}

void edit::getModelTreeRequest()
{
    QNetworkRequest request;
    request.setUrl(QUrl(g_getBaseUrl() + g_getModeTreeUrl + "?productMappingId=3&schemeLibraryClass=1"));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setRawHeader("Authorization", g_userToken.toUtf8());

    QNetworkReply* reply = g_networkManager.get(request);
    reply->setParent(this);
    connect(reply, SIGNAL(finished()), this, SLOT(onGetModelTreeFinished()));
}

void edit::getModelTreeRequestCap()
{
    QNetworkRequest request;
    request.setUrl(QUrl(g_getBaseUrl() + g_getModeTreeUrl + "?productMappingId=3&schemeLibraryClass=3"));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setRawHeader("Authorization", g_userToken.toUtf8());

    QNetworkReply* reply = g_networkManager.get(request);
    reply->setParent(this);
    connect(reply, SIGNAL(finished()), this, SLOT(onGetModelTreeFinishedCap()));
}

void edit::makeStandardGitTree(StandardGitTreeItem* root, QJsonObject jObj)
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

void edit::assignForItemByJobject(StandardGitTreeItem* item, QJsonObject jObject)
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

StandardGitTreeItem* edit::findItemInEditTreeView(StandardGitTreeItem* rootItem, QString targetId)
{
    if (rootItem->id == targetId)return rootItem;

    StandardGitTreeItem* targetItem = nullptr;

    for (int i = 0; i < rootItem->rowCount(); ++i) {

        StandardGitTreeItem* itemChild = static_cast<StandardGitTreeItem*>(rootItem->child(i));
        if (itemChild == nullptr)continue;
        if (itemChild->id == targetId)return itemChild;
        for (int j = 0; j < itemChild->rowCount(); ++j) {
            targetItem = findItemInEditTreeView(itemChild, targetId);
            if (targetItem != nullptr)return targetItem;
        }
    }

    return nullptr;
}

void edit::makeCapGitTree(StandardGitTreeItem* root, QJsonArray arr)
{
    if (arr.isEmpty())return;
    for (int i = 0; i < arr.count(); ++i) {
        StandardGitTreeItem* item = new StandardGitTreeItem();
        assignForItemByJobject(item, arr.at(i).toObject());
        root->setChild(root->rowCount(), item);
    }
}

void edit::postCheckIn(QUrl url, QMap<QString, QString> head, QString graphTypeId, QString materialNo, char* filePath, QString desc, QString graphName)
{
    QNetworkRequest request;
    int num = m_editDataModel->data(m_editDataModel->index(0, 4)).toInt();
    request.setUrl(QUrl(url.toString() + "?graphTypeId=" + graphTypeId + "&materialNo=" + materialNo + "&desc=" + desc.toUtf8() + "&num=" + QString::number(num) + "&graphName=" + graphName));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

    for (auto i = head.begin(); i != head.end(); ++i) {
        request.setRawHeader(i.key().toUtf8(), i.value().toUtf8());
    }

    QFileInfo f(QString::fromLocal8Bit(filePath));
    QStringList _list = f.fileName().split('.', QString::SkipEmptyParts);
    if (_list.count() <= 0)return;
    _list[_list.count() - 1] = "jpg";

    QString imgPath;

    if (g_currentWorkDir.isEmpty()) {
        imgPath = _list.join('.');
        cvxFilePreviewExtract(filePath, imgPath.toLocal8Bit());
    }
    else {
        imgPath = g_currentWorkDir + "\\" + _list.join('.');
        cvxFilePreviewExtract(filePath, imgPath.toLocal8Bit());
    }

    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpg"));
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"thumbnailFile\";filename=\"%1\";").arg(_list.join('.'))));
    QFile* file = new QFile(imgPath.toUtf8());
    //QFile file(_list.join('.').toUtf8());
    bool bopen1 = file->open(QIODevice::ReadOnly);
    imagePart.setBodyDevice(file);
    file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart

    QFile* file2 = new QFile(QString::fromLocal8Bit(filePath));
    //QFile file2(QString::fromLocal8Bit(filePath));
    QHttpPart dbFilePart;
    QString requestFormat = QString::fromLocal8Bit("form-data;name=%1;filename=%2;type = application/octet-stream")
        .arg("file")
        .arg(f.fileName());
    dbFilePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(requestFormat.toUtf8()));

    bool bopen2 = file2->open(QIODevice::ReadOnly);
    dbFilePart.setBodyDevice(file2);
    file2->setParent(multiPart);

    multiPart->append(imagePart);
    multiPart->append(dbFilePart);

    QNetworkReply* reply = g_networkManager.post(request, multiPart);
    multiPart->setParent(reply);
    reply->setParent(this);

    connect(reply, SIGNAL(finished()), this, SLOT(onPostCheckInFinished()));
}

void edit::postCheckOut(QUrl url, QMap<QString, QString> head, QString graphId, QString graphTypeId)
{
    QNetworkRequest request;
    request.setUrl(QUrl(url.toString() + "?graphId=" + graphId + "&graphTypeId=" + graphTypeId));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

    for (auto i = head.begin(); i != head.end(); ++i) {
        request.setRawHeader(i.key().toUtf8(), i.value().toUtf8());
    }
    QByteArray arr;
    QNetworkReply* reply = g_networkManager.post(request, arr);
    reply->setParent(this);
    connect(reply, SIGNAL(finished()), this, SLOT(onPostCheckOutFinished()));
}

void edit::on_btnCheckOutEdit_clicked()
{
    this->setEnabled(false);
    int AttCnt = 0;
    svxAttribute* UserAt = NULL;
    if (cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt) != ZW_API_NO_ERROR) {
        cvxMsgDisp2(QString::fromUtf8(u8"获取用户属性失败,取消检出操作.").toLocal8Bit(),4);
        this->setEnabled(true);
        return;
    }
    QMap<QString, QString> head;
    head["Authorization"] = g_userToken;
    QString graphId;
    QString graphTypeId;
    for (int i = 0; i < AttCnt; ++i) {
        if (QString::fromLocal8Bit(UserAt[i].label) == g_graphId) {
            graphId = QString::fromLocal8Bit(UserAt[i].strValue);
        }
        else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphTypeId) {
            graphTypeId = QString::fromLocal8Bit(UserAt[i].strValue);
        }
    }

    postCheckOut(QUrl(g_getBaseUrl() + g_projectCheckOutUrl), head, graphId, graphTypeId);
}

void edit::on_btnCheckInEdit_clicked() {
    if (ui->stackedWidgetEdit->isHidden()) {
        ui->stackedWidgetEdit->show();
    }
    else {
        if (ui->treeViewEdit->currentIndex().isValid()) {
            this->setEnabled(false);

            char name[1024] = { 0 }, path[1024] = { 0 };
            cvxFileInqActive(name, 1024);


            if (name[0] == 0) {
                cvxMsgDisp2(QString::fromUtf8(u8"当前没有激活零件,取消检入操作.").toLocal8Bit(),4);
                this->setEnabled(true);
                return;
            }

            cvxPathFindByFileName(name, path, 1024);

            cvxFileSave3(0, 1, 0);

            QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->treeViewEdit->model());
            StandardGitTreeItem* _item = static_cast<StandardGitTreeItem*>(model->itemFromIndex(ui->treeViewEdit->currentIndex()));
            if (_item->realType.toInt() == 7) {
                QMessageBox::warning(this, u8"警告", u8"请到元器件库检入.");
                this->setEnabled(true);
                return;
            }
            else if (_item->realType.toInt() == 8) {
                QMessageBox::warning(this, u8"警告", u8"请到铜排零件图层级检入.");
                this->setEnabled(true);
                return;
            }
            else if (_item->realType.isEmpty()) {
                QMessageBox::warning(this, u8"警告", u8"选中层级RealType值为空,请联系管理员维护.");
                this->setEnabled(true);
                return;
            }

            QMap<QString, QString> head;
            head["Authorization"] = g_userToken;

            int AttCnt = 0;
            svxAttribute* UserAt = NULL;
            cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt);
            QString _desc;
            QString _graphName;
            for (int i = 0; i < AttCnt; ++i) {
                if (QString::fromLocal8Bit(UserAt[i].label) == g_remark) {
                    _desc = QString::fromLocal8Bit(UserAt[i].strValue);
                }
                else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphName) {
                    _graphName = QString::fromLocal8Bit(UserAt[i].strValue);
                }
            }



            postCheckIn(QUrl(g_getBaseUrl() + g_projectCheckInUrl), head, _item->id, m_editDataModel->data(m_editDataModel->index(0, 0)).toString(), path, _desc, _graphName);

        }
        else {
            cvxMsgDisp2(QString::fromUtf8(u8"请先选则检入位置.").toLocal8Bit(), 4);
        }
    }
}

void edit::on_btnUpdateEdit_clicked()
{
    this->setEnabled(false);

    ui->combGitChoiceEdit->currentIndexChanged(ui->combGitChoiceEdit->currentIndex());

    m_editDataModel->removeRows(0, m_editDataModel->rowCount());

    int AttCnt = 0;
    svxAttribute* UserAt = NULL;
    if (cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt) != ZW_API_NO_ERROR) {
        this->setEnabled(true);
        return;
    }
    QString targetGraphTypeId;

    if (m_editDataModel->rowCount() == 0) {
        m_editDataModel->insertRow(0);
    }

    for (int i = 0; i < AttCnt; ++i) {
        if (QString::fromLocal8Bit(UserAt[i].label) == g_materialNo) {
            m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 0), QString::fromLocal8Bit(UserAt[i].strValue).toUtf8());
        }
        else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphName) {
            m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 1), QString::fromLocal8Bit(UserAt[i].strValue).toUtf8());
        }
        else if (QString::fromLocal8Bit(UserAt[i].label) == g_isOutputGraph) {
            m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 2), QString::fromLocal8Bit(UserAt[i].strValue).toUtf8());
        }
        else if (QString::fromLocal8Bit(UserAt[i].label) == g_detector) {
            m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 3), QString::fromLocal8Bit(UserAt[i].strValue).toUtf8());
        }
        else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphTypeId) {
            targetGraphTypeId = QString::fromLocal8Bit(UserAt[i].strValue);
        }
    }

    int count = 0;
    svxEntPath* pEntPaths = NULL;
    if (cvxCompInqPaths(NULL, 2, 0, &count, &pEntPaths) != ZW_API_NO_ERROR) {
        this->setEnabled(true);
        return;
    }
    std::vector<svxEntPath> entPaths(pEntPaths, pEntPaths + count);
    cvxMemFree((void**)&pEntPaths);
    m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 4), count + 1);
    for (int k = 0; k < m_editDataModel->columnCount(); ++k) {
        QStandardItem* item = m_editDataModel->item(m_editDataModel->rowCount() - 1, k);
        if (item != NULL) {
            item->setTextAlignment(Qt::AlignCenter);
        }
    }

    QMap<QString, int> m;
    QMap<QString, QStringList> nameToPro;
    for (auto entPath : entPaths)
    {
        vxLongName name;
        cvxEntNameByPath(&entPath, name);
        m[QString::fromLocal8Bit(name)]++;

        int userAttributeListCount = 0;
        svxAttribute* pUserAttributeList = NULL;
        vxLongName _n;
        QString _s = QString::fromLocal8Bit(name) + ".Z3PRT";
        std::strcpy(_n, _s.toLocal8Bit());
        if (cvxPartUserAtGet(_n, name, &userAttributeListCount, &pUserAttributeList) != ZW_API_NO_ERROR)continue;

        QStringList list;
        for (int i = 0; i < userAttributeListCount; i++) {

            if (QString::fromLocal8Bit(pUserAttributeList[i].label) == g_materialNo) {
                if (list.count() == 0) {
                    list << pUserAttributeList[i].data;
                }
                else {
                    list.insert(1, pUserAttributeList[i].data);
                }

            }
            else if (QString::fromLocal8Bit(pUserAttributeList[i].label) == g_isOutputGraph) {
                if (list.count() == 0) {
                    list << " " << QString::fromLocal8Bit(pUserAttributeList[i].data);
                }
                else {
                    list << QString::fromLocal8Bit(pUserAttributeList[i].data);
                }

            }
        }

        nameToPro[QString::fromLocal8Bit(name)] = list;
        cvxMemFree((void**)&pUserAttributeList);

    }

    for (auto i = m.begin(); i != m.end(); ++i) {
        if (i.value() >= 0) {
            m_editDataModel->insertRow(m_editDataModel->rowCount());
            m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 1), i.key().toUtf8());
            m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 4), i.value());

            if (nameToPro[i.key()].count() == 2)
            {
                m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 0), nameToPro[i.key()].at(0).toUtf8());
                m_editDataModel->setData(m_editDataModel->index(m_editDataModel->rowCount() - 1, 2), nameToPro[i.key()].at(1).toUtf8());
            }

            for (int k = 0; k < m_editDataModel->columnCount(); ++k) {
                QStandardItem* item = m_editDataModel->item(m_editDataModel->rowCount() - 1, k);
                if (item != NULL) {
                    item->setTextAlignment(Qt::AlignCenter);
                }
            }
        }
    }

    this->setEnabled(true);
}

void edit::on_btnSaveEdit_clicked()
{
    this->setEnabled(false);
    cvxFileSave3(0, 1, 1);
    this->setEnabled(true);
}

void edit::on_btnGenDwg_clicked()
{
    this->setEnabled(false);

    m_2Dcount = 0;
    m_2Dtotal = 0;

    QFile file(g_currentWorkDir + "/" + g_newGenJsonFileName);
    QFile oldJsonFile(g_currentWorkDir + "/" + g_chemeHitJsonFileName);
    if (!file.exists()) {
        QMessageBox::warning(this, u8"提示", u8"未检测到新生成方案命中JSON文件.");
        cvxMsgDisp2(QString::fromUtf8(u8"未检测到新生成方案命中JSON文件.").toLocal8Bit(), 4);
        this->setEnabled(true);
        return;
    }
    if (!oldJsonFile.exists()) {
        QMessageBox::warning(this, u8"提示", u8"未检测到旧方案命中JSON文件.");
        cvxMsgDisp2(QString::fromUtf8(u8"未检测到旧方案命中JSON文件.").toLocal8Bit(), 4);
        this->setEnabled(true);
        return;
    }

    file.open(QIODevice::ReadOnly);
    oldJsonFile.open(QIODevice::ReadOnly);
    QJsonObject rootObj = QJsonDocument::fromJson(file.readAll()).object();
    QJsonObject rootObjOld = QJsonDocument::fromJson(oldJsonFile.readAll()).object();
    file.close();
    oldJsonFile.close();

    QJsonArray temp = rootObj.value("schemeData").toArray();
    QJsonArray tempOld = rootObjOld.value("schemeData").toArray();
    if (tempOld.count() < 1) {
        QMessageBox::warning(this, u8"警告", u8"没有需要生成二维图的零件.");
        this->setEnabled(true);
        return;
    }

    QString fileRootPath = g_currentWorkDir + "/" + g_projectDirName + "/" + rootObj.value("projectName").toString() + "/" + temp.at(0).toObject().value("cabinetDTO").toObject().value("cabinetName").toString();

    QJsonArray standardCopperBarSchemeListArr = temp.at(0).toObject().value("standardCopperBarSchemeList").toArray();
    QJsonArray standardCopperBarSchemeListArrOld = tempOld.at(0).toObject().value("standardCopperBarSchemeList").toArray();

    cvxMsgDisp(QString::fromUtf8(u8"开始生成二维图...").toLocal8Bit());


    for (int i = 0; i < standardCopperBarSchemeListArr.count(); ++i) {
        QJsonObject child = standardCopperBarSchemeListArr.at(i).toObject();
        if (child.value("variantStatus").toBool() == false)continue;
        m_2Dtotal += 3;
    }


    for (int i = 0; i < standardCopperBarSchemeListArr.count(); ++i) {
        QJsonObject child = standardCopperBarSchemeListArr.at(i).toObject();
        if (child.value("variantStatus").toBool() == false)continue;

        QStringList list;
        bool flag = false;
        for (int i = 0; i < standardCopperBarSchemeListArrOld.count(); ++i) {
            QJsonObject childOld = standardCopperBarSchemeListArrOld.at(i).toObject();
            if (childOld.value("fileUniqueIdentify").toString() == child.value("id").toString()) {
                flag = true;
                list = childOld.value("graphFile").toString().split('/', QString::SkipEmptyParts);
                break;
            }
        }

        if (flag == false)continue;
        if (list.count() < 2)continue;

        QString filePath = fileRootPath + "/" + list.back();
        if (!QFile::exists(filePath)) {
            cvxMsgDisp2(QString::fromUtf8(u8"文件不存在:" + filePath.toUtf8()).toLocal8Bit(),4);
            continue;
        }

        cvxFileSaveAll();
        cvxSessionClear();

        QString tempStr = filePath;
        tempStr.remove(tempStr.lastIndexOf('.'), tempStr.size() - tempStr.lastIndexOf('.'));
        QFile fileDrw(tempStr + ".Z3DRW");
        if (!fileDrw.exists()) {
            cvxMsgDisp2(QString::fromUtf8(u8"DRW文件不存在,路径" + fileDrw.fileName().toUtf8()).toLocal8Bit(),4);
            QMessageBox::warning(this, u8"警告", u8"DRW文件不存在,路径" + fileDrw.fileName().toUtf8());
            this->setEnabled(true);
            return;
        }

        cvxFileOpen(filePath.toLocal8Bit());

        svxDWGData data;
        if (cvxFileExportInit(VX_EXPORT_TYPE_DWG, 0, &data) != ZW_API_NO_ERROR) {
            QMessageBox::warning(this, u8"警告", u8"转DWG失败.");
            cvxMsgDisp2(QString::fromUtf8(u8"转DWG失败.").toLocal8Bit(), 4);
            continue;
        }


        data.Version = VX_DWG_VERSION_2010;
        data.FileType = 0;// 0-DWG, 1- DXF(ASCLL), 2-DXF(Binary)
        data.ExportType = 0;
        data.ExportLayer = 0;
        data.ExcludeGeom = 0;
        data.exportSheetOnly = 1;

        char name[512], fullPath[512];
        cvxFileInqActive(name, 512);
        cvxPathFindByFileName(name, fullPath, 512);
        QString fullPathStr = QString::fromLocal8Bit(fullPath);

        fullPathStr.remove(fullPathStr.lastIndexOf('.'), fullPathStr.size() - fullPathStr.lastIndexOf('.'));

        if (!fullPathStr.isEmpty()) {

            cvxFileExport(VX_EXPORT_TYPE_DWG, QString::fromUtf8(fullPathStr.toUtf8() + u8".dwg").toLocal8Bit(), &data);

            data.FileType = 1;//dxf
            cvxFileExport(VX_EXPORT_TYPE_DWG, QString::fromUtf8(fullPathStr.toUtf8() + u8".dxf").toLocal8Bit(), &data);

            QString fileUrl = child.value("graphFile").toString();
            fileUrl.remove(fileUrl.lastIndexOf('.'), fileUrl.size() - fileUrl.lastIndexOf('.'));
            fileUrl += ".dwg";

            QUrl url(fileUrl);

            url.setUserName(g_ftpUserName);
            url.setPassword(g_ftpUserPswd);

            QFile tempFile(fullPathStr.toUtf8() + u8".dwg");

            if (!tempFile.open(QIODevice::ReadOnly)) {
                cvxMsgDisp2(QString::fromUtf8(u8"二维图打开失败,取消上传该文件:" + tempFile.fileName().toUtf8()).toLocal8Bit(),4);
              
                continue;
            }

            QNetworkRequest request;
            request.setUrl(url);
            request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

            QNetworkReply* _reply = g_networkManager.put(request, tempFile.readAll());
            _reply->setParent(this);
            tempFile.close();
            connect(_reply, SIGNAL(finished()), this, SLOT(onPutFtpFileFinished()));

            //dxf
            fileUrl.remove(fileUrl.lastIndexOf('.'), fileUrl.size() - fileUrl.lastIndexOf('.'));
            fileUrl += ".dxf";

            url.setUrl(fileUrl);
            tempFile.setFileName(fullPathStr.toUtf8() + u8".dxf");
            if (!tempFile.open(QIODevice::ReadOnly)) {
                cvxMsgDisp2(QString::fromUtf8(u8"二维图打开失败,取消上传该文件:" + tempFile.fileName().toUtf8()).toLocal8Bit(),4);
                continue;
            }
            request.setUrl(url);
            _reply = g_networkManager.put(request, tempFile.readAll());
            _reply->setParent(this);
            tempFile.close();
            connect(_reply, SIGNAL(finished()), this, SLOT(onPutFtpFileFinished()));

            //DRW
            fileUrl.remove(fileUrl.lastIndexOf('.'), fileUrl.size() - fileUrl.lastIndexOf('.'));
            fileUrl += ".Z3DRW";

            url.setUrl(fileUrl);
            tempFile.setFileName(fullPathStr.toUtf8() + u8".Z3DRW");
            if (!tempFile.open(QIODevice::ReadOnly)) {
                cvxMsgDisp2(QString::fromUtf8(u8"二维图打开失败,取消上传该文件:" + tempFile.fileName().toUtf8()).toLocal8Bit(),4);
                continue;
            }
            request.setUrl(url);
            _reply = g_networkManager.put(request, tempFile.readAll());
            _reply->setParent(this);
            tempFile.close();
            connect(_reply, SIGNAL(finished()), this, SLOT(onPutFtpFileFinished()));
        }
        else {
            QMessageBox::warning(this, u8"警告", u8"转DWG失败.");
            cvxMsgDisp2(QString::fromUtf8(u8"警告").toLocal8Bit(), 4);
            continue;
        }
        cvxFileSave3(1, 1, 1);
    }
}

void edit::onGetModelTreeFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply == nullptr)return;

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    int code = -1;
    code = doc.object().value("code").toInt();

    if (reply->error() || code != 200) {

        QMessageBox::warning(this, u8"警告", u8"获取目录树信息时发生错误,请重新登陆.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode));
    }
    else if (statusCode == 200) {
        m_editTreeModel->removeRows(0, m_editTreeModel->rowCount());
        this->rootItem = new StandardGitTreeItem();
        QJsonObject dataObj = doc.object().value("data").toArray().at(0).toObject();
        makeStandardGitTree(rootItem, dataObj);
        m_editTreeModel->appendRow(rootItem);

        ui->treeViewEdit->setExpanded(rootItem->index(), true);
        ui->treeViewEdit->setRootIndex(rootItem->index());

        int AttCnt = 0;
        svxAttribute* UserAt = NULL;
        cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt);
        QString targetGraphTypeId;

        for (int i = 0; i < AttCnt; ++i) {
            if (QString::fromLocal8Bit(UserAt[i].label) == g_graphTypeId) {
                targetGraphTypeId = QString::fromLocal8Bit(UserAt[i].strValue);
            }
        }

        if (!targetGraphTypeId.isEmpty()) {
            StandardGitTreeItem* item = findItemInEditTreeView(rootItem, targetGraphTypeId);
            if (item != nullptr) {
                ui->treeViewEdit->expandAll();
                ui->treeViewEdit->setCurrentIndex(item->index());
            }
        }
    }

    reply->deleteLater();
    reply = nullptr;
}

void edit::onGetModelTreeFinishedCap()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply == nullptr)return;

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    int code = -1;
    code = doc.object().value("code").toInt();

    if (reply->error() || code != 200) {

        QMessageBox::warning(this, u8"警告", u8"获取目录树信息时发生错误,请重新登陆.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode));
    }
    else if (statusCode == 200) {
        m_editTreeModel->removeRows(0, m_editTreeModel->rowCount());
        this->rootItem = new StandardGitTreeItem();
        QJsonArray arr = doc.object().value("data").toArray();
        makeCapGitTree(rootItem, arr);
        m_editTreeModel->appendRow(rootItem);

        ui->treeViewEdit->setExpanded(rootItem->index(), true);
        ui->treeViewEdit->setRootIndex(rootItem->index());

        int AttCnt = 0;
        svxAttribute* UserAt = NULL;
        cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt);
        QString targetGraphTypeId;

        for (int i = 0; i < AttCnt; ++i) {
            if (QString::fromLocal8Bit(UserAt[i].label) == g_graphTypeId) {
                targetGraphTypeId = QString::fromLocal8Bit(UserAt[i].strValue);
            }
        }

        if (!targetGraphTypeId.isEmpty()) {
            StandardGitTreeItem* item = findItemInEditTreeView(rootItem, targetGraphTypeId);
            if (item != nullptr) {
                ui->treeViewEdit->expandAll();
                ui->treeViewEdit->setCurrentIndex(item->index());
            }
        }
    }

    reply->deleteLater();
    reply = nullptr;
}

void edit::showEvent(QShowEvent *event)
{
    ui->stackedWidgetEdit->hide();
    on_btnUpdateEdit_clicked();//更新编辑表格数据
    //ui->combGitChoiceEdit->currentIndexChanged((ui->combGitChoiceEdit->currentIndex()));//更新目录树

    QDialog::showEvent(event);
}

void edit::closeEvent(QCloseEvent *event)
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

edit* edit::getInstance()
{
    if (m_instance == nullptr)m_instance = new edit;
    return m_instance;
}

edit::~edit()
{
    m_instance = nullptr;
    delete ui;
}

void edit::on_combGitChoiceEdit_currentIndexChanged(int index)
{
    if (index == 0) {//标准库
        getModelTreeRequest();//更新目录树
    }
    else if (index == 1) {//元器件库
        getModelTreeRequestCap();
    }
}

void edit::onPostCheckInFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply == nullptr)return;

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    int code = -1;
    code = doc.object().value("code").toInt();

    if (reply->error() || code != 200) {
        QString errString = doc.object().value("msg").toString();
        QString note = u8"检入文件时发生错误.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode) + u8" 错误信息:" + errString;
        QMessageBox::warning(this, u8"警告", note);
        cvxMsgDisp2(note.toLocal8Bit(), 4);
        this->setEnabled(true);
        reply->deleteLater();
        reply = nullptr;
        return;
    }

    if (statusCode == 200) {

        QMessageBox::information(this, u8"提示", u8"检入操作已完成!");

        this->setEnabled(true);

        reply->deleteLater();
        reply = nullptr;
    }
}

void edit::onPostCheckOutFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply == nullptr) {
        this->setEnabled(true);
        return;
    }

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
       
        return;
    }

    if (statusCode == 200) {
		if (m_editDataModel->rowCount() > 0) {
			m_editDataModel->setData(m_editDataModel->index(0, 3), doc.object().value("data").toObject().value("detector").toString());

			int AttCnt = 0;
			svxAttribute* UserAt = NULL;
			cvxPartUserAtGet(nullptr, nullptr, &AttCnt, &UserAt);
			QString detector;

			for (int i = 0; i < AttCnt; ++i) {

				if (QString::fromLocal8Bit(UserAt[i].label) == g_detector) {

					strcpy_s(UserAt[i].data, doc.object().value("data").toObject().value("detector").toString().toLocal8Bit());
					cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
					cvxFileSave3(0, 1, 0);
				}
			}
		}
		
		QMessageBox::information(this, u8"提示", u8"文件已检出.");
        this->setEnabled(true);
        
        reply->deleteLater();
        reply = nullptr;
    }
}

void edit::onPutFtpFileFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    m_2Dcount++;
    if (reply == nullptr) return;

	if (m_2Dcount >= m_2Dtotal) {
		cvxMsgDisp(QString::fromUtf8(u8"上传二维工程图完成,一共:" + QString::number(m_2Dtotal).toUtf8() + u8"个.").toLocal8Bit());

		
		QFile file(g_currentWorkDir + "/" + g_newGenJsonFileName);
		file.open(QIODevice::ReadOnly);
		QJsonObject rootObj = QJsonDocument::fromJson(file.readAll()).object();
		file.close();

		QJsonArray temp = rootObj.value("schemeData").toArray();

		//QString fileRootPath = ui->editCurrentWorkDir->text() + "/" + g_projectDirName + "/" + rootObj.value("projectName").toString() + "/" + temp.at(0).toObject().value("cabinetDTO").toObject().value("cabinetName").toString();

		QJsonArray standardCopperBarSchemeListArr = temp.at(0).toObject().value("standardCopperBarSchemeList").toArray();

		QJsonObject targetObj;
		targetObj.insert("productMappingId", rootObj.value("productMappingId"));
		targetObj.insert("projectId", rootObj.value("projectId"));
		targetObj.insert("groupId", rootObj.value("groupId"));
		targetObj.insert("productId", rootObj.value("productId"));

		QJsonObject l2obj;
		l2obj.insert("electricVal", temp.at(0).toObject().value("electricVal"));

		QJsonArray sjCbGraphsArr;

		for (int i = 0; i < standardCopperBarSchemeListArr.count(); ++i) {
			QJsonObject child = standardCopperBarSchemeListArr.at(i).toObject();
			if (child.value("variantStatus").toBool() == false)continue;

			QJsonObject sjCbGraphsObj;
			sjCbGraphsObj.insert("graphCode", child.value("graphCode"));
			sjCbGraphsObj.insert("graphName", child.value("graphName"));
			sjCbGraphsObj.insert("graphJpgFile", child.value("graphJpgFile"));


			QString baseStr = child.value("graphFile").toString();
			baseStr.remove(baseStr.lastIndexOf('.'), baseStr.size() - baseStr.lastIndexOf('.'));

			sjCbGraphsObj.insert("graphFile", baseStr + ".Z3DRW" + "," + baseStr + ".dwg," + baseStr + ".dxf");
			sjCbGraphsObj.insert("propDesc", child.value("propDesc"));
			sjCbGraphsObj.insert("valDesc", child.value("valDesc"));
			sjCbGraphsObj.insert("amount", child.value("amount"));
			sjCbGraphsObj.insert("unit", child.value("unit"));
			sjCbGraphsArr.append(sjCbGraphsObj);
		}
		l2obj.insert("sjCbGraphs", sjCbGraphsArr);
		QJsonArray arr;
		arr.append(l2obj);
		targetObj.insert("copperBarList", arr);

		QNetworkRequest request;
		request.setUrl(QUrl(g_getBaseUrl() + g_engineeringDrawingUrl));
		request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
		request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
		request.setRawHeader("Authorization", g_userToken.toUtf8());

		QNetworkReply* reply2 = g_networkManager.post(request, QJsonDocument(targetObj).toJson(QJsonDocument::Compact));
        reply2->setParent(this);

		connect(reply2, SIGNAL(finished()), this, SLOT(onPostUpload2DPicFinished()));
		cvxMsgDisp(QString::fromUtf8(u8"开始上传二维工程图JSON...").toLocal8Bit());
	}   
}

void edit::onPostUpload2DPicFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    int code = doc.object().value("code").toInt();
    if (reply->error() == QNetworkReply::NoError && code == 200) {
        cvxMsgDisp2(QString::fromUtf8(u8"上传二维工程图JSON完成.").toLocal8Bit(),1);
        QMessageBox::information(this, u8"提示", u8"上传二维工程图JSON完成.");
    }
    else {
        cvxMsgDisp2(QString::fromUtf8(u8"上传二维工程图JSON出错.出错代码:" + QString::number(code).toUtf8() + u8" 出错原因:" + reply->errorString().toUtf8()).toLocal8Bit(),4);
        QMessageBox::warning(this, u8"警告", u8"上传二维工程图JSON出错.出错代码:" + QString::number(code).toUtf8() + u8" 出错原因:" + reply->errorString().toUtf8());
    }

    this->setEnabled(true);

    reply->deleteLater();
    reply = nullptr;
}

