#ifndef STANDARDGITTREEITEM_H
#define STANDARDGITTREEITEM_H

#include <QStandardItem>
#include <QObject>
#include <qmessagebox.h>
#include <VxApi.h>

class StandardGitTreeItem : public QObject,public QStandardItem
{
    Q_OBJECT
public:
    StandardGitTreeItem();
    ~StandardGitTreeItem();
    //公有成员部分
    QString id;
    QString plmId;
    QString code;
    QString label;
    QString typeEnum;
    QString mediumTypeEnum;
    QString attrTypeId;
    QString isLibrary;
    QString realType;
    QString codeAutoFlag;
    QString productMappingId;
    QString schemeLibraryClass;
};

#endif // STANDARDGITTREEITEM_H
