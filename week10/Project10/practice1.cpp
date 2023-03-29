#include <iostream>
#include <string>
#include <algorithm>

class Shape { //도형클래스들을 캡슐화한 인터페이스
public:
	virtual void draw() = 0; //Shape 인터페이스를 구현한 클래스들에서 구현해야할 가상 함수
};

class RoundedRectangle : public Shape { //Shape 인터페이스를 구현한 RoundedRectangle 도형 클래스
public:
	void draw() { //Shape 인터페이스의 가상 함수를 오버라이딩 함
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape { //Shape 인터페이스를 구현한 RoundedSquare 도형 클래스
public:
	void draw() { //Shape 인터페이스의 가상 함수를 오버라이딩 함
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape { //Shape 인터페이스를 구현한 Rectangle 도형 클래스
public:
	void draw() { //Shape 인터페이스의 가상 함수를 오버라이딩 함
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape { //Shape 인터페이스를 구현한 Square 도형 클래스
public:
	void draw() { //Shape 인터페이스의 가상 함수를 오버라이딩 함
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory { //ShapeFactory 클래스와 RoundedShpaeFactory 클래스를 캡슐화한 인터페이스
public:
	virtual Shape* getShape(std::string shapeType) = 0; //AbstractFactory 인터페이스를 구현한 클래스들에서 구현해야할 가상 함수
};

class ShapeFactory : public AbstractFactory { //AbstractFactory 인터페이스를 구현한(또는 AbstractFactory클래스를 상속한) ShapeFactory 클래스
public:
	Shape* getShape(std::string shapeType) { //shapeType 변수의 값에 따라 Rectangle 객체 또는 Square 객체를 리턴하는 함수
		std::transform(shapeType.begin(), shapeType.end(), shapeType.begin(), ::toupper); //shapeType 문자열의 문자들을 모두 대문자로 바꿈
		if (shapeType.compare("RECTANGLE") == 0) { //shapeType이 "RECTANGLE"문자열과 같다면 Rectangle 객체를 리턴함
			return new Rectangle();
		}
		else if (shapeType.compare("SQUARE") == 0) { //shapeType이 "SQUARE"문자열과 같다면 Square 객체를 리턴함
			return new Square();
		}
		return nullptr; //shapeType이 "RECTANGLE" 또는 "SQUARE"문자열과 같지 않다면 nullptr을 리턴함
	}
};

class RoundedShapeFactory : public AbstractFactory { //AbstractFactory 인터페이스를 구현한(또는 AbstractFactory클래스를 상속한) RoundedShapeFactory 클래스
public:
	Shape* getShape(std::string shapeType) { //shapeType 변수의 값에 따라 RoundedRectangle 객체 또는 RoundedSquare 객체를 리턴하는 함수
		std::transform(shapeType.begin(), shapeType.end(), shapeType.begin(), ::toupper); //shapeType 문자열의 문자들을 모두 대문자로 바꿈
		if (shapeType.compare("RECTANGLE") == 0) { //shapeType이 "RECTANGLE"문자열과 같다면 RoundedRectangle 객체를 리턴함
			return new RoundedRectangle();
		}
		else if (shapeType.compare("SQUARE") == 0) { //shapeType이 "RECTANGLE"문자열과 같다면 RoundedSquare 객체를 리턴함
			return new RoundedSquare();
		}
		return nullptr; //shapeType이 "RECTANGLE" 또는 "SQUARE"문자열과 같지 않다면 nullptr을 리턴함
	}
};

class FactoryProducer { //RoundedShapeFactory 객체를 생성할지 ShapeFactory 객체를 생성할지 결정하는 클래스
public:
	static AbstractFactory* getFactory(bool rounded) { //rounded 변수의 값(true, false)에 따라 RoundedShapeFactory 객체 또는 ShapeFactory 객체를 리턴하는 함수
		if (rounded) { //rounded의 값이 true라면 RoundedShapeFactory 객체를 리턴함
			return new RoundedShapeFactory();
		}
		else { //rounded의 값이 false라면 ShapeFactory 객체를 리턴함
			return new ShapeFactory();
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false); //getFactory함수의 인자를 false이므로 ShapeFactory 객체가 리턴됨
	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); //getShape함수의 인자가 "RECTANGLE"이므로 Rectangle 객체가 리턴됨
	shape1->draw(); //shape1이 Rectangle 객체이므로 Rectangle 클래스에 정의된 draw함수가 호출됨

	Shape* shape2 = shapeFactory->getShape("SQUARE"); //getShape함수의 인자가 "SQUARE"이므로 Square 객체가 리턴됨
	shape2->draw(); //shape1이 Square 객체이므로 Square 클래스에 정의된 draw함수가 호출됨

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true); //getFactory함수의 인자를 false이므로 RoundedShapeFactory 객체가 리턴됨
	Shape* shape3 = shapeFactory1->getShape("RECTANGLE"); //getShape함수의 인자가 "RECTANGLE"이므로 RoundedRectangle 객체가 리턴됨
	shape3->draw(); //shape1이 RoundedRectangle 객체이므로 RoundedRectangle 클래스에 정의된 draw함수가 호출됨

	Shape* shape4 = shapeFactory1->getShape("SQUARE"); //getShape함수의 인자가 "SQUARE"이므로 RoundedSquare 객체가 리턴됨
	shape4->draw(); //shape1이 RoundedSquare 객체이므로 RoundedSquare 클래스에 정의된 draw함수가 호출됨
}