#pragma once
class Point
{
private:
	int color;
	float posY;
	float posX;
public:
	Point(float posX, float posY, int color) 
	{
		this->posX = posX;
		this->posY = posY;
		this->color = color;
	}
	
	float getPosX()
	{
		return posX;
	}

	float getPosY()
	{
		return posY;
	}

	int getColor()
	{
		return color;
	}

};

