//250318 자료구조 3주차 
//자료구조: 스택
//관련된 데이터를 함수의 매개변수로 전달하는 방법 
//예시: 뷔페 접시, 소방관....

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5	//5를 MAX_STACK_SIZE로 부를게요(의미부여)

//스택 데이터의 높이를 저장하는 top변수 생성(구조체로...왜?) 
typedef int element; //int라고 써도 되고 element라고 써도 됨 (의미부여를 위해 바꾼 것임)
typedef struct sample {
	element data[MAX_STACK_SIZE];	//의미의 측면에서 int -> element, MAX_STACK_SIZE 움직이도록
	int top;			//그냥 인덱스이기 때문에  int로 해도 무방
}StackType;				//구조체의 새로운 타입 이름

//struct smaple x;	//x에 메모리 
//StackType x;

void init_stack(StackType *s) {	//main함수의 변수에 접근하지 못하기 때문에 top을 매개변수로 전달 -> 메모리 절약을 위해 메모리의 주소값을 전달한다(값말고)	
	s->top = -1;	//에로우(->)사용
}

int is_full(StackType *s) {		//0또는 1 반환...반환형 int
	return s->top == MAX_STACK_SIZE - 1;	// top이 MAX_STACK_SIZE와 같으면 1을 반환, 아니면 0을 반환
};

//스택에 데이터를 집어넣는 함수
void push(StackType *s, element item) {	
	//배열 크기만큼만 가능하도록 통제해야됨(그 이상 ->오버플로우)
	//overflow check...
	if (is_full(s)) {	//*s라고 해버리면 주소가 아니라 값을 가져오게 되어버림
		printf("스택 오버플로우 에러 \n");
		return;
	}
	else {
		//s->top += 1 또는...	
		++(s->top);	//연산자 우선순위 중요...(지금은 애로우가 먼저이긴 함)
		s->data[s->top] = item;//계속 ->를 써야하는구나...
	}
	//else에 있는 명령 이렇게 쓸수도 있음(한줄임)
	//s->data[++s->top = item];
};

int is_empty(StackType* s) {
	return s->top == -1;	// top이 -1이면 1을 반환, 아니면 0을 반환
};
//가장 위의 값 날리는 함수
element pop(StackType *s) {//함수 이름도 element로 써도 되는구나...(의미!!)
	//언더플로우 조심(아무것도 없는데 또 뺴기)
	//underflow check...
	if (is_empty(s)) {//if(1)이면...(while(1)처럼)
		printf("스택이 비어있음");
		exit(1); //탈출(리턴값이 없기때문에 exit을 사용)
	}
	else {
		int res;
		res = s->data[s->top];
		s->top = s->top - 1;
		return res;
		//return s->data[(s->top)--]; //위의 네 줄 한 줄로 가능하다!!
	}
};

int main(void) {

	StackType s;

	init_stack(&s);	//top값을 -1로 초기화하는 함수(주소값을 매개변수로)
	push(&s, 10); push(&s, 20); push(&s, 30);

	int res;	//.c파일일 시 메인함수 가장 위에 선언하도록 한다...

	res = pop(&s);	//30		//값을 저장하기 때문에 함수pop에는 return값 존재... 
	printf("pop vallue is %d\n", res);

	res = pop(&s);  //20
	printf("pop vallue is %d\n", res);

	return 0;
}