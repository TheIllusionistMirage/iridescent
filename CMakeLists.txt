cmake_minimum_required(VERSION 2.6)
project(iridescent)

add_executable(iridescent main.cpp)

install(TARGETS iridescent RUNTIME DESTINATION bin)
