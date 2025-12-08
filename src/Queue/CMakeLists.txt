# 将本目录下所有 cpp 自动收集进库（CONFIGURE_DEPENDS 在添加/删除源文件时会触发重新 configure）
file(GLOB LINKED_SRCS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(ds_queue_lib ${LINKED_SRCS})

target_include_directories(ds_queue_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})