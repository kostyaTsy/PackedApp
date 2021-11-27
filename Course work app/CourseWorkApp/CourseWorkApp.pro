QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

VERSION = 1.0.0.1

SOURCES += \
    Modules/LZ77.cpp \
    Modules/PriorityQueueAndTree.cpp \
    Modules/RLE.cpp \
    Modules/convertFiles.cpp \
    Modules/huffman.cpp \
    helpwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    packunpackwindow.cpp \
    statisticswindow.cpp

HEADERS += \
    ../Modules/convertFiles.h \
    Modules/LZ77.h \
    Modules/PriorityQueueAndTree.h \
    Modules/RLE.h \
    Modules/convertFiles.h \
    Modules/huffman.h \
    helpwindow.h \
    mainwindow.h \
    packunpackwindow.h \
    statisticswindow.h

FORMS += \
    helpwindow.ui \
    mainwindow.ui \
    packunpackwindow.ui \
    statisticswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc


