set(LINKED_SRCS
    linked_list.cpp
    circle_list.cpp
    doubly_list.cpp
)

add_library(ds_list_lib ${LINKED_SRCS})

target_include_directories(ds_list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
