cmake_minimum_required(VERSION 3.15)

project(AlienInvasion)

set(CMAKE_CXX_STANDARD 20)

# Find SFML library
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system audio)

# Find Google Test
find_package(GTest REQUIRED)

# Set the source files for the main game
set(GAME_SOURCES
    src/Player.cpp
    src/Alien.cpp
    src/Projectile.cpp
    src/GameState.cpp
)

# Set the source files for the tests
set(TEST_SOURCES
    tests/TestAlien.cpp
    tests/TestPlayer.cpp
    tests/TestProjectile.cpp
    tests/TestGameLogic.cpp
    tests/TestCollision.cpp
)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create the main game executable
add_executable(alien_invasion src/main.cpp ${GAME_SOURCES})
target_link_libraries(alien_invasion sfml-graphics sfml-window sfml-system sfml-audio)

# Create the test executable
add_executable(tests ${TEST_SOURCES} ${GAME_SOURCES})
target_link_libraries(tests GTest::GTest GTest::Main pthread sfml-graphics sfml-window sfml-system sfml-audio)

# Enable testing
enable_testing()
add_test(NAME RunTests COMMAND tests)
