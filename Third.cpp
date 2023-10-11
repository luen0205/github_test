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

*/

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