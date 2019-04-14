// testopencv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace cv;
using namespace std;

int main()
{
	Mat image;
	//float x = 0, y = 0, blue, green, red;
	image = imread("a.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	//image1 = imread("home.jpg", CV_LOAD_IMAGE_COLOR);
	//image2 = Mat(image1.rows, image1.cols, CV_8UC3);
	//image = imread(argv[1], CV_LOAD_IMAGE_COLOR); // Read the file
	
	if (!image.data) // Check for invalid input
	{
		 cout << "Could not open or find the image" << std::endl;
		return -2;
	 }

	
	/*for (int y = 0; y < image.rows; y++) {
		for (int x = 0; x < image.cols; x++) {
			Scalar intensity = image.at<uchar>(y, x);
			intensity.val[0] /= 255;
			intensity.val[0] = 2 / (1 + exp(-4*((double)intensity.val[0])));
			image.at<uchar>(y, x) = intensity.val[0] * 255;
		}
	}*/
	cout << "Input number : ";
	int num; Scalar intensity;
	cin >> num;
	double sum;
	for (int x = num / 2; x < image.cols - num / 2; x++) {
		for (int y = num / 2; y < image.rows - num / 2; y++) {
			sum = 0;
			for (int i = -num / 2; i < num / 2 + 1; i++) {
				for (int j = -num / 2; j < num / 2 + 1; j++) {
					intensity = image.at<uchar>(Point(x + i, y + j));
					sum = sum + intensity.val[0];
				}
			}
			sum /= (pow(num,2));
			image.at<uchar>(Point(x, y)) = sum;
		}
	}

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", image); // Show our image inside it.
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}

