cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(BUILD_TESTS "Build tests" OFF)

include("cmake/HunterGate.cmake")

project(insert)
set(INSERT_VERSION_MAJOR 0)
set(INSERT_VERSION_MINOR 1)
set(INSERT_VERSION_PATCH 0)
set(INSERT_VERSION_TWEAK 1)
set(INSERT_VERSION ${INSERT_VERSION_MAJOR}.${INSERT_VERSION_MINOR}.${INSERT_VERSION_PATCH}.${INSERT_VERSION_TWEAK})
set(INSERT_VERSION_STRING "v${INSERT_VERSION}")


# In case if I decide to divide kurs_test.cpp to multiple files
# file(GLOB ${PROJECT_NAME}_INSERT_SOURCES sources/*.cpp)
set(${PROJECT_NAME}_INSERT_SOURCES sources/kurs_test.cpp)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_INSERT_SOURCES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)


if(BUILD_EXAMPLES)
  file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
  foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} print)
    install(TARGETS ${EXAMPLE_NAME}
      RUNTIME DESTINATION bin
    )
  endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

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
 
include(CPackConfig.cmake)
