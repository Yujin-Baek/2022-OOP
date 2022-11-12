#include <iostream>

class BaseClass { //�θ� Ŭ����
public:
	virtual void print() { //�������� ���� ���� �Լ�
		std::cout << "This is BaseClass" << std::endl;
	};
};

class DerivedClass : public BaseClass { //�θ� Ŭ������ BaseClass�� ��ӹ��� �ڽ� Ŭ����
public:
	void print() { //�θ� Ŭ������ ���� �Լ��� �������̵��� �Լ�
		std::cout << "This is DerivedClass" << std::endl;
	}
};

int main() {
	BaseClass* base = new DerivedClass(); //�θ�Ŭ���� Ÿ���� �����ͷ� �ڽ�Ŭ������ ��ü�� ��ĳ������
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base); //�ڽ�Ŭ���� Ÿ���� �����ͷ� �θ�Ŭ������ ��ü�� dynamic_cast��

	if (base != nullptr && derived != nullptr) { //�� ��ü�� ��� �� �Ҵ�Ǿ����� üũ��(���� nullptr�̶�� ��ü�� �������� ������)
		std::cout << "Everything is OKAY" << std::endl; //�� ��ü�� ��� �� �Ҵ�Ǿ��ٸ� "Everything is OKAY"�� �����
	}
	else {
		std::cout << "Wrong Output" << std::endl; //�� ��ü�� �ϳ��� �� �Ҵ���� �ʾҴٸ� "Wrong Output"�� �����
	}
}