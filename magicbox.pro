#-------------------------------------------------
#
# Project created by QtCreator 2013-09-02T01:21:42
#
#-------------------------------------------------

QT       +=

equals(QT_MAJOR_VERSION, 4): QT += webkit
greaterThan(QT_MAJOR_VERSION, 4): QT += webkitwidgets widgets

TARGET = magicbox
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11
#INCLUDEPATH += "$$_PRO_FILE_PWD_/third-party/jsoncpp/include"
LIBS +=


SOURCES += main.cpp \
        mainwindow.cpp \
    magicbox.cpp \
    magics/ssq.cpp \
    magics/magics_common.cpp \
    randoms/random_mt.cpp \
    randoms/random_std.cpp \
    randoms/random_rand.cpp

HEADERS  += mainwindow.h \
    magicbox.h \
    magics/ssq.h \
    magics/magics_common.h \
    utils/log.h \
    randoms/random_mt.h \
    randoms/random_std.h \
    randoms/random_rand.h

RESOURCES += \
    views/views.qrc

OTHER_FILES +=
