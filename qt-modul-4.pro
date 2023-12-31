#-------------------------------------------------
#
# Project created by QtCreator 2017-09-22T11:50:04
#
#-------------------------------------------------

QT       += core gui network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-modul-4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    add_movie_dialog.cpp \
    custom_film_list_widget.cpp \
    filter_widget.cpp \
    info_movie_dialog.cpp \
        main.cpp \
    main_window.cpp \
    movie.cpp \
    my_model.cpp \
    online_films.cpp

HEADERS += \
    add_movie_dialog.h \
    custom_film_list_widget.h \
    filter_widget.h \
    info_movie_dialog.h \
    main_window.h \
    movie.h \
    my_model.h \
    online_films.h

FORMS +=
