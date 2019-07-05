# OpenCV_demo
ubuntu编译:
```
* hsv_detector.cpp编译: g++ hsv_detector.cpp `pkg-config --cflags --libs opencv4` -o hsv_detector

* rgb_detector.cpp编译: g++ rgb_detector.cpp `pkg-config --cflags --libs opencv4` -o rgb_detector

如果报错显示需要使用c++11:
* hsv_detector.cpp编译:    g++ hsv_detector.cpp `pkg-config --cflags --libs opencv4` -o hsv_detector -std=c++11

* rgb_detector.cpp编译:    g++ rgb_detector.cpp `pkg-config --cflags --libs opencv4` -o rgb_detector -std=c++11
```
[opencv安装](https://github.com/xb-hub/my-study)