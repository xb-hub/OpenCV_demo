# OpenCV_demo  
- 环境:ubuntu 16.04,ubuntu 18.04
# OpenCV安装
## 安装依赖
```
* 编辑/etc/apt/source.list，取消屏蔽的src源
* sudo apt-get update
* sudo apt-get build-dep opencv
* sudo apt-get install libeigen3-dev ffmpeg doxygen liblapacke-dev libgoogle-glog-dev libgstreamer1.0-dev libgstreamer0.10-dev libavresample-dev libopenblas-dev libgphoto2-dev libgtk-3-dev libv4l-dev python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev liblapacke-dev libgflags-dev libjpeg-dev libtiff-dev libpng-dev ccache libprotobuf-dev libgoogle-glog-dev libharfbuzz-dev
```

## 从源码安装opencv4.1.0，并安装opencv_contrib4.1.0贡献包
```
cd ~/libsrc/opencv-4.1.0/
mkdir build
cd build
cmake -D OPENCV_GENERATE_PKGCONFIG=YES -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-4.1.0/modules ..
make -j4 #如果安装了matlab，速度可能会非常慢，大约一小时左右
vim unix-install/opencv.pc #编辑该文件，搜索-lippicv，将其删除
sudo make install
sudo ldconfig #库文件立即生效，不用重启
```
 
## 删除
```
sudo make uninstall
```

## 卸载
在build目录下：
```
* sudo make uninstall
* cd ..
* sudo rm -r build
```

# Demo编译
## g++编译:
```
* hsv_detector.cpp编译: g++ hsv_detector.cpp `pkg-config --cflags --libs opencv4` -o hsv_detector

* rgb_detector.cpp编译: g++ rgb_detector.cpp `pkg-config --cflags --libs opencv4` -o rgb_detector

如果报错显示需要使用c++11:
* hsv_detector.cpp编译:    g++ hsv_detector.cpp `pkg-config --cflags --libs opencv4` -o hsv_detector -std=c++11

* rgb_detector.cpp编译:    g++ rgb_detector.cpp `pkg-config --cflags --libs opencv4` -o rgb_detector -std=c++11
```

## cmake-make编译:
```
* mkdir cmake_build
* cd cmake_build
* cmake ..
* make
```
- **cmake_build用于存放cmake生成的中间文件和Makefile**
- **make_build用存放生成的可执行文件**