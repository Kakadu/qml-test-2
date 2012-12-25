#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QString>

class DataObject {  // my custom container class
public:
  DataObject(const QString &firstName,
             const QString &lastName):
     first(firstName),
     last(lastName) {}
  QString first;
  QString last;
};

#endif // DATAOBJECT_H
