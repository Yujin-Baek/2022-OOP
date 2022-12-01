#include <iostream>

class Shape { //가장 상위 인터페이스
  public:
    virtual void draw() = 0;
};

class Rectangle : public Shape { //Shape 인터페이스를 상속받아 Rectangle 객체를 생성하는 클래스
  public:
    void draw() { //Rectangle 객체의 모양을 출력하도록 오버라이딩된 함수
      std::cout << "Shape: Rectangle" << std::endl;
    }
};

class Circle : public Shape { //Shape 인터페이스를 상속받아 Circle 객체를 생성하는 클래스
  public:
    void draw() { //Circle 객체의 모양을 출력하도록 오버라이딩된 함수
      std::cout << "Shape: Circle" << std::endl;
    }
};

class ShapeDecorator : public Shape { //Shape 인터페이스를 상속받아 Shape 객체를 꾸며주는 클래스
  protected:
    Shape* decoratedShape; //Shape 객체에 접근하기 위한 포인터

  public:
    ShapeDecorator(Shape* decoratedShape) {
      this->decoratedShape = decoratedShape; //포인터를 넘겨받은 Shape 객체의 포인터로 초기화한다
    }

    void draw() { //Shape 객체의 포인터로 그 Shape 객체의 draw() 함수를 호출한다
      decoratedShape->draw();
    }
};

class RedShapeDecorator : public ShapeDecorator { //Shape 객체를 꾸미는 ShapeDecorator 클래스를 상속받아 확장한 클래스
  public:
    RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {} //Shape 객체는 넘겨받은 Shape 객체의 포인터로 값을 초기화한다

    void draw() { //ShapeDecorator의 draw() 함수를 확장함(setRedBorder() 함수 추가)
      decoratedShape->draw(); //Shape 객체의 포인터로 그 Shape 객체의 draw() 함수를 호출한다
      setRedBorder(decoratedShape); //Shape 객체의 포인터를 함수의 인자로 넘겨준다
    }

  private:
    void setRedBorder(Shape* decoratedShape) { //넘겨받은 Shape 포인터로 setRedBorder() 함수가 호출된다
      std::cout << "Border Color: Red" << std::endl;
    }
};

int main() {
  Shape* circle = new Circle(); //Shape 인터페이스를 상속받은 Circle 객체를 생성한다
  
  Shape* redCircle = new RedShapeDecorator(new Circle()); //Circle 객체를 생성하는데 꾸며주기 위해 RedShapeDecorator로 객체를 생성하고, 인자로 Shape 객체인 Circle 객체를 생성해 넘겨준다

  Shape* redRectangle = new RedShapeDecorator(new Rectangle()); //Rectangle 객체를 생성하는데 꾸며주기 위해 RedShapeDecorator로 객체를 생성하고, 인자로 Shape 객체인 Rectangle 객체를 생성해 넘겨준다
  std::cout << "Circle with normal border" << std::endl;
  circle->draw(); //생성한 객체에 해당하는 draw() 함수를 호출한다

  std::cout << "\nCircle of red border" << std::endl;
  redCircle->draw(); //생성한 객체에 해당하는 draw() 함수를 호출한다

  std::cout << "\nRectangle of red border" << std::endl;
  redRectangle->draw(); //생성한 객체에 해당하는 draw() 함수를 호출한다
}