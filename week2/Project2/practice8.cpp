#include <iostream>
int main() {
	int array[3] = { 8,1,7 };
	int(&re)[3] = array;
	re[0] = 8;
	re[1] = 7;
	re[2] = 1;
	/* 코드 작성 */ // array 배열과 연결되는 레퍼런스 배열 re 정의
	/* 코드 작성 */ // re에 값 입력
	std::cout << "Array: " << array[0] << array[1] << array[2] << std::endl;
	std::cout << "Reference: " << re[0] << re[1] << re[2] << std::endl;
	return 0;
}