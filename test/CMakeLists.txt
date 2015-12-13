set( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR} )

include_directories( .. )

set(apkthumbnailtest_SRCS apkthumbtest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/../apkthumb.cpp
)


add_executable(apkthumbnailtest ${apkthumbnailtest_SRCS} )

target_link_libraries(apkthumbnailtest KF5::KIOCore KF5::Archive KF5::KIOWidgets Qt5Gui)