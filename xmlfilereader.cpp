#include "xmlfilereader.h"
#include <QFile>

XmlFileReader::XmlFileReader()
{
    reader = new QXmlStreamReader();
    dataList = new QStringList();
}

void XmlFileReader::readXmlFile(const QString & fileName) {
    QFile * file = new QFile(fileName);
    if(!file->open(QFile::ReadOnly)) {
        return;
    }
    reader->setDevice(file);
    if (reader->readNextStartElement()) {
        if (reader->name() == QLatin1String("data")) {
            while (reader->readNextStartElement()) {
                if (reader->name() == QLatin1String("widget")) {
                    QString widgetName = reader->readElementText();
                    dataList->push_back(widgetName);
                }
            }
        }
    }
}

