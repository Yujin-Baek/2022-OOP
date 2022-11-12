#include <iostream>
#include <string>
#include <algorithm>

class Shape { //����Ŭ�������� ĸ��ȭ�� �������̽�
public:
	virtual void draw() = 0; //Shape �������̽��� ������ Ŭ�����鿡�� �����ؾ��� ���� �Լ�
};

class RoundedRectangle : public Shape { //Shape �������̽��� ������ RoundedRectangle ���� Ŭ����
public:
	void draw() { //Shape �������̽��� ���� �Լ��� �������̵� ��
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape { //Shape �������̽��� ������ RoundedSquare ���� Ŭ����
public:
	void draw() { //Shape �������̽��� ���� �Լ��� �������̵� ��
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape { //Shape �������̽��� ������ Rectangle ���� Ŭ����
public:
	void draw() { //Shape �������̽��� ���� �Լ��� �������̵� ��
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape { //Shape �������̽��� ������ Square ���� Ŭ����
public:
	void draw() { //Shape �������̽��� ���� �Լ��� �������̵� ��
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory { //ShapeFactory Ŭ������ RoundedShpaeFactory Ŭ������ ĸ��ȭ�� �������̽�
public:
	virtual Shape* getShape(std::string shapeType) = 0; //AbstractFactory �������̽��� ������ Ŭ�����鿡�� �����ؾ��� ���� �Լ�
};

class ShapeFactory : public AbstractFactory { //AbstractFactory �������̽��� ������(�Ǵ� AbstractFactoryŬ������ �����) ShapeFactory Ŭ����
public:
	Shape* getShape(std::string shapeType) { //shapeType ������ ���� ���� Rectangle ��ü �Ǵ� Square ��ü�� �����ϴ� �Լ�
		std::transform(shapeType.begin(), shapeType.end(), shapeType.begin(), ::toupper); //shapeType ���ڿ��� ���ڵ��� ��� �빮�ڷ� �ٲ�
		if (shapeType.compare("RECTANGLE") == 0) { //shapeType�� "RECTANGLE"���ڿ��� ���ٸ� Rectangle ��ü�� ������
			return new Rectangle();
		}
		else if (shapeType.compare("SQUARE") == 0) { //shapeType�� "SQUARE"���ڿ��� ���ٸ� Square ��ü�� ������
			return new Square();
		}
		return nullptr; //shapeType�� "RECTANGLE" �Ǵ� "SQUARE"���ڿ��� ���� �ʴٸ� nullptr�� ������
	}
};

class RoundedShapeFactory : public AbstractFactory { //AbstractFactory �������̽��� ������(�Ǵ� AbstractFactoryŬ������ �����) RoundedShapeFactory Ŭ����
public:
	Shape* getShape(std::string shapeType) { //shapeType ������ ���� ���� RoundedRectangle ��ü �Ǵ� RoundedSquare ��ü�� �����ϴ� �Լ�
		std::transform(shapeType.begin(), shapeType.end(), shapeType.begin(), ::toupper); //shapeType ���ڿ��� ���ڵ��� ��� �빮�ڷ� �ٲ�
		if (shapeType.compare("RECTANGLE") == 0) { //shapeType�� "RECTANGLE"���ڿ��� ���ٸ� RoundedRectangle ��ü�� ������
			return new RoundedRectangle();
		}
		else if (shapeType.compare("SQUARE") == 0) { //shapeType�� "RECTANGLE"���ڿ��� ���ٸ� RoundedSquare ��ü�� ������
			return new RoundedSquare();
		}
		return nullptr; //shapeType�� "RECTANGLE" �Ǵ� "SQUARE"���ڿ��� ���� �ʴٸ� nullptr�� ������
	}
};

class FactoryProducer { //RoundedShapeFactory ��ü�� �������� ShapeFactory ��ü�� �������� �����ϴ� Ŭ����
public:
	static AbstractFactory* getFactory(bool rounded) { //rounded ������ ��(true, false)�� ���� RoundedShapeFactory ��ü �Ǵ� ShapeFactory ��ü�� �����ϴ� �Լ�
		if (rounded) { //rounded�� ���� true��� RoundedShapeFactory ��ü�� ������
			return new RoundedShapeFactory();
		}
		else { //rounded�� ���� false��� ShapeFactory ��ü�� ������
			return new ShapeFactory();
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false); //getFactory�Լ��� ���ڸ� false�̹Ƿ� ShapeFactory ��ü�� ���ϵ�
	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); //getShape�Լ��� ���ڰ� "RECTANGLE"�̹Ƿ� Rectangle ��ü�� ���ϵ�
	shape1->draw(); //shape1�� Rectangle ��ü�̹Ƿ� Rectangle Ŭ������ ���ǵ� draw�Լ��� ȣ���

	Shape* shape2 = shapeFactory->getShape("SQUARE"); //getShape�Լ��� ���ڰ� "SQUARE"�̹Ƿ� Square ��ü�� ���ϵ�
	shape2->draw(); //shape1�� Square ��ü�̹Ƿ� Square Ŭ������ ���ǵ� draw�Լ��� ȣ���

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true); //getFactory�Լ��� ���ڸ� false�̹Ƿ� RoundedShapeFactory ��ü�� ���ϵ�
	Shape* shape3 = shapeFactory1->getShape("RECTANGLE"); //getShape�Լ��� ���ڰ� "RECTANGLE"�̹Ƿ� RoundedRectangle ��ü�� ���ϵ�
	shape3->draw(); //shape1�� RoundedRectangle ��ü�̹Ƿ� RoundedRectangle Ŭ������ ���ǵ� draw�Լ��� ȣ���

	Shape* shape4 = shapeFactory1->getShape("SQUARE"); //getShape�Լ��� ���ڰ� "SQUARE"�̹Ƿ� RoundedSquare ��ü�� ���ϵ�
	shape4->draw(); //shape1�� RoundedSquare ��ü�̹Ƿ� RoundedSquare Ŭ������ ���ǵ� draw�Լ��� ȣ���
}