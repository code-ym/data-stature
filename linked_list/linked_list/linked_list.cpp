#include "linked_list.h"

int main() {

  list<int> a;
  a.push_front(3);
  a.push_back(5);
  a.display();
  std::cout << "------------" << std::endl;
  a.pop_back();
  a.display();

  return 0;
}