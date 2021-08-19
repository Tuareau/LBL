#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_lbl.h"

class LBL : public QMainWindow
{
    Q_OBJECT

public:
    LBL(QWidget *parent = Q_NULLPTR);

private:
    Ui::LBLClass ui;
};
