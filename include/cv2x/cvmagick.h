#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>


namespace magick {

cv::Mat			equalize(const cv::Mat& img);
cv::Mat			enhance(const cv::Mat& img);
cv::Mat			autoLevel(const cv::Mat& img);
cv::Mat			normalize(const cv::Mat& img);
cv::Mat			despeckle(const cv::Mat& img);
cv::Mat			segment(const cv::Mat& img,float clusterThreshold_ = 1.0, float smoothingThreshold_ = 1.5);
cv::Mat			sharpen(const cv::Mat& img,float clusterThreshold_ = 1.0, float smoothingThreshold_ = 1.5);
cv::Mat			contrast(const cv::Mat& img,float clusterThreshold_ = 1.0);

}

