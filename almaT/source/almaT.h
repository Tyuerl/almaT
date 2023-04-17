#ifndef ALMA_T_Almat_H
#define ALMA_T_Almat_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class almat; }
QT_END_NAMESPACE

class almat : public QMainWindow
{
    Q_OBJECT

public:
    almat(QWidget* parent = nullptr);
    ~almat();

private:
    Ui::almat* ui;
};
#endif // ALMAT_H
