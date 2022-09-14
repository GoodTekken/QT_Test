unix:QMAKE_CFLAGS_WARN_ON +=-Wno-deprecated-copy
unix:QMAKE_CXXFLAGS_WARN_ON +=-Wno-deprecated-copy

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    MainWindow.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Test_01 \
    Test_02 \
    Test_03 \
    Test_04 \
    Test_05 \
    Test_06 \
    Test_07 \
    Test_08 \
    Test_09 \
    Test_10 \
    Test_11 \
    Test_12 \
    Test_13 \
    Test_14

RESOURCES += \
    pic.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../MyLibrary/C++/release/ -ltest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../MyLibrary/C++/debug/ -ltest
else:unix: LIBS += -L$$PWD/../../MyLibrary/C++/ -ltest

INCLUDEPATH += $$PWD/../../MyLibrary/C++
DEPENDPATH += $$PWD/../../MyLibrary/C++

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../MyLibrary/C++/release/libtest.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../MyLibrary/C++/debug/libtest.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../MyLibrary/C++/release/test.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../MyLibrary/C++/debug/test.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../MyLibrary/C++/libtest.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../MyLibrary/C++/release/ -ladd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../MyLibrary/C++/debug/ -ladd
else:unix: LIBS += -L$$PWD/../../MyLibrary/C++/ -ladd

INCLUDEPATH += $$PWD/../../MyLibrary/C++
DEPENDPATH += $$PWD/../../MyLibrary/C++
