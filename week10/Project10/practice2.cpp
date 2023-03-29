#include <iostream>

class DrawAPI { //구현부의 인터페이스
public:
	virtual void drawCircle(int radius, int x, int y) = 0; //Circle의 속성을 출력하는 가상 함수를 가짐
};

class RedCircle : public DrawAPI { //DrawAPI를 구현한 클래스
public:
	void drawCircle(int radius, int x, int y) { //DrawAPI 인터페이스의 가상 함수를 구현함
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class GreenCircle : public DrawAPI { //DrawAPI를 구현한 클래스
public:
	void drawCircle(int radius, int x, int y) { //DrawAPI 인터페이스의 가상 함수를 구현함
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class Shape { //Circle을 캡슐화하고 DrawAPI 인터페이스와 연결해줄 클래스
protected:
	DrawAPI* drawAPI; //DrawAPI 인터페이스에 접근하기 위한 포인터

	Shape(DrawAPI* drawAPI) { //생성자의 인자로 받은 drawAPI 포인터로 this의 drawAPI를 초기화함
		this->drawAPI = drawAPI;
	}
public: //Shape 클래스를 상속받은 Circle에서 구현할 가상함수
	virtual void draw() = 0;
};

class Circle : public Shape { //Shape 클래스를 상속받은 클래스
private:
	int x, y, radius; //Circle의 속성인 x, y, radius 변수
public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI) { //drawAPI는 상속받은 클래스에서 초기화된 값 그대로 초기화하고, 나머지 인자들은 넘겨받은 값으로 초기화함
		this->x = x;
		this->y = y;
		this->radius = radius;
	}
	void draw() { //실질적인 구현은 인터페이스인 DrawAPI에 되어 있으므로 drawAPI 포인터를 이용해 함수에 접근함
		drawAPI->drawCircle(radius, x, y);
	}
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); //Circle 객체를 생성하고 부모 클래스인 Shape의 포인터 타입으로 그 객체에 접근할 수 있도록 함
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

	redCircle->draw(); //부모 클래스의 포인터타입으로 draw함수에 접근하여 호출함
	greenCircle->draw();
}