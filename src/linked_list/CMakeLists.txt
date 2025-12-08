# src/linked_list/CMakeLists.txt
# 将本目录下所有 cpp 自动收集进库（CONFIGURE_DEPENDS 在添加/删除源文件时会触发重新 configure）
file(GLOB LINKED_SRCS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 创建库 target，名字约定为 linked_list_lib
add_library(linked_list_lib ${LINKED_SRCS})

# 暴露 include 路径（PUBLIC 表示 link 到该库的 target 会继承这个 include path）
target_include_directories(linked_list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
