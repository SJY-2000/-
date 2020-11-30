#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat dstMat;
	Mat srcMat = imread("G:\\picture\\18.jpg", 1);
	Mat buffMat = imread("G:\\picture\\18.jpg", 0);
	Mat lineMat;
	
	Canny(buffMat, dstMat, 20, 200, 3, false);		
	
	HoughLinesP(dstMat, lineMat, 1, CV_PI / 180, 50, 40, 5);		//累积概率霍夫变换，投票阈值为50
		
	for (int i = 0; i < lineMat.rows; i++)
	{
		Point pt1, pt2;

		pt1.x = lineMat.at<Vec4i>(i, 0)[0];
		pt1.y = lineMat.at<Vec4i>(i, 0)[1];
		pt2.x = lineMat.at<Vec4i>(i, 0)[2];
		pt2.y = lineMat.at<Vec4i>(i, 0)[3];

		line(srcMat, pt1, pt2, Scalar(0, 255, 255), 1, LINE_AA);
	}
	imshow("srcMat", srcMat);
	
	waitKey(0);
}