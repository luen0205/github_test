/*

#include "header.h"

Array <string> katok;
void add_data(string data) {
	katok.push_back("None");
	int kLen = len(katok);
	katok[kLen - 1] = data;
}

int main() {
	add_data("����");
	add_data("����");
	add_data("����");
	add_data("�糪");
	add_data("��ȿ");

	printArray(katok);



/*

Array <string> katok = { "����", "����", "����", "�糪", "��ȿ" };

void insert_data(int position, string data) {
	if ((position < 0) || (position > len(katok))) {
		print("�����͸� ������ ������ ������ϴ�.");
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
	insert_data(2, "�ָ�");
	printArray(katok);
	insert_data(6, "����");
	printArray(katok);
}

*/