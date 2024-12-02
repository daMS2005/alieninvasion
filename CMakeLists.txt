cmake_minimum_required(VERSION 3.15)

project(AlienInvasion)

set(CMAKE_CXX_STANDARD 20)

# Automatically look for SFML if it is installed on the system
find_package(SFML 2.6.0 REQUIRED COMPONENTS graphics window system)


# Set the source files
set(SOURCES
    main.cpp
    Player.cpp
    Alien.cpp
    Projectile.cpp
)

# Create executable
add_executable(alien_invasion ${SOURCES})

# Link SFML libraries
target_link_libraries(alien_invasion sfml-graphics sfml-window sfml-system)
