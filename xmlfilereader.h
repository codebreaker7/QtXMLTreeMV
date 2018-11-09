#ifndef XMLFILEREADER_H
#define XMLFILEREADER_H

#include <QXmlStreamReader>

class XmlFileReader
{
public:
    XmlFileReader();
    QStringList * getItems() const;
    void readXmlFile(const QString&);
private:
    QXmlStreamReader * reader;
    QStringList * dataList;
};

#endif // XMLFILEREADER_H
