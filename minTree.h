#ifndef MINTREE_H
#define MINTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Edge
{
  int weight;
  int node1;
  int node2;
};

struct TNode
{
  TNode *right;
  TNode *left;
  string ch;
};


class min_heap
{

 private:
  int next;

 public:

  vector<Edge> heap_array;

  min_heap(); //default constructor                                                                                                                                                           
  ~min_heap();
  void push(Edge* node);
  Edge* pop();
  void percolate_up();
  void percolate_down();

  int getNext() { return next;};

};


#endif
