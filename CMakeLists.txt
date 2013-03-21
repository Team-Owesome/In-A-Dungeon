cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

project(InADungeon)
file(GLOB_RECURSE sources "src/*.cpp")
file(GLOB_RECURSE headers "src/*.hpp")

set(INCLUDE_DIRS, "")
foreach(headerFile ${headers})
		get_filename_component(dir ${headerFile} PATH)
		list(APPEND INCLUDE_DIRS ${dir})
endforeach()


list(REMOVE_DUPLICATES INCLUDE_DIRS)

# Libraries
if(APPLE)
	set(SFML_STATIC_LIBRARIES false)
else()
	set(SFML_STATIC_LIBRARIES true)
endif()

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SFML 2 COMPONENTS network system window graphics audio)
find_package(GLM REQUIRED)

include_directories(${GLEW_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})
include_directories(${GLM_INCLUDE_DIR})

# C++11
set (CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -g3 -Wall -O0")

add_executable(${PROJECT_NAME} ${sources} ${headers})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${SFML_LIBRARIES})

set(files ${headers} ${sources})

foreach(file ${files})
		set(groupName "")

		get_filename_component(dir ${file} PATH)
		get_filename_component(dirName ${dir} NAME)

		while(NOT dirName STREQUAL "src")

			set(groupName "${dirName}\\${groupName}")

			get_filename_component(dir ${dir} PATH)
			get_filename_component(dirName ${dir} NAME)


		endwhile()

		set(groupName "src\\${groupName}")
		source_group(${groupName} FILES ${file})
endforeach()
