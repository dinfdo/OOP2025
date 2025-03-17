#include "Math.h"
#include "Canvas.h"
#include <iostream>
int main() {
	Math m;
	/*printf("Add(2, 3) = %d\n", m.Add(2, 3));
	printf("Add(2, 3, 4) = %d\n", m.Add(2, 3, 4));
	printf("Add(2.5, 3.5) = %d\n", m.Add(2.5, 3.5));
	printf("Mul(2, 3) = %d\n", m.Mul(2, 3));
	printf("Mul(2.5, 3.5) = %d\n", m.Mul(2.5, 3.5));
	printf("Add(4, 10, 20, 30, 40) = %d\n", m.Add(4, 10, 20, 30, 40));
	printf("%s \n", m.Add("H", "a"));*/
	Canvas canvas(51,51);
	canvas.Clear();

	canvas.DrawRect(2, 1, 17, 8, '*');
	canvas.FillRect(2, 1, 17, 8, '+');
	canvas.Print();
	canvas.Clear();

	canvas.DrawCircle(6, 1, 4, '*');
	canvas.FillCircle(6, 1, 4, '+');
	canvas.Print();
	canvas.Clear();

	canvas.SetPoint(2, 2, '*');
	canvas.SetPoint(18, 8, '*');
	canvas.DrawLine(2, 2, 18, 8, '/');
	canvas.Print();
	canvas.Clear();

    canvas.Print();

	return 0;
}