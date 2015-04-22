cmake_minimum_required(VERSION 2.8)
project( code2D )
find_package( OpenCV REQUIRED )
FILE( GLOB SOURCE "./*.cpp" )
add_executable( code2D ${SOURCE} )
target_link_libraries( code2D ${OpenCV_LIBS} )

