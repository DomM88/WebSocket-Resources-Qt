project(WebSocket-Resources-Qt)

find_package( Qt5Core REQUIRED )
find_package( Qt5Concurrent REQUIRED )

set( Project_SRC
   WebSocketClient.cpp

   messages/WebSocketMessage.h
   messages/WebSocketMessageFactory.h
   messages/WebSocketRequestMessage.h
   messages/WebSocketResponseMessage.h

   messages/WebSocketMessage.cpp
   messages/WebSocketMessageError.cpp
   messages/protobuf/ProtoBufWebSocketMessage.cpp
   messages/protobuf/ProtoBufWebSocketRequestMessage.cpp
   messages/protobuf/ProtoBufWebSocketResponseMessage.cpp
)

add_library(${PROJECT_NAME} ${Project_SRC})

qt5_use_modules(${PROJECT_NAME} Core Concurrent )
