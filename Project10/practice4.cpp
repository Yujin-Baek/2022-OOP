#include <iostream>
#include <cassert>

class CEO { //rank1 클래스
public:
	virtual void who() { //다형성을 위한 가상 함수
		std::cout << "CEO" << std::endl;
	};
};

class CPO { //randk2 클래스
public:
	virtual void who() { //다형성을 위한 가상 함수
		std::cout << "CPO" << std::endl;
	};
};

class Manager : public CEO, public CPO { //상위 계층인 rank1, rank2 클래스를 모두 상속받은 rank3 클래스
public:
	void who() { //부모 클래스의 가상 함수를 오버라이딩 함
		std::cout << "Manager" << std::endl;
	};
};

class Staff : public Manager { //rank3인 Manager 클래스를 상속받은 클래스
public:
	void who() { //부모 클래스의 가상 함수를 오버라이딩 함
		std::cout << "Staff" << std::endl;
	};
};

int main() {
	CPO* cpo = new Staff(); //Staff 객체를 cpo에 할당함으로써 업캐스팅함
	Staff* staff = dynamic_cast<Staff*>(cpo); //Staff* 타입으로 cpo를 dynamic_cast함
	Manager* manager = dynamic_cast<Manager*>(cpo); //Manager* 타입으로 cpo를 dynamic_cast함
	CEO* ceo = dynamic_cast<CEO*>(cpo); //CEO*타입으로 cpo를 dynamic_cast함

	assert(typeid(cpo) == typeid(Staff*)); //cpo와 Staff*의 typeid가 다르다면 값이 0이 되므로 assert 메시지가 출력됨

	delete cpo; //new 연산자로 동적 할당한 객체를 delete
	delete staff;
	delete manager;
	delete ceo;
}