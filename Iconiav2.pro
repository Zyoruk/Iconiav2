TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/dataStructures/Node.cpp \
    src/dataStructures/SimpleList/Node/SimpleListNode.cpp \
    src/dataStructures/Tree/binarytreenode.cpp \
    src/dataStructures/Tree/binarytree.cpp \
    src/test.cpp \
    src/test2.cpp \
    src/genetico/genetico.cpp \
    src/genetico/mutatron.cpp

HEADERS += \
    src/dataStructures/Node.h \
    src/dataStructures/SimpleList/Node/SimpleListNode.h \
    src/dataStructures/Iterator.h \
    src/dataStructures/Tree/binarytreenode.h \
    src/dataStructures/Tree/binarytree.h \
    src/test.h \
    src/genetico/test.h \
    src/test2.h \
    src/genetico/genetico.h \
    src/genetico/mutatron.h

OTHER_FILES += \
    src/genetico/bitacora temporal josa \
    src/genetico/bitacora temporal josa

