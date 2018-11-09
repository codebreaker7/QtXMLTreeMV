#include "widgetitemmodel.h"

WidgetItemModel::WidgetItemModel(const QStringList &data, QObject *parent):
    QAbstractItemModel(parent)
{
    QList<QString> rootdata;
    rootdata << "Widget";
    rootItem = new WidgetDataItem(rootdata);
    setupModelData(data, rootItem);
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

void WidgetItemModel::setupModelData(const QStringList &lines, WidgetDataItem *parent) {
    // for now just add items into the model expecting just single line per item
    // TODO: parse data from XML into items to create a tree structure
    for (int i = 0; i < lines.size(); ++i) {
        parent->appendChild(new WidgetDataItem(QList<QString>() << lines.at(i), parent));
    }
}


WidgetItemModel::~WidgetItemModel() {
    delete rootItem;
}
