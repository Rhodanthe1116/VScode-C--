#include <iostream>
#include <string>
#include "Integer.h"
#include "String.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include <time.h>
using namespace std;

void testFind(BinaryTree<Integer, String> *tree, int n, string truth)
{
  Integer key(n);
  Entry<Integer, String> *entry = tree->find(key);
  cout << "Calling find() on " << n << endl;
  if (entry == NULL)
  {
    cout << "  returned null." << endl;
    if (!truth.empty())
    {
      cout << "  SHOULD BE " << truth << "." << endl;
    }
  }
  else
  {
    cout << "  returned " << entry->getvalue().getvalue() << endl;
    if (entry->getvalue().compareTo(truth) != 0)
    {
      if (truth.empty())
      {
        cout << "  SHOULD BE null." << endl;
      }
      else
      {
        cout << "  SHOULD BE " << truth << "." << endl;
      }
    }
  }
}

void testRemove(BinaryTree<Integer, String> *tree, int n, string shouldBe)
{
  Integer key(n);
  cout << "After remove(" << n << "):  " << endl;
  tree->remove(key);
  cout << tree->toString() << endl;
  if (shouldBe.compare(tree->toString()) != 0)
    cout << "  SHOULD BE " << shouldBe << endl;
}

void testMakeEmpty(BinaryTree<Integer, String> *tree)
{
  cout << "\nTesting makeEmpty() ..." << endl;
  tree->makeEmpty();
  cout << "Size:  " << tree->size() << endl;
  cout << "Tree after made empty: " << tree->toString() << endl;
  cout << "Is tree empty? " << tree->isEmpty() << endl;
}

void testRandom(BinaryTree<Integer, String> *tree, int start, int stop, int step)
{
  srand(time(NULL));
  cout << "\nTesting random insert, find, remove, make empty ..." << endl;
  for (int t = start; t < stop; t += step)
  {
    cout << "--------------------- Testing " << t << " ---------------------" << endl;
    for (int i = 0; i < t; i++)
    {
      int k = rand() % (t), v = rand() % 26;
      tree->insert(Integer(k), String(string(1, 'A' + v)));
      cout << "Insert " << k << char('A' + v) << ": " << tree->toString() << endl;
    }
    for (int i = 0; i < t; i++)
    {
      int k = rand() % (t);
      Entry<Integer, String> *entry = tree->find(Integer(k));
      cout << "Find " << k << " ";
      if (entry == NULL)
      {
        cout << "returned NULL." << endl;
      }
      else
      {
        cout << "returned " << entry->getkey().getvalue() << entry->getvalue().getvalue() << endl;
      }
    }
    for (int i = 0; i < t; i++)
    {
      int k = rand() % t;
      cout << "After remove(" << k << "):  ";
      tree->remove(Integer(k));
      cout << tree->toString() << endl;
    }
    cout << "make empty:";
    tree->makeEmpty();
    cout << tree->toString() << endl;
    cout << "--------------------- End testing " << t << " ---------------------" << endl;
  }
}
int main()
{
  BinaryTree<Integer, String> *tree = new BinaryTree<Integer, String>();
  cout << "Inserting 1A, 6V, 3K, 2Z, 5L, 9L:" << endl;
  tree->insert(Integer(1), String("A"));
  tree->insert(Integer(6), String("V"));
  tree->insert(Integer(3), String("K"));
  tree->insert(Integer(2), String("Z"));
  tree->insert(Integer(5), String("L"));
  tree->insert(Integer(9), String("L"));
  cout << "The tree is:  " << tree->toString() << endl;
  cout << "Size: " << tree->size() << endl;

  cout << "\nTesting find() ..." << endl;
  testFind(tree, 1, "A");
  testFind(tree, 9, "L");
  testFind(tree, 5, "L");
  testFind(tree, 4, "");
  testFind(tree, 6, "V");
  testFind(tree, 3, "K");

  cout << "\nTesting remove() (for nodes with < 2 children) ..." << endl;
  testRemove(tree, 5, "1A(((2Z)3K)6V(9L))");
  testRemove(tree, 3, "1A((2Z)6V(9L))");
  testRemove(tree, 1, "(2Z)6V(9L)");
  tree->insert(Integer(7), String("S"));
  tree->insert(Integer(8), String("X"));
  tree->insert(Integer(10), String("B"));
  cout << "After inserting 7S, 8X, 10B:  " << tree->toString() << endl;
  cout << "Size:  " << tree->size() << endl;
  if (tree->size() != 6)
    cout << "  SHOULD BE 6." << endl;

  cout << "\nTesting remove() (for nodes with 2 children) ..." << endl;
  testRemove(tree, 6, "(2Z)7S((8X)9L(10B))");
  testRemove(tree, 9, "(2Z)7S((8X)10B)");
  cout << "Size:  " << tree->size() << endl;
  if (tree->size() != 4)
    cout << "  SHOULD BE 4." << endl;

  testMakeEmpty(tree);

  testRandom(tree, 5, 100, 5);

  return 0;
}
