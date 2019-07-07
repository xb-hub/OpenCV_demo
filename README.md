# OpenCV_demo  
- 环境:ubuntu 16.04,ubuntu 18.04
- [opencv安装](https://github.com/xb-hub/my-study)
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