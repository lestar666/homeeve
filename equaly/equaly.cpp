#include <iostream>  
#include <opencv2/opencv.hpp>  

using namespace cv;
using namespace std;

int main()
{
	Mat m = imread("etest.jpg");

	vector<Mat> channels;//定义存储的容器
	split(m, channels);

	Mat dst;
	Mat b = channels[0];//blue通道的图像
	equalizeHist(b, b);//均衡化

	Mat g = channels[1];
	equalizeHist(g, g);

	Mat r = channels[2];
	equalizeHist(r, r);

	merge(channels, dst);//合并通道

	imshow("src", m);

	imshow("dst", dst);
	waitKey(0);
	return 0;
}
