TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/constants/constants.cpp \
    src/dataStructures/geometricFiguresKnowledge/geometricFiguresTree.cpp \
    src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.cpp \
    src/genetico/genetico.cpp \
    src/genetico/mutatron.cpp \
    src/JSON/jsonparser.cpp \

HEADERS += \
    src/dataStructures/SimpleList/Node/SimpleListNode.h \
    src/dataStructures/Tree/binarytreenode.h \
    src/dataStructures/Tree/binarytree.h \
    src/dataStructures/interfaceNode.h \
    src/constants/constants.h \
    src/dataStructures/geometricFiguresKnowledge/geometricFiguresTree.h \
    src/dataStructures/geometricFiguresKnowledge/geometricFigure/geometricfigure.h \
    src/dataStructures/Graph/graphNode/graphnode.h \
    src/dataStructures/SimpleList/SimpleList.h \
    src/genetico/test.h \
    src/genetico/genetico.h \
    src/genetico/mutatron.ḥ \
OTHER_FILES += \
    src/genetico/bitacora temporal josa \
    src/genetico/bitacora temporal josa
OTHER_FILES += \
    database/knowledge.txt \

