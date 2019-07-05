#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

void RTOG(Mat r, int row, int col)
{
    int rows = row + 10;
    int cols = col + 5;
    for(; row < rows; row++)
    {
        for(; col < cols; col++)
        {
            r.at<Vec3b>(row, col)[0] = 0;
            r.at<Vec3b>(row, col)[1] = 255;
            r.at<Vec3b>(row, col)[2] = 0;
        }
    }
}

void detector(Mat red)
{
    int min_row = 1000, min_col = 1000, max_row = 0, max_col = 0;

    Mat r;

    r = red.clone();

    for(int row = 0; row < r.rows; row++)
    {
        for(int col = 0; col < r.cols; col++)
        {
            if(r.at<Vec3b>(row, col)[2] < 160)
            {
                r.at<Vec3b>(row, col)[0] = 0;
                r.at<Vec3b>(row, col)[1] = 0;
                r.at<Vec3b>(row, col)[2] = 0;
            }
            if(r.at<Vec3b>(row, col)[2] >= 160 && r.at<Vec3b>(row, col)[0] < 100 && r.at<Vec3b>(row, col)[1] < 100)
            {
                r.at<Vec3b>(row, col)[0] = 0;
                r.at<Vec3b>(row, col)[1] = 0;
            }
            if(r.at<Vec3b>(row, col)[2] >= 160 && (r.at<Vec3b>(row, col)[0] >= 100 || r.at<Vec3b>(row, col)[1] >= 100))
            {
                r.at<Vec3b>(row, col)[0] = 0;
                r.at<Vec3b>(row, col)[1] = 0;
                r.at<Vec3b>(row, col)[2] = 0;
            }
        }
    }

    imshow("image", red);
    // imshow("detector", r);
    // printf("width: %d  length: %d", r.rows, r.cols);
    for(int row = 0; row < r.rows; row++)
    {
        for(int col = 0; col < r.cols; col++)
        {
            if(r.at<Vec3b>(row, col)[2])
            {
                if(row < min_row)
                    min_row = row;
                if(row > max_row)
                    max_row = row;
                if(col < min_col)
                    min_col = col;
                if(col > max_col)
                    max_col = col;
            }
        }
    }
    RTOG(r, (min_row + max_row)/2, (min_col + max_col)/2);
    // r.at<Vec3b>((min_row + max_row)/2, (min_col + max_col)/2)[1] = 255;

    // printf("rows:%d cols:%d\n",( min_row + max_row)/2, (min_col + max_col)/2);
    imshow("detector", r);
    waitKey(10);
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
        detector(image);
    }
    return 0;
}

/* g++ rgb_detector.cpp `pkg-config --cflags --libs opencv4` -o rgb_detector */