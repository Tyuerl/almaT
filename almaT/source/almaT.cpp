#include "almat.h"
#include "ui_almat.h"

almat::almat(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::almat)
{
    ui->setupUi(this);
    QNetworkAccessManager* networkManager = new QNetworkAccessManager();
    // Подключаем networkManager к обработчику ответа
    //connect(networkManager, &QNetworkAccessManager::finished, this, &Widget::onResult);
    // Получаем данные, а именно JSON файл с сайта по определённому url
    networkManager->get(QNetworkRequest(QUrl("https://192.168.0.25:5000/algo_list")));
    
}

almat::~almat()
{
    delete ui;
}

