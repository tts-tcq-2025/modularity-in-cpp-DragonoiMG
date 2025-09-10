cmake_minimum_required(VERSION 3.10)
project(TelCoColorCoder)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(inc)

# Source files
set(SOURCES
    src/ColorDefinitions.cpp
    src/ColorPair.cpp
    src/ColorCoder.cpp
    src/ReferenceManual.cpp
)

# Test source files
set(TEST_SOURCES
    tests/ColorPairTests.cpp
    tests/ReferenceManualTests.cpp
    tests/TestRunner.cpp
)

# Create library from core sources
add_library(ColorCoderLib ${SOURCES})

# Main executable
add_executable(color_coder src/main.cpp)
target_link_libraries(color_coder ColorCoderLib)

# Test executable
add_executable(test_runner ${TEST_SOURCES})
target_link_libraries(test_runner ColorCoderLib)

# Enable testing
enable_testing()
add_test(NAME ColorCoderTests COMMAND test_runner)
