#include <iostream>

class BaseClass { //부모 클래스
public:
	virtual void print() { //다형성을 위한 가상 함수
		std::cout << "This is BaseClass" << std::endl;
	};
};

class DerivedClass : public BaseClass { //부모 클래스인 BaseClass를 상속받은 자식 클래스
public:
	void print() { //부모 클래스의 가상 함수를 오버라이딩한 함수
		std::cout << "This is DerivedClass" << std::endl;
	}
};

int main() {
	BaseClass* base = new DerivedClass(); //부모클래스 타입의 포인터로 자식클래스의 객체를 업캐스팅함
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base); //자식클래스 타입의 포인터로 부모클래스의 객체를 dynamic_cast함

	if (base != nullptr && derived != nullptr) { //두 객체가 모두 잘 할당되었는지 체크함(만약 nullptr이라면 객체가 생성되지 않은것)
		std::cout << "Everything is OKAY" << std::endl; //두 객체가 모두 잘 할당되었다면 "Everything is OKAY"를 출력함
	}
	else {
		std::cout << "Wrong Output" << std::endl; //두 객체중 하나라도 잘 할당되지 않았다면 "Wrong Output"을 출력함
	}
}