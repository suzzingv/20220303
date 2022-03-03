#include <stdio.h>
#include <stdlib.h> //난수 생성
#include <time.h> //시간 정보 함수

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