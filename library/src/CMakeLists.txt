project(WebSocket-Resources-Qt)

find_package( Qt5Core REQUIRED )
find_package( Qt5WebSockets REQUIRED )

set( Project_SRC
   WebSocketClient.cpp
   WebSocketResponseTask.cpp

   messages/WebSocketMessage.h
   messages/WebSocketMessageFactory.h
   messages/WebSocketRequestMessage.h
   messages/WebSocketResponseMessage.h

   messages/WebSocketMessage.cpp
   messages/WebSocketMessageError.cpp
   messages/protobuf/ProtoBufWebSocketMessage.cpp
   messages/protobuf/ProtoBufWebSocketRequestMessage.cpp
   messages/protobuf/ProtoBufWebSocketResponseMessage.cpp
   messages/protobuf/ProtobufWebSocketMessageFactory.cpp

   ../protobuf/SubProtocol.proto
)

add_library(${PROJECT_NAME} ${Project_SRC})
target_link_libraries(${PROJECT_NAME} ProtoBufGenLib)

qt5_use_modules(${PROJECT_NAME} Core WebSockets )
