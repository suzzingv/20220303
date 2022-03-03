#include <stdio.h>
#include <stdlib.h> //난수 생성
#include <time.h> //시간 정보 함수

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