#include <cassert>
#include "DList.cpp"
#include "DListNode.cpp"
#include "LockDList.cpp"
#include "LockDListNode.cpp"
using namespace std;

int main() {
  cout << "====================" << endl;
  cout << "Part 1 Testing DList" << endl;
  cout << "====================" << endl;
  DList<int> d1;
  DList<int> dempty;

  cout << "Insert 3 items(1,3,999) at the front of this DList.";
  d1.insertFront(1);
  d1.insertFront(3);
  d1.insertFront(999);
  assert((d1.length() == 3) && (d1.isEmpty() == false));
  cout << "->OK" << endl;

  cout << "Insert 2 items(2,222) at the back of this DList.";
  d1.insertBack(2); 
  d1.insertBack(222);
  assert(d1.length() == 5);
  cout << "->OK" << endl;
  
  cout << "999 is at the front of this DList.";
  assert(d1.front()->item == 999);
  cout << "->OK" << endl;
  cout << "If the DList is empty, front() return null."; 
  assert(!dempty.front());
  cout << "->OK" << endl;
  
  cout << "222 is at the back of this DList.";
  assert(d1.back()->item == 222); 
  cout << "->OK" << endl;
  cout << "If the DList is empty, back() return null."; 
  assert(!dempty.back());
  cout << "->OK" << endl;

  cout << "The node following 999 is 3";
  assert(d1.next(d1.front())->item == 3);
  cout << ",and the node following 3 is 1.";
  assert(d1.next(d1.next(d1.front()))->item == 1);
  cout << "->OK" << endl;
  cout << "222 is the last node in this DList, return null.";
  assert(!(d1.next(d1.back())));
  cout << "->OK" << endl;
  cout << "If input is null,return null.";
  assert(!(d1.next(NULL)));
  cout << "->OK" << endl;

  cout << "The node prior to 222 is 2";
  assert(d1.prev(d1.back())->item == 2);
  cout << ",and the node prior to 2 is 1.";
  assert(d1.prev(d1.prev(d1.back()))->item == 1);
  cout << "->OK" << endl;
  cout << "999 is the first node in this DList, return null.";
  assert(!(d1.prev(d1.front())));
  cout << "->OK" << endl;
  cout << "If input is null,return null.";
  assert(!(d1.prev(NULL)));
  cout << "->OK" << endl;
  
  cout << endl;
  cout << "insertAfter() Test:" << endl;
  cout << "[999 3 1 2 222]->[999 3 12345 1 2 222 123456]" << endl;
  d1.toString();
  d1.insertAfter(12345, d1.next(d1.front()));
  assert(d1.next(d1.next(d1.front()))->item == 12345);
  d1.insertAfter(123456, d1.back());
  assert(d1.back()->item == 123456);
  d1.toString();
  cout << endl;
  cout << "insertAfter(item,NULL) do nothing.";
  d1.insertAfter(1,NULL);
  cout << "->OK" << endl;

  cout << endl;
  cout << "insertBefore() Test:" << endl;
  cout << "[999 3 12345 1 2 222 123456]->[4 999 3 12345 1 2 222 44 123456]" << endl;
  d1.insertBefore(4, d1.front());
  assert(d1.front()->item == 4);
  d1.insertBefore(44, d1.back());
  assert(d1.prev(d1.back())->item == 44);
  d1.toString();
  cout << endl;
  cout << "insertBefore(item,NULL) do nothing.";
  d1.insertBefore(1,NULL);
  cout << "->OK" << endl;
  
  cout << endl;
  cout << "remove() Test ";
  d1.remove(NULL);
  d1.remove(d1.next(d1.next(d1.front())));
  d1.remove(d1.front());
  d1.remove(d1.front());
  d1.remove(d1.back());
  d1.remove(d1.back());
  d1.remove(d1.back());
  d1.remove(d1.back());
  assert(d1.front()->item == 12345 && d1.back()->item == 1);
  cout << "->OK" << endl;
  
  cout << endl;
  cout << "========================" << endl;
  cout << "Part 2 Testing LockDList" << endl;
  cout << "========================" << endl;
  LockDList<int> ld1;
  ld1.insertFront(2);
  ld1.insertBack(3);
  ld1.insertAfter(5, ld1.next(ld1.front()));
  ld1.insertBefore(4, ld1.back());
  ld1.insertFront(1);
  ld1.toString();
  cout << "Lock the node 1 and the node 5." << endl;
  ld1.lockNode(ld1.back());
  ld1.lockNode(ld1.front());
  cout << "Remove all nodes." << endl;
  DListNode<int>* ld1backNode = ld1.back();
  int ld1length = ld1.length();
  for(int i = 0; i < ld1length; i++) {
    DListNode<int>* temp = ld1.prev(ld1backNode);
    ld1.remove(temp);
    temp = ld1backNode;
  }
  assert(ld1.front()->item == 1 && ld1.back()->item == 5);
  ld1.toString();
  
  cout << "====================" << endl;
  cout << "Part 3 Testing DList" << endl;
  cout << "====================" << endl;
  DList<char> d3;
  DList<char> dempty3;

  cout << "Insert 3 items(1,3,a) at the front of this DList.";
  d3.insertFront('1');
  d3.insertFront('3');
  d3.insertFront('a');
  assert((d3.length() == 3) && (d3.isEmpty() == false));
  cout << "->OK" << endl;

  cout << "Insert 2 items(2,b) at the back of this DList.";
  d3.insertBack('2'); 
  d3.insertBack('b');
  assert(d3.length() == 5);
  cout << "->OK" << endl;
  
  cout << "a is at the front of this DList.";
  assert(d3.front()->item == 'a');
  cout << "->OK" << endl;
  cout << "If the DList is empty, front() return null."; 
  assert(!dempty3.front());
  cout << "->OK" << endl;
  
  cout << "b is at the back of this DList.";
  assert(d3.back()->item == 'b'); 
  cout << "->OK" << endl;
  cout << "If the DList is empty, back() return null."; 
  assert(!dempty3.back());
  cout << "->OK" << endl;

  cout << "The node following a is 3";
  assert(d3.next(d3.front())->item == '3');
  cout << ",and the node following 3 is 1.";
  assert(d3.next(d3.next(d3.front()))->item == '1');
  cout << "->OK" << endl;
  cout << "b is the last node in this DList, return null.";
  assert(!(d3.next(d3.back())));
  cout << "->OK" << endl;
  cout << "If input is null,return null.";
  assert(!(d3.next(NULL)));
  cout << "->OK" << endl;

  cout << "The node prior to b is 2";
  assert(d3.prev(d3.back())->item == '2');
  cout << ",and the node prior to 2 is 1.";
  assert(d3.prev(d3.prev(d3.back()))->item == '1');
  cout << "->OK" << endl;
  cout << "a is the first node in this DList, return null.";
  assert(!(d3.prev(d3.front())));
  cout << "->OK" << endl;
  cout << "If input is null,return null.";
  assert(!(d3.prev(NULL)));
  cout << "->OK" << endl;
  
  cout << endl;
  cout << "insertAfter() Test:" << endl;
  cout << "[a 3 1 2 b]->[a 3 c 1 2 b d]" << endl;
  d3.toString();
  d3.insertAfter('c', d3.next(d3.front()));
  assert(d3.next(d3.next(d3.front()))->item == 'c');
  d3.insertAfter('d', d3.back());
  assert(d3.back()->item == 'd');
  d3.toString();
  cout << endl;
  cout << "insertAfter(item,NULL) do nothing.";
  d3.insertAfter('1',NULL);
  cout << "->OK" << endl;

  cout << endl;
  cout << "insertBefore() Test:" << endl;
  cout << "[a 3 c 1 2 b d]->[4 a 3 c 1 2 b e d]" << endl;
  d3.insertBefore('4', d3.front());
  assert(d3.front()->item == '4');
  d3.insertBefore('e', d3.back());
  assert(d3.prev(d3.back())->item == 'e');
  d3.toString();
  cout << endl;
  cout << "insertBefore(item,NULL) do nothing.";
  d3.insertBefore('1',NULL);
  cout << "->OK" << endl;
  
  cout << endl;
  cout << "remove() Test ";
  d3.remove(NULL);
  d3.remove(d3.next(d3.next(d3.front())));
  d3.remove(d3.front());
  d3.remove(d3.front());
  d3.remove(d3.back());
  d3.remove(d3.back());
  d3.remove(d3.back());
  d3.remove(d3.back());
  assert(d3.front()->item == 'c' && d3.back()->item == '1');
  cout << "->OK" << endl;
  
  cout << endl;
  
  return 0;
}
