#include <stdio.h>
#include <stdlib.h> //난수 생성
#include <time.h> //시간 정보 함수
/*
//도전 2
void SnailArrRow(int arr[][10], int *ptrI, int *ptrJ, int *ptrS, int m, int *ptrK) //2차원 배열 매개변수: int arr[][10] || int (*arr)[10]
{ //변수가 들어가면 변수는 안 변한다. 변수의 값만 전달해주기 때문
	if ((*ptrJ) == (*ptrS))
	{
		for ((*ptrJ) = (*ptrS); (*ptrJ) < (m - ((*ptrS) + 1)); (*ptrJ)++)
		{
			arr[*ptrI][*ptrJ] = *ptrK;
			(*ptrK)++;
		}
	}
	else
	{
		for ((*ptrJ) = (m - ((*ptrS) + 1)); (*ptrJ) > (*ptrS); (*ptrJ)--)
		{
			arr[*ptrI][*ptrJ] = *ptrK;
			(*ptrK)++;
		}
	}
}

void SnailArrCol(int arr[][10], int* ptrI, int* ptrJ, int* ptrS, int m, int* ptrK)
{
	if ((*ptrI) == (*ptrS))
	{
		for ((*ptrI) = (*ptrS); (*ptrI) < (m - ((*ptrS) + 1)); (*ptrI)++)
		{
			arr[*ptrI][*ptrJ] = *ptrK;
			(*ptrK)++;
		}
	}
	else
	{
		for ((*ptrI) = (m - ((*ptrS) + 1)); (*ptrI) > (*ptrS); (*ptrI)--)
		{
			arr[*ptrI][*ptrJ] = *ptrK;
			(*ptrK)++;
		}
	}
}
void Print2DArr(int(*arr)[10], int m)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
			printf("%3d", arr[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int n, i=0, j=0, k=1, m, s=0;
	int* ptrI = &i, * ptrJ = &j, * ptrK = &k, * ptrS = &s;
	int arr[10][10];
	scanf_s("%d", &n);
	m = n;

	while (n > 0)
	{
		if (n != 1)
		{
			SnailArrRow(arr, ptrI, ptrJ, ptrS, m, ptrK);
			SnailArrCol(arr, ptrI, ptrJ, ptrS, m, ptrK);
			SnailArrRow(arr, ptrI, ptrJ, ptrS, m, ptrK);
			SnailArrCol(arr, ptrI, ptrJ, ptrS, m, ptrK);
		}
		else
			arr[i][j] = k;
		j++; i++; s++;
		n=n-2;
	}
	Print2DArr(arr, m);
	return 0;
}

//도전 3
int main(void)
{
	int i;
	int rand(void); //의사 난수 반환: 진정한 의미의 난수는 아니지만 난수로 칠 수 있는,몇 번을 실행해도 똑같은 값 나옴
	printf("난수의 범위: 0부터 %d까지 \n", RAND_MAX); //RAND_MAX: 32767
	for (i = 0; i < 5; i++)
		printf("난수 출력: %d \n", rand()%100);
	return 0;
}

//도전 4
int main(void)
{
	int seed, i;
	printf("씨드 값 입력: ");
	scanf_s("%d", &seed);
	srand(seed); //씨를 심는다, seed 값에 따라 랜덤 생성 함수 //seed값 똑같으면 결과도 똑같다

	for (i = 0; i < 5; i++)
		printf("정수 출력: %d \n", rand()); //열매를 수확한다
	return 0;
}

int main(void)
{
	int i;
	srand((int)time(NULL)); //시간정보만 불러오고 싶으면 인자로 NULL 전달 //시간은 항상 다르기 때문에 매번 다른 씨드 가능
	for (i = 0; i < 5; i++)
		printf("정수 출력: %d \n", rand());
	return 0;
}

int main(void)
{
	int i;
	srand((int)time(NULL)); //(int)time(NULL): 시간 정보를 정수로
	for (i = 0; i < 2; i++)
		printf("주사위 %d의 결과: %d \n", i + 1, (rand() % 5)+1);
	return 0;
}

//도전 5
const char* ChangeToKorean(int r) //const: 변경할 수 없는 상수의 속성 부여, 이거 안 하면 값 잃는다
{
	if (r == 1)
		return "바위";
	else if (r == 2)
		return "가위";
	else
		return "보";
}
int main(void)
{
	int rsp, rspC, win = 0, tie = 0;
	srand((int)time(NULL));

	while (1)
	{
		printf("바위는 1, 가위는 2, 보는 3: ");
		scanf_s("%d", &rsp);
		rspC = (rand() % 3) + 1;

		if (rspC == rsp)
		{
			printf("당신은 %s 선택, 컴퓨터는 %s 선택, 비겼습니다! \n", ChangeToKorean(rsp), ChangeToKorean(rspC));
			tie++;
		}
		else if ((rspC - rsp == -2) || (rspC - rsp == 1))
		{
			printf("당신은 %s 선택, 컴퓨터는 %s 선택, 당신이 이겼습니다! \n", ChangeToKorean(rsp), ChangeToKorean(rspC));
			win++;
		}
		else
		{
			printf("당신은 %s 선택, 컴퓨터는 %s 선택, 당신이 졌습니다! \n", ChangeToKorean(rsp), ChangeToKorean(rspC));
			break;
		}
	}
	printf("게임의 결과: %d승 %d무 \n", win, tie);
	return 0;
}

//도전 6
int main(void)
{
	int b=0, s=0, i, n=1;
	int arrME[3], arrCOM[3];
	srand((int)time(NULL));
	arrCOM[0] = rand() % 10;
	arrCOM[1] = rand() % 10;
	arrCOM[2] = rand() % 10;
	printf("Start Game! \n");

	while (1)
	{
		printf("3개의 숫자 선택: ");
		scanf_s("%d %d %d", &arrME[0], &arrME[1], &arrME[2]);
		for (i = 0; i < 3; i++)
		{
			if (arrCOM[i] == arrME[i])
				s++;
			else if (arrCOM[i] == arrME[0] || arrCOM[i] == arrME[1] || arrCOM[i] == arrME[2])
				b++;
			else
				continue;
		}
		printf("%d번째 도전 결과: %dstrike, %dball! \n", n, s, b);
		if (s == 3)
			break;
		s = 0; b = 0;
		n++;
	}
	return 0;
}
*/
int main(void)
{
	printf("장윤석 \n");
	return 0;
}