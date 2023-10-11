/*

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

*/