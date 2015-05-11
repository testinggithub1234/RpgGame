#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 3.1)
project(RpgGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/andrei/ClionProjects/RpgGame/Binaries")
set(SOURCE_FILES Main.cpp)

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)

include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "RpgGame")
add_executable(RpgGame ${SOURCE_FILES} Engine.cpp Engine.h Map/Level.cpp Map/Level.h Player/Player.cpp Player/Player.h Utilities/Fps.h Collision/Collision.h Map/Npc/Npc.cpp Map/Npc/Npc.h Manager/EntityManager.cpp Manager/EntityManager.h Manager/TextureManager.cpp Manager/TextureManager.h Animation/Animation.cpp Animation/Animation.h Animation/AnimatedSprite.cpp Animation/AnimatedSprite.h Collision/Collision.cpp Collision/Collision.h Map/TileMap.cpp Map/TileMap.h Actor/Actor.cpp Actor/Actor.h Utilities/Parser.cpp Utilities/Parser.h Map/Terrain.cpp Map/Terrain.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})


