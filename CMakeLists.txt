cmake_minimum_required(VERSION 3.3)
project(Mini_Projecto_1)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall")

set(SOURCE_FILES
        src/main.c
        src/prefix.h src/containers/list.c src/containers/list.h)

add_executable(Mini_Projecto_1 ${SOURCE_FILES})

# set the language to be C instead of C++
set_target_properties(Mini_Projecto_1 PROPERTIES LINKER_LANGUAGE C)