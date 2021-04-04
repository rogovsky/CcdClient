#
#

INCLUDEPATH += $$PWD/QJSON/src/libQJSON

# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- #
BASE_HEADERS += \
    $$PWD/QJSON/src/libQJSON/JSONArray.h \
    $$PWD/QJSON/src/libQJSON/JSONDocument.h \
    $$PWD/QJSON/src/libQJSON/JSONParseError.h \
    $$PWD/QJSON/src/libQJSON/JSONObject.h \
    $$PWD/QJSON/src/libQJSON/JSONValue.h

HEADERS += \
    $$BASE_HEADERS \
    $$PWD/QJSON/src/libQJSON/Private/qjsonwriter_p.h \
    $$PWD/QJSON/src/libQJSON/Private/qjsonparser_p.h \
    $$PWD/QJSON/src/libQJSON/Private/qjson_p.h

# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- #
SOURCES += \
    $$PWD/QJSON/src/libQJSON/Private/qjsonwriter.cpp \
    $$PWD/QJSON/src/libQJSON/Private/qjsonvalue.cpp \
    $$PWD/QJSON/src/libQJSON/Private/qjsonparser.cpp \
    $$PWD/QJSON/src/libQJSON/Private/qjsonobject.cpp \
    $$PWD/QJSON/src/libQJSON/Private/qjsondocument.cpp \
    $$PWD/QJSON/src/libQJSON/Private/qjsonarray.cpp \
    $$PWD/QJSON/src/libQJSON/Private/qjson.cpp
# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+- #
