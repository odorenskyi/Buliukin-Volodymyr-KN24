TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/release/ -lModulesBuliukin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/debug/ -lModulesBuliukin
else:unix: LIBS += -L$$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/ -lModulesBuliukin

INCLUDEPATH += $$PWD/../ModulesBuliukin
DEPENDPATH += $$PWD/../ModulesBuliukin

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/release/libModulesBuliukin.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/debug/libModulesBuliukin.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/release/ModulesBuliukin.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/debug/ModulesBuliukin.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ModulesBuliukin/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/libModulesBuliukin.a
