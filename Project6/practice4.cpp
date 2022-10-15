#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string name, int age, string address) { //�������� �Ű������� name, age, address���� �޾� �ʱ�ȭ��
		this->name = name;
		this->age = age;
		this->address = address;
	}
	void getName() { //name�� ���
		cout << this->name << endl;
	}
	void getAge() { //age�� ���
		cout << this->age << endl;
	}
	void getAddress() { //address�� ���
		cout << this->address << endl;
	}

private:
	string name; //�̸�
	int age; //����
	string address; //�ּ�
};

class Student : Person { //Person Ŭ������ ��ӹ��� Student Ŭ����
public:
	Student(string name, int age, string address, string id) : Person(name, age, address) {
		this->id = id; //���� �߰��� ���� id�� �Ű����� ������ �ʱ�ȭ��
	}

	void printInfo() { //name, age, address, id ��� ����ϴ� �Լ�
		getName();
		getAge();
		getAddress();
		cout << this->id << endl;
	}
private:
	string id;
};

int main() {
	Student s("BaekYuJin", 10, "daejeon", "202102644"); //Student ��ü ����
	s.printInfo(); //�ļ��� Student ��ü�� ��� ���� ���
}