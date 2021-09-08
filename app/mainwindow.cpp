#include "mainwindow.h"
#include "stdafx.h"

#include <QPushButton>
#include <QLayout>
#include <QSpacerItem>

#include <QFont>

#define UPPER_BUTTONS 5

MainWindow::MainWindow(QApplication * app, QWidget *parent)
    : _app(app), QWidget(parent)
{
    ui.setupUi(this);
}

void MainWindow::setupWindow()
{
	this->setMinimumSize(QSize(960, 540));
	this->setMaximumSize(QSize(1280, 720));
	this->setWindowTitle("");

	// menu font
	QFontDatabase::addApplicationFont(":/mainwindow/fonts/Segoe UI Bold.ttf");
	QFont font("Segoe UI Bold", 10, 1);

	// menu
	QHBoxLayout * layout = new QHBoxLayout(this);

	QPushButton * button;
	button = new QPushButton("FILE");
	button->setObjectName("file_button");
	button->setFont(font);

	layout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), _app, SLOT(quit()));

	for (size_t i = 0; i < UPPER_BUTTONS; ++i) {
		button = new QPushButton(QString("B") + QString::number(i));
		button->setObjectName("upper_button");
		button->setFont(font);

		layout->addWidget(button);
		QObject::connect(button, SIGNAL(clicked()), _app, SLOT(quit()));
	}

	QSpacerItem * spacer = new QSpacerItem(80, 28);
	layout->addItem(spacer);
	layout->setSpacing(1);

	this->setLayout(layout);
}

const QLayout * MainWindow::makeMenuBar()
{
	// menu font
	QFontDatabase::addApplicationFont(":/mainwindow/fonts/Segoe UI Bold.ttf");
	QFont font("Segoe UI Bold", 10, 1);

	// menu
	QHBoxLayout * layout = new QHBoxLayout(this);

	QPushButton * button;
	button = new QPushButton("FILE");
	button->setObjectName("file_button");
	button->setFont(font);

	layout->addWidget(button);
	QObject::connect(button, SIGNAL(clicked()), _app, SLOT(quit()));

	for (size_t i = 0; i < UPPER_BUTTONS; ++i) {
		button = new QPushButton(QString("B") + QString::number(i));
		button->setObjectName("upper_button");
		button->setFont(font);

		layout->addWidget(button);
		QObject::connect(button, SIGNAL(clicked()), _app, SLOT(quit()));
	}

	QSpacerItem * spacer = new QSpacerItem(80, 28);
	layout->addItem(spacer);
	layout->setSpacing(1);

	this->setLayout(layout);

	return 
}
