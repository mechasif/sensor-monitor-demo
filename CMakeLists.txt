cmake_minimum_required(VERSION 3.28)
project(SensorMonitor VERSION 0.1.0 LANGUAGES CXX)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing via CTest
include(CTest)
enable_testing()

# Enable FetchContent
include(FetchContent)

# Fetch cpp-httplib
FetchContent_Declare(
    httplib
    GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
    GIT_TAG v0.19.0
)

FetchContent_MakeAvailable(httplib)

# Fetch Catch2 (for tests)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)