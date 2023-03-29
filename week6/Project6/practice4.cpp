#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person(string name, int age, string address) { //생성자의 매개변수로 name, age, address값을 받아 초기화함
		this->name = name;
		this->age = age;
		this->address = address;
	}
	void getName() { //name을 출력
		cout << this->name << endl;
	}
	void getAge() { //age를 출력
		cout << this->age << endl;
	}
	void getAddress() { //address를 출력
		cout << this->address << endl;
	}

private:
	string name; //이름
	int age; //나이
	string address; //주소
};

class Student : Person { //Person 클래스를 상속받은 Student 클래스
public:
	Student(string name, int age, string address, string id) : Person(name, age, address) {
		this->id = id; //새로 추가된 변수 id를 매개변수 값으로 초기화함
	}

	void printInfo() { //name, age, address, id 모두 출력하는 함수
		getName();
		getAge();
		getAddress();
		cout << this->id << endl;
	}
private:
	string id;
};

int main() {
	Student s("BaekYuJin", 10, "daejeon", "202102644"); //Student 객체 생성
	s.printInfo(); //셍성한 Student 객체의 모든 정보 출력
}