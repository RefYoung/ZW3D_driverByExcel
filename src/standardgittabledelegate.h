#ifndef STANDARDGITTABLEDELEGATE_H
#define STANDARDGITTABLEDELEGATE_H

#include <QItemDelegate>
#include <QCheckBox>
#include <QApplication>
#include <QDebug>
#include <QStyleOptionViewItem>
#include <QPainter>
#include <QStandardItemModel>
#include <QMouseEvent>
#include <VxApi.h>

class standardGitTableDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    standardGitTableDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    static QRect CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions);
};

#endif // STANDARDGITTABLEDELEGATE_H
