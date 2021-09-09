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

	QLayout * menu_layout = this->makeMenuBar();
	this->setLayout(menu_layout);
}

QLayout * MainWindow::makeMenuBar()
{
	QFontDatabase::addApplicationFont(":/mainwindow/fonts/Segoe UI Bold.ttf");
	QFont font("Segoe UI Bold", 10, 1);

	QHBoxLayout * layout = new QHBoxLayout(this);

	QPushButton * button;
	
	button = new QPushButton;
	button->setFont(font);
	button->setText("FILE");
	button->setObjectName("file_button");	

	layout->addWidget(button, 0, Qt::AlignLeft);
	QObject::connect(button, SIGNAL(clicked()), _app, SLOT(quit()));

	for (size_t i = 0; i < UPPER_BUTTONS; ++i) {
		button = new QPushButton(QString("B") + QString::number(i + 1));
		button->setFont(font);
		button->setObjectName("upper_button");		

		layout->addWidget(button, 0, Qt::AlignLeft);
	}

	layout->addSpacing(700);

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	layout->setSpacing(1);
	return layout;
}
