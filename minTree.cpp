#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "minTree.h"

using namespace std;


min_heap::min_heap()
{
  next = 1;
  Edge initial;
  heap_array.push_back(initial);
}


min_heap::~min_heap()
{



}



void min_heap::push(Edge* node)
{
  heap_array.push_back(*node); //add to array
  
  if (heap_array.size() - 1 % 2 == 1) 
      next++; //update next

  percolate_up();
}


Edge* min_heap::pop()
{
  heap_array[0] = heap_array[1]; //swap first and last nodes in array
  heap_array[1] = heap_array[heap_array.size()-1];
  heap_array[heap_array.size()-1] = heap_array[0];
  
  if(heap_array.size() - 1 % 2 == 1) //adjust next if necessary                                                                                                                     
    next --;
  
  Edge *tmp = &heap_array[heap_array.size()-1]; 

  heap_array.pop_back(); //remove from array representing min_heap


  percolate_down();
  
  //cout << "we popped successfully" << endl;
  return tmp;
}


void min_heap::percolate_up()
{
  int child = heap_array.size()-1; //initialize child node
  
  while(child > 1)
    {
      
      if (heap_array[child].weight < heap_array[child/2].weight)
	{
	  heap_array[0] = heap_array[child];       //swap the nodes if the invariant is not satisfied, 
	  heap_array[child] = heap_array[child/2]; //using the 0th position of the array as a temp;
	  heap_array[child/2] = heap_array[0];
	  
	  child = child/2;  //move up the heap to the next parent child pair to check the invariant
	}
      else    //if the invariant is satisfied
	break;
    }
}



void min_heap::percolate_down()
{
  int parent = 1;
  
  while(2*parent < heap_array.size())
    {
      if (2*parent + 1 <= heap_array.size() - 1)
	{
	  if (heap_array[parent].weight > heap_array[2*parent].weight || heap_array[parent].weight > heap_array[2*parent+1].weight)
	    {
	      if (heap_array[2*parent].weight < heap_array[2*parent+1].weight)
		{
		  heap_array[0] = heap_array[parent];
		  heap_array[parent] = heap_array[2*parent];
		  heap_array[2*parent] = heap_array[0];

		  parent = 2*parent;
		}
	      else
		{
		  heap_array[0] = heap_array[parent];
		  heap_array[parent] = heap_array[2*parent+1];
		  heap_array[2*parent+1] = heap_array[0];

		  parent = 2*parent+1;
		}
	    }
	  else
	    break;
	}
      else 
	{
	  if (heap_array[parent].weight > heap_array[2*parent].weight) 
	    {
	      heap_array[0] = heap_array[parent];
	      heap_array[parent] = heap_array[2*parent];
	      heap_array[2*parent] = heap_array[0];
	    }
	
	  break;
	}
    }
}
