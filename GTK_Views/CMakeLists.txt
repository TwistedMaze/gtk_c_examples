cmake_minimum_required(VERSION 3.10)
project(GtkMultiView VERSION 1.0)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})

add_definitions(${GTK4_CFLAGS_OTHER})

set(SOURCES
    main.c 
    main_view.c 
    second_view.c)

add_executable(${PROJECT_NAME} ${SOURCES}
)

target_include_directories(GtkMultiView PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_libraries(GtkMultiView PRIVATE ${GTK4_LIBRARIES})
# target_compile_options(GtkMultiView PRIVATE ${GTK4_CFLAGS_OTHER})

configure_file(styles.css ${CMAKE_BINARY_DIR}/style.css COPYONLY)
