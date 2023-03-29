#include <iostream>
#include <algorithm>
#include <forward_list>
template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
  for(ForwardIterator sorted=first; first!=last; last=sorted) { //sorted는 이미 정렬이 끝난 변수를 가리킴 first부터 시작해 last값을 새로운 sorted값으로 업데이트 해나가다 first와 last값이 같아지면 for문을 종료한다
    sorted = first; //루프를 다시 돌 때 위에서 last의 값은 sorted값으로 업데이트해주고 새 루프를 돌아야 하므로 sorted값은 first로 설정한다.
    for (ForwardIterator current=first, prev=first; ++current!=last; ++prev) { //current는 조건문에서 전위연산자로 증가하고, prev는 반복문이 실행된다음 전위연산자로 증가하므로 prev는 항상 current보다 하나 이전의 값으로, current가 last와 값이 같아지기 전까지 하나 이전의 값과 비교해 나간다
      if (comp(*current, *prev)) { //comp() 함수의 리턴 값이 참이라면
        std::iter_swap(current, prev); //current와 prev의 자리를 바꾼다
        sorted = current; //sorted값은 다음 루프에서 어디까지 정렬이 됐는지 알아야 하므로 자리가 바뀔 때마다 current값으로 업데이트한다
      }
    }
  }
}
class compGreater {

public:
  bool operator()(int x, int y) { //y가 즉, bubble_sort에서 prev 값이 더 크면 true를 리턴하는 함수
    return x < y;
  }
};
class compLess {
public:
  bool operator()(int x, int y) { //x가 즉, bubble_sort에서 current값이 더 크면 true를 리턴하는 함수
    return x > y;
  }
};
int main() {
std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };
std::cout << "오름차순 정렬" << std::endl;

compGreater greater; //오름차순으로 정렬하는 함수를 가진 클래스의 객체
bubble_sort(values.begin(), values.end(), greater); //bubble_sort()의 첫번째, 두번째 인자는 리스트의 시작과 끝을 가리키는 iterator, 마지막 인자는 정렬 기준이 되는 객체를 넘겨준다
for(auto &v : values) std::cout << v << " ";
std::cout << std::endl;
std::cout << "내림차순 정렬" << std::endl;

compLess less; //내림차순으로 정렬하는 함수를 가진 클래스의 객체
bubble_sort(values.begin(), values.end(), less); //bubble_sort()의 첫번째, 두번째 인자는 리스트의 시작과 끝을 가리키는 iterator, 마지막 인자는 정렬 기준이 되는 객체를 넘겨준다
for(auto &v : values) std::cout << v << " ";
std::cout << std::endl;
return 0;
}