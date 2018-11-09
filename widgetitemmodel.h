#ifndef WIDGETITEMMODEL_H
#define WIDGETITEMMODEL_H

#include <QAbstractItemModel>
#include "widgetdataitem.h"

class WidgetItemModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit WidgetItemModel(const QStringList &data, QObject * parent = 0);
    ~WidgetItemModel();

    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
private:
    void setupModelData(const QStringList& lines, WidgetDataItem * parent);
    WidgetDataItem * rootItem;
};

#endif // WIDGETITEMMODEL_H
