set( testname WebSocketResponseTask )
set( testmodules Test Core WebSockets)
set( testlibraries ProtoBufGenLib WebSocket-Resources-Qt )

find_package( Qt5Core REQUIRED )
find_package( Qt5Test    REQUIRED )
find_package( Qt5WebSockets REQUIRED )

set( Test_SOURCES
   tst_${testname}Test.cpp
)

add_executable( ${testname} ${Test_SOURCES} )
qt5_use_modules( ${testname} ${testmodules} )
target_link_libraries( ${testname} ${testlibraries} )

add_test( NAME ${testname} COMMAND ${testname} )
