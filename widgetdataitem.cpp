#include "widgetdataitem.h"

WidgetDataItem::WidgetDataItem(const QList<QString> &vals, WidgetDataItem * parent)
{
    this->parent = parent;
    datas = vals;
}

int WidgetDataItem::childCount() const {
    return children.count();
}

int WidgetDataItem::columnCount() const {
    return datas.count();
}

int WidgetDataItem::row() const {
    if (parent) {
        return parent->children.indexOf(const_cast<WidgetDataItem*>(this));
    }
    return 0;
}

void WidgetDataItem::appendChild(WidgetDataItem *child) {
    children.append(child);
}

QString WidgetDataItem::data(int column) const {
    return datas.value(column);
}

WidgetDataItem * WidgetDataItem::parentItem() {
    return parent;
}

WidgetDataItem * WidgetDataItem::child(int row) {
    return children.value(row);
}

WidgetDataItem::~WidgetDataItem() {
    qDeleteAll(children);
}
