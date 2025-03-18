//250318 자료구조 3주차 
//자료구조: 스택
//괄호검사 알고리즘
//교재 121p

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	


typedef char element; 
typedef struct sample {
	element data[MAX_STACK_SIZE];	
	int top;			
}StackType;				

//스택 초기화 함수
void init_stack(StackType* s) {		
	s->top = -1;	//에로우(->)사용
}

int is_full(StackType* s) {		//0또는 1 반환...반환형 int
	return s->top == MAX_STACK_SIZE - 1;	// top이 MAX_STACK_SIZE와 같으면 1을 반환, 아니면 0을 반환
};

//스택에 데이터를 집어넣는 함수
void push(StackType* s, element item) {
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
//스택이 비었는지 확인하는 함수(top을 이용)
int is_empty(StackType* s) {
	return s->top == -1;	// top이 -1이면 1을 반환, 아니면 0을 반환 '==' 반환 참거짓임을 주의
};

//스택의 값을 꺼내는 함수
element pop(StackType* s) {//함수 이름도 element로 써도 되는구나...(의미!!)
	//언더플로우 조심(아무것도 없는데 또 뺴기)
	//underflow check...
	if (is_empty(s)) {//if(1)이면...(while(1)처럼)
		printf("스택이 비어있음");
		exit(1); //탈출(리턴값이 없기때문에 exit을 사용)
	}
	else {
		/*int res;
		res = s->data[s->top];
		s->top = s->top - 1;
		return res;*/
		return s->data[(s->top)--]; //위의 네 줄 한 줄로 가능하다!!(s에서 top을 가져오고 --)
	}
};

int check_matching(const char* in) {	//변수와 똑같이 const 붙여주자!
	
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);	
	init_stack(&s);

	for (i = 0;i < n;i++) {
		ch = in[i];			//'in' 도 포인터라는점...포인터, 배열처럼 역할 할 수 있다!
		switch (ch) {
		case'(': case'{': case'[':		//여는 괄호이면 push하기(스택에 넣기)
			push(&s, ch);				//이렇게 되면 A같은 글자들은 그냥 패스 하겠지요? ^^
			break;						//switch문 break 꼭 넣을것...(이거때문에 제대로 작동 안했음;)
		
		case')':	//닫는 괄호일때 스택에 저장된 걸 pop해서 비교
		case'}':
		case']': 
			if (is_empty(&s)) return 0;			//스택이 비었는지 확인 네=1 아니오=2	 
			else {//괄호의 짝이 맞는지
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '{' && ch != '}') ||
					(open_ch == '[' && ch != ']')) {
					return 0;
				}
				break;
			}
				
		}//end switch
	}//end for
	if (!is_empty(&s)) return 0;	//여는 괄호가 더 많으면 -> 0을 반환

	return 1;
};

int main(void) {
	
	const char* p = "{ A[(i+1)]=0; }";	//문자열이 저장된 포인터 변경되지 않도록 const 붙인다.

	if (check_matching(p) == 1) {
		printf("%s: 괄호 검사 성공!!\n", p);
	}
	else {
		printf("%s: 괄호 검사 실패!!\n", p);
	}

	return 0;
}