#include "standardgittabledelegate.h"

standardGitTableDelegate::standardGitTableDelegate() {}

QWidget *standardGitTableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    Q_UNUSED(option);
    
    QCheckBox* editor = new QCheckBox(parent);

    QStandardItemModel* model = (QStandardItemModel*)(index.model());
    int count = 0;
    int i = 0;
    for (; i < model->rowCount(); ++i)
        if (model->data(model->index(i, 0)).toInt() == 1) {
            count++;
            break;
        }
            
    if (count == 1) {
        editor->setEnabled(false);
        if (i == index.row()) {
            editor->setEnabled(true);
        }
    }

    return editor;
}

void standardGitTableDelegate::setEditorData(QWidget *editor, const QModelIndex &index)const
{

    QCheckBox* control=static_cast<QCheckBox*>(editor);
    if(index.model()->data(index).toInt()){
        
        control->setChecked(true);
    }else{
        control->setChecked(false);
    }
}

void standardGitTableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox* control=static_cast<QCheckBox*>(editor);
    if(control->isChecked()){
        model->setData(index,1,Qt::EditRole);
    }else{
        
        model->setData(index,0,Qt::EditRole);
    }
}

void standardGitTableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
    Q_UNUSED(index);
    editor->setGeometry(CheckBoxRect(option));

    // editor->move(20,20);
    // QStandardItemModel* model=(QStandardItemModel*)(index.model());
    // editor->setParent(model->item(index.row(),0))
    // editor->move(option.rect.x()+option.rect.width()/2-editor->width()/2,option.rect.y()+option.rect.height()/2-editor->height()/2);

}

void standardGitTableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 0)//��Ҫ�������ڵڼ�����ʾcheckbox
    {
        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();

        //�˴����������źţ�
        QStyleOptionButton checkBoxStyleOption;
        checkBoxStyleOption.state |= QStyle::State_Enabled;
        checkBoxStyleOption.state |= checked? QStyle::State_On : QStyle::State_Off;
        checkBoxStyleOption.rect = CheckBoxRect(option);


        QApplication::style()->drawControl(QStyle::CE_CheckBox,&checkBoxStyleOption,painter);
    }
    else
    {
        standardGitTableDelegate::paint(painter, option, index);
    }
}

QRect standardGitTableDelegate::CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions)
{
    //���ư�ť����Ҫ�Ĳ���
    QStyleOptionButton checkBoxStyleOption;
    //���ո����ķ����� ����Ԫ��������
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    //����QCheckBox����
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x()+viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                         viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //����QCheckBox������״
    return QRect(checkBoxPoint, checkBoxRect.size());

}
