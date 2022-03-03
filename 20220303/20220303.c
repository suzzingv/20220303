#include <stdio.h>
#include <stdlib.h> //난수 생성
#include <time.h> //시간 정보 함수

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