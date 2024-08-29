#include "schHit.h"

schHit* schHit::m_instance = nullptr;

schHit::schHit(QObject *parent)
	: QObject(parent)
{}

void schHit::schemeHandle()
{
    cvxMsgDisp(QString::fromUtf8(u8"开始变形...").toLocal8Bit());
    for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {

        if (i.value().variantStatus == false)continue;
        QFile* file = i.value().file;
        if (file != nullptr) {

            ZwDatabase db;
            ZwDbOpenFile(file->fileName().toLocal8Bit(), ZeAccessMode::Z_MODE_WRITE, &db);

            if (db.pBin != NULL) {
                QFileInfo info(file->fileName());

                QString baseName = info.fileName();
                baseName.remove(baseName.lastIndexOf("."), baseName.size() - baseName.lastIndexOf(".") + 1);

                ZwObjHandle* pPartObj = ZwDbFindRootObject(&db, baseName.toLocal8Bit());

                if (pPartObj) {

                    QJsonDocument doc;
                    doc = doc.fromJson(i.value().valDes.toUtf8());
                    QJsonObject obj = doc.object();

                    for (auto j = obj.begin(); j != obj.end(); ++j) {


                        ZwEqn equation = { 0 };
                        strcpy_s(equation.name, j.key().toLocal8Bit());

                        equation.type = -1;
                        ZwDbObjGetEquation(pPartObj, &equation);
                        if (equation.type != -1)
                        {
                            //cvxMsgDisp(j.key().toLocal8Bit() + ":" + j.value().toString().toLocal8Bit()+QString::fromUtf8(u8" �޸�����.").toLocal8Bit());
                            strcpy_s(equation.expression, j.value().toString().toLocal8Bit());//����ʽ�ı���ʽ
                            //strcpy_s(equation.expression, "1000");
                            ZwDbObjSetEquation(pPartObj, &equation);

                        }
                    }

                    ZwDbSaveFile(&db, NULL, 0);
                    ZwDbCloseFile(&db);
                    ZwDbFree((void**)&pPartObj);

                    cvxFileOpen(file->fileName().toLocal8Bit());
                    cvxCmdSend((char*)"~AsmCall(RegenAllCmp)");
                    //cvxCmdSend((char*)"$CdAsmFtrRegenAll");

                    cvxFileSave3(1, 1, 1);


                    cvxFileOpen(file->fileName().toLocal8Bit());


                    if (i.value().graphFile.endsWith("Z3ASM", Qt::CaseInsensitive)) {

                        QSet<QString> set;
                        for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
                            set << i.value().cabinetName;
                        }

                        if (set.count() == 1) {

                            int count = 0;
                            svxEntPath* pEntPaths = NULL;
                            cvxCompInqPaths(NULL, -1, 0, &count, &pEntPaths);
                            std::vector<svxEntPath> entPaths(pEntPaths, pEntPaths + count);
                            cvxMemFree((void**)&pEntPaths);

                            for (auto entPath : entPaths)
                            {
                                vxLongName name;
                                if (cvxEntNameByPath(&entPath, name) == ZW_API_NO_ERROR && std::string(name).find("柜体") != std::string::npos) {

                                    cvxCompVisSet(&entPath, false);
                                }
                            }
                        }
                    }
                    cvxViewStd(evxViewStd::VX_VIEW_LEFT, 100.0);
                    cvxFileSave(1);
                    cvxFilePreviewExtract(file->fileName().toLocal8Bit(), info.absolutePath().toLocal8Bit() + "/" + i.value().fileUniqueIdentify.toLocal8Bit() + ".jpg");

                }
            }
        }
    }

    cvxMsgDisp(QString::fromUtf8(u8"变形完成.").toLocal8Bit());

    postUpdatePic();
}

void schHit::postUpdatePic()
{
    QNetworkRequest request;
    request.setUrl(QUrl(g_getBaseUrl() + g_batchUploadThumbnail));
    //request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

    QMap<QString, QString> head;
    head["Authorization"] = g_userToken;
    for (auto i = head.begin(); i != head.end(); ++i) {
        request.setRawHeader(i.key().toUtf8(), i.value().toUtf8());
    }

    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType, this);

    for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
        if (i.value().variantStatus == false)continue;
        QString picPath = i.value().file->fileName();
        picPath.remove(picPath.lastIndexOf('/') + 1, 256);
        picPath += i.value().fileUniqueIdentify;
        picPath += ".jpg";
        //picPath.insert(picPath.lastIndexOf('/')+1, "_");
        QHttpPart imagePart;
        imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpg"));
        QStringList _list = picPath.split('/', QString::SkipEmptyParts);
        imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"files\";filename=\"%1\";").arg("_" + _list.at(_list.count() - 1))));
        QFile* file = new QFile(picPath);
        file->open(QIODevice::ReadOnly);
        imagePart.setBodyDevice(file);
        file->setParent(multiPart);
        multiPart->append(imagePart);
    }


    QNetworkReply* reply = g_networkManager.post(request, multiPart);
    reply->setParent(this);

    multiPart->setParent(reply);

    connect(reply, SIGNAL(finished()), this, SLOT(onPostUpdatePicFinished()));
    cvxMsgDisp(QString::fromUtf8(u8"开始上传缩略图...").toLocal8Bit());
}

