cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(application VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)
	 
file(GLOB_RECURSE TARGET_SOURCES
     src/*.hpp
	 src/*.h
	 src/*.cpp
	 src/*.ui)
	
file(GLOB_RECURSE TARGET_QRC_FILES
    resources/*.qrc)

source_group("resources" FILES ${TARGET_QRC_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES
	${TARGET_SOURCES})
	
add_executable(${PROJECT_NAME} WIN32
	${TARGET_SOURCES}
	${TARGET_QRC_FILES}
	)
	
unset(TARGET_SOURCES)
unset(TARGET_QRC_FILES)

target_include_directories(${PROJECT_NAME}
	PUBLIC src)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		Qt5::Widgets
	)
	
if(WIN32)
    # Run winddeployqt if it can be found
    find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt HINTS ${QTDIR} ENV QTDIR PATH_SUFFIXES bin)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${WINDEPLOYQT_EXECUTABLE} $<TARGET_FILE:${PROJECT_NAME}>)
endif()
