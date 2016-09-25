#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc.hpp>
class Button
{
public:
	Button(cv::Mat canvas, int x, int y, int w, int h, cv::String t, cv::Scalar c);
	Button();
	~Button();

	//getter
	int& getX() { return x; }
	int& getY() { return y; }
	int& getWidth() { return width; }
	int& getHeight() { return height; }
	cv::String& getText() { return Text; }
	cv::Scalar& getColor() { return Color; }

	//setter
	void setX(int x) { this->x = x; updateObject(); }
	void setY(int y) { this->y = y; updateObject(); }
	void setPos(cv::Point point) { this->x = x; this->y = y; updateObject(); }
	void setWidth(int w) { this->width = w; updateObject(); }
	void setHeight(int h) { this->height = h; updateObject(); }
	void setColor(cv::Scalar color) { this->Color = color; updateObject(); }
	void setColor(double B, double G, double R) { setColor(cv::Scalar(B, G, R)); }
	void setText(cv::String text) { this->Text = text; updateObject(); }

	bool isInPos(int x, int y);
private:
	int x;
	int y;
	int width;
	int height;
	cv::Scalar Color;
	cv::String Text;

	cv::Mat canvas;

	void updateObject();
};

