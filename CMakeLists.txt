cmake_minimum_required(VERSION 3.15)

project(DataStructs LANGUAGES CXX)

# ========================
# 基本配置
# ========================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 可选：开启优化（刷算法建议开）
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

# ========================
# 自动收集所有源文件（核心）
# ========================
file(GLOB_RECURSE SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# 关键：当有新文件加入时自动重新配置
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# ========================
# 生成可执行文件
# ========================
add_executable(main_exec ${SRC_FILES})

# ========================
# 头文件路径
# ========================
target_include_directories(main_exec PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# ========================
# （可选）编译警告（建议开启）
# ========================
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(main_exec PRIVATE -Wall -Wextra -Wpedantic)
endif()