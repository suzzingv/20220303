#include <stdio.h>

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