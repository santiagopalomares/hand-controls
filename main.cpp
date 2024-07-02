#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream> // Include this for cerr

using namespace std;
using namespace cv;

int main(){
    VideoCapture cap(0); // Use 0 for the default camera
    if (!cap.isOpened()) {
        cerr << "Error: Could not open camera" << endl;
        return -1;
    }

    Mat img, imgBlur, imgCanny;

    while (true)
    {
        cap.read(img);
        if (img.empty()) {
            cerr << "Error: Could not grab frame" << endl;
            break;
        }

        GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
        Canny(imgBlur, imgCanny, 50, 150);
        imshow("Image", imgCanny);

        if (waitKey(1) >= 0) {
            break;
        }
    }
    return 0;
}
