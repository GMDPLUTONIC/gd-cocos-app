add_library(cocos2d INTERFACE)

if (NOT DEFINED ENV{GEODE_SDK})
	message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
	message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

set(GEODE_LOADER_PATH $ENV{GEODE_SDK}/loader)

target_include_directories(cocos2d INTERFACE
	${GEODE_LOADER_PATH}/include/Geode/cocos/include
	${GEODE_LOADER_PATH}/include/Geode/cocos/extensions
	${GEODE_LOADER_PATH}/include
)

target_compile_definitions(cocos2d INTERFACE -DGEODE_IS_MEMBER_TEST=1)

target_link_libraries(cocos2d INTERFACE
	${GEODE_LOADER_PATH}/include/link/win64/libcocos2d.lib
	${GEODE_LOADER_PATH}/include/link/win64/libExtensions.lib
)
