#include <iostream>

using namespace std::string_literals;

template<typename T>
auto sum(T x) { //args의 마지막 인자에서 호출되며 넘겨받은 인자를 리턴하는 함수
  return x;
}

template<typename T, typename...Args>
auto sum(T x, Args...args) { //args의 인자를 하나씩 꺼내어 sum함수를 재귀호출한 값과 더한 값을 리턴하는 함수
  return x+sum(args...);
}

template<typename...Args>
auto average(Args...args) { //args의 인자로 sum함수를 호출해 리턴받은 값과 sizeof...함수로 args의 size를 구해 args의 인자들의 평균을 구하고 리턴하는 함수
  return sum(args...)/sizeof...(args);
}

int main() {
std::cout << average(1, 2, 3, 4, 10, 10) << std::endl; // average = 5
return 0;
}