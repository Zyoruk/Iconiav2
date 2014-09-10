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
    src/dataStructures/testClasses/testSimpleListNode.cpp

HEADERS += \
    src/dataStructures/Node.h \
    src/dataStructures/SimpleList/Node/SimpleListNode.h \
    src/dataStructures/Iterator.h \
    src/dataStructures/Tree/binarytreenode.h \
    src/dataStructures/Tree/binarytree.h

