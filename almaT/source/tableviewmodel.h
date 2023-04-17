#ifndef ALMA_T_Table_VIEW_MODEL_H
#define ALMA_T_Table_VIEW_MODEL_H
 
#include <QAbstractTableModel>
#include <vector>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QSize>
#include <QFont>    
#include <memory>

namespace viewer
{
    namespace view
    {
        class Tab;
        class TableViewModel : public QAbstractTableModel
        {
        public:
            TableViewModel(QObject* parent = 0);
            int rowCount(const QModelIndex& parent = QModelIndex()) const override;
            int columnCount(const QModelIndex& parent = QModelIndex()) const override;
            QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
            bool        canFetchMore(const QModelIndex& parent) const override;
            void        fetchMore(const QModelIndex& parent) override;
            QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
            /*void setTabs(std::vector<std::shared_ptr<viewer::core::ExaminationPreview>>* mainTab);*/

        private slots:
            void        loadMoreData();
            void        changeFocusedItem(const QModelIndex& index);

        protected:
            /*std::vector<std::shared_ptr<viewer::core::ExaminationPreview>>* mExaminations = nullptr;*/
            int mCurrentSize{ 0 };
            int mSelectedIndex{ -1 };
        };

    }
}

#endif // ASDIC_M_VIEWER_VIEW_Table_VIEW_MODEL_H
