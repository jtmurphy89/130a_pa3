#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "minTree.h"

using namespace std;


void parseInput(string inputString, min_heap *heap)
{
  int int1,int2,int3;                                                                                      Edge E;

  istringstream totalSString(inputString);
  totalSString >> int1 >> int2 >> int3;
  
  E.weight = int3;
  E.node1 = int1;
  E.node2 = int2;
  
  (*heap).push(&E);
}






int main()
{
  string firstLine, secondLine,inputString;
  min_heap heap;
  int N;
  int E;
  Edge *edge;

  getline(cin,firstLine);
  getline(cin,secondLine);

  istringstream totalSString1(firstLine);
  totalSString1 >> N;

  istringstream totalSString2(secondLine);
  totalSString2 >> E;

  for (int i = 0; i < E; i++)
    {
      getline(cin, inputString);
      parseInput(inputString, &heap); 
      /* if (inputString == "")
	break;
           if (cin.eof())
        break;
      */
      
    }

  for (int i = 0; i < E; i++)
    {
      edge =  heap.pop();
      cout << edge->weight << ' ' << edge->node1 << ' ' << edge->node2 << ' ' << endl;
    }

  return 0;
}
