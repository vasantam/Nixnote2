#include "notemodel.h"
#include "logger/qslog.h"
#include "global.h"

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql>


//****************************************************
//* This class is used to read & write information
//* to the NoteModel class.  This class holds what
//* a user sees in the table listing in the GUI.
//****************************************************


// Generic constructor
NoteModel::NoteModel(QObject *parent)
    :QSqlTableModel(parent)
{
    // Check if the table exists.  If not, create it.
    QSqlQuery sql;
    sql.exec("Select *  from sqlite_master where type='table' and name='NoteTable';");
    if (!sql.next())
        this->createTable();
    this->setEditStrategy(QSqlTableModel::OnFieldChange);

    this->setTable("NoteTable");
    this->setFilter("lid in (select lid from filter)");
}

// Destructor
NoteModel::~NoteModel() {
}



//* Create the NoteModel table.
void NoteModel::createTable() {
    QLOG_TRACE() << "Entering NoteModel::createTable()";

    QLOG_DEBUG() << "Creating table NoteTable";
    QSqlQuery sql;
    QString command("Create table if not exists NoteTable (" +
                  QString("lid integer primary key,") +
                  QString("dateCreated real default null,") +
                  QString("dateUpdated real default null,") +
                  QString("title text default null collate nocase,") +
                  QString("notebookLid integer default null,") +
                  QString("notebook text default null collate nocase,") +
                  QString("tags text default null collate nocase,") +

                  QString("author text default null collate nocase,") +
                  QString("dateSubject real default null,") +
                  QString("dateDeleted real default null,") +

                  QString("source text default null collate nocase,") +
                  QString("sourceUrl text default null collate nocase,") +
                  QString("sourceApplication text default null collate nocase,") +
                  QString("latitude real default null,") +
                  QString("longitude real default null,") +
                  QString("altitude real default null,") +
                  QString("hasEncryption integer default null,") +
                  QString("hasTodo integer default null,") +
                  QString("isDirty integer default null,") +
                  QString("size integer default null") +
                  QString(")"));
    if (!sql.exec(command) ||
            !sql.exec("CREATE INDEX NoteTable_Title_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Author_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Notebook_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Notebook_Lid_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_DateCreated_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_DateUpdated_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Date_Subject_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Date_Deleted_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Source_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Source_Url_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Source_Application_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Latitude_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Longitude_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Altitude_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Has_Encryption_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Has_Todo_Index on NoteTable (lid)") ||
            !sql.exec("CREATE INDEX NoteTable_Is_Dirty_Index on NoteTable (lid)")
       ) {
        QLOG_ERROR() << "Creation of NoteTable table failed: " << sql.lastError();
    }
}


//int NoteModel::rowCount(const QModelIndex & /*parent*/) const
// {
//    QLOG_TRACE() << "Entering NoteModel::rowCount()";

//    QSqlQuery sql;
//    sql.exec("Select count(lid) from NoteTable where lid in (select lid from filter)");
//    if (!sql.next()) {
//        QLOG_ERROR() << "Error retrieving NoteModel::rowCount: " << sql.lastError();
//        return 0;
//    }
//    int rowCount = QVariant(sql.value(0)).toInt();
//    return rowCount;

// }

int NoteModel::columnCount(const QModelIndex &parent) const {
//    parent.column();
    return NOTE_TABLE_COLUMN_COUNT;
}


Qt::ItemFlags NoteModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    // Make the table row non-editable
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

