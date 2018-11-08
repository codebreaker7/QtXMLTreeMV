#include "widgetdataitem.h"

WidgetDataItem::WidgetDataItem(const QList<QString> &vals, WidgetDataItem * parent = 0)
{
    this->parent = parent;
    data = vals;
}

int WidgetDataItem::childCount() {
    return children.count();
}

int WidgetDataItem::row() {
    if (parent) {
        return parent->children.indexOf(const_cast<WidgetDataItem*>(this));
    }
    return 0;
}

void WidgetDataItem::appendChild(WidgetDataItem *child) {
    children.append(child);
}

QString WidgetDataItem::data(int column) const {
    return data.value(column);
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
