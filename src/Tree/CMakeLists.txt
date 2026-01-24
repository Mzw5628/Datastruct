set(SRCS 
    tree.cpp
    BTtree.cpp
    BStree.cpp
)
# 创建库 target，名字约定为 ds_stack_lib
add_library(ds_tree_lib ${SRCS})

# 暴露 include 路径（PUBLIC 表示 link 到该库的 target 会继承这个 include path）
target_include_directories(ds_tree_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})