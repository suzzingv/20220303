#include <stdio.h>
#include <st>
//도전 3
int main(void)
{
	int i;
	int rand(void); //의사 난수 반환: 진정한 의미의 난수는 아니지만 난수로 칠 수 있는,몇 번을 실행해도 똑같은 값 나옴
	printf("난수의 범위: 0부터 %d까지 \n", RAND_MAX); //RAND_MAX: 32767
	for (i = 0; i < 5; i++)
		printf("난수 출력: %d \n", rand() % 100);
	return 0;
}
