cmake_minimum_required(VERSION 3.15)

project(AlienInvasion)

set(CMAKE_CXX_STANDARD 20)

# Automatically look for SFML if it is installed on the system
find_package(SFML 2.6.0 REQUIRED COMPONENTS graphics window system)

# Automatically look for Google Test
find_package(GTest REQUIRED)

# Set the source files for the main game
set(SOURCES
    src/main.cpp
    src/Player.cpp
    src/Alien.cpp
    src/Projectile.cpp
)

# Set the source files for the tests
set(TEST_SOURCES
    tests/TestAlien.cpp
    tests/TestPlayer.cpp
    tests/TestProjectile.cpp
    tests/TestGameLogic.cpp
    tests/TestCollision.cpp
)

# Include directories for headers
include_directories(include)

# Create the main game executable
add_executable(alien_invasion ${SOURCES})
target_link_libraries(alien_invasion sfml-graphics sfml-window sfml-system)

# Create the test executable (include both test and game sources)
add_executable(tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(tests GTest::GTest GTest::Main pthread sfml-graphics sfml-window sfml-system)

# Enable testing
enable_testing()
add_test(NAME RunTests COMMAND tests)
