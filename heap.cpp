// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;
// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata = std::vector<int>(start, end);
  for(int i = vdata.size() / 2 - 1; i >= 0; i--){
    // heapify down from index i
    if(vdata[i] > vdata[2*i + 1]){
      std::swap(vdata[i], vdata[2*i + 1]);
    }
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
vdata.push_back(value);
vdata = Heap(vdata.begin(), vdata.end()).vdata;
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(!vdata.empty()){
    vdata[0] = vdata.back();
    vdata.pop_back();
    vdata = Heap(vdata.begin(), vdata.end()).vdata;
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    