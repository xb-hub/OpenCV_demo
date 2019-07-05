cmake_minimum_required(VERSION 2.8)
project( OpenCV_demo )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

aux_source_directory(hsv_detector HSV)
aux_source_directory(rgb_detector RGB)

set(EXECUTABLE_OUTPUT_PATH ../make_build)

add_executable( hsv_detector ${HSV} )
target_link_libraries( hsv_detector ${OpenCV_LIBS} )

add_executable( rgb_detector ${RGB} )
target_link_libraries( rgb_detector ${OpenCV_LIBS} )