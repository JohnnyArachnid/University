void sprawdzenie(double a[2][2], double xy[2], double out[2])
{
	out[0] = a[0][0]*xy[0] + a[0][1]*xy[1];
	out[1] = a[1][0]*xy[0] + a[1][1]*xy[1];
	return ;
}