void schHit::uploadNewJsonFile()
{
    QJsonArray topArr = m_jsonDoc.object().value("schemeData").toArray();
    QJsonArray newArr;
    for (int i = 0; i < topArr.count(); ++i) {
        QJsonObject objCabinet = topArr.at(i).toObject();
        if (objCabinet.value("variantStatus").toBool() == true) {
            QJsonArray assemblySchemeListArr = objCabinet.value("assemblySchemeList").toArray();
            QJsonArray newAssemblySchemeListArr;
            for (int j = 0; j < assemblySchemeListArr.size(); ++j) {
                QJsonObject objChild = assemblySchemeListArr.at(j).toObject();
                if (objChild.value("variantStatus") == true) {
                    for (auto k = m_schHitMap.begin(); k != m_schHitMap.end(); ++k) {
                        if (k.value().fileUniqueIdentify == objChild.value("fileUniqueIdentify").toString()) {
                            objChild.insert("graphFile", k.value().fileUrl);
                            objChild.insert("graphJpgFile", k.value().picPath);
                            break;
                        }
                    }
                }
                newAssemblySchemeListArr.append(objChild);
            }
            objCabinet.insert("assemblySchemeList", newAssemblySchemeListArr);

            QJsonArray partsSchemeListArr = objCabinet.value("partsSchemeList").toArray();
            QJsonArray newPartsSchemeListArr;
            for (int j = 0; j < partsSchemeListArr.size(); ++j) {
                QJsonObject objChild = partsSchemeListArr.at(j).toObject();
                if (objChild.value("variantStatus") == true) {
                    for (auto k = m_schHitMap.begin(); k != m_schHitMap.end(); ++k) {
                        if (k.value().fileUniqueIdentify == objChild.value("fileUniqueIdentify").toString()) {
                            objChild.insert("graphFile", k.value().fileUrl);
                            objChild.insert("graphJpgFile", k.value().picPath);
                            break;
                        }
                    }
                }
                newPartsSchemeListArr.append(objChild);
            }
            objCabinet.insert("partsSchemeList", newPartsSchemeListArr);

            QJsonArray standardCopperBarSchemeListArr = objCabinet.value("standardCopperBarSchemeList").toArray();
            QJsonArray newStandardCopperBarSchemeListArr;
            for (int j = 0; j < standardCopperBarSchemeListArr.size(); ++j) {
                QJsonObject objChild = standardCopperBarSchemeListArr.at(j).toObject();
                if (objChild.value("variantStatus") == true) {
                    for (auto k = m_schHitMap.begin(); k != m_schHitMap.end(); ++k) {
                        if (k.value().fileUniqueIdentify == objChild.value("fileUniqueIdentify").toString()) {
                            objChild.insert("graphFile", k.value().fileUrl);
                            objChild.insert("graphJpgFile", k.value().picPath);
                            break;
                        }
                    }
                }
                newStandardCopperBarSchemeListArr.append(objChild);
            }
            objCabinet.insert("standardCopperBarSchemeList", newStandardCopperBarSchemeListArr);

            QJsonArray componentsAndPartsSchemeListArr = objCabinet.value("componentsAndPartsSchemeList").toArray();
            QJsonArray newComponentsAndPartsSchemeListArr;
            for (int j = 0; j < componentsAndPartsSchemeListArr.size(); ++j) {
                QJsonObject objChild = componentsAndPartsSchemeListArr.at(j).toObject();
                if (objChild.value("variantStatus") == true) {
                    for (auto k = m_schHitMap.begin(); k != m_schHitMap.end(); ++k) {
                        if (k.value().fileUniqueIdentify == objChild.value("fileUniqueIdentify").toString()) {
                            objChild.insert("graphFile", k.value().fileUrl);
                            objChild.insert("graphJpgFile", k.value().picPath);
                            break;
                        }
                    }
                }
                newComponentsAndPartsSchemeListArr.append(objChild);
            }
            objCabinet.insert("componentsAndPartsSchemeList", newComponentsAndPartsSchemeListArr);
        }
        newArr.append(objCabinet);
    }

    QJsonObject targetJsonObj = m_jsonDoc.object();
    targetJsonObj.insert("schemeData", newArr);

    QMap<QString, QString> head;
    head["Authorization"] = g_userToken;
    QNetworkRequest request;
    request.setUrl(QUrl(g_getBaseUrl() + g_generateNewScheme));
    request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json;charset=UTF-8"));
    for (auto i = head.begin(); i != head.end(); ++i) {
        request.setRawHeader(i.key().toUtf8(), i.value().toUtf8());
    }

    QNetworkReply* reply = g_networkManager.post(request, QJsonDocument(targetJsonObj).toJson());
    reply->setParent(this);

    connect(reply, SIGNAL(finished()), this, SLOT(onPostUploadNewJsonFileFinished()));
}

