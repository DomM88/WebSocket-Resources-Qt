find_package( Protobuf REQUIRED )
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS protobuf/SubProtocol.proto)
add_library(ProtoBufGenLib ${PROTO_SRCS} ${PROTO_HDRS} )
target_link_libraries(ProtoBufGenLib ${PROTOBUF_LIBRARIES})

add_subdirectory(src)
