#include "BinaryTree.h"
using namespace std;

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree()
{
  tsize = 0;
  root = NULL;
  makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int BinaryTree<K, V>::size()
{
  return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool BinaryTree<K, V>::isEmpty()
{
  return size() == 0;
}

template <typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V> *entry, const K &key, BinaryTreeNode<K, V> *node)
{
  if (key.compareTo(node->entry->getkey()) <= 0)
  {
    if (node->leftChild == NULL)
    {
      node->leftChild = new BinaryTreeNode<K, V>(entry, node);
      node->leftChild->parent = node;
    }
    else
    {
      insertHelper(entry, key, node->leftChild);
    }
  }
  else
  {
    if (node->rightChild == NULL)
    {
      node->rightChild = new BinaryTreeNode<K, V>(entry, node);
      node->rightChild->parent = node;
    }
    else
    {
      insertHelper(entry, key, node->rightChild);
    }
  }
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template <typename K, typename V>
void BinaryTree<K, V>::insert(const K &key, const V &value)
{
  Entry<K, V> *entry = new Entry<K, V>(key, value);
  if (root == NULL)
  {
    root = new BinaryTreeNode<K, V>(entry);
    root->parent = root;
  }
  else
  {
    insertHelper(entry, key, root);
  }
  tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return null.
 *
 *  Be sure this method returns null if node == null.
 **/
template <typename K, typename V>
BinaryTreeNode<K, V> *BinaryTree<K, V>::findHelper(const K &key, BinaryTreeNode<K, V> *node)
{
  // Replace the following line with your solution.
  if (key.compareTo(node->entry->getkey()) == 0)
  {
    return node;
  }
  else if (key.compareTo(node->entry->getkey()) <= 0)
  {
    if (node->leftChild == NULL)
    {
      return NULL;
    }
    else
    {
      findHelper(key, node->leftChild);
    }
  }
  else if (key.compareTo(node->entry->getkey()) > 0)
  {
    if (node->rightChild == NULL)
    {
      return NULL;
    }
    else
    {
      findHelper(key, node->rightChild);
    }
  }
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or null if
 *          no entry contains the specified key.
 **/
template <typename K, typename V>
Entry<K, V> *BinaryTree<K, V>::find(const K &key)
{
  BinaryTreeNode<K, V> *node = findHelper(key, root);
  if (node != NULL)
  {
    return node->entry;
  }
  else
  {
    return NULL;
  }
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template <typename K, typename V>
void BinaryTree<K, V>::remove(const K &key)
{
  // Your solution here.
  BinaryTreeNode<K, V> *node = findHelper(key, root);
  if (node == NULL)
  {
    return;
  }
  else if (node->leftChild == NULL && node->rightChild == NULL)
  {
    if (node == root)
    {
      root->parent = NULL;
      root = NULL;
    }
    else if (key.compareTo(node->parent->entry->getkey()) <= 0)
    {
      node->parent->leftChild = NULL;
    }
    else
    {
      node->parent->rightChild = NULL;
    }
    delete node;
    tsize -= 1;
  }
  else if (node->leftChild && node->rightChild == NULL)
  {
    if (node == root)
    {
      root = node->leftChild;
      root->parent = root;
    }
    else if (key.compareTo(node->parent->entry->getkey()) <= 0)
    {
      node->parent->leftChild = node->leftChild;
      node->leftChild->parent = node->parent;
    }
    else
    {
      node->parent->rightChild = node->leftChild;
      node->leftChild->parent = node->parent;
    }
    delete node;
    tsize -= 1;
  }
  else if (node->leftChild == NULL && node->rightChild)
  {
    if (node == root)
    {
      root = node->rightChild;
      root->parent = root;
    }
    else if (key.compareTo(node->parent->entry->getkey()) <= 0)
    {
      node->parent->leftChild = node->rightChild;
      node->rightChild->parent = node->parent;
    }
    else
    {
      node->parent->rightChild = node->rightChild;
      node->rightChild->parent = node->parent;
    }
    delete node;
    tsize -= 1;
  }
  else if (node->leftChild && node->rightChild)
  {
    BinaryTreeNode<K, V>* min = node->rightChild;
    while (min->leftChild != NULL)
    {
      min = min->leftChild;
    }
    Entry<K, V>* minEntry = new Entry<K, V>(min->entry->getkey(), min->entry->getvalue());
    if (min == min->parent->leftChild)
    {
      min->parent->leftChild = min->rightChild;
      if (min->rightChild != NULL)
      {
        min->rightChild->parent = min->parent;
      }
    }
    else
    {
      min->parent->rightChild = min->rightChild;
      if (min->rightChild != NULL)
      {
        min->rightChild->parent = min->parent;
      }
    }
    delete min;
    tsize -= 1;
    node->entry = minEntry;
  }
  
  return;
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void BinaryTree<K, V>::makeEmpty()
{
  while (tsize > 0)
  {
    remove(root->entry->getkey());
  }
}

/**
 *  Convert the tree into a string.
 **/
template <typename K, typename V>
std::string BinaryTree<K, V>::toString()
{
  if (root == NULL)
  {
    return "";
  }
  else
  {
    return root->toString();
  }
}