void schHit::onPostUpdatePicFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if(reply==nullptr)return;

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    int code = -1;
    code = doc.object().value("code").toInt();

    if (reply->error() || code != 200) {
        QString errString = doc.object().value("msg").toString();
        QString note = u8"上传缩略图时发生错误.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode) + u8" 错误信息:" + errString;
        QMessageBox::warning(0, u8"警告", note);
        reply->deleteLater();
        reply = nullptr;

        return;
    }

    if (statusCode == 200) {
        QJsonArray arr = doc.object().value("data").toArray();

        QMap<QString, QString> identifyToPath;//������ʶ����·��֮����ӳ��ͼ
        for (int i = 0; i < arr.count(); ++i) {
            QJsonObject obj = arr.at(i).toObject();
            identifyToPath[obj.value("fileUniqueIdentify").toString()] = g_getBaseUrl() + obj.value("path").toString();
        }
        for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
            if (i.value().variantStatus == false)continue;
            i.value().picPath = identifyToPath[i.value().fileUniqueIdentify];
        }

        cvxMsgDisp(QString::fromUtf8(u8"缩略图上传完成.").toLocal8Bit());
        reply->deleteLater();
        reply = nullptr;


        cvxMsgDisp(QString::fromUtf8(u8"开始上传新方案命中文件...").toLocal8Bit());
        uploadNewJsonFile();
    }
}

void schHit::onPostUploadNewJsonFileFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    if (reply == nullptr)return;

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    int code = -1;
    code = doc.object().value("code").toInt();

    if (reply->error() || code != 200) {
        QString errString = doc.object().value("msg").toString();
        QMessageBox::warning(0, u8"警告", u8"上传新方案命中文件时发生错误.\n错误代码:" + QString::number(code) + u8" http状态码:" + QString::number(statusCode) + u8" 错误信息:" + errString);
        cvxMsgDisp2(QString::fromUtf8(u8"上传新方案命中文件时发生错误.\n错误代码:" + QString::number(code).toUtf8() + u8" http状态码:" + QString::number(statusCode).toUtf8() + u8" 错误信息:" + errString.toUtf8()).toLocal8Bit(),4);

        reply->deleteLater();
        reply = nullptr;

        return;
    }

    if (statusCode == 200) {
        QJsonObject newObj = doc.object().value("data").toObject();

        QFile file(g_currentWorkDir + "/" + g_newGenJsonFileName);
        file.open(QIODevice::WriteOnly);
        file.write(QJsonDocument(newObj).toJson());
        file.close();

        cvxMsgDisp(QString::fromUtf8(u8"新方案命中文件上传完成.").toLocal8Bit());

        reply->deleteLater();
        reply = nullptr;

        QJsonArray tempArr = newObj.value("schemeData").toArray();
        if (tempArr.count() < 1) {
            cvxMsgDisp2(QString::fromUtf8(u8"新方案命中文件出现错误.").toLocal8Bit(),4);
            QMessageBox::warning(0, u8"警告", u8"新方案命中文件出现错误.");
            return;
        }
        QJsonObject newSchemeData = tempArr.at(0).toObject();
        QMap<QString, QString> tempMap;

        QJsonArray newassemblySchemeList = newSchemeData.value("assemblySchemeList").toArray();
        for (int i = 0; i < newassemblySchemeList.count(); ++i) {
            QJsonObject child = newassemblySchemeList.at(i).toObject();
            if (child.value("variantStatus").toBool() == false)continue;
            tempMap[child.value("id").toString()] = child.value("graphFile").toString();
        }

        QJsonArray newpartsSchemeList = newSchemeData.value("partsSchemeList").toArray();
        for (int i = 0; i < newpartsSchemeList.count(); ++i) {
            QJsonObject child = newpartsSchemeList.at(i).toObject();
            if (child.value("variantStatus").toBool() == false)continue;
            tempMap[child.value("id").toString()] = child.value("graphFile").toString();
        }

        QJsonArray newstandardCopperBarSchemeList = newSchemeData.value("standardCopperBarSchemeList").toArray();
        for (int i = 0; i < newstandardCopperBarSchemeList.count(); ++i) {
            QJsonObject child = newstandardCopperBarSchemeList.at(i).toObject();
            if (child.value("variantStatus").toBool() == false)continue;
            tempMap[child.value("id").toString()] = child.value("graphFile").toString();
        }

        QJsonArray newcomponentsAndPartsSchemeList = newSchemeData.value("componentsAndPartsSchemeList").toArray();
        for (int i = 0; i < newcomponentsAndPartsSchemeList.count(); ++i) {
            QJsonObject child = newcomponentsAndPartsSchemeList.at(i).toObject();
            if (child.value("variantStatus").toBool() == false)continue;
            tempMap[child.value("id").toString()] = child.value("graphFile").toString();
        }


        for (auto i = tempMap.begin(); i != tempMap.end(); ++i) {
            if (i.value().isEmpty())continue;
            for (auto j = m_schHitMap.begin(); j != m_schHitMap.end(); ++j) {
                if (i.key() == j.value().fileUniqueIdentify) {
                    j.value().fileUrl = i.value();
                    continue;
                }
            }
        }


        m_schHitUpFtpFileTotal = 0;
        m_schHitUpFtoCount = 0;
        for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
            if (i.value().variantStatus == false)continue;
            m_schHitUpFtpFileTotal++;
        }

        //更改装配的变形后的子零件名称
        for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
            if (i.value().fileName.endsWith(".Z3ASM", Qt::CaseInsensitive)) {
                if (0 == cvxFileOpen(i.value().file->fileName().toLocal8Bit())) {
                    //获取当前组件下所有级别的子组件
                    int count = 0;
                    svxEntPath* pEntPaths = NULL;
                    cvxCompInqPaths(NULL, -1, false, &count, &pEntPaths);
                    std::vector<svxEntPath> entPaths(pEntPaths, pEntPaths + count);
                    cvxMemFree((void**)&pEntPaths);

                    for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
                        if (i.value().variantStatus == false)continue;
                        if (i.value().fileName.endsWith(".Z3ASM", Qt::CaseInsensitive))continue;
                        QStringList _list = i.value().fileUrl.split('/', QString::SkipEmptyParts);
                        if (_list.count() < 2)continue;
                        QString newFileName = _list.back();
                        newFileName.remove(newFileName.lastIndexOf('.'), newFileName.size() - newFileName.lastIndexOf('.'));
                        QString oldFileName = i.value().fileName;
                        oldFileName.remove(oldFileName.lastIndexOf('.'), oldFileName.size() - oldFileName.lastIndexOf('.'));

                        const int count = 1;

                        vxLongPath fileNames[count] = {};//要更改的组件的文件名
                        std::strcpy(fileNames[0], i.value().fileName.toLocal8Bit().toStdString().c_str());
                        vxRootName rootNames[count] = {};//要更改的组件的根对象名，一般为文件名去掉后缀
                        std::strcpy(rootNames[0], oldFileName.toLocal8Bit().toStdString().c_str());
                        vxLongPath newFileNames[count] = { };//新组件名（文件名）
                        std::strcpy(newFileNames[0], _list.back().toLocal8Bit().toStdString().c_str());
                        vxRootName newRootNames[count] = {};//新根对象名，一般为文件名去掉后缀
                        std::strcpy(newRootNames[0], newFileName.toLocal8Bit().toStdString().c_str());
                        int res = cvxRootRenameMultiByLongPath(count, fileNames, rootNames, newFileNames, newRootNames, false);
                        
                    }

                    cvxFileClose2(NULL, 1);
                }
            }
        }

        cvxMsgDisp(QString::fromUtf8(u8"开始上传新零件到服务器,一共" + QString::number(m_schHitUpFtpFileTotal).toUtf8() + u8"个.").toLocal8Bit());
        for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
            if (i.value().variantStatus == false)continue;
            QUrl url(i.value().fileUrl);

            url.setUserName(g_ftpUserName);
            url.setPassword(g_ftpUserPswd);

            if (!i.value().file->open(QIODevice::ReadOnly)) {
                cvxMsgDisp2(QString::fromUtf8(u8"文件打开失败,取消上传该文件:" + i.value().file->fileName().toUtf8()).toLocal8Bit(),4);
                continue;
            }

            QNetworkRequest request;
            request.setUrl(url);
            request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

            QNetworkReply* _reply = g_networkManager.put(request, i.value().file->readAll());
            _reply->setParent(this);

            i.value().file->close();
            connect(_reply, SIGNAL(finished()), this, SLOT(onPutFtpFileFinished()));
        }
    }
}

void schHit::onPutFtpFileFinished()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    m_schHitUpFtoCount++;
    cvxMsgDisp(QString(u8"文件已上传" + QString::number(m_schHitUpFtoCount).toUtf8() + u8"个,还差" + QString::number(m_schHitUpFtpFileTotal - m_schHitUpFtoCount).toUtf8() + u8"个").toLocal8Bit());

    if (reply != NULL) {
        int error = reply->error();
        if (error == QNetworkReply::NoError) {

        }
        else {
            cvxMsgDisp2(QString::fromUtf8(u8"上传出错,出错信息:" + reply->errorString().toUtf8()).toLocal8Bit(),4);
        }
    }

    if (m_schHitUpFtpFileTotal <= m_schHitUpFtoCount) {
        cvxMsgDisp(QString::fromUtf8(u8"零件已全部上传.").toLocal8Bit());
        cvxMsgDisp2(QString::fromUtf8(u8"方案命中操作完成.").toLocal8Bit(),1);



        for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
            if (i.value().fileName.endsWith(".Z3ASM", Qt::CaseInsensitive)) {
                cvxFileOpen(i.value().file->fileName().toLocal8Bit());
            }
        }

        QMessageBox* msg = new QMessageBox();
        msg->setWindowFlag(Qt::WindowStaysOnTopHint);
        msg->setWindowTitle(u8"提示");
        msg->setText(u8"方案命中操作已完成.");
        msg->setAttribute(Qt::WA_DeleteOnClose);
        msg->addButton(QMessageBox::Ok);
        //msg->move(QApplication::desktop()->width() / 2 - msg->size().width() / 2, QApplication::desktop()->height() / 2 - msg->size().height() / 2);
        msg->show();
    }
}

void schHit::onGetFtpFileFinished()
{
    if (m_schHitFailFlag)return;

    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());

    m_schHitFileCount++;
    bool flag = false;

    if (m_schHitFileCount >= m_schHitFileTotal) {
        flag = true;
    }

    if (reply != NULL) {
        if (reply->error() == QNetworkReply::NoError) {
            schHitItem* item = &m_schHitMap[reply];
            if (item != nullptr) {

                QString filePath = g_currentWorkDir + "/" + g_projectDirName + "/" + item->projectName + "/" + item->cabinetName + "/";
                QDir _dir;
                if (!_dir.exists(filePath)) {
                    _dir.mkpath(filePath);
                }

                QFile* file = new QFile(filePath + item->fileName, this);

                if (file->open(QIODevice::WriteOnly)) {
                    file->write(reply->readAll());
                    reply->close();

                    file->flush();
                    file->close();
                    item->file = file;
                    cvxFileOpen(file->fileName().toLocal8Bit());
                    cvxCmdSend((char*)"~AsmCall(RegenAllCmp)");


                    cvxFileSave3(1, 1, 1);
                }

            }
        }
        else {
            m_schHitFailFlag = true;
            cvxMsgDisp2(QString::fromUtf8(u8"下载出错,出错地址:" + m_schHitMap[reply].graphFile.toUtf8() + u8" 出错原因:" + reply->errorString().toUtf8()).toLocal8Bit(),4);
            return;
        }
    }

    cvxMsgDisp(QString::fromUtf8(u8"已下载" + QString::number(m_schHitFileCount).toUtf8() + u8"个,还差" + QString::number(m_schHitFileTotal - m_schHitFileCount).toUtf8() + u8"个.").toLocal8Bit());


    if (flag == true && m_schHitFailFlag == false) {
        QJsonArray array = m_jsonDoc.object().value("schemeData").toArray();
        if (array.count() <= 0)return;

        //为每个零件写入用户信息
        for (auto i = m_omItemsMap.begin(); i != m_omItemsMap.end(); ++i) {
            openModelItem item = i.value();

            QString filePath;
            filePath = g_currentWorkDir + "\\" + g_projectDirName + "\\" + m_schHitMap.begin().value().projectName + "\\" + m_schHitMap.begin().value().cabinetName + "\\" + i.value().fileName;

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
                    bool flag7 = false;

                    for (int i = 0; i < AttCnt; ++i) {

                        if (QString::fromLocal8Bit(UserAt[i].label) == g_graphTypeId) {

                            strcpy_s(UserAt[i].data, item.graphTypeId.toLocal8Bit());
                            cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                            //cvxFileSave3(0, 1, 0);
                            flag = true;
                        }
                        else if (QString::fromLocal8Bit(UserAt[i].label) ==g_detector) {

                            strcpy_s(UserAt[i].data, item.detector.toLocal8Bit());
                            cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                            //cvxFileSave3(0, 1, 0);
                            flag2 = true;
                        }
                        else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphId) {

                            strcpy_s(UserAt[i].data, item.graphId.toLocal8Bit());
                            cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                            //cvxFileSave3(0, 1, 0);
                            flag3 = true;
                        }
                        else if (QString::fromLocal8Bit(UserAt[i].label) == g_materialNo) {

                            strcpy_s(UserAt[i].data, item.materialNo.toLocal8Bit());
                            cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                            //cvxFileSave3(0, 1, 0);
                            flag4 = true;
                           
                        }
                        else if (QString::fromLocal8Bit(UserAt[i].label) == g_graphName) {

                            strcpy_s(UserAt[i].data, item.graphName.toLocal8Bit());
                            cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                            //cvxFileSave3(0, 1, 0);
                            flag5 = true;
                        }
                        else if (QString::fromLocal8Bit(UserAt[i].label) == g_remark) {

                            strcpy_s(UserAt[i].data, item.remark.toLocal8Bit());
                            cvxPartUserAtSet(0, 0, true, AttCnt, UserAt);
                            //cvxFileSave3(0, 1, 0);
                            flag6 = true;
                        }
                        else if (QString::fromLocal8Bit(UserAt[i].label) == g_isOutputGraph) {

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


        if (array.at(0).toObject().value("variantStatus").toBool() == false) {

            cvxMsgDisp(QString::fromUtf8(u8"方案命中操作完成.").toLocal8Bit());

            for (auto i = m_schHitMap.begin(); i != m_schHitMap.end(); ++i) {
                if (i.value().fileName.endsWith(".Z3ASM", Qt::CaseInsensitive)) {

                    cvxFileOpen(i.value().file->fileName().toLocal8Bit());
                }
            }

            QMessageBox* msg = new QMessageBox();
            msg->setWindowFlag(Qt::WindowStaysOnTopHint);
            msg->setWindowTitle(u8"提示");
            msg->setText(u8"方案命中操作已完成.");
            msg->setAttribute(Qt::WA_DeleteOnClose);
            msg->addButton(QMessageBox::Ok);
            msg->move(QApplication::desktop()->width() / 2 - msg->size().width() / 2, QApplication::desktop()->height() / 2 - msg->size().height() / 2);
            msg->show();
        }
        else {
            schemeHandle();
        }

    }
}

schHit* schHit::getInstance()
{
	if(m_instance == nullptr) m_instance = new schHit();
	return m_instance;
}

void schHit::funSchit()
{
    if (g_currentWorkDir.isEmpty()) {
        QMessageBox::warning(0, u8"警告", u8"工作路径为空.");
        return;
    }

    QFile file(g_currentWorkDir + "/" + g_chemeHitJsonFileName);
    if (!file.exists(g_currentWorkDir + "/" + g_chemeHitJsonFileName)) {
        QMessageBox::warning(0, u8"警告", u8"json命中文件不存在.");
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(0, u8"警告", u8"3DJSON文件打开失败.");
        return;
    }

    QMessageBox* msg = new QMessageBox();
    msg->setWindowFlag(Qt::WindowStaysOnTopHint);
    msg->setWindowTitle(u8"询问");
    msg->setText(u8"已检测到命中文件,确定要执行方案命中吗?");
    msg->setAttribute(Qt::WA_DeleteOnClose);
    msg->addButton(QMessageBox::Yes);
    msg->addButton(QMessageBox::No);
    //msg->move(QApplication::desktop()->width() / 2 - msg->size().width() / 2, QApplication::desktop()->height() / 2 - msg->size().height() / 2);
    int result = msg->exec();
    if (result != QMessageBox::Yes)return;

    //清除缓存 
    m_schHitFailFlag = false;
    m_schHitFileTotal = 0;//需要下载的文件总数
    m_schHitFileCount = 0;//方案命中的文件数量

    cvxFileSaveAll();
    cvxSessionClear();

    QDir _dir;
    QString projectPath = g_currentWorkDir + "/" + g_projectDirName + "/";
    if (!_dir.exists(projectPath))_dir.mkdir(projectPath);

    cvxMsgDisp(QString::fromUtf8(u8"开始执行方案命中...").toLocal8Bit());

    QJsonDocument doc;
    doc = doc.fromJson(file.readAll());
    m_jsonDoc = doc;
    file.close();

    QString projectName = doc.object().value("projectName").toString();

    QJsonArray array = doc.object().value("schemeData").toArray();

    for (int i = 0; i < array.count(); ++i) {

        QJsonObject obj = array.at(i).toObject();


        QString cabinetName = obj.value("cabinetDTO").toObject().value("cabinetName").toString();

        bool GvariantStatus = false;
        if (obj.value("variantStatus").toBool() == true) {
            GvariantStatus = true;
        }
        QJsonArray arrAssemblySchemeList = obj.value("assemblySchemeList").toArray();
        for (int j = 0; j < arrAssemblySchemeList.count(); ++j) {
            QJsonObject assemblySchemeListObj = arrAssemblySchemeList.at(j).toObject();
            schHitItem s;
            s.graphFile = assemblySchemeListObj.value("graphFile").toString();
            if (s.graphFile.isEmpty())continue;

            s.valDes = assemblySchemeListObj.value("valDesc").toString();
            if (!s.valDes.isEmpty() && GvariantStatus && assemblySchemeListObj.value("variantStatus").toBool()) {
                s.variantStatus = true;
            }
            else {
                s.variantStatus = false;
            };

            s.projectName = projectName;
            s.cabinetName = cabinetName;
            s.fileUniqueIdentify = assemblySchemeListObj.value("fileUniqueIdentify").toString();
            //
            s.fileUrl = g_ftpBaseUrl + g_3DCopperBarScheme + "/"
                + QDate::currentDate().toString("yyyy") + "/" + QDate::currentDate().toString("MM") + "/" + QDate::currentDate().toString("dd") + "/"
                + s.fileUniqueIdentify + ".Z3ASM";

            QStringList _list = s.graphFile.split('/', QString::SkipEmptyParts);
            if (_list.count() >= 2) {
                s.fileName = _list.at(_list.count() - 1);
            }
            else continue;

            QNetworkRequest request;
            QUrl url(s.graphFile);
            url.setUserName(g_ftpUserName);
            url.setPassword(g_ftpUserPswd);
            request.setUrl(url);
            request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

            QNetworkReply* reply = g_networkManager.get(request);
            reply->setParent(this);
            m_schHitMap[reply] = s;

            openModelItem omItem;
            omItem.fileName = _list.at(_list.count() - 1);
            omItem.graphId = assemblySchemeListObj.value("id").toString();
            omItem.graphTypeId = assemblySchemeListObj.value("graphTypeId").toString();
            omItem.graphName = assemblySchemeListObj.value("graphName").toString();
            omItem.materialNo = assemblySchemeListObj.value("graphCode").toString();
            omItem.detector = assemblySchemeListObj.value("updateBy").toString();
            omItem.remark = assemblySchemeListObj.value("remark").toString();
            omItem.isOutPutGraph = assemblySchemeListObj.value("isOutputGraph").toString();
            m_omItemsMap[reply] = omItem;

            m_schHitFileTotal++;

            connect(reply, SIGNAL(finished()), this, SLOT(onGetFtpFileFinished()));
            //connect(reply, SIGNAL(downloadProgress(qint64 , qint64 )), this, SLOT(onDownloadProgress(qint64, qint64)));
        }

        QJsonArray partsSchemeList = obj.value("partsSchemeList").toArray();
        for (int j = 0; j < partsSchemeList.count(); ++j) {
            QJsonObject partsSchemeListObj = partsSchemeList.at(j).toObject();

            schHitItem s;
            s.graphFile = partsSchemeListObj.value("graphFile").toString();
            if (s.graphFile.isEmpty())continue;

            s.valDes = partsSchemeListObj.value("valDesc").toString();
            if (!s.valDes.isEmpty() && GvariantStatus && partsSchemeListObj.value("variantStatus").toBool()) {
                s.variantStatus = true;
            }
            else {
                s.variantStatus = false;
            };

            s.projectName = projectName;
            s.cabinetName = cabinetName;
            s.fileUniqueIdentify = partsSchemeListObj.value("fileUniqueIdentify").toString();
            s.fileUrl = g_ftpBaseUrl + g_3DCopperBarScheme+ "/"
                + QDate::currentDate().toString("yyyy") + "/" + QDate::currentDate().toString("MM") + "/" + QDate::currentDate().toString("dd") + "/"
                + s.fileUniqueIdentify + ".Z3PRT";
            QStringList _list = s.graphFile.split('/', QString::SkipEmptyParts);
            if (_list.count() >= 2) {
                s.fileName = _list.at(_list.count() - 1);
            }
            else continue;

            QNetworkRequest request;
            QUrl url(s.graphFile);
            url.setUserName(g_ftpUserName);
            url.setPassword(g_ftpUserPswd);
            request.setUrl(url);
            request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

            QNetworkReply* reply = g_networkManager.get(request);
            reply->setParent(this);
            m_schHitMap[reply] = s;

            openModelItem omItem;
            omItem.fileName = _list.at(_list.count() - 1);
            omItem.graphId = partsSchemeListObj.value("id").toString();
            omItem.graphTypeId = partsSchemeListObj.value("graphTypeId").toString();
            omItem.graphName = partsSchemeListObj.value("graphName").toString();
            omItem.materialNo = partsSchemeListObj.value("graphCode").toString();
            omItem.detector = partsSchemeListObj.value("updateBy").toString();
            omItem.remark = partsSchemeListObj.value("remark").toString();
            omItem.isOutPutGraph = partsSchemeListObj.value("isOutputGraph").toString();
            m_omItemsMap[reply] = omItem;

            m_schHitFileTotal++;

            connect(reply, SIGNAL(finished()), this, SLOT(onGetFtpFileFinished()));
            //connect(reply, SIGNAL(downloadProgress(qint64 , qint64 )), this, SLOT(onDownloadProgress(qint64, qint64)));

        }

        QJsonArray standardCopperBarSchemeList = obj.value("standardCopperBarSchemeList").toArray();
        for (int j = 0; j < standardCopperBarSchemeList.count(); ++j) {
            QJsonObject standardCopperBarSchemeListObj = standardCopperBarSchemeList.at(j).toObject();

            schHitItem s;
            s.graphFile = standardCopperBarSchemeListObj.value("graphFile").toString();
            if (s.graphFile.isEmpty())continue;

            s.valDes = standardCopperBarSchemeListObj.value("valDesc").toString();
            if (!s.valDes.isEmpty() && GvariantStatus && standardCopperBarSchemeListObj.value("variantStatus").toBool()) {
                s.variantStatus = true;
            }
            else {
                s.variantStatus = false;
            };

            s.projectName = projectName;
            s.cabinetName = cabinetName;
            s.fileUniqueIdentify = standardCopperBarSchemeListObj.value("fileUniqueIdentify").toString();

            s.fileUrl = g_ftpBaseUrl+ g_3DCopperBarScheme + "/"
                + QDate::currentDate().toString("yyyy") + "/" + QDate::currentDate().toString("MM") + "/" + QDate::currentDate().toString("dd") + "/"
                + s.fileUniqueIdentify + ".Z3PRT";
            QStringList _list = s.graphFile.split('/', QString::SkipEmptyParts);
            if (_list.count() >= 2) {
                s.fileName = _list.at(_list.count() - 1);
            }
            else continue;

            QNetworkRequest request;
            QUrl url(s.graphFile);
            url.setUserName(g_ftpUserName);
            url.setPassword(g_ftpUserPswd);
            request.setUrl(url);
            request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

            QNetworkReply* reply = g_networkManager.get(request);
            reply->setParent(this);
            m_schHitMap[reply] = s;

            openModelItem omItem;
            omItem.fileName = _list.at(_list.count() - 1);
            omItem.graphId = standardCopperBarSchemeListObj.value("id").toString();
            omItem.graphTypeId = standardCopperBarSchemeListObj.value("graphTypeId").toString();
            omItem.graphName = standardCopperBarSchemeListObj.value("graphName").toString();
            omItem.materialNo = standardCopperBarSchemeListObj.value("graphCode").toString();
            omItem.detector = standardCopperBarSchemeListObj.value("updateBy").toString();
            omItem.remark = standardCopperBarSchemeListObj.value("remark").toString();
            omItem.isOutPutGraph = standardCopperBarSchemeListObj.value("isOutputGraph").toString();
            m_omItemsMap[reply] = omItem;

            m_schHitFileTotal++;

            connect(reply, SIGNAL(finished()), this, SLOT(onGetFtpFileFinished()));
            //connect(reply, SIGNAL(downloadProgress(qint64 , qint64 )), this, SLOT(onDownloadProgress(qint64, qint64)));

        }

        QJsonArray componentsAndPartsSchemeList = obj.value("componentsAndPartsSchemeList").toArray();
        for (int j = 0; j < componentsAndPartsSchemeList.count(); ++j) {
            QJsonObject componentsAndPartsSchemeListObj = componentsAndPartsSchemeList.at(j).toObject();

            schHitItem s;
            s.graphFile = componentsAndPartsSchemeListObj.value("graphFile").toString();
            if (s.graphFile.isEmpty())continue;

            s.valDes = componentsAndPartsSchemeListObj.value("valDesc").toString();
            if (!s.valDes.isEmpty() && GvariantStatus && componentsAndPartsSchemeListObj.value("variantStatus").toBool()) {
                s.variantStatus = true;
            }
            else {
                s.variantStatus = false;
            };

            s.projectName = projectName;
            s.cabinetName = cabinetName;
            s.fileUniqueIdentify = componentsAndPartsSchemeListObj.value("fileUniqueIdentify").toString();

            s.fileUrl = g_ftpBaseUrl+ g_3DCopperBarScheme + "/"
                + QDate::currentDate().toString("yyyy") + "/" + QDate::currentDate().toString("MM") + "/" + QDate::currentDate().toString("dd") + "/"
                + s.fileUniqueIdentify + ".Z3PRT";
            QStringList _list = s.graphFile.split('/', QString::SkipEmptyParts);
            if (_list.count() >= 2) {
                s.fileName = _list.at(_list.count() - 1);
            }
            else continue;

            QNetworkRequest request;
            QUrl url(s.graphFile);
            url.setUserName(g_ftpUserName);
            url.setPassword(g_ftpUserPswd);
            request.setUrl(url);
            request.setAttribute(QNetworkRequest::RedirectPolicyAttribute, true);

            QNetworkReply* reply = g_networkManager.get(request);
            reply->setParent(this);
            m_schHitMap[reply] = s;

            openModelItem omItem;
            omItem.fileName = _list.at(_list.count() - 1);
            omItem.graphId = componentsAndPartsSchemeListObj.value("id").toString();
            omItem.graphTypeId = componentsAndPartsSchemeListObj.value("graphTypeId").toString();
            omItem.graphName = componentsAndPartsSchemeListObj.value("graphName").toString();
            omItem.materialNo = componentsAndPartsSchemeListObj.value("graphCode").toString();
            omItem.detector = componentsAndPartsSchemeListObj.value("updateBy").toString();
            omItem.remark = componentsAndPartsSchemeListObj.value("remark").toString();
            omItem.isOutPutGraph = componentsAndPartsSchemeListObj.value("isOutputGraph").toString();
            m_omItemsMap[reply] = omItem;

            m_schHitFileTotal++;

            connect(reply, SIGNAL(finished()), this, SLOT(onGetFtpFileFinished()));
            //connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(onDownloadProgress(qint64, qint64)));

        }

    }

    if (m_schHitFileTotal > 0) {
        cvxMsgDisp(QString::fromUtf8(u8" 开始下文件,一共" + QString::number(m_schHitFileTotal).toUtf8() + u8"个").toLocal8Bit());
    }
    else
    {
        cvxMsgDisp(QString::fromUtf8(u8" 方案命中文件读取完成,但没有需要下载的零件.").toLocal8Bit());
    }
}

schHit::~schHit()
{
	m_instance = nullptr;
}
