TEMPLATE=app
TARGET=qneoroid
CONFIG+=qtopia

# Input
HEADERS=cell.h\
        mainwindow.h

SOURCES=cell.cpp \
        mainwindow.cpp \
        main.cpp

RESOURCES=pics/pics.qrc

TRANSLATIONS+=translations/qnetwalk_de.ts \
                translations/qnetwalk_es.ts \
                translations/qnetwalk_fr.ts \
                translations/qnetwalk_it.ts \
                translations/qnetwalk_nl.ts \
                translations/qnetwalk_pl.ts \
                translations/qnetwalk_pt_BR.ts \
                translations/qnetwalk_ru.ts

DEFINES+=QTOPIA_PHONE

pkg [
    name=qneoroid
    desc="qneoroid"
    version=$$QTOPIA_VERSION
    license=$$QTOPIA_LICENSE
    maintainer=$$QTOPIA_MAINTAINER
]

target [
    hint=sxe
    domain=trusted
]

desktop [
    hint=desktop
    files=qneoroid.desktop
    path=/apps/Games
]

pics [
    hint=pics
    files=pics/*
    path=/pics/qneoroid
]

sounds [
    hint=image
    files=sounds/*
    path=/sounds/qneoroid
]


