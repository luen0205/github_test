#include "header.h"

Array <string> katok;
void add_data(string data) {
	katok.push_back("None");
	int kLen = len(katok);
	katok[kLen - 1] = data;
}

int main() {
	add_data("다현");
	add_data("정연");
	add_data("쯔위");
	add_data("사나");
	add_data("지효");

	printArray(katok);



Array <string> katok = { "다현", "정연", "쯔위", "사나", "지효" };

void insert_data(int position, string data) {
	if ((position < 0) || (position > len(katok))) {
		print("데이터를 삽입할 범위를 벗어났습니다.");
		return;
	}

	katok.push_back("None");
	int kLen = len(katok);

	for (int i = kLen - 1; i > position; i--) {
		katok[i] = katok[i - 1];
		katok[i - 1] = "None";
	}
	katok[position] = data;
}

int main() {
	insert_data(2, "솔리");
	printArray(katok);
	insert_data(6, "문별");
	printArray(katok);
}



#include "header.h"

Array <int> px = { 7, -4, 0, 5 }; // = 7x^3 -4x^2 +0x^1 +5x^0
string printPoly(Array <int> p_x) {
	int term = len(p_x) - 1; // 최고차항 숫자 = 배열길이 - 1
	string polyStr = "P(x) = ";
	for (int i = 0; i < len(p_x); i++) {
		int coef = p_x[i]; // 계수
		if (coef >= 0)
			polyStr += "+";
		polyStr += to_string(coef) + "x^" + to_string(term) + " ";
		term--;
	}
	return polyStr;
}

int calcPoly(int xVal, Array <int> p_x) {
	int retValue = 0;
	int term = len(p_x) - 1; // 최고차항 숫자 = 배열길이 - 1
	for (int i = 0; i < len(p_x); i++) {
		int coef = p_x[i]; // 계수
		retValue += coef * (int)pow(xVal, term);
		term--;
	}
	return retValue;
}

int main() {
	string pStr = printPoly(px);
	println(pStr);
	int xValue;
	input(xValue, "X값 --> ");
	int pxValue = calcPoly(xValue, px);
	println(pxValue);
}



/*

#include "header.h"

typedef struct _Node{
	string data;
	struct _Node* link = NULL;
} Node;

int main() {
	Node* head;

	Node* node1 = new Node;
	node1->data = "다현";
	head = node1;

	Node* node2 = new Node;
	node2->data = "정연";
	node1->link = node2;

	Node* node3 = new Node;
	node3->data = "쯔위";
	node2->link = node3;

	Node* node4 = new Node;
	node4->data = "사나";
	node3->link = node4;

	Node* node5 = new Node;
	node5->data = "지효";
	node4->link = node5;

	node2->link = node3->link;
	delete node3;

	Node* newNode = new Node;
	newNode->data = "재남";
	newNode->link = node2->link;
	node2->link = newNode;
	
	print(head->data);
	print(head->link->data);
	print(head->link->link->data);
	print(head->link->link->link->data);
	print(head->link->link->link->link->data);
}




#include "header.h"

typedef struct _Node {
	int data; // int형 데이터
	struct _Node* link = NULL;
} Node;
Array <Node*> memory;
Node* head, * current, * pre;

void printNodes(Node* start) {
	if (start == NULL)
		return;
	Node* current = start;
	print(current->data);
	while (current->link != start) {
		current = current->link;
		print(current->data);
	}
	println("");
}

void freeMemory() {
	// 할당된 모든 노드의 메모리를 해제한다.
	for (int i = 0; i < len(memory); i++)
		delete memory[i];
}

Array <int> countOddEven() {
	// 홀수와 짝수 개수를 배열로 반환
	Array <int> retData;
	// {홀수, 짝수} 형태 배열
	int odd = 0, even = 0;

	current = head;
	while (true) {
		if (current->data % 2 != 0)
			odd++; // 홀수
		else
			even++; // 짝수
		if (current->link == head)
			break;
		current = current->link;
	}
	retData = { odd, even };
	return retData;
}

void makeZeroNumber(int odd, int even) {
	int reminder; // 나머지 값
	if (odd > even)
		reminder = 1;
	else
		reminder = 0;
	current = head;
	while (true) {
		if (current->data % 2 == reminder)
			current->data *= -1;
		if (current->link == head)
			break;
		current = current->link;
	}
}

int main() {
	randomInit(1, 100);
	Array <int> dataArray;
	for (int i = 0; i < 7; i++)
		dataArray.push_back(cookRandom(gen));
	Node* node = new Node;
	node->data = dataArray[0]; // 첫 번째 노드
	head = node;
	node->link = head;
	memory.push_back(node);
	for (int i = 1; i < len(dataArray); i++) {
		// 두 번째 이후 노드
		int data = dataArray[i];
		pre = node;
		node = new Node;
		node->data = data;
		pre->link = node;
		node->link = head;
		memory.push_back(node);
	}
	Array <int> retCount = countOddEven();
	// {홀수, 짝수}로 반환
	int oddCount = retCount[0];
	int evenCount = retCount[1];
	println("홀수 개수 --> " + to_string(oddCount));
	println("짝수 개수 --> " + to_string(evenCount));
	makeZeroNumber(oddCount, evenCount);
	printNodes(head);
	freeMemory();
}



#include "header.h"

int SIZE;
Array <string> stack;
int top = -1;

bool isStackFull() {   // 스택이 꽉 찼는지 확인하는 함수
	if (top >= SIZE - 1)
		return true;
	else
		return false;
}

bool isStackEmpty() {  // 스택이 비었는지 확인하는 함수
	if (top == -1)
		return true;
	else
		return false;
}

void push(string data) {   // 스택에 데이터를 삽입하는 함수
	if (isStackFull()) {
		println("스택이 꽉 찼습니다.");
		return;
	}
	top++;
	stack[top] = data;
}

string pop() {   // 스택에서 데이터를을 추출하는 함수
	if (isStackEmpty()) {
		println("스택이 비었습니다.");
		return "None";
	}
	string data = stack[top];
	stack[top] = "None";
	top--;
	return data;
}

string peek() {  // 스택에서 top 위치의 데이터를 확인하는 함수
	if (isStackEmpty()) {
		println("스택이 비었습니다.");
		return "None";
	}
	return stack[top];
}

int main() {
	input(SIZE, "스택 크기를 입력하세요 ==> ");
	for (int i = 0; i < SIZE; i++)
		stack.push_back("None");

	char select;
	input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ");

	string data;
	while (select != 'X' && select != 'x') {
		switch (select) {
		case 'I':
		case 'i':
			input(data, "입력할 데이터--> ");
			push(data);
			print("스택 상태 : ");
			printArray(stack);
			break;
		case 'E':
		case 'e':
			data = pop();
			println("추출한 데이터-->" + data);
			print("스택 상태 : ");
			printArray(stack);
			break;
		case 'V':
		case 'v':
			data = peek();
			println("top의 데이터 확인-->" + data);
			printArray(stack);
			break;
		default:
			println("입력이 잘못됨");
		}
		input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ");
	}
	println("프로그램 종료!");
}



#include "header.h"

int SIZE;
Array <string> queue;
int front = -1, rear = -1;

bool isQueueFull() {
	if (rear != SIZE - 1)
		return false;
	else if ((rear == SIZE - 1) && (front == - 1))
		return true;
	else {
		for (int i = front + 1; i < SIZE; i++) {
			queue[i - 1] = queue[i];
			queue[i] = "None";
		}
		front--;
		rear--;
		return false;
	}
}

bool isQuereEmpty() {
	if (front == rear)
		return true;
	else
		return false;
}

void enQueue(string data) {
	if (isQueueFull()) {
		println("큐가 꽉 찼습니다.");
		return;
	}
	rear++;
	queue[rear] = data;
}

string deQueue() {
	if (isQuereEmpty()) {
		println("큐가 비었습니다.");
		return "None";
	}
	front++;
	string data = queue[front];
	queue[front] = "None";
	return data;
}

string peek() {
	if (isQuereEmpty()) {
		println("큐가 비었습니다.");
		return "None";
	}
	return queue[front + 1];
}

int main() {
	input(SIZE, "큐 크기를 입력하세요 ==> ");
	for (int i = 0; i < SIZE; i++)
		queue.push_back("None");

	char select;
	input(select, "삽입(1)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ");

	string data;
	while (select != 'X' && select != 'X') {
		switch (select) {
		case 'I':
		case 'i':
			input(data, "입력할 데이터 --> ");
			enQueue(data);
			print("큐 상태 : ");
			printArray(queue);
			break;
		case 'E':
		case 'e':
			data = deQueue();
			println("추출한 데이터 --> " + data);
			print("큐 상태 : ");
			printArray(queue);
			break;
		case 'V':
		case 'v':
			data = peek();
			println("다음에 나올 데이터 확인 --> " + data);
			printArray(queue);
			break;
		default:
			println("입력이 잘못 됨");
		}
		input(select, "삽입(I)/추출(E)/확인(V)/종료(X) 중 하나를 선택 ==> ");
	}
	println("프로그램 종료!");
}
