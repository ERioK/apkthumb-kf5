# apkthunb-kf5
thumbnail for apk file using aapt

aapt is needed

link one to /usr/bin

Installation

cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr -DLIB_INSTALL_DIR=lib -DKDE_INSTALL_USE_QT_SYS_PATHS=ON -DBUILD_TESTING=OFF CMakeLists.txt

make 

sudo make install
