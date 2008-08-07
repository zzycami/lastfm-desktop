debug:macx-xcode {
    QT = core gui network phonon xml webkit

    TEMPLATE = app
    TARGET = Last.fm
    ICON = app/client/mac/client.icns
	VERSION	= 2.0.0
	QMAKE_INFO_PLIST = app/client/mac/Info.plist.in

    include( $$SRC_DIR/common/qmake/include.pro )

    DIRS = app/client lib/core lib/ws lib/unicorn lib/moose lib/radio lib/types lib/scrobble

    for( dir, DIRS ) {
        SOURCES += $$findSources( cpp, $$dir )
        HEADERS += $$findSources( h, $$dir )
        FORMS += $$findSources( ui, $$dir )
		RESOURCES += $$findSources( qrc, $$dir )	
    }

    SOURCES += common/c++/Logger.cpp
    SOURCES -= lib/core/UnicornUtils_win.cpp

    INCLUDEPATH += app/client
    LIBS += -framework SystemConfiguration -framework CoreServices
}
else {
    TEMPLATE = subdirs

    SUBDIRS += app/client/appclient.pro \ #LEAVE THIS FIRST! --mxcl
               lib/core/libcore.pro \
               lib/ws/libws.pro \
               lib/types/libtypes.pro \
               lib/unicorn/libunicorn.pro \               
               lib/moose/libmoose.pro \
               lib/radio/libradio.pro \
               lib/scrobble/libscrobble.pro
}
