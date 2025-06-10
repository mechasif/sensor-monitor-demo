# Build the test executable

# Test source files
set(TEST_FILES
    test_sensor.cpp
    ../src/Sensor.cpp
)

# Create test executable
add_executable(sensor_tests ${TEST_FILES})

# Include source directory
target_include_directories(sensor_tests PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Link Catch2
target_link_libraries(sensor_tests PRIVATE Catch2::Catch2WithMain)

# Register test with CTest
add_test(NAME sensor_tests COMMAND sensor_tests)