cmake_minimum_required(VERSION 3.5)

project(Desafio2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Desafio2 main.cpp
    ListaDeEstacion.h ListaDeEstacion.cpp
    Linea.h Linea.cpp
    NodoLinea.h NodoLinea.cpp
    NodoEst.h NodoEst.cpp
    Estacion.h Estacion.cpp
    ListaDeLinea.h ListaDeLinea.cpp
    Red.h Red.cpp)

include(GNUInstallDirs)
install(TARGETS Desafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
