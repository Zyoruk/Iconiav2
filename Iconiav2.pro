TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/dataStructures/SimpleList/Node/SimpleListNode.cpp \
    src/dataStructures/Tree/binarytreenode.cpp \
    src/dataStructures/Tree/binarytree.cpp \
    src/dataStructures/interfaceNode.cpp

HEADERS += \
    src/dataStructures/SimpleList/Node/SimpleListNode.h \
    src/dataStructures/Tree/binarytreenode.h \
    src/dataStructures/Tree/binarytree.h \
    src/dataStructures/interfaceNode.h

