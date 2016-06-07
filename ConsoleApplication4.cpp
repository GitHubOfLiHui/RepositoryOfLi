#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>

HANDLE pThread[100]; //producer线程句柄
#define m 5
int points;

struct Circle
{
	int r;
	int mux;
	int muy;
};
int zj[200][200];
Circle circle[m];
Circle point[5];


bool cmp(int a, int b){
	if (a > b)
	{
		if ((a - b) <= 1)
			return true;
		else
			return false;
	}
	else
	{
		if ((b - a) <= 1)
			return true;
		else
			return false;
	}
}
bool cmp2(int a, int b, int r){
	if (a > b)
	{
		if ((a - b) <= r)
			return true;
		else
			return false;
	}
	else
	{
		if ((b - a) <= r)
			return true;
		else
			return false;
	}
}
int CalculateDistance(Circle a, Circle b){
	int distance;
	distance = int(sqrt(float((a.mux - b.mux)*(a.mux - b.mux) + (a.muy - b.muy)*(a.muy - b.muy))));
	return distance;
}
void Qrmax(int n)
{
	Circle ci;
	int Rmax = 0, X = 0, Y = 0;
	for (int i = 0; i < 200; i++)
	for (int j = 0; j < 200; j++)
	{

		int pd = 0;
		ci.mux = i;
		ci.muy = j;
		for (int ii = 0; ii < n; ii++){
			if (cmp2(i, circle[ii].mux, circle[ii].r) && cmp2(j, circle[ii].muy, circle[ii].r))
				pd = 1;
		}
		if (pd)
			break;
		for (int r = 0; r < 100; r++)
		{
			ci.r = r;
			for (int t = 0; t < n; t++)
			{
				if (cmp(CalculateDistance(circle[n], circle[t]), (circle[n].r + circle[t].r)))
				{
					if (r >= Rmax)
					{
						Rmax = r;
						X = i;
						Y = j;
					}
					pd = 1;
					break;
				}
			}

			if ((i - r <= 0) || (i + r >= 199) || (j + r >= 199) || (j - r <= 0))
			{
				pd = 1;
				if (r >= Rmax)
				{
					Rmax = r;
					X = i;
					Y = j;
				}
			}
			for (int h = 0; h < points; h++)
			{
				if (cmp(CalculateDistance(ci, point[h]), (ci.r + point[h].r)))
				{

					if (r >= Rmax)
					{
						Rmax = r;
						X = i;
						Y = j;
					}
					pd = 1;
					break;
				}

			}
			if (pd)
				break;
		}
	}
	circle[n].mux = X;
	circle[n].muy = Y;
	circle[n].r = Rmax;
}



pThread1 = CreateThread(NULL, 0, producer1, NULL, 0, NULL);
pThread2 = CreateThread(NULL, 0, producer2, NULL, 0, NULL);
pThread3 = CreateThread(NULL, 0, producer3, NULL, 0, NULL);
pThread4 = CreateThread(NULL, 0, producer4, NULL, 0, NULL);


WaitForSingleObject(pThread1, INFINITE);
WaitForSingleObject(pThread2, INFINITE);
WaitForSingleObject(pThread3, INFINITE);
WaitForSingleObject(pThread4, INFINITE)
int main()
{

	srand(time(0));
	int i, j;
	points = (rand() % 5 + 1);//随机生成1-5个点
	for (int h = 0; h < points; h++)
	{
		i = rand() % 200;
		j = rand() % 200;
		if (zj[i][j] == 0)
		{
			zj[i][j] = 1;
			point[h].mux = i;
			point[h].muy = j;
		}
		else h--;
	}
	for (int t = 0; t < m; t++){
		Qrmax(t);
	}
	printf("要求：%d个圆\n", m);
	for (int i = 0; i < points; i++)
	{
		printf("点(x,y)%.2f %.2f\t", float(point[i].mux - 100) / 100, float(point[i].muy - 100) / 100);
	}
	printf("\n");
	for (int i = 0; i < m; i++)
	{
		printf(" %.2f %.2f %.2f", float(circle[i].mux - 100) / 100, float(circle[i].muy - 100) / 100, float(circle[i].r) / 100);
		printf("\n");
	}
	getchar();
	return 0;
}
