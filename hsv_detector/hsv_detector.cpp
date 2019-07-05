
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<iostream>
 
using namespace cv;
using namespace std;
 
void hsv_detector(Mat image)
{
    Mat hsvImg;

    //将RGB颜色空间转换为HSV颜色空间
    cvtColor(image, hsvImg, COLOR_BGR2HSV); //CV_BGR2YCrCb

    imshow("hsv", hsvImg);

    int minH = 0; //26
    int maxH = 0; //34

    int minS = 0; //
    int maxS = 0;

    int minV = 0; //200
    int maxV = 0;

    Mat yellowImg, blueImg, redImg, greenImg;

    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
            case 0: //黄色
                minH = 16; //26
                maxH = 35; //34

                minS = 160; //
                maxS = 255;

                minV = 50; //200
                maxV = 255;

                // inRange(原图像, 最小值的范围, 最大值的范围, 输出图像); //输出图像是黑白二值图像，其中 最小值<=像素点<=最大值 的像素点是白色
                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), yellowImg); //Threshold the image
                imshow("yellow", yellowImg);
                break;

            case 1: //蓝色
                 minH = 70; //26
                maxH = 120; //34

                minS = 150; //
                maxS = 255;

                minV = 50; //200
                maxV = 255;

                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), blueImg); //Threshold the image
                imshow("blue", blueImg);
                break;

            case 2: //红色
                minH = 156; //26
                maxH = 180; //34

                minS = 100; //
                maxS = 255;

                minV = 46; //200
                maxV = 255;

                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), redImg); 
                imshow("red", redImg);
                break;

            case 3: //绿色
                minH = 35; //26
                maxH = 77; //34

                minS = 43; //
                maxS = 255;

                minV = 46; //200
                maxV = 255;

                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), greenImg); 
                imshow("green", greenImg);
                break;

            default:
                cout << "颜色标志输入错误" << endl;
        }
    
    }
    // Mat resultImg;
    // Mat yeBluImg;

    // //bitwise_or(a, b, ab);
    // //图像或 ，ab = a||b

    // bitwise_or(yellowImg, blueImg, yeBluImg); //图像或 
    // bitwise_or(yeBluImg, redImg, resultImg); //图像或

    // imshow("result", resultImg);


    // //开操作 (去除一些噪点)  如果二值化后图片干扰部分依然很多，增大下面的size
    Mat eleOpen = getStructuringElement(MORPH_RECT, Size(4, 4));
    morphologyEx(yellowImg, yellowImg, MORPH_OPEN, eleOpen);
    morphologyEx(blueImg, blueImg, MORPH_OPEN, eleOpen);
    morphologyEx(redImg, redImg, MORPH_OPEN, eleOpen);
    morphologyEx(greenImg, greenImg, MORPH_OPEN, eleOpen);
    imshow("yellow", yellowImg);
    imshow("blue", blueImg);
    imshow("red", redImg);
    imshow("green", greenImg);
    // imshow("open", resultImg);
}

int main()
{
    VideoCapture capture(0);
    Mat image, red_image;
    while(waitKey(33) != 27)
    {
        capture.read(image); //摄像头一帧内容存入mat
        if(image.empty())
            break;
        hsv_detector(image);
    }
    return 0;
}

/* g++ hsv_detector.cpp `pkg-config --cflags --libs opencv4` -o hsv_detector */