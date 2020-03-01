cmake_minimum_required(VERSION 3.13)
project(type_traits)

# Set up Conan package manager =========================================================================================
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Compiler settings ====================================================================================================
set(CMAKE_CXX_STANDARD 17)

# Glob sources =========================================================================================================
file(GLOB sources_test "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")

# Targets ==============================================================================================================
add_library   (${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE "src")

add_executable(${PROJECT_NAME}_test ${sources_test})
target_include_directories(${PROJECT_NAME}_test PRIVATE "src")

# Linking ==============================================================================================================
target_link_libraries(${PROJECT_NAME}_test ${CONAN_LIBS})