QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExamClient
TEMPLATE = app

SOURCES += \
           AuthenticationWindow.cpp \
           Client.cpp \
           ExamCompletionWindow.cpp \
           ExamSelectionWindow.cpp \
           ExamWindow.cpp \
           LoginWindow.cpp \
           MainWindow.cpp \
           RegistrationWindow.cpp \
           StatisticsWindow.cpp \
           WelcomeWindow.cpp \
           main.cpp

HEADERS  += \
            AuthenticationWindow.h \
            Client.h \
            ExamCompletionWindow.h \
            ExamQuestion.h \
            ExamSelectionWindow.h \
            ExamWindow.h \
            LoginWindow.h \
            MainWindow.h \
            RegistrationWindow.h \
            StatisticsWindow.h \
            WelcomeWindow.h

FORMS    += \
    AuthenticationWindow.ui \
            ExamCompletionWindow.ui \
    ExamSelectionWindow.ui \
    ExamWindow.ui \
    LoginWindow.ui \
    MainWindow.ui \
    RegistrationWindow.ui \
    StatisticsWindow.ui \
    WelcomeWindow.ui

RESOURCES += \
    resources.qrc
