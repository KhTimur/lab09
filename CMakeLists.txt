cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(BUILD_TESTS "Build tests" OFF)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.123.tar.gz"
    SHA1 "57d07480686f82ddc916a5980b4f2a18e5954c2b"
)

project(insert)
set(INSERT_VERSION_MAJOR 0)
set(INSERT_VERSION_MINOR 1)
set(INSERT_VERSION_PATCH 0)
set(INSERT_VERSION_TWEAK 0)
set(INSERT_VERSION 
${INSERT_VERSION_MAJOR}.${INSERT_VERSION_MINOR}.${INSERT_VERSION_PATCH}.${INSERT_VERSION_TWEAK})
set(INSERT_VERSION_STRING "v${INSERT_VERSION}")


# In case if I decide to divide kurs_test.cpp to multiple files
# file(GLOB ${PROJECT_NAME}_INSERT_SOURCES sources/*.cpp)
set(${PROJECT_NAME}_INSERT_SOURCES sources/kurs_test.cpp)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_INSERT_SOURCES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)


install(TARGETS insert
    EXPORT insert-config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT insert-config DESTINATION cmake)




install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(EXPORT insert-config DESTINATION cmake)

if(BUILD_TESTS)
  hunter_add_package(Catch)
  find_package(Catch CONFIG REQUIRED)
  enable_testing()
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check ${PROJECT_NAME} Catch::Catch )
  add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes")

endif()

