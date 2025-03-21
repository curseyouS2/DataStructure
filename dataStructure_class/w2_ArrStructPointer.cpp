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

	printf("%c %d %.2lf\n", super.c, super.k, super.d);		// 구조체타입.이름 식으로 할 것(교재74p 참고)

	//변수와 포인터
	
	int a = 200;
	printf("a의 주소: %p\n", &a);  //%u:unsigned(부호x), 주소: %p(16진수)
	printf("%d\n", &a);

	printf("%p\n", arr); //배열의 이름은 그 배열의 시작 주소
	printf("%p\n", &arr[0]);

	printf("%p\n", arr+1);		//다음 인덱스로~ 인덱스가 0부터 시작하는 이유인 것이다...(와샌즈;)
	printf("%p\n", &arr[1]); 
	
	printf("%p", &arr[2]);
	printf("%p\n", arr + 2);    //인덱스2로 가고싶으면 배열 이름에 +2를 하면 되겠죠?
	//포인터의 놀라운 점: 타입에 따라 더하는 값을 바꿀 필요가 없음(헐!!!!!!!!!!!!!!!!!!!!!!!)

	//포인터 변수 선언하기
	//해당 메모리에 원래 저장된 값의 타입과 같은 타입으로 선언, 이름 앞에 * 붙일것. 주소=&
	
	int *pt = &a; //pt 출력 가능
	printf("a의 주소: %p\n", pt);

	//배열과 포인터...배열에 대한 포인터변수 선언 + 초기화!
	
	int* apt = arr;					//배열 이름이 곧 주소이기 때문에 & 붙이지 않아도 됨
	printf("arr의 주소: %p\n", apt); 
	printf("arr[1]의 주소: %p\n", apt + 1); //앞에서와 같이 '+1'도 가능!!!!(대박이다)


	//구조체와 포인터
	
	struct babo *spt = &super;

	printf("\n~~~포인터로 구조체 출력하기~~~\n");
	printf("%c\n", spt->c);		//포인터를 이용해 구조체 내 멤버에 접근 (이 경우에는 super라는 구조체 내 c라는 멤버에 접근 한 것)
	printf("%d\n", spt->k);
	printf("%.2lf", spt->d);

	//스택 실습












	return 0;
}