QT       += core gui
QT       += sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++23

QMAKE_CXXFLAGS_WARN_ON += -Wno-deprecated
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardview.cpp \
    customer.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    order.cpp \
    product.cpp \
    showproducts.cpp

HEADERS += \
    cardview.h \
    customer.h \
    database.h \
    mainwindow.h \
    order.h \
    product.h \
    showproducts.h

FORMS += \
    mainwindow.ui \
    showproducts.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
target.path = $$[QT_INSTALL_EXAMPLES]/sql/cachedtable

RESOURCES += \
    recurses.qrc
