#include "Canvas.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>  
using namespace std;

Canvas::Canvas(int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int centreX = x + ray;
	int centreY = y + ray;
	int distance;

	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			distance = (i - centreX) * (i - centreX) + (j - centreY) * (j - centreY);
			if (distance <= ray * ray)
			{
				matrix[j][i] = ch;
			}
		}
	}

	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			distance = (i - centreX) * (i - centreX) + (j - centreY) * (j - centreY);
			if (distance <= (ray - 1) * (ray - 1))
			{
				matrix[j][i] = ' ';
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int centreX = x + ray;
	int centreY = y + ray;
	int distance;

	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			distance = (i - centreX) * (i - centreX) + (j - centreY) * (j - centreY);
			if (distance <= (ray - 1) * (ray - 1))
			{
				matrix[j][i] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
	{
		matrix[i][left] = ch;
		matrix[i][right] = ch;
	}
	for (int i = left; i <= right; i++)
	{
		matrix[top][i] = ch;
		matrix[bottom][i] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i < bottom; i++)
	{
		for (int j = left + 1; j < right; j++)
		{
			matrix[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int sx, sy;

	if (x1 < x2) {
		sx = 1;
	}
	else {
		sx = -1;
	}
	if (y1 < y2) {
		sy = 1;
	}
	else {
		sy = -1;
	}

	int err= dx + dy;
	int e2;

	while (true)
	{
		matrix[y1][x1] = ch;
		if (x1 == x2 && y1 == y2)
		{
			break;
		}
		e2 = 2 * err;
		if (e2 >= dy)
		{
			if (x1 == x2) break;
			err = err + dy;
			x1 = x1 + sx;
		}
		if (e2 <= dx)
		{
			if (y1 == y2) break;
			err = err + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("%c ", matrix[i][j]);  // Print the character
		}
		printf("\n");  // Print a newline after each row
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

