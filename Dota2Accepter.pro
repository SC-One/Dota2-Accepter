QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    APIGetter.cpp \
    MouseControl.cpp \
    MouseCursorChanging.cpp \
    ScreenShot.cpp \
    SimilarInQImage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    APIGetter.h \
    MouseControl.h \
    MouseCursorChanging.h \
    ScreenShot.h \
    SimilarInQImage.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





QT += network


LIBS += -lUser32
TARGET = Dota2Accepter
RC_ICONS = AdImage.ico  // in current directory

RESOURCES += \
    Src.qrc





################ for OpenCV msvc 2017 x64   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#INCLUDEPATH += C:\\OpenCv\\OpenCV_4.1.1\\opencv\\build\\install\\include
#LIBS += -LC:\\OpenCv\\OpenCV_4.1.1\\opencv\\build\\install\\x64\\vc15\\lib -lopencv_core411 -lopencv_imgproc411 -lopencv_highgui411 -lopencv_imgcodecs411 -lopencv_videoio411 -lopencv_video411 -lopencv_calib3d411 -lopencv_photo411 -lopencv_features2d411 -lopencv_dnn411 -lopencv_flann411 -lopencv_gapi411 -lopencv_ml411 -lopencv_objdetect411 -lopencv_stitching411
#DEPENDPATH += C:\\OpenCv\\OpenCV_4.1.1\\opencv\\build\install\\include
################ for OpenCV msvc 2017 x64   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



############### for OpenCV msvc 2017 x86   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
INCLUDEPATH += C:\\OpenCv\\OpenCV_4.1.1\\opencv\\build\\install\\include
LIBS += -LC:\\OpenCv\\OpenCV_4.1.1\\opencv\\build\\install\\x86\\vc15\\lib -lopencv_core411 -lopencv_imgproc411 -lopencv_highgui411 -lopencv_imgcodecs411 -lopencv_videoio411 -lopencv_video411 -lopencv_calib3d411 -lopencv_photo411 -lopencv_features2d411 -lopencv_dnn411 -lopencv_flann411 -lopencv_gapi411 -lopencv_ml411 -lopencv_objdetect411 -lopencv_stitching411
DEPENDPATH += C:\\OpenCv\\OpenCV_4.1.1\\opencv\\build\install\\include
############### for OpenCV msvc 2017 x86   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
