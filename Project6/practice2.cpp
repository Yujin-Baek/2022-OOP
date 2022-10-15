#include <iostream>
#include <exception>
using namespace std;

class Ex : public std::exception { //Ŭ���� Ex�� exceptionŬ������ ��ӹ���
public:
	int c; //a/b�� ����� ������ ����

	void div(int a, int b) { //a/b�� ����� c�� �����ϴ� ����� �ϴ� �Լ�
		if (b == 0) throw Ex(); //b�� 0�̶�� ����ó���� ����� �ϹǷ� Ex��ü�� throw��
		else cout << "c = " << a / b << endl; //b�� 0�� �ƴ϶�� c�� a/b ����� ������
	}

	const char* what() {
		return "NewException"; //what �޼��� �������̵�
	}
};

int main() {

	int a, b; //����ڷκ��� �Է¹��� �� ����

	cin >> a >> b; //����ڷκ��� a�� b���� �Է¹���

	Ex ex; //Ex�� ��ü ����

	try {
		ex.div(a, b); //ExŬ������ div�Լ��� ȣ���ϸ� b�� 0�� ��쿡 ���ܰ� �߻��ϹǷ� try�� �ȿ� �ۼ�
	}
	catch (Ex& ex) { //exception Ŭ������ ��ӹ��� ExŬ������ ��ü���� �߻��� ���ܸ� catch��
		cout << "My exception is ";
		cout << ex.what() << endl; //�������̵��� what �޼����� ������ �����
	}
	return 0;
}