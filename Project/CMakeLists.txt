# Projektets namn
project (Project)
# Minsta tillåtna CMake version
cmake_minimum_required(VERSION 3.2)

# Kompilera med stöd för C++ 11
set (CMAKE_CXX_STANDARD 11)

# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Project ${SOURCES} src/Time.cpp include/Time.h src/Song.cpp include/Song.h src/Album.cpp include/Album.h src/MenuItem.cpp include/MenuItem.h src/Menu.cpp include/Menu.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Project PRIVATE include/ ../_Resources/_libs/)