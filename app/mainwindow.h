#pragma once

#include <QtWidgets/QWidget>
#include <QStyleOption>
#include <QPainter>
#include "ui_mainwindow.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QApplication * app, QWidget *parent = Q_NULLPTR);
	void setupWindow();

private:
    Ui::MainWindowClass ui;
	QApplication * _app;

	const QLayout * makeTitleBar();
	const QLayout * makeMenuBar();
	const QLayout * makeCentralWidget();
	const QLayout * makeStatusBar();
};
