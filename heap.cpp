// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;
using std::swap;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata = std::vector<int>(start, end);

  for(int i = vdata.size() / 2 - 1; i >= 0; i--){
    int curr = i;

    while(true){
      int left = 2*curr + 1;
      int right = 2*curr + 2;
      int smallest = curr;

      if(left < vdata.size() && vdata[left] < vdata[smallest])
        smallest = left;

      if(right < vdata.size() && vdata[right] < vdata[smallest])
        smallest = right;

      if(smallest == curr) break;

      swap(vdata[curr], vdata[smallest]);
      curr = smallest;
    }
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);

  int curr = vdata.size() - 1;

  while(curr > 0){
    int parent = (curr - 1) / 2;

    if(vdata[curr] >= vdata[parent]) break;

    swap(vdata[curr], vdata[parent]);
    curr = parent;
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(vdata.empty()) return;

  swap(vdata[0], vdata[vdata.size()-1]);
  vdata.pop_back();

  int curr = 0;

  while(true){
    int left = 2*curr + 1;
    int right = 2*curr + 2;
    int smallest = curr;

    if(left < vdata.size() && vdata[left] < vdata[smallest])
      smallest = left;

    if(right < vdata.size() && vdata[right] < vdata[smallest])
      smallest = right;

    if(smallest == curr) break;

    swap(vdata[curr], vdata[smallest]);
    curr = smallest;
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