# CMakeList.txt : CMake project for datastructures-implementations core library
cmake_minimum_required (VERSION 3.8)

# Grab all source files

# Stack Source Files
set (STACK_SOURCES   
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Stacks/sized-int-stack.c"
)

# Queue Source Files
set (QUEUE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/Queues/sized-int-queue.c"    
)

# Combine source files
add_library(Core STATIC
    ${STACK_SOURCES}
    ${QUEUE_SOURCES}
)

# Expose headers
target_include_directories(Core
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/Include/Stacks"
    "${CMAKE_CURRENT_SOURCE_DIR}/Include/Queues"
)