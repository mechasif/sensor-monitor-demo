# Build the main executable

# Source files
set(SRC_FILES
    Sensor.cpp
    Monitor.cpp
    WebAPI.cpp
    Logger.cpp
    main.cpp
)

# Create executable
add_executable(ssm ${SRC_FILES})

# Include directories
target_include_directories(ssm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link external libraries
target_link_libraries(ssm PRIVATE
    pthread
    httplib::httplib
)

# Compiler options
target_compile_options(ssm PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Weffc++
    -ffunction-sections
    -fdata-sections
    -Os
)

# Linker options
target_link_options(ssm PRIVATE
    -Wl,--gc-sections
)