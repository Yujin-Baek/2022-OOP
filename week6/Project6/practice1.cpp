#include <iostream>

using namespace std;

class Class { //������ų ��ü�� Ŭ����
private:
    int a;
public:
    Class() {
        a = 5; //a �ʱⰪ �ʱ�ȭ
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
    cout << a << endl; //a �ʱⰪ ���
    a++;
    cout << a << endl; //a ���� ���� ��� ���
    ++a;
    cout << a << endl; //a ���� ���� ��� ���
}