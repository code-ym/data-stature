#pragma once
#include <iostream>

template <typename T>
struct __list_node {
  __list_node<T>* prev;
  __list_node<T>* next;
  T data;
};

template <typename T>
struct __list_iterator {
  typedef __list_node<T> list_node;
  typedef list_node* link_type;
  typedef __list_iterator<T> iterator;

  link_type node;

  __list_iterator() : node(nullptr) {}

  __list_iterator(link_type x) : node(x) {}
  __list_iterator(const iterator& x) : node(x.node) {}

  bool operator==(const iterator& x) { return node == x.node; }

  bool operator!=(const iterator& x) { return node != x.node; }

  iterator& operator++() {
    node = node->next;
    return *this;
  }

  iterator operator++(int) {
    iterator tmp = *this;
    ++*this;
    return tmp;
  }

  iterator& operator--() {
    node = node->prev;
    return *this;
  }

  iterator operator--(int) {
    iterator tmp = *this;
    --*this;
    return tmp;
  }

  T& operator*() const { return node->data; }

  T* operator->() const { return *node; }
};

template <typename T>
class list {
 private:
  int length;
  __list_node<T>* header;
  __list_node<T>* trailer;

 public:
  typedef __list_node<T> list_node;
  typedef list_node* link_type;
  typedef __list_iterator<T> iterator;

  list() { init(); }

  void init() {
    length = 0;
    header = new list_node();
    trailer = new list_node();
    header->next = trailer;
    header->prev = nullptr;
    trailer->next = nullptr;
    trailer->prev = header;
  }

  iterator begin() const { return header->next; }

  iterator end() const { return trailer; }

  void push_front(const T& e) { insert(begin(), e); }

  void push_back(const T& e) { insert(end(), e); }

  void pop_front() { erase(begin()); }

  void pop_back() { erase(--end()); }

  iterator insert(iterator pos, const T& e) {
    link_type tmp = new list_node();
    tmp->next = pos.node;
    tmp->prev = pos.node->prev;
    pos.node->prev->next = tmp;
    pos.node->prev = tmp;

    tmp->data = e;
    ++length;
    return tmp;
  }

  iterator erase(iterator pos) {
    link_type next_node = link_type(pos.node->next);
    link_type prev_node = link_type(pos.node->prev);
    next_node->prev = prev_node;
    prev_node->next = next_node;
    delete pos.node;
    --length;

    return next_node;
  }

  void display() const {
    iterator first = begin();
    iterator last = end();
    while (first != last) {
      std::cout << first.node->data << std::endl;
      ++first;
    }
  }
};
