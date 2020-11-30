#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("G:\\picture\\18.jpg",0);
	if (srcMat.empty())return -1;
	Mat dstMat;
	
	Canny(srcMat, dstMat, 20, 230, 3, false);		//提取边缘
	
	std::vector<cv::Vec2f>lines;
	HoughLines(dstMat, lines,1,CV_PI/180,100);		//霍夫变换，投票域值设为100
	//imshow("lines", lines);
	std::vector<cv::Vec2f>::iterator it = lines.begin();
	for (; it != lines.end(); ++it) {
		float rho = (*it)[0], theta = (*it)[1];		//极坐标的长度和角度
		Point pt1, pt2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a*rho;
		double y0 = b*rho;
		pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
		pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
		pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
		pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
		cv::line(srcMat, pt1, pt2, cv::Scalar(255, 0, 0), 1, CV_AA);
	}
	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
}