/*

#include "header.h"

typedef struct _Node{
	string data;
	struct _Node* link = NULL;
} Node;

int main() {
	Node* head;

	Node* node1 = new Node;
	node1->data = "����";
	head = node1;

	Node* node2 = new Node;
	node2->data = "����";
	node1->link = node2;

	Node* node3 = new Node;
	node3->data = "����";
	node2->link = node3;

	Node* node4 = new Node;
	node4->data = "�糪";
	node3->link = node4;

	Node* node5 = new Node;
	node5->data = "��ȿ";
	node4->link = node5;

	node2->link = node3->link;
	delete node3;

	Node* newNode = new Node;
	newNode->data = "�糲";
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
	int data; // int�� ������
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
	// �Ҵ�� ��� ����� �޸𸮸� �����Ѵ�.
	for (int i = 0; i < len(memory); i++)
		delete memory[i];
}

Array <int> countOddEven() {
	// Ȧ���� ¦�� ������ �迭�� ��ȯ
	Array <int> retData;
	// {Ȧ��, ¦��} ���� �迭
	int odd = 0, even = 0;

	current = head;
	while (true) {
		if (current->data % 2 != 0)
			odd++; // Ȧ��
		else
			even++; // ¦��
		if (current->link == head)
			break;
		current = current->link;
	}
	retData = { odd, even };
	return retData;
}

void makeZeroNumber(int odd, int even) {
	int reminder; // ������ ��
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
	node->data = dataArray[0]; // ù ��° ���
	head = node;
	node->link = head;
	memory.push_back(node);
	for (int i = 1; i < len(dataArray); i++) {
		// �� ��° ���� ���
		int data = dataArray[i];
		pre = node;
		node = new Node;
		node->data = data;
		pre->link = node;
		node->link = head;
		memory.push_back(node);
	}
	Array <int> retCount = countOddEven();
	// {Ȧ��, ¦��}�� ��ȯ
	int oddCount = retCount[0];
	int evenCount = retCount[1];
	println("Ȧ�� ���� --> " + to_string(oddCount));
	println("¦�� ���� --> " + to_string(evenCount));
	makeZeroNumber(oddCount, evenCount);
	printNodes(head);
	freeMemory();
}