#include "functions.h"

//교차점 구하는거
Point* isIntersection(Point p1, Point p2, Point p3, Point p4) {
	// Store the values for fast access and easy
	// equations-to-code conversion
	float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
	float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;

	float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	// If d is zero, there is no intersection
	if (d == 0) return NULL;

	// Get the x and y
	float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
	float x = (pre * (x3 - x4) - (x1 - x2) * post) / d;
	float y = (pre * (y3 - y4) - (y1 - y2) * post) / d;

	// Check if the x and y coordinates are within both lines
	if (x < min(x1, x2) || x > max(x1, x2) ||
		x < min(x3, x4) || x > max(x3, x4)) return NULL;
	if (y < min(y1, y2) || y > max(y1, y2) ||
		y < min(y3, y4) || y > max(y3, y4)) return NULL;

	// Return the point of intersection
	Point* ret = new Point();
	ret->x = x;
	ret->y = y;
	return ret;
}

//모프? 좀 더 뭉뚱그리는거같음
void morphOpen(Mat &thresh, int w, int h) {

	//create structuring element that will be used to "dilate" and "erode" image.
	//the element chosen here is a 3px by 3px rectangle
	Mat erodeElement = getStructuringElement(MORPH_ELLIPSE, Size(w, h));
	//dilate with larger element so make sure object is nicely visible
	Mat dilateElement = getStructuringElement(MORPH_ELLIPSE, Size(w, h));

	erode(thresh, thresh, erodeElement);
	dilate(thresh, thresh, dilateElement);
}

void morphClose(Mat &thresh, int w, int h ) {

	//create structuring element that will be used to "dilate" and "erode" image.
	//the element chosen here is a 3px by 3px rectangle
	Mat erodeElement = getStructuringElement(MORPH_ELLIPSE, Size(w, h));
	//dilate with larger element so make sure object is nicely visible
	Mat dilateElement = getStructuringElement(MORPH_ELLIPSE, Size(w, h));

	dilate(thresh, thresh, dilateElement);
	erode(thresh, thresh, erodeElement);
}

void morphOpCl(Mat &thresh, int w, int h)
{
	morphOpen(thresh, w, h);
	morphClose(thresh, w, h);
}

//get Angle with two points.
double calcAngleFromPoints(Point2f p1, Point2f p2, bool radian = true)
{
	float angle;
	float dX = p1.x - p2.x;
	float dY = p1.y - p2.y;
	float rad = atan2(dY, dX);
	return radian ? rad : (rad * 180) / 3.14159262;
}

//get end point of line with "start point & radian" + "two point of another line"
Point* calcEndOfLinePoint(Point startP, float radian, Point barPoint1, Point barPoint2)
{
	Point pE;
	pE.x = (int(round(startP.x + 1000 * cos(radian))));
	pE.y = (int(round(startP.y + 1000 * sin(radian))));

	return isIntersection(startP, pE, barPoint1, barPoint2);
}