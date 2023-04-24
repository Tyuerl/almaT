#ifndef ALMA_T_Almat_H
#define ALMA_T_Almat_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>

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
