#ifndef STANDARDGITTABLEDELEGATEIMG_H
#define STANDARDGITTABLEDELEGATEIMG_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>

class standardGitTableDelegateImg : public QStyledItemDelegate
{
    Q_OBJECT
public:
    standardGitTableDelegateImg();

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // STANDARDGITTABLEDELEGATEIMG_H
