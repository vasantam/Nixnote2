#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include "logger/qslog.h"
#include "logger/qslogdest.h"
#include "settings/filemanager.h"
#include "settings/startupconfig.h"
#include "filters/filtercriteria.h"
#include "models/notecache.h"
//#include "java/javamachine.h"

#include <string>

//*******************************
//* This class is used to store
//* global values across the
//* program.
//*******************************

#define NOTE_TABLE_LID_POSITION 0
#define NOTE_TABLE_DATE_CREATED_POSITION 1
#define NOTE_TABLE_DATE_UPDATED_POSITION 2
#define NOTE_TABLE_TITLE_POSITION 3
#define NOTE_TABLE_NOTEBOOK_LID_POSITION 4
#define NOTE_TABLE_NOTEBOOK_POSITION 5
#define NOTE_TABLE_TAGS_POSITION 6

#define NOTE_TABLE_AUTHOR_POSITION 7
#define NOTE_TABLE_DATE_SUBJECT_POSITION 8
#define NOTE_TABLE_DATE_DELETED_POSITION 9
#define NOTE_TABLE_SOURCE_POSITION 10
#define NOTE_TABLE_SOURCE_URL_POSITION 11
#define NOTE_TABLE_SOURCE_APPLICATION_POSITION 12
#define NOTE_TABLE_LATITUDE_POSITION 13
#define NOTE_TABLE_LONGITUDE_POSITION 14
#define NOTE_TABLE_ALTITUDE_POSITION 15
#define NOTE_TABLE_HAS_ENCRYPTION_POSITION 16
#define NOTE_TABLE_HAS_TODO_POSITION 17
#define NOTE_TABLE_IS_DIRTY_POSITION 18
#define NOTE_TABLE_SIZE_POSITION 19

#define NOTE_TABLE_COLUMN_COUNT 20


#define MINIMUM_RECOGNITION_WEIGHT 80

using namespace std;

class Global
{
public:
    Global();           // Generic constructor
    ~Global();          // destructor
    int argc;           // Initial argument count from the program start
    char** argv;        // List of arguments from the program start
    FileManager fileManager;
    unsigned int cryptCounter;
    QString attachmentNameDelimeter;
    string username;
    string password;
    bool connected;
    bool confirmDeletes();
    QString tagBehavior();
    QString server;
    //JavaMachine jvm;

    // Filter criteria.  Used for things like the back & forward buttons
    QList<FilterCriteria*> filterCriteria;
    qint32 filterPosition;

    // Note cache
    QHash<int, NoteCache*> cache;

    void setup(StartupConfig config);  // Setup the global variables
    QString getProgramDirPath();      // Get the path the program is executing from
    QList< QPair<int, QString> > passwordRemember;   // Cache of passwords
};

bool caseInsensitiveLessThan(const QString &s1, const QString &s2);

#endif // GLOBAL_H
