/****************************************************************************
** Meta object code from reading C++ file 'ntabwidget.h'
**
** Created: Sat Jul 14 13:12:09 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gui/ntabwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ntabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NTabWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,
      56,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   72,   11,   11, 0x0a,
     100,   92,   11,   11, 0x0a,
     131,  117,   11,   11, 0x0a,
     154,  150,   11,   11, 0x0a,
     179,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NTabWidget[] = {
    "NTabWidget\0\0updateSelectionRequested()\0"
    "noteUpdated(int)\0tagCreated(int)\0index\0"
    "closeTab(int)\0to,from\0moveTab(int,int)\0"
    "lid,newWindow\0openNote(int,bool)\0lid\0"
    "tagCreationSignaled(int)\0"
    "noteUpdateSignaled(int)\0"
};

const QMetaObject NTabWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NTabWidget,
      qt_meta_data_NTabWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NTabWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NTabWidget))
        return static_cast<void*>(const_cast< NTabWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateSelectionRequested(); break;
        case 1: noteUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: tagCreated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: moveTab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: openNote((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: tagCreationSignaled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: noteUpdateSignaled((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void NTabWidget::updateSelectionRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void NTabWidget::noteUpdated(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NTabWidget::tagCreated(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE