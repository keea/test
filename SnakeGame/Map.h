/*
* ¸Ê Á¤º¸
* @file		Map.h
* @date     Tue Nov 14 11:21:04 2017
* @author   keea
*/

#pragma once

class Map
{
private:
	int width;
	int height;
	char shape;
public:
	Map(int _width, int _height) :width(_width), height(_height), shape('*') {};
	int GetWidth();
	int GetHeight();
	char GetShpae();
};

