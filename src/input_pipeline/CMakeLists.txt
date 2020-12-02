find_package(OpenCV 2.4.13.6 REQUIRED core imgproc highgui calib3d objdetect NO_DEFAULT_PATH)
find_package(dlib)
find_package(glm)
file(GLOB SOURCE_FILES *.cpp *.h analyzers/*.cpp analyzers/*.h)

add_library(InputPipeline ${SOURCE_FILES})
target_link_libraries(InputPipeline ${OpenCV_LIBS} glm dlib::dlib -lblas -llapack)
