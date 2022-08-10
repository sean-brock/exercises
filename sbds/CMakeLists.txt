cmake_minimum_required(VERSION 3.7...3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(sbds  VERSION 1.0
              DESCRIPTION "Data Structures"
              LANGUAGES CXX)

add_library(sbds_module INTERFACE)
target_include_directories(sbds_module INTERFACE include/)
install(TARGETS sbds_module)

add_subdirectory(apps)