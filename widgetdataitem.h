#ifndef WIDGETDATAITEM_H
#define WIDGETDATAITEM_H

#include <QList>

class WidgetDataItem
{
public:
    explicit WidgetDataItem(const QList<QString> vals, WidgetDataItem * parent = 0);
    ~WidgetDataItem();

    void appendChild(WidgetDataItem * child);
    int childCount() const;
    int columnCount() const;
    QString data(int column) const;
    int row() const;
    WidgetDataItem * child(int row);
    WidgetDataItem * parentItem();
private:
    QList<WidgetDataItem*> children;
    WidgetDataItem * parent;
    QList<QString> data;
};

#endif // WIDGETDATAITEM_H
