#include "standardGitTableDelegateImg.h"

standardGitTableDelegateImg::standardGitTableDelegateImg() {}

void standardGitTableDelegateImg::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.data().canConvert<QPixmap>()){
        QPixmap pixmap=index.data().value<QPixmap>();
        painter->drawPixmap(option.rect,pixmap);
    }else{
        QStyledItemDelegate::paint(painter,option,index);
    }
}

QWidget *standardGitTableDelegateImg::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return nullptr;
}
