cmake_minimum_required(VERSION 3.26)
project(Hello_SDL2)

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR "${CMAKE_CURRENT_LIST_DIR}/SDL2")
set(SDL2_IMAGE_DIR ${SDL2_DIR})
set(SDL2_TTF_DIR ${SDL2_DIR})
set(SDL2_MIXER_DIR ${SDL2_DIR})

set(SDL2_INCLUDE_DIRS "${SDL2_DIR}/include")

set(SDL2_LIBRARIES
        "${SDL2_DIR}/lib/x64/SDL2.lib"
        "${SDL2_DIR}/lib/x64/SDL2main.lib"
        "${SDL2_DIR}/lib/x64/SDL2_image.lib"
        "${SDL2_DIR}/lib/x64/SDL2_mixer.lib"
        "${SDL2_DIR}/lib/x64/SDL2_ttf.lib"
)

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_MIXER REQUIRED)
find_package(SDL2_TTF REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_DIR}/lib/x64)

add_executable(Hello_SDL2 main.cpp)

target_include_directories(Hello_SDL2 PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(Hello_SDL2 ${SDL2_LIBRARIES})

# If Release, turn off console
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set_target_properties(Hello_SDL2 PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
endif ()
