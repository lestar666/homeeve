#include <iostream>  
#include <opencv2/opencv.hpp>  

using namespace cv;
using namespace std;

int gammaF(cv::Mat srcMat, cv::Mat & dstMat, float gamma)
{

	//处理单通道图像
	if (srcMat.channels() != 1)return -1;

	//建立查询表
	unsigned char LUT[256];
	for (int i = 0; i < 256; i++)
	{

		LUT[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
		float inten = (float)i;
	}

	srcMat.copyTo(dstMat);

	MatIterator_<uchar> it, end;
	for (it = dstMat.begin<uchar>(), end = dstMat.end<uchar>(); it != end; it++) {
		*it = LUT[(*it)];
	}

	return 0;
}
int main()
{

	cv::Mat src = imread("gtest.jpg", 0);
	cv::Mat dstMat1;

	if (!src.data)
	{
		printf("could not load image...\n");
		return -1;
	}

	float gamma1 = 0.7;


	gammaF(src, dstMat1, gamma1);

	imshow("src", src);
	imshow("dst1", dstMat1);

	waitKey(0);

	destroyAllWindows();

	return 0;
}
