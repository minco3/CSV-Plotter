cmake_minimum_required(VERSION 3.0.0)
project(graphingthing VERSION 0.1.0)

include(CTest)
enable_testing()

file(COPY "${CMAKE_SOURCE_DIR}/resources" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

set(INCLUDES_FOLDER includes)
FILE(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}   "${INCLUDES_FOLDER}/*.cpp" )

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main main.cpp ${SOURCE_FILES})

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(main ${SFML_LIBRARIES})
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
