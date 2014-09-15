TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/JSON/jsonparser.cpp

HEADERS += \
    src/dataStructures/SimpleList/Node/SimpleListNode.h \
    src/dataStructures/Tree/binarytreenode.h \
    src/dataStructures/Tree/binarytree.h \
    src/dataStructures/interfaceNode.h \
    src/dataStructures/SimpleList/SimpleList.h \
    src/constants/constants.h \
    src/JSON/jsonparser.h \
    src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h

OTHER_FILES += \
    database/knowledge.txt

