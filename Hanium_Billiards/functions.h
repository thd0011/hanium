#pragma once
#include <opencv2\imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <algorithm>
using namespace cv;

Point* isIntersection(Point p1, Point p2, Point p3, Point p4);
void morphOpen(Mat &thresh, int w, int h);
void morphClose(Mat &thresh, int w, int h);
void morphOpCl(Mat &thresh, int w, int h);
double calcAngleFromPoints(Point2f p1, Point2f p2, bool radian);
Point* calcEndOfLinePoint(Point startP, float radian, Point barPoint1, Point barPoint2);