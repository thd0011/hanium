#include "button.h"
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc.hpp>

Button::Button() {}
Button::Button(cv::Mat canvas, int x, int y, int w, int h, cv::String text, cv::Scalar color)
{
	this->canvas = canvas;
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
	this->Text = text;
	this->Color = color;
	updateObject();
}

Button::~Button()
{
	canvas.release();
}

void Button::updateObject()
{
	cv::Rect r(this->x, this->y, this->width, this->height);
	this->canvas(r) = this->Color;
	cv::putText(this->canvas(r), this->Text,
		cv::Point(this->width*0.5 - (this->Text.length()*4.5), this->height*0.7),
		cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 0));
}

bool Button::isInPos(int x, int y)
{
	if (this->x <= x && this->y <= y && this->x + this->width >= x && this->y + this->height >= y)
		return true;
	else return false;
}