// Reference link : https://www.youtube.com/watch?v=oHFTM1XPicI&ab_channel=SoftwareTechVision

#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define RESPONSE_TIME 10

int main(int argc, char** argv) 
{
    VideoCapture cap(0);

    if (!cap.isOpened())
    {
        return -1;
    }

    while (true)
    {
        Mat frame;

        cap.read(frame);
        imshow("Live feed", frame);

        if (waitKey(RESPONSE_TIME) == 's')
        {
            Mat frame2;
            frame2 = frame.clone();
            imshow("Captured image", frame2);
        }

        if (waitKey(30) == 'd')
        {
            break;
        }
    }
    cap.release();
    destroyAllWindows();

    printf("PROGRAM FINISHED...\r\n");
    return 0;
}