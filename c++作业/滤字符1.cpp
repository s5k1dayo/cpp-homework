#include <stdio.h>
int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		char s[100] = {0}, y[100] = {0}, t;
		scanf("%s", s);
		t = getchar();
		t = getchar();
		char *p = s, *q = y;
		for (p = s, q = y; *p != '\0'; p++)
		{
			if (*p != t)
			{
				*q = *p;
				q++;
			}
		}
		if (y[0] == '\0')
		{
			printf("NULL\n");
		}
		else
		{
			printf("%s\n", y);
		}
	}
	return 0;
}
