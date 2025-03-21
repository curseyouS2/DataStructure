//자료구조 2주차 과제
//구조체로 복소수 계산하는 프로그램 만들기
//2491040 강주현

//솔루션 탐색기 컨알엘

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct complex {
	double real = 0;;
	double imagine = 0;;
};

//덧셈 함수
double sum(struct complex num) {
	return 0;
};
//뺄셈 함수
double min(struct complex num) {
	return 0;
};
//곱셈 함수
double mul(struct complex num) {
	return 0;
};
//나눗셈 함수
double div(struct complex num) {
	return 0;
};

int main(void) {
	struct complex num;
	struct complex* nump = &num;

	
														
	printf("◆작업할 번호를 입력>>");
	scanf("%lf", &num.real);
	printf("%.2lf\n", num.real);
	scanf("%lf", &num.imagine);
	printf("%.2lf\n", num.imagine);


}