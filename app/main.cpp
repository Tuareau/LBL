#include "mainwindow.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QString>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	app.setApplicationName("LBL");

	QFontDatabase::addApplicationFont(":/mainwindow/fonts/Segoe UI.ttf");
	QFont font("Segoe UI", 10, 1);
	app.setFont(font);

	QFile style_sheet_file;

	style_sheet_file.setFileName(":/mainwindow/app.qss");
	style_sheet_file.open(QFile::ReadOnly);
	QString qss_text = style_sheet_file.readAll();

	app.setStyleSheet(qss_text);

    MainWindow w(&app);
	w.setupWindow();
    w.show();
    return app.exec();
}
