#include <iostream>
using namespace std;

class Ex {
public:
	Ex() { //ExŬ������ ������
		cout << "Constructor()" << endl;
	}
	~Ex() { //ExŬ������ �Ҹ���
		cout << "Destructor()" << endl;
	}
};

int main() {
	try {
		Ex ex; //Ex��ü�� ����
		throw 1; //int�� �ƹ� ���̳� throw��
	}
	catch (int i) { //try������ ���� ���� int�̹Ƿ� catch��
		cout << "Catch 10" << endl;
	}
}