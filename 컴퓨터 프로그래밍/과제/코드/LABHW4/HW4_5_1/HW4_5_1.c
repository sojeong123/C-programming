//20201012 컴퓨터학과 임소정
//HW4_5_1
#include <stdio.h>
int get_cycle_number(int n);
int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf_s("%d", &n);

	printf("사이클 길이는 %d이다.\n", get_cycle_number(n));
}

int get_cycle_number(int n)
{
	int cnt = 1;
	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
		cnt++;
	}
	return cnt;
}