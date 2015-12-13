cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)
project(apkthumb-kf5)

set(QT_MIN_VERSION "5.2.0")
find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(FeatureSummary)

find_package(KF5 REQUIRED COMPONENTS KIO Archive)
#find_package(Qt5 REQUIRED COMPONENTS Gui)

set(apkthumb_SRCS apkthumb.cpp)

add_library(apkthumb MODULE ${apkthumb_SRCS})

target_link_libraries(apkthumb KF5::KIOCore KF5::Archive KF5::KIOWidgets)

install(TARGETS apkthumb DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES  apkthumb.desktop DESTINATION ${SERVICES_INSTALL_DIR})

if(BUILD_TESTING)
    add_subdirectory(test)
endif()


#cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr -DLIB_INSTALL_DIR=lib -DKDE_INSTALL_USE_QT_SYS_PATHS=ON -DBUILD_TESTING=OFF CMakeLists.txt