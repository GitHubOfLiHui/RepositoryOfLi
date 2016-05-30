// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <conio.h>

int main()
{
	int i;
	float  a[6] = { 261.926, 226.601, 202.573, 184.165, 170.001, 157.592 };
	for (i = 0; i < 6; i++)
		printf("%.4f", 1 / (a[i] * 2 * 3.14159));
	getch();
	return 0;
}

