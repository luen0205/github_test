#include "header.h"

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