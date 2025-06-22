# CMakeList.txt : CMake project for datastructures-implementations
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Project 
project (datastructures-implementations LANGUAGES C)

# Build Main
add_executable (${PROJECT_NAME} main.c)

# Add Core Library
add_subdirectory(Core)
target_link_libraries(${PROJECT_NAME} PRIVATE Core)

# VS Gen stuff
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET datastructures-implementations PROPERTY CXX_STANDARD 20)
endif()


