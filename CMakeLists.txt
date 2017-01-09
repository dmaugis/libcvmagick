cmake_minimum_required(VERSION 2.6)
project(cvmagick)
find_package(OpenCV REQUIRED )
find_package(ImageMagick COMPONENTS Magick++ convert)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(ROOT ~)

set(cvmagick_SOURCES	
    cvmagick.cpp
    )

set(cvmagick_HEADERS
    include/cv2x/cvmagick.h
   )

include_directories(.)
include_directories(./include)
include_directories(./include/cv2x)
include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${ImageMagick_INCLUDE_DIRS})
include_directories(${ImageMagick_Magick++_INCLUDE_DIR})
	

add_library (cvmagick SHARED ${cvmagick_SOURCES})
add_library (cvmagick_static STATIC ${cvmagick_SOURCES})

set_target_properties(cvmagick_static PROPERTIES OUTPUT_NAME cvmagick)


install (TARGETS cvmagick
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib
         RUNTIME DESTINATION bin)

install (TARGETS cvmagick_static
         ARCHIVE DESTINATION lib
         LIBRARY DESTINATION lib
         RUNTIME DESTINATION bin)


install(FILES ${cvmagick_HEADERS} DESTINATION include/cv2x )

#link_directories (${ROOT}/usr/local/lib)
#add_executable(im2iglrgb    ${im2iglrgb_SOURCES})
#target_link_libraries(im2iglrgb ${PCL_LIBRARIES}  ${OpenCV_LIBS} ${Boost_LIBRARIES} ${GSL_LIBRARIES} ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} ${ImageMagick_LIBRARIES} cvbk cvm pclx cblas)
#install(TARGETS im2iglrgb RUNTIME DESTINATION bin)
