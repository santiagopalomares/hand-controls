#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Path to the video file
    std::string videoPath = "resources/converted_video.mp4";
    
    // Open the video file
    cv::VideoCapture cap(videoPath);
    
    // Check if the video opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file: " << videoPath << std::endl;
        return -1;
    }

    // Get the frames per second of the video
    double fps = cap.get(cv::CAP_PROP_FPS);

    // Create a window for display
    cv::namedWindow("Video", cv::WINDOW_NORMAL);

    while (true) {
        cv::Mat frame;
        
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break the loop
        if (frame.empty())
            break;

        // Display the resulting frame
        cv::imshow("Video", frame);

        // Press  'q' to exit the loop
        if (cv::waitKey(1000 / fps) == 'q')
            break;
    }

    // When everything is done, release the video capture object
    cap.release();

    // Close all OpenCV windows
    cv::destroyAllWindows();

    return 0;
}
