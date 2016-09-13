cmake_minimum_required(VERSION 2.8.9)
project(ListaDoblementeLigada)

include_directories(include)

set(SOURCES src/Nodo.cpp src/main.cpp src/ListaDoble.cpp)

add_executable(lista_doble ${SOURCES})
