#include <iostream>
#include <cassert>

class CEO { //rank1 Ŭ����
public:
	virtual void who() { //�������� ���� ���� �Լ�
		std::cout << "CEO" << std::endl;
	};
};

class CPO { //randk2 Ŭ����
public:
	virtual void who() { //�������� ���� ���� �Լ�
		std::cout << "CPO" << std::endl;
	};
};

class Manager : public CEO, public CPO { //���� ������ rank1, rank2 Ŭ������ ��� ��ӹ��� rank3 Ŭ����
public:
	void who() { //�θ� Ŭ������ ���� �Լ��� �������̵� ��
		std::cout << "Manager" << std::endl;
	};
};

class Staff : public Manager { //rank3�� Manager Ŭ������ ��ӹ��� Ŭ����
public:
	void who() { //�θ� Ŭ������ ���� �Լ��� �������̵� ��
		std::cout << "Staff" << std::endl;
	};
};

int main() {
	CPO* cpo = new Staff(); //Staff ��ü�� cpo�� �Ҵ������ν� ��ĳ������
	Staff* staff = dynamic_cast<Staff*>(cpo); //Staff* Ÿ������ cpo�� dynamic_cast��
	Manager* manager = dynamic_cast<Manager*>(cpo); //Manager* Ÿ������ cpo�� dynamic_cast��
	CEO* ceo = dynamic_cast<CEO*>(cpo); //CEO*Ÿ������ cpo�� dynamic_cast��

	assert(typeid(cpo) == typeid(Staff*)); //cpo�� Staff*�� typeid�� �ٸ��ٸ� ���� 0�� �ǹǷ� assert �޽����� ��µ�

	delete cpo; //new �����ڷ� ���� �Ҵ��� ��ü�� delete
	delete staff;
	delete manager;
	delete ceo;
}