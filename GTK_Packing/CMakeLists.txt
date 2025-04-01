cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(HelloWorldGTK VERSION 1.0)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

# Include directories
include_directories(${GTK4_INCLUDE_DIRS} inc)  # Add your inc directory
link_directories(${GTK4_LIBRARY_DIRS})

# Set compile flags
add_definitions(${GTK4_CFLAGS_OTHER})

# Source files
set(SOURCES
    src/main.c
    src/gtk_callbacks.c          # Update this list with your source files
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link GTK4
target_link_libraries(${PROJECT_NAME} ${GTK4_LIBRARIES})

# Modern method for include directories (optional, recommended)
target_include_directories(${PROJECT_NAME} PRIVATE inc)

