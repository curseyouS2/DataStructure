//250318 �ڷᱸ�� 3���� 
//�ڷᱸ��: ����
//��ȣ�˻� �˰���
//���� 121p

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	


typedef char element; 
typedef struct sample {
	element data[MAX_STACK_SIZE];	
	int top;			
}StackType;				

//���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {		
	s->top = -1;	//���ο�(->)���
}

int is_full(StackType* s) {		//0�Ǵ� 1 ��ȯ...��ȯ�� int
	return s->top == MAX_STACK_SIZE - 1;	// top�� MAX_STACK_SIZE�� ������ 1�� ��ȯ, �ƴϸ� 0�� ��ȯ
};

//���ÿ� �����͸� ����ִ� �Լ�
void push(StackType* s, element item) {
	//�迭 ũ�⸸ŭ�� �����ϵ��� �����ؾߵ�(�� �̻� ->�����÷ο�)
	//overflow check...
	if (is_full(s)) {	//*s��� �ع����� �ּҰ� �ƴ϶� ���� �������� �Ǿ����
		printf("���� �����÷ο� ���� \n");
		return;
	}
	else {
		//s->top += 1 �Ǵ�...	
		++(s->top);	//������ �켱���� �߿�...(������ �ַο찡 �����̱� ��)
		s->data[s->top] = item;//��� ->�� ����ϴ±���...
	}
	//else�� �ִ� ��� �̷��� ������ ����(������)
	//s->data[++s->top = item];
};
//������ ������� Ȯ���ϴ� �Լ�(top�� �̿�)
int is_empty(StackType* s) {
	return s->top == -1;	// top�� -1�̸� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ '==' ��ȯ ���������� ����
};

//������ ���� ������ �Լ�
element pop(StackType* s) {//�Լ� �̸��� element�� �ᵵ �Ǵ±���...(�ǹ�!!)
	//����÷ο� ����(�ƹ��͵� ���µ� �� ����)
	//underflow check...
	if (is_empty(s)) {//if(1)�̸�...(while(1)ó��)
		printf("������ �������");
		exit(1); //Ż��(���ϰ��� ���⶧���� exit�� ���)
	}
	else {
		/*int res;
		res = s->data[s->top];
		s->top = s->top - 1;
		return res;*/
		return s->data[(s->top)--]; //���� �� �� �� �ٷ� �����ϴ�!!(s���� top�� �������� --)
	}
};

int check_matching(const char* in) {	//������ �Ȱ��� const �ٿ�����!
	
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);	
	init_stack(&s);

	for (i = 0;i < n;i++) {
		ch = in[i];			//'in' �� �����Ͷ����...������, �迭ó�� ���� �� �� �ִ�!
		switch (ch) {
		case'(': case'{': case'[':		//���� ��ȣ�̸� push�ϱ�(���ÿ� �ֱ�)
			push(&s, ch);				//�̷��� �Ǹ� A���� ���ڵ��� �׳� �н� �ϰ�����? ^^
			break;						//switch�� break �� ������...(�̰Ŷ����� ����� �۵� ������;)
		
		case')':	//�ݴ� ��ȣ�϶� ���ÿ� ����� �� pop�ؼ� ��
		case'}':
		case']': 
			if (is_empty(&s)) return 0;			//������ ������� Ȯ�� ��=1 �ƴϿ�=2	 
			else {//��ȣ�� ¦�� �´���
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
	if (!is_empty(&s)) return 0;	//���� ��ȣ�� �� ������ -> 0�� ��ȯ

	return 1;
};

int main(void) {
	
	const char* p = "{ A[(i+1)]=0; }";	//���ڿ��� ����� ������ ������� �ʵ��� const ���δ�.

	if (check_matching(p) == 1) {
		printf("%s: ��ȣ �˻� ����!!\n", p);
	}
	else {
		printf("%s: ��ȣ �˻� ����!!\n", p);
	}

	return 0;
}