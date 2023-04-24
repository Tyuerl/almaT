﻿#include "almat.h"
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

void Widget::onResult(QNetworkReply* reply)
{
    // Если ошибки отсутсвуют
    if (!reply->error()) {

        // То создаём объект Json Document, считав в него все данные из ответа
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

        // Забираем из документа корневой объект
        QJsonObject root = document.object();
        /* Находим объект "departament", который располагается самым первым в корневом объекте.
         * С помощью метода keys() получаем список всех объектов и по первому индексу
         * забираем название объекта, по которому получим его значение
         * */
        ui->textEdit->append(root.keys().at(0) + ": " + root.value(root.keys().at(0)).toString());

        // Второе значение пропишем строкой
        QJsonValue jv = root.value("employees");
        // Если значение является массивом, ...
        if (jv.isArray()) {
            // ... то забираем массив из данного свойства
            QJsonArray ja = jv.toArray();
            // Перебирая все элементы массива ...
            for (int i = 0; i < ja.count(); i++) {
                QJsonObject subtree = ja.at(i).toObject();
                // Забираем значения свойств имени и фамилии добавляя их в textEdit
                ui->textEdit->append(subtree.value("firstName").toString() +
                    " " +
                    subtree.value("lastName").toString());
            }
        }
        // В конце забираем свойство количества сотрудников отдела и также выводим в textEdit
        ui->textEdit->append(QString::number(root.value("number").toInt()));
    }
    reply->deleteLater();
}

almat::~almat()
{
    delete ui;
}

