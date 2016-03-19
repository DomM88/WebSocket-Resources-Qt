set( testname WebSocketMessageError )
set( testmodules Test Core )
set( testlibraries ProtoBufGenLib WebSocket-Resources-Qt )

find_package( Qt5Core REQUIRED )
find_package( Qt5Test    REQUIRED )

set( Test_SOURCES
   tst_${testname}Test.cpp
)

add_executable( ${testname} ${Test_SOURCES} )
qt5_use_modules( ${testname} ${testmodules} )
target_link_libraries( ${testname} ${testlibraries} )

add_test( NAME ${testname} COMMAND ${testname} )
