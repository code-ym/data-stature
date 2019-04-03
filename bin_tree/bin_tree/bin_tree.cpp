#include "bin_tree.h"

int main() {
  BinTree<int> test;
  test.CreatTestBinTree();
  std::cout << "先序遍历的结果为：" << std::endl;
  test.PreOrderTraversal();
  std::cout << "中序遍历的结果为：" << std::endl;
  test.InOrderTraversal();
  std::cout << "后序遍历" << std::endl;
  test.PostOrderTraversal();
}
