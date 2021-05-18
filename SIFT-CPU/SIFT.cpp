//Uncomment the following line if you are compiling this code in Visual Studio

#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    
    

    const cv::Mat input = cv::imread("rgray8.bmp", 0); //Load as grayscale
    
    cv::Ptr<cv::SIFT> siftPtr = cv::SIFT::create(10000);
    std::vector<cv::KeyPoint> keypoints;
    SiftDescriptorExtractor detector();

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    siftPtr->detect(input, keypoints);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[µs]" << std::endl;
    // Add results to image and save.
    cv::Mat output;
    cv::drawKeypoints(input, keypoints, output);
    cv::imwrite("sift_result.jpg", output); 

        return 0;
}