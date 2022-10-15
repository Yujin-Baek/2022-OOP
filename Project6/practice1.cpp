#include <iostream>

using namespace std;

class Class { //증가시킬 객체의 클래스
private:
    int a;
public:
    Class() {
        a = 5; //a 초기값 초기화
    }

    //prefix unary
    Class operator++() {
        a += 1;
        return *this;
    }

    //postfix unary
    Class operator++(int) {
        a += 1;
        return *this;
    }

    //ostream overoading
    friend ostream& operator << (ostream& os, const Class& c) {
        os << c.a;
        return os;
    }
};

int main() {
    Class a;
    cout << a << endl; //a 초기값 출력
    a++;
    cout << a << endl; //a 후위 연산 결과 출력
    ++a;
    cout << a << endl; //a 전위 연산 결과 출력
}