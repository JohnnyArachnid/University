#include <stdio.h>

double wyznacznik3x3(double a[3][3])
{
	double c1 = a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[0][2]*a[1][0]*a[2][1];
	double c2 = a[0][2]*a[1][1]*a[2][0] + a[0][0]*a[1][2]*a[2][1] + a[0][1]*a[1][0]*a[2][2];
	return c1-c2;
}

int uklad3(double a[3][3], double b[3], double c[3])
{
	double wG = wyznacznik3x3(a);
	double jd1[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			jd1[i][j] = a[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		jd1[i][0] = b[i];
	}
	double wX,wY,wZ;
	wX = wyznacznik3x3(jd1);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			jd1[i][j] = a[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		jd1[i][1] = b[i];
	}
	wY = wyznacznik3x3(jd1);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			jd1[i][j] = a[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		jd1[i][2] = b[i];
	}
	wZ = wyznacznik3x3(jd1);
	if(wG != 0)
	{
		c[0] = wX/wG;
		c[1] = wY/wG;
		c[2] = wZ/wG;
		return 1;
	}
	if(wX == 0 && wY == 0 && wZ == 0)
	{
		return 1000;
	}
	return 0;
}
