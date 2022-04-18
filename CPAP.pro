QT       += core gui charts serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chartview.cpp \
    main.cpp \
    sp_widget.cpp \
    widget.cpp \
    worker.cpp

HEADERS += \
    chartview.h \
    qcustomplot.h \
    sp_widget.h \
    widget.h \
    worker.h

FORMS += \
    sp_widget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
