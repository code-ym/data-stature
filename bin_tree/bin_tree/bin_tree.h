#pragma once
#include <iostream>
#include <stack>
#include <utility>

template <typename T>
struct __bin_tree_node {
  T elem;
  __bin_tree_node<T>* left_child;
  __bin_tree_node<T>* right_child;

  __bin_tree_node() : elem(0), left_child(nullptr), right_child(nullptr) {}
};

template <typename T>
class BinTree {
 public:
  typedef __bin_tree_node<T> bin_node;

  BinTree() { root = new bin_node; }

  void InsertAsLeftChild(bin_node* x, T e) {
    bin_node* tmp = new bin_node;
    x->left_child = tmp;
    tmp->elem = e;
  }

  void InsertAsRightChild(bin_node* x, T e) {
    bin_node* tmp = new bin_node;
    x->right_child = tmp;
    tmp->elem = e;
  }

  void CreatTestBinTree();

  void PreOrderTraversal();

  void InOrderTraversal();

  void PostOrderTraversal();

  void Display(bin_node* x) { std::cout << x->elem << std::endl; }

  // private:
  bin_node* root;
};

template <typename T>
void BinTree<T>::CreatTestBinTree() {
  root->elem = 1;
  InsertAsLeftChild(root, 2);
  InsertAsRightChild(root, 3);
  InsertAsLeftChild(root->left_child, 4);
  InsertAsRightChild(root->left_child, 5);
  InsertAsLeftChild(root->right_child, 6);
  InsertAsRightChild(root->right_child, 7);
}

template <typename T>
void BinTree<T>::InOrderTraversal() {
  bin_node* x = root;
  std::stack<bin_node*> s;

  while (!s.empty() || x) {
    while (x) {
      s.push(x);
      x = x->left_child;
    }

    if (!s.empty()) {
      x = s.top();
      s.pop();
      std::cout << x->elem << std::endl;
      x = x->right_child;
    }
  }
}

template <typename T>
void BinTree<T>::PreOrderTraversal() {
  bin_node* x = root;
  std::stack<bin_node*> s;

  while (!s.empty() || x) {
    while (x) {
      s.push(x);
      std::cout << x->elem << std::endl;
      x = x->left_child;
    }

    if (!s.empty()) {
      x = s.top();
      s.pop();
      x = x->right_child;
    }
  }
}

template <typename T>
void BinTree<T>::PostOrderTraversal() {
  bin_node* x = root;
  std::stack<std::pair<bin_node*, int>> s;

  while (!s.empty() || x) {
    if (x) {
      s.push(std::make_pair(x, 1));
      x = x->left_child;
    } else {
      auto current = s.top();
      s.pop();
      if (current.second == 1) {
        s.push(std::make_pair(current.first, 0));
        x = current.first->right_child;
      } else {
        std::cout << current.first->elem << std::endl;
      }
    }
  }
}
