cmake_minimum_required(VERSION 3.3)
project(containers)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall")

set(SOURCE_FILES
        src/main.c
        src/containers/list.c src/containers/list.h
        src/containers/queue.c src/containers/queue.h)

add_executable(containers ${SOURCE_FILES})

# set the language to be C instead of C++
set_target_properties(containers PROPERTIES LINKER_LANGUAGE C)