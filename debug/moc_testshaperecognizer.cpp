/****************************************************************************
** Meta object code from reading C++ file 'testshaperecognizer.h'
**
** Created: Tue 19. May 18:10:37 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../testshaperecognizer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testshaperecognizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestShapeRecognaizer[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      34,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      43,   21,   21,   21, 0x08,
      64,   21,   21,   21, 0x08,
      85,   21,   21,   21, 0x08,
     106,   21,   21,   21, 0x08,
     127,   21,   21,   21, 0x08,
     148,   21,   21,   21, 0x08,
     169,   21,   21,   21, 0x08,
     190,   21,   21,   21, 0x08,
     212,   21,   21,   21, 0x08,
     234,   21,   21,   21, 0x08,
     256,   21,   21,   21, 0x08,
     278,   21,   21,   21, 0x08,
     300,   21,   21,   21, 0x08,
     322,   21,   21,   21, 0x08,
     344,   21,   21,   21, 0x08,
     366,   21,   21,   21, 0x08,
     384,   21,   21,   21, 0x08,
     402,   21,   21,   21, 0x08,
     420,   21,   21,   21, 0x08,
     438,   21,   21,   21, 0x08,
     456,   21,   21,   21, 0x08,
     493,   21,   21,   21, 0x08,
     530,   21,   21,   21, 0x08,
     567,   21,   21,   21, 0x08,
     604,   21,   21,   21, 0x08,
     641,   21,   21,   21, 0x08,
     678,   21,   21,   21, 0x08,
     715,   21,   21,   21, 0x08,
     752,   21,   21,   21, 0x08,
     789,   21,   21,   21, 0x08,
     827,   21,   21,   21, 0x08,
     865,   21,   21,   21, 0x08,
     903,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestShapeRecognaizer[] = {
    "TestShapeRecognaizer\0\0test_is_triangle_1()\0"
    "test_is_triangle_2()\0test_is_triangle_3()\0"
    "test_is_triangle_4()\0test_is_triangle_5()\0"
    "test_is_triangle_6()\0test_is_triangle_7()\0"
    "test_is_triangle_8()\0test_is_rectangle_1()\0"
    "test_is_rectangle_2()\0test_is_rectangle_3()\0"
    "test_is_rectangle_4()\0test_is_rectangle_5()\0"
    "test_is_rectangle_6()\0test_is_rectangle_7()\0"
    "test_is_rectangle_8()\0test_is_round_1()\0"
    "test_is_round_2()\0test_is_round_3()\0"
    "test_is_round_4()\0test_is_round_5()\0"
    "test_find_geometrical_primitives_1()\0"
    "test_find_geometrical_primitives_2()\0"
    "test_find_geometrical_primitives_3()\0"
    "test_find_geometrical_primitives_4()\0"
    "test_find_geometrical_primitives_5()\0"
    "test_find_geometrical_primitives_6()\0"
    "test_find_geometrical_primitives_7()\0"
    "test_find_geometrical_primitives_8()\0"
    "test_find_geometrical_primitives_9()\0"
    "test_find_geometrical_primitives_10()\0"
    "test_find_geometrical_primitives_11()\0"
    "test_find_geometrical_primitives_12()\0"
    "test_find_geometrical_primitives_13()\0"
};

const QMetaObject TestShapeRecognaizer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestShapeRecognaizer,
      qt_meta_data_TestShapeRecognaizer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestShapeRecognaizer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestShapeRecognaizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestShapeRecognaizer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestShapeRecognaizer))
        return static_cast<void*>(const_cast< TestShapeRecognaizer*>(this));
    return QObject::qt_metacast(_clname);
}

int TestShapeRecognaizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: test_is_triangle_1(); break;
        case 1: test_is_triangle_2(); break;
        case 2: test_is_triangle_3(); break;
        case 3: test_is_triangle_4(); break;
        case 4: test_is_triangle_5(); break;
        case 5: test_is_triangle_6(); break;
        case 6: test_is_triangle_7(); break;
        case 7: test_is_triangle_8(); break;
        case 8: test_is_rectangle_1(); break;
        case 9: test_is_rectangle_2(); break;
        case 10: test_is_rectangle_3(); break;
        case 11: test_is_rectangle_4(); break;
        case 12: test_is_rectangle_5(); break;
        case 13: test_is_rectangle_6(); break;
        case 14: test_is_rectangle_7(); break;
        case 15: test_is_rectangle_8(); break;
        case 16: test_is_round_1(); break;
        case 17: test_is_round_2(); break;
        case 18: test_is_round_3(); break;
        case 19: test_is_round_4(); break;
        case 20: test_is_round_5(); break;
        case 21: test_find_geometrical_primitives_1(); break;
        case 22: test_find_geometrical_primitives_2(); break;
        case 23: test_find_geometrical_primitives_3(); break;
        case 24: test_find_geometrical_primitives_4(); break;
        case 25: test_find_geometrical_primitives_5(); break;
        case 26: test_find_geometrical_primitives_6(); break;
        case 27: test_find_geometrical_primitives_7(); break;
        case 28: test_find_geometrical_primitives_8(); break;
        case 29: test_find_geometrical_primitives_9(); break;
        case 30: test_find_geometrical_primitives_10(); break;
        case 31: test_find_geometrical_primitives_11(); break;
        case 32: test_find_geometrical_primitives_12(); break;
        case 33: test_find_geometrical_primitives_13(); break;
        default: ;
        }
        _id -= 34;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
