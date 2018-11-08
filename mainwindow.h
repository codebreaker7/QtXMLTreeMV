#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "xmlfilereader.h"
#include "widgetitemmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void selectFileToOpen();
private:
    Ui::MainWindow *ui;
    XmlFileReader * reader;
    WidgetItemModel * itemModel;
};

#endif // MAINWINDOW_H
