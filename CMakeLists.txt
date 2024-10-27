cmake_minimum_required(VERSION 3.21)

project(my-cocos-app)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my-cocos-app
	src/main.cpp
	src/AppDelegate.cpp
	src/HelloWorldScene.cpp
)

if (WIN32)
	# This allows you to compile in debug mode
	add_definitions(-D_HAS_ITERATOR_DEBUGGING=0)
	target_compile_definitions(${PROJECT_NAME} INTERFACE _HAS_ITERATOR_DEBUGGING=0)
endif()

include(cocos.cmake)

target_link_libraries(my-cocos-app PRIVATE cocos2d)
