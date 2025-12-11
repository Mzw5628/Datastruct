set(LINKED_SRCS
    linked_list.cpp
)
add_library(linked_list_lib ${LINKED_SRCS})

target_include_directories(linked_list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
