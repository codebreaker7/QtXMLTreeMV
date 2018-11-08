#include "widgetitemmodel.h"

WidgetItemModel::WidgetItemModel(const QString &data, QObject *parent):
    QAbstractItemModel(parent)
{
    QList<QVariant> rootdata;
    rootdata << "Widget";
    rootItem = new WidgetDataItem(rootdata);

}

QModelIndex WidgetItemModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent)) {
        return QModelIndex();
    }
    WidgetDataItem * parentItem;
    if(!parent.isValid()) {
        parentItem = rootItem;
    } else {
        parentItem = static_cast<WidgetDataItem*>(parent.internalPointer());
    }
    WidgetDataItem * childItem = parentItem->child(row);
    if (childItem) {
        return createIndex(row, column, childItem);
    } else {
        return QModelIndex();
    }
}

QModelIndex WidgetItemModel::parent(const QModelIndex &child) const
{
    if (!child.isValid()) {
        return QModelIndex();
    }
    WidgetDataItem * childItem = static_cast<WidgetDataItem*>(child.internalPointer());
    WidgetDataItem * parentItem = childItem->parentItem();
    if (parentItem == rootItem) {
        return QModelIndex();
    }
    return createIndex(parentItem->row(), 0, parentItem);
}

int WidgetItemModel::rowCount(const QModelIndex &parent) const
{
    WidgetDataItem * parentItem;
    if (parent.column() > 0) {
        return 0;
    }

    if (!parent.isValid()) {
        parentItem = rootItem;
    } else {
        parentItem = static_cast<WidgetDataItem*>(parent.internalPointer());
    }
    return parentItem->childCount();
}

int WidgetItemModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return static_cast<WidgetDataItem*>(parent.internalPointer())->columnCount();
    } else {
        return rootItem->columnCount();
    }
}

QVariant WidgetItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    WidgetDataItem * item = static_cast<WidgetDataItem*>(index.internalPointer());
    return item->data(index.column());
}

QVariant WidgetItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return rootItem->data(section);
    }
    return QVariant();
}

Qt::ItemFlags WidgetItemModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return 0;
    }
    return QAbstractItemModel::flags(index);
}


WidgetItemModel::~WidgetItemModel() {
    delete rootItem;
}
