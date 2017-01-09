#include <assert.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <cv2x/cvmagick.h>
using namespace cv;

#define MAGICKCORE_HDRI_ENABLE			0
#define MAGICKCORE_QUANTUM_DEPTH 	16

#include <Magick++.h>


namespace magick {
	
static bool			init=false;
static inline void	__init(){
	if(!init){
			Magick::InitializeMagick("");
			init=true;
	}
}	

inline Mat			Mat4to3(Mat& img)
{
	std::vector<Mat> v;
	split(img,v);
	v.pop_back();
	merge(v,img);
	return img;
}

Mat			equalize(const Mat& img)
{
	__init();
	//Magick::Blob blob(img.data, img.rows*img.cols*sizeof(float));
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.equalize();

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);
	return Mat4to3(x);
}

Mat			enhance(const Mat& img)
{
	__init();
	//Magick::Blob blob(img.data, img.rows*img.cols*sizeof(float));
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.enhance();

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);
	return Mat4to3(x);
}

Mat			autoLevel(const Mat& img)
{
		__init();
	//Magick::Blob blob(img.data, img.rows*img.cols*sizeof(float));
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.autoLevel();

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);

	return Mat4to3(x);
}

Mat			normalize(const Mat& img)
{
		__init();
	//Magick::Blob blob(img.data, img.rows*img.cols*sizeof(float));
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.normalize();

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);
	return Mat4to3(x);
}


Mat			despeckle(const Mat& img)
{
	__init();
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.despeckle();

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);
	return Mat4to3(x);
}

Mat			segment(const Mat& img,float clusterThreshold_ , float smoothingThreshold_ )
{
	__init();
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.segment(clusterThreshold_,smoothingThreshold_);

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);
	return Mat4to3(x);
}

Mat			sharpen(const Mat& img,float clusterThreshold_, float smoothingThreshold_ )
{
	__init();
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.sharpen(clusterThreshold_,smoothingThreshold_);

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);
	return Mat4to3(x);
}

Mat			contrast(const Mat& img,float clusterThreshold_ )
{
	__init();
	Magick::Image image(img.cols,img.rows,"BGR",Magick::FloatPixel,img.data);
	image.contrast(clusterThreshold_);

	Mat  x(img.size(),CV_16UC4,Scalar(0,0,0,0));
	memcpy(x.data,image.getConstPixels(0, 0, image.columns(), image.rows()),x.rows*x.cols*sizeof(long));
	x.convertTo(x,CV_32FC4,1./65535.);
	return Mat4to3(x);
}


}


