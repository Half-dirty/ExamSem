QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExamClient
TEMPLATE = app

SOURCES += \
           AuthenticationWindow.cpp \
           ChangePasswordWindow.cpp \
           Client.cpp \
           ExamCompletionWindow.cpp \
           ExamSelectionWindow.cpp \
           ExamWindow.cpp \
           LoginWindow.cpp \
           MainWindow.cpp \
           ProfileWindow.cpp \
           RegistrationWindow.cpp \
           StatisticsWindow.cpp \
           WelcomeWindow.cpp \
           main.cpp

HEADERS  += \
            AuthenticationWindow.h \
            ChangePasswordWindow.h \
            Client.h \
            ExamCompletionWindow.h \
            ExamQuestion.h \
            ExamSelectionWindow.h \
            ExamWindow.h \
            LoginWindow.h \
            MainWindow.h \
            ProfileWindow.h \
            RegistrationWindow.h \
            StatisticsWindow.h \
            WelcomeWindow.h

FORMS    += \
            AuthenticationWindow.ui \
            ChangePasswordWindow.ui \
            ExamCompletionWindow.ui \
            ExamSelectionWindow.ui \
            ExamWindow.ui \
            LoginWindow.ui \
            MainWindow.ui \
            ProfileWindow.ui \
            RegistrationWindow.ui \
            StatisticsWindow.ui \
            WelcomeWindow.ui

RESOURCES += \
            resources.qrc
