cmake_minimum_required(VERSION 3.15)
project(DataStructs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 将模块目录加入构建（模块化方式）
add_subdirectory(src/linked_list)
add_subdirectory(src/Stack)
add_subdirectory(src/Queue)

# 顶层可执行文件
add_executable(main_exec src/main.cpp)

# 链接各模块库
target_link_libraries(main_exec PRIVATE linked_list_lib)
target_link_libraries(main_exec PRIVATE ds_stack_lib)
target_link_libraries(main_exec PRIVATE ds_queue_lib)

# 让 各链接库 能被找到（把 src 设为 include 路径）
target_include_directories(main_exec PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
