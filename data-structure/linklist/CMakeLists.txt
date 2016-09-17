cmake_minimum_required(VERSION 2.8)

project(LinkList)

aux_source_directory(. DIR_SCRS)

add_subdirectory(linklist)

add_executable(Main ${DIR_SCRS})
target_link_libraries(Main linklist)