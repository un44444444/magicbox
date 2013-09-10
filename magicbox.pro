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


SOURCES += main.cpp\
        mainwindow.cpp \
    magicbox.cpp \
    magics/ssq.cpp \
    magics/magics_common.cpp

HEADERS  += mainwindow.h \
    magicbox.h \
    magics/ssq.h \
    magics/magics_common.h

RESOURCES += \
    views/views.qrc

OTHER_FILES +=
