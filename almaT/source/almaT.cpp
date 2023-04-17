#include "almat.h"
#include "ui_almat.h"

almat::almat(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::almat)
{
    ui->setupUi(this);
}

almat::~almat()
{
    delete ui;
}

