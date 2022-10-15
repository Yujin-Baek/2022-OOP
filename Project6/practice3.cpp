#include <iostream>
using namespace std;

class Ex {
public:
	Ex() { //Ex클래스의 생성자
		cout << "Constructor()" << endl;
	}
	~Ex() { //Ex클래스의 소멸자
		cout << "Destructor()" << endl;
	}
};

int main() {
	try {
		Ex ex; //Ex객체를 생성
		throw 1; //int중 아무 값이나 throw함
	}
	catch (int i) { //try문에서 던진 값이 int이므로 catch함
		cout << "Catch 10" << endl;
	}
}