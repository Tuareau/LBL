#include "mainwindow.h"
#include "stdafx.h"

#include <QPushButton>
#include <QLayout>
#include <QSpacerItem>

#include <QLabel>

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

	// QWidget * window_frame_widget = this->makeWindowHandlerWidget();
	QWidget * menu_widget = this->makeMenuBarWidget();
	menu_widget->setObjectName("menu_widget");
	// QWidget * central_widget = this->makeCentralWidget();
	QWidget * status_bar_widget = this->makeStatusBarWidget();
	menu_widget->setObjectName("status_bar");

	_main_layout = new QVBoxLayout(this);
	//_main_layout->addWidget(menu_widget);
	_main_layout->addWidget(menu_widget);
	// _main_layout->addWidget(menu_widget);
	_main_layout->addSpacing(200);
	_main_layout->addWidget(status_bar_widget);

	_main_layout->setContentsMargins(0, 0, 0, 0);
	_main_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	_main_layout->setSpacing(0);

	this->setLayout(_main_layout);
}

QWidget * MainWindow::makeMenuBarWidget() const
{
	QFontDatabase::addApplicationFont(":/mainwindow/fonts/Segoe UI Bold.ttf");
	QFont font("Segoe UI Bold", 10, 1);

	QWidget * widget = new QWidget;
	QHBoxLayout * layout = new QHBoxLayout(widget);

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

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	layout->setSpacing(1);

	widget->setLayout(layout);
	return widget;
}

QWidget * MainWindow::makeStatusBarWidget() const
{
	QWidget * widget = new QWidget;
	QHBoxLayout * layout = new QHBoxLayout(widget);

	QLabel * status_label = new QLabel("SEASON: AUTUMN 2021");
	status_label->setObjectName("status_bar_label");

	QLabel * app_name = new QLabel("LBL");
	app_name->setObjectName("status_bar_label");

	layout->addWidget(status_label, 0, Qt::AlignLeft);
	layout->addSpacing(100);
	layout->addWidget(app_name, 0, Qt::AlignRight);

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	widget->setLayout(layout);
	return widget;
}
