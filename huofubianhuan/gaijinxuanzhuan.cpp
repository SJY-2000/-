#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{
	Mat srcMat = imread("G:\\picture\\44.jpg");
	Mat dstMat;
	if (srcMat.empty())return -1;
	float angle = -10.0, scale = 1;
	Point2f center(srcMat.cols / 2.0, srcMat.rows / 2.0);
	Mat rot = getRotationMatrix2D(center, angle, scale);
	Rect bbox = RotatedRect(center, srcMat.size(), angle).boundingRect();
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
	warpAffine(srcMat, dstMat, rot, bbox.size());

	
	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
}