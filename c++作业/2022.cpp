#include <stdio.h>
using namespace std;
int main()
{
	float zhong, sheng, qian;
	char a;
	scanf("%f %f ", &sheng, &zhong);
	scanf("%c", &a);
	if (a == 'm')
	{
		if (zhong == 90)
		{
			qian = 6.95 * sheng * 0.95;
		}
		else if (zhong == 93)
		{
			qian = 7.44 * sheng * 0.95;
		}
		else if (zhong == 97)
		{
			qian = 7.93 * sheng * 0.95;
		}
	}
	else if (a == 'e')
	{
		if (zhong == 90)
		{
			qian = 6.95 * sheng * 0.97;
		}
		else if (zhong == 93)
		{
			qian = 7.44 * sheng * 0.97;
		}
		else if (zhong == 97)
		{
			qian = 7.93 * sheng * 0.97;
		}
	}
	printf("%.2f", qian);
	return 0;
}
