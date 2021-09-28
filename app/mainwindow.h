#pragma once

#include <QtWidgets/QWidget>
#include <QStyleOption>
#include <QPainter>
#include <QLayout>
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
	QVBoxLayout * _main_layout;

	QWidget * makeTitleBarWidget() const;
	QWidget * makeMenuBarWidget() const;
	QWidget * makeCentralWidgetWidget() const;
	QWidget * makeStatusBarWidget() const;
};
