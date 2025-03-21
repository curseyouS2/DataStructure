#include <stdio.h>   //라이브러리 '삽입' -> printf() 함수 사용을 위해

int main(void) {
	
	//배열: '같은 타입'의 데이터를 '연속'적으로 메모리 할당하기

	int arr[3] = {10, 20, 30};    //메모리 요청...'선언문'
	//선언과 할당을 동시에~ (초기화)

	/*arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;	이렇게 해도 되긴하는데 위 방법이 편함 굿*/

	//배열값 출력
	for (int i = 0;i <= 2;i++) {
		printf("%d\n", arr[i]);
	}


	//구조체: '다른 타입'의 데이터를 연속적으로 정의(같은 타입도 됨)
	//.c확장자는 진행 전에 선언 모두 끝내야 함...c++은 안 그래도 됨 그러니까 c++확장자를 사용하자~

	
	// 구조체 정의(메모리 할당 아직 x)
	struct babo {
		char c;
		int k;
		double d;
	};

	//구조체 선언(이름: super)
	struct babo super;

	super.c = 'h';			//문자 할당시 문자에 ''붙일것
	super.k = 1212;
	super.d = 1.23;

	printf("%c %d %.2lf", super.c, super.k, super.d);		// 구조체타입.이름 식으로 할 것
















	return 0;
}