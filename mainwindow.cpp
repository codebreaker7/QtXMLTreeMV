#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reader = new XmlFileReader();
}

void MainWindow::selectFileToOpen() {
    QFileDialog dialog;
    dialog.setNameFilter("XML files (*.xml)");
    if(dialog.exec()) {
        QString filename = dialog.selectedFiles().first();
        ui->fileNameEdit->setText(filename);
        reader->readXmlFile(filename);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
