#include <iostream>
#include <exception>
using namespace std;

class Ex : public std::exception { //클래스 Ex가 exception클래스를 상속받음
public:
	int c; //a/b의 결과를 저장할 변수

	void div(int a, int b) { //a/b의 결과를 c에 저장하는 기능을 하는 함수
		if (b == 0) throw Ex(); //b가 0이라면 예외처리를 해줘야 하므로 Ex객체를 throw함
		else cout << "c = " << a / b << endl; //b가 0이 아니라면 c에 a/b 결과를 저장함
	}

	const char* what() {
		return "NewException"; //what 메서드 오버라이딩
	}
};

int main() {

	int a, b; //사용자로부터 입력받을 두 변수

	cin >> a >> b; //사용자로부터 a와 b값을 입력받음

	Ex ex; //Ex의 객체 생성

	try {
		ex.div(a, b); //Ex클래스의 div함수를 호출하면 b가 0인 경우에 예외가 발생하므로 try문 안에 작성
	}
	catch (Ex& ex) { //exception 클래스를 상속받은 Ex클래스의 객체에서 발생한 예외를 catch함
		cout << "My exception is ";
		cout << ex.what() << endl; //오버라이딩된 what 메서드의 내용을 출력함
	}
	return 0;
}