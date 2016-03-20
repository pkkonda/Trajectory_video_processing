#include "stdafx.h"
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
//#include<opencv2/imgproc/imgproc.hpp>                            //INCLUDED FOR CANNY



using namespace std;
using namespace cv;

//Mat findred(Mat image, Mat img2);

int main()
{
	//Mat image;
	//image = imread("E:\\asd.jpg");
	Mat img(480,640, CV_8UC1, Scalar(255));
	
		
//	namedWindow("Frame", WINDOW_AUTOSIZE);
//	imshow("Frame", img);
//	Mat imgres(480, 640, CV_8UC1, Scalar(255));
	//imgres = findred(image, imgres);
	VideoCapture v(0);
	/*namedWindow("Frame2", WINDOW_AUTOSIZE);
	imshow("Frame2", imgres);*/
	while (1)
	{
		Mat image;
		v >> image;
		for (int i = 1; i < img.rows-1; i++)
			for (int j = 1; j < img.cols-1; j++)
			{
				if (image.at<Vec3b>(i, j)[2] >85 && image.at<Vec3b>(i, j)[2] < 115)
					if (image.at<Vec3b>(i, j)[0] >10 && image.at<Vec3b>(i, j)[0] < 20)
						//if (image.at<Vec3b>(i, j)[1] >20 && image.at<Vec3b>(i, j)[2] <35)
					{
						img.at<uchar>(i, 640 - j) = 0;
						//break;
					}
			}
		//imgres = findred(frame, imgres);
		imshow("Frame", img);     //480 rows  640 cols
		//imshow("Frame2", mirror1(frame));
		waitKey(33);
	}
	waitKey(0);
}