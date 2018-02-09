#-------------------------------------------------
#
# Project created by QtCreator 2016-06-07T23:22:52
#
#-------------------------------------------------

QT       += core
QT       += gui widgets
TARGET = boostan_graphical_finalAPprojrct
CONFIG   += widget c++11
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    frm_login.cpp \
    check_user_pass.cpp \
    frm_main_admin.cpp \
    frm_courses_admin.cpp \
    database.cpp \
    student.cpp \
    students_table.cpp \
    frm_students_admin.cpp \
    frm_add_student_admin.cpp \
    course.cpp \
    courses_table.cpp \
    frm_add_course_admin.cpp \
    student_course.cpp \
    student_course_table.cpp

HEADERS += \
    frm_login.h \
    check_user_pass.h \
    mydefs.h \
    frm_main_admin.h \
    frm_courses_admin.h \
    database.h \
    student.h \
    students_table.h \
    frm_students_admin.h \
    frm_add_student_admin.h \
    course.h \
    courses_table.h \
    frm_add_course_admin.h \
    student_course.h \
    student_course_table.h
