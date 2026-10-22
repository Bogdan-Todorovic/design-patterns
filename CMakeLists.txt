cmake_minimum_required(VERSION 3.20)

project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(creational/singleton/cpp)
add_subdirectory(creational/factory-method/cpp)
add_subdirectory(creational/builder/cpp)
add_subdirectory(creational/abstract-factory/cpp)
add_subdirectory(creational/prototype/cpp)

add_subdirectory(behavioral/command/cpp)
add_subdirectory(behavioral/mediator/cpp)
add_subdirectory(behavioral/memento/cpp)
add_subdirectory(behavioral/observer/cpp)
add_subdirectory(behavioral/strategy/cpp)
add_subdirectory(behavioral/template-method/cpp)

add_subdirectory(structural/adapter/cpp)
add_subdirectory(structural/bridge/cpp)
add_subdirectory(structural/composite/cpp)
add_subdirectory(structural/decorator/cpp)
add_subdirectory(structural/facade/cpp)
add_subdirectory(structural/flyweight/cpp)
add_subdirectory(structural/proxy/cpp)
