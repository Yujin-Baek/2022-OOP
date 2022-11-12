#include <iostream>

class DrawAPI { //�������� �������̽�
public:
	virtual void drawCircle(int radius, int x, int y) = 0; //Circle�� �Ӽ��� ����ϴ� ���� �Լ��� ����
};

class RedCircle : public DrawAPI { //DrawAPI�� ������ Ŭ����
public:
	void drawCircle(int radius, int x, int y) { //DrawAPI �������̽��� ���� �Լ��� ������
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class GreenCircle : public DrawAPI { //DrawAPI�� ������ Ŭ����
public:
	void drawCircle(int radius, int x, int y) { //DrawAPI �������̽��� ���� �Լ��� ������
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << std::endl;
	}
};

class Shape { //Circle�� ĸ��ȭ�ϰ� DrawAPI �������̽��� �������� Ŭ����
protected:
	DrawAPI* drawAPI; //DrawAPI �������̽��� �����ϱ� ���� ������

	Shape(DrawAPI* drawAPI) { //�������� ���ڷ� ���� drawAPI �����ͷ� this�� drawAPI�� �ʱ�ȭ��
		this->drawAPI = drawAPI;
	}
public: //Shape Ŭ������ ��ӹ��� Circle���� ������ �����Լ�
	virtual void draw() = 0;
};

class Circle : public Shape { //Shape Ŭ������ ��ӹ��� Ŭ����
private:
	int x, y, radius; //Circle�� �Ӽ��� x, y, radius ����
public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI) { //drawAPI�� ��ӹ��� Ŭ�������� �ʱ�ȭ�� �� �״�� �ʱ�ȭ�ϰ�, ������ ���ڵ��� �Ѱܹ��� ������ �ʱ�ȭ��
		this->x = x;
		this->y = y;
		this->radius = radius;
	}
	void draw() { //�������� ������ �������̽��� DrawAPI�� �Ǿ� �����Ƿ� drawAPI �����͸� �̿��� �Լ��� ������
		drawAPI->drawCircle(radius, x, y);
	}
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); //Circle ��ü�� �����ϰ� �θ� Ŭ������ Shape�� ������ Ÿ������ �� ��ü�� ������ �� �ֵ��� ��
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

	redCircle->draw(); //�θ� Ŭ������ ������Ÿ������ draw�Լ��� �����Ͽ� ȣ����
	greenCircle->draw();
}