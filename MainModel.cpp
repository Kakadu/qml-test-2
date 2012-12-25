#include "MainModel.h"
#include "dataobject.h"



MainModel::MainModel(QObject *parent) :
    QAbstractListModel(parent)
{
    QList<DataObject*> data1;
    data1 << new DataObject("a","A") << new DataObject("c","C") << new DataObject("b","B");
    innerData.append( new MiniModel(data1) );

    QList<DataObject*> data2;
    data2 << new DataObject("d","D") << new DataObject("e","E") << new DataObject("f","F");
    innerData.append( new MiniModel(data2) );

    QList<DataObject*> data3;
    data3 << new DataObject("g","G") << new DataObject("h","H") << new DataObject("i","I");
    innerData.append( new MiniModel(data3) );

    _roles.insert(HOMMRole, QByteArray("homm"));
}

int MainModel::rowCount ( const QModelIndex & ) const {
    //qDebug() << "rowCount = " << innerData.count();
    return innerData.count();
}

QVariant MainModel::data ( const QModelIndex & index, int role ) const {
    Q_UNUSED(role);
    //qDebug() << "data where index = " << index.row();
    int r = index.row();
    if ((r<0) || (r>=innerData.count()))
        return QVariant::Invalid;

    auto dobj =  innerData.at(r);
    switch (role) {
    case Qt::DisplayRole: // The default display role now displays the first name as well
    case HOMMRole:
        return QVariant::fromValue(dobj);
    default:
        return QVariant();
    }
}


