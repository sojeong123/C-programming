//20201012 컴퓨터학과 임소정

// LAB6_0 (문자열의 정의, 표준출력, 문자열 종료방법)
// 다음 예제 프로그램의 결과를 예상해 보세요.
// 그리고 프로그램을 실행한 후 자신의 예상 결과와 비교해 보세요
// 1)2)3)4)를 잘 살펴보라.

/*
#include <stdio.h>
int main(void)
{
	int i;

	// 1) 문자열을 정의하는 여러가지 방법들입니다.
	char digits[] = "0123456789";
	char abc[] = { 'A', 'B', 'C', 'D', '\0' };
	char lan[5] = "java";

	// 2) 출력 결과는?
	printf("%s %s\n", digits, abc);		//%s를 사용한다.

	// 3) 아래처럼 lan 문자열변수를 2가지 방법으로 출력할 수 있다.
	//	  %c와 %s의 쓰임새에 주목하라.
	printf("%s\n", lan);

	for (i = 0; lan[i] != '\0'; i++)	// A)문자열의 마지막을 확인하는 방법을 유의해보라.
		printf("%c", lan[i]);

	// 4) digits[]의 중간에 null character를 삽입하면
	digits[6] = '\0';
	printf("\n%s\n", digits);
	
	return 0;
}
*/

// LAB6_a_1
//하나의 문자열 변수 word를 읽어들여서 (%s 사용),
// 이를 출력(%s 사용)하는 간단한 프로그램을 작성하라.
// word의 길이는 최대 10이라 가정하자.
// 즉, char word[11]이라 선언하여 사용하면 된다.
// 
// 실행 예시
// Enter a word(<= 10 chars) : Happy
// Happy

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char word[11];

	printf("Enter a word(<= 10 chars) : ");
	scanf("%s", word);
	printf("%s\n", word);

	return 0;
}
*/

// LAB6_a_2
// 위의 프로그램을 수정하여 출력할 때, word안의 문자를 하나하나를 출력하도록 하라.
// 즉, 실행 예시는 그대로이다.
// (위의 Lab6_0의 A부분을 참조하라.)

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char word[11];
	int i;

	printf("Enter a word(<= 10 chars) : ");
	scanf("%s", word);

	for (i = 0; word[i] != '\0'; i++)
		printf("%c", word[i]);
	printf("\n");

	return 0;
}
*/

/*
문제 5. 2차원 배열 시계방향 rotate(난이도 중)

행의 개수와 열의 개수가 5인 2차원 배열의 원소들을 입력받아
시계방향으로 90도 회전하여 출력하려한다.

함수 rotate2dimArray를 완성시켜
아래와 같이 출력되게 하라.

실행예:
입력)
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
출력)
21 16 11 6 1
22 17 12 7 2
23 18 13 8 3
24 19 14 9 4
25 20 15 10 5
*/

/*
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// a를 90도 시계방향으로 회전하여 b에 넣는다
void rotate2dimArray(int a[][5], int b[][5], int size)
{
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			b[j][size - 1 - i] = a[i][j];
	}
	return;
}

int main(void)
{
	int A[5][5];
	int B[5][5];
	int n, key;
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			scanf("%d", &A[i][j]);

	rotate2dimArray(A, B, 5);
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}
}
*/

/*
지뢰찾기

입력프롬트
Input Grid:
는 제거하고 돌려보세요
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define X_VALUE 5 //2차원 배열의 행의 수
#define Y_VALUE 5 //2차원 배열의 열의 수

void readBombInfo(char grid[][Y_VALUE + 1])
{
	int i;
	// grid 및 지뢰 정보 입력
	printf("Input Grid\n");
	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]);
}
void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;

	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*') {
				// 여기에 지뢰의 개수를 세어 numOfBombs에 넣는 코드 작성
				//코드작성
				if (i - 1 >= 0 && j - 1 >= 0)
					numOfBombs[i - 1][j - 1]++;
				if (i - 1 >= 0)
					numOfBombs[i - 1][j]++;
				if (i - 1 >= 0 && j + 1 < Y_VALUE)
					numOfBombs[i - 1][j + 1]++;
				if (j - 1 >= 0)
					numOfBombs[i][j - 1]++;
				if (j + 1 < Y_VALUE)
					numOfBombs[i][j + 1]++;
				if (i + 1 < X_VALUE && j - 1 >= 0)
					numOfBombs[i + 1][j - 1]++;
				if (i + 1 < X_VALUE)
					numOfBombs[i + 1][j]++;
				if (i + 1 < X_VALUE && j + 1 < Y_VALUE)
					numOfBombs[i + 1][j + 1]++;
			}
}


void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}

int main(void)
{
	char grid[X_VALUE][Y_VALUE + 1]; //문자열의 경우 마지막에 NULL이 들어가야 하므로 
	// 5X5 배열이 아닌 5X6 배열이 되어야 한다.	
	int numOfBombs[X_VALUE][Y_VALUE] = { 0 }; //지뢰의 개수를 넣는 정수형 5X5 배열

	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	display_numOfBombs(grid, numOfBombs);
}
*/