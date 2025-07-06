# CMakeList.txt : CMake project for datastructures-implementations core library
cmake_minimum_required (VERSION 3.10)

# Grab all source files

# Queue Source Files
set (QUEUE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/queues/int-circ-queue.c"   
    "${CMAKE_CURRENT_SOURCE_DIR}/src/queues/generic-ll-queue.c"  
)

# Stack Source Files
set (STACK_SOURCES   
    "${CMAKE_CURRENT_SOURCE_DIR}/src/stacks/int-arr-stack.c"
)

# Combine source files
add_library(core STATIC
    ${QUEUE_SOURCES}
    ${STACK_SOURCES}
)

# Expose headers
target_include_directories(core
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/common"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/queues"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/stacks"
)
