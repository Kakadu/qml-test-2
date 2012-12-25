#ifndef MINIMODEL_H
#define MINIMODEL_H

#include <QAbstractListModel>
#include "dataobject.h"

static const int FirstNameRole = Qt::UserRole + 101;
static const int SortRole = Qt::UserRole + 102;

class MiniModel: public QAbstractListModel
{
    Q_OBJECT
    QList<DataObject*> _items;
    QHash<int, QByteArray> _roles;

public:
    MiniModel(QObject* parent  = 0) : QAbstractListModel(parent) {
        _roles.insert(FirstNameRole, QByteArray("name"));
        _roles.insert(SortRole, QByteArray("sort"));
    }
    virtual QHash<int, QByteArray> roleNames() {
        return _roles;
    }

    Q_INVOKABLE int itemsCount() { return _items.count(); }
    MiniModel(QList<DataObject*> lst) : MiniModel(NULL) {
        _items = lst;
    }
    int rowCount(const QModelIndex & ) const {
        return _items.count();
    }
    QVariant data (const QModelIndex & index, int role) const {
        int r = index.row();
        if ((r<0) || (r>=_items.count()))
            return QVariant::Invalid;

        DataObject* dobj =  _items.at(r);
        switch (role) {
        case Qt::DisplayRole:
        case FirstNameRole:
            return QVariant::fromValue(dobj->first);
        case SortRole:
            return QVariant::fromValue(dobj->last);
        default:
            return QVariant();
        }
    }
};

#endif // MINIMODEL_H
