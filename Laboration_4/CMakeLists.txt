# Projektets namn
project (Laboration_4)
# Minsta tillåtna CMake version
cmake_minimum_required(VERSION 3.2)

# Kompilera med stöd för C++ 11
set (CMAKE_CXX_STANDARD 11)

# Add source directory
aux_source_directory(src/ SOURCES)

# Create executable for the run configuration
add_executable(${PROJECT_NAME}-Laboration_4 ${SOURCES} src/IntArray.cpp include/IntArray.h src/Program.cpp include/Program.h src/Sort.cpp include/Sort.h)

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directory to the configuration
target_include_directories(${PROJECT_NAME}-Laboration_4 PRIVATE include/ ../_Resources/_libs/)