#include "tableviewmodel.h"
#include <QColor>

using namespace viewer::view;

TableViewModel::TableViewModel(QObject* parent)
    :QAbstractTableModel(parent)
{
    for (int i = 0; i < 50; i++)
    {
        //mPersons.push_back(IPerson());
    }
}
#include <QDebug>

int TableViewModel::rowCount(const QModelIndex& parent) const
{

    Q_UNUSED(parent);
    if (!mExaminations)
        return 0;
    return mExaminations->size();//*mExaminations->size();
}

int TableViewModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 6;
}


QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
        return QVariant();
}

QVariant TableViewModel::data(const QModelIndex& index, int role) const
{
    switch (role)
    { 
    case Qt::FontRole:
            return QFont("Roboto", 14, 400);
    case Qt::BackgroundColorRole:
            return QColor("#424242");
    case Qt::SizeHintRole:
            return QSize(0, 15);
    case Qt::TextColorRole:
            return QColor(Qt::white);
    case Qt::DisplayRole:
    {
            if (!mExaminations)
                return QVariant();
            if (index.row() >= mCurrentSize)
                return QVariant();
            switch (index.column())
            {
            case 0:
                return QString::fromStdString(mExaminations->at(index.row()).get()->getId());
            case 1:
                return  QString::fromStdString(mExaminations->at(index.row()).get()->getIPerson()->getFullName());
            case 2:
                return  QString::number(mExaminations->at(index.row()).get()->getIPerson()->getBirthdayDate()->getDay()) +
                    ":" + QString::number(mExaminations->at(index.row()).get()->getIPerson()->getBirthdayDate()->getMonth()) +
                    ":" + QString::number(mExaminations->at(index.row()).get()->getIPerson()->getBirthdayDate()->getYear());
            case 3:
                return  QDate(
                    mExaminations->at(index.row()).get()->getDate()->getYear(),
                    mExaminations->at(index.row()).get()->getDate()->getMonth(),
                    mExaminations->at(index.row()).get()->getDate()->getDay()
                );
            case 4:
                return QTime(
                    mExaminations->at(index.row()).get()->getTime().get()->getHour(),
                    mExaminations->at(index.row()).get()->getTime().get()->getMinute(),
                    mExaminations->at(index.row()).get()->getTime().get()->getSecond()
                );
            case 5:
                return  QString::fromStdString(mExaminations->at(index.row()).get()->getId());
            default:
                return QVariant();
            }
        }
    default:
        return QVariant();
    }

    return QVariant();
}

void TableViewModel::setTabs(std::vector<std::shared_ptr<viewer::core::ExaminationPreview>>* mainTab)
{
    mExaminations = mainTab;
    int countToAddExm;
    if (!mExaminations)
        return;
    if (mCurrentSize > 0)
    {
        emit beginRemoveRows(QModelIndex(), 0, mCurrentSize - 1);
        emit endRemoveRows();
    }
    if (mExaminations->size() > 200)
        countToAddExm = 200;
    else
        countToAddExm = mExaminations->size();
    emit beginInsertRows(QModelIndex(), 0, countToAddExm - 1);
    emit endInsertRows();
    mCurrentSize = countToAddExm;
}

bool TableViewModel::canFetchMore(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return true;
}

void TableViewModel::fetchMore(const QModelIndex& parent)
{
    Q_UNUSED(parent);
    loadMoreData();
}

void TableViewModel::loadMoreData()
{
    int insertLen;

    if (!mExaminations)
        return;
    if (mExaminations->size() == mCurrentSize)
        return;
    if (mExaminations->size() > mCurrentSize + 200)
        insertLen = 200;
    else
        insertLen = mExaminations->size() - mCurrentSize;

    emit beginInsertRows(QModelIndex(), mCurrentSize, mCurrentSize + insertLen - 1);
    mCurrentSize += insertLen;
    emit endInsertRows();
    
}

void TableViewModel::changeFocusedItem(const QModelIndex& index)
{

}