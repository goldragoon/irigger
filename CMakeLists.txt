cmake_minimum_required(VERSION 3.0)
project(irigger)
find_package(OpenCV 2.4.13.6 REQUIRED core imgproc highgui calib3d objdetect NO_DEFAULT_PATH)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src/input_pipeline)
add_subdirectory(src/render)

add_executable(irigger src/main.cpp)
target_link_libraries(irigger ${OpenCV_LIBS} InputPipeline Render )
