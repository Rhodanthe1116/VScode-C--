/**
 * Briefly explain the function of this class->
 *
 * @author 			Your name here
 * @ID 				Your student ID here
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * TestHashTable.cpp
 * version 1.0
 */

#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "String.cpp"
#include "Double.cpp"
#include "HashTableChained.cpp"
#include "CheckerBoard.cpp"
#include <iostream>
using namespace std;
 

// Returns a string of random alphabets of 
// length n. 
string printRandomString(int);

template<typename K, typename V>
void testStringHashTable(HashTableChained<K, V>*, int);
template<typename K, typename V>
void testDoubleHashTable(HashTableChained<K, V>*, int);
template<typename K, typename V>
void testCheckerBoardHashTable(HashTableChained<K, V>*, int);

int main() {

    // initialize random seed:
    srand(time(NULL));
    
    HashTableChained<String*, Integer*>* table;
    table = new HashTableChained<String*, Integer*>();
    testStringHashTable(table, 100);

    table = new HashTableChained<String*, Integer*>(100000);
    testStringHashTable(table, 100000);


    HashTableChained<Double*, Integer*>* doubleTable;
    doubleTable = new HashTableChained<Double*, Integer*>();
    testDoubleHashTable(doubleTable, 100);

    doubleTable = new HashTableChained<Double*, Integer*>(100000);
    testDoubleHashTable(doubleTable, 100000);


    HashTableChained<CheckerBoard*, Integer*>* checkerBoardTable;
    checkerBoardTable = new HashTableChained<CheckerBoard*, Integer*>();
    testCheckerBoardHashTable(checkerBoardTable, 100);

    checkerBoardTable = new HashTableChained<CheckerBoard*, Integer*>(100000);
    testCheckerBoardHashTable(checkerBoardTable, 100000);
}


/**
 *  Generates a random 8 x 8 CheckerBoard.
 **/
CheckerBoard* randomBoard() {
    CheckerBoard* board = new CheckerBoard;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board->setElementAt(x, y, rand());
        }
    }
    return board;
}

string printRandomString(int n) 
{ 
    const int MAX = 26;
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',  
                          'o', 'p', 'q', 'r', 's', 't', 'u', 
                          'v', 'w', 'x', 'y', 'z' }; 
  
    string res = ""; 
    for (int i = 0; i < n; i++)  
        res = res + alphabet[rand() % MAX]; 
      
    return res; 
} 


template<typename K, typename V>
void testStringHashTable(HashTableChained<K, V>* table, int sizeEstimate)
{
    cout << "......Testing HashTableChained for String......" << endl;
    int random_insert_number = sizeEstimate;
    String* newString;
    for(int i = 0; i < random_insert_number; i++)
    {
        newString = new String(printRandomString(5));
        table->insert(newString, new Integer(rand()));
    }
    table->describe();

    cout << endl << "Testing find() function......" << endl;
    newString = new String("xxxxx");
    table->insert(newString, new Integer(rand()));
    cout << "Find xxxxx...? " << table->find(newString) << endl;
    newString = new String("AAAAA");
    cout << "Find AAAAA...? " << table->find(newString) << endl;
    cout << endl;

    cout << "Testing remove() function......" << endl;
    newString = new String("xxxxx");
    cout << "Find xxxxx...? " << table->find(newString) << endl;
    cout << "xxxxx is be removed" << endl;
    table->remove(newString);
    cout << "Find xxxxx...? " << table->find(newString) << endl;
    cout << endl;

    cout << "Testing makeEmpty() function......" << endl;
    table->makeEmpty();
    table->describe();
    
}

template<typename K, typename V>
void testDoubleHashTable(HashTableChained<K, V>* table, int sizeEstimate)
{
    cout << "......Testing HashTableChained for Double......" << endl;
    int random_insert_number = sizeEstimate;
    Double* newDouble;
    for(int i = 0; i < random_insert_number; i++)
    {
        double f = (double)rand() / RAND_MAX;
        table->insert(new Double(f), new Integer(rand()));
    }
    table->describe();

    cout << "Testing find() function......" << endl;
    newDouble = new Double(999.99999);
    table->insert(newDouble, new Integer(rand()));
    cout << "Find xxxxx...? " << table->find(newDouble) << endl;
    newDouble = new Double(777.77777);
    cout << "Find AAAAA...? " << table->find(newDouble) << endl;
    cout << endl;

    cout << "Testing remove() function......" << endl;
    newDouble = new Double(999.99999);
    cout << "Find xxxxx...? " << table->find(newDouble) << endl;
    cout << "xxxxx is be removed" << endl;
    table->remove(newDouble);
    cout << "Find xxxxx...? " << table->find(newDouble) << endl;
    cout << endl;

    cout << "Testing makeEmpty() function......" << endl;
    table->makeEmpty();
    table->describe();
}


/**
 *  Empties the given table, then inserts "numBoards" boards into the table.
 *  @param table is the hash table to be initialized.
 *  @param numBoards is the number of random boards to place in the table.
 **/
template<typename K, typename V>
void testCheckerBoardHashTable(HashTableChained<K, V>* table, int sizeEstimate) {
    cout << "......Testing HashTableChained for CheckerBoard......" << endl;
    table->makeEmpty();
    int random_insert_number = sizeEstimate;
    for (int i = 0; i < random_insert_number; i++) {
        table->insert(randomBoard(), new Integer(i));
    }
    table->describe();

    cout << "Testing find() function......" << endl;
    K key_ptr;
    key_ptr = new CheckerBoard();
    table->insert(key_ptr, new Integer(99999));
    cout << "Find all zero board that exists? " << table->find(key_ptr) << endl;
    key_ptr = new CheckerBoard();
    key_ptr->setElementAt(0, 0, 2);
    cout << "Find another board that does not exist...? " << table->find(key_ptr) << endl;
    cout << endl;

    cout << "Testing remove() function......" << endl;
    key_ptr = new CheckerBoard();
    cout << "Find all zero board that exists...? " << table->find(key_ptr) << endl;
    cout << "all zero board is be removed" << endl;
    table->remove(key_ptr);
    cout << "Find all zero board that does not exist...? " << table->find(key_ptr) << endl;
    cout << endl;

    cout << "Testing makeEmpty() function......" << endl;
    table->makeEmpty();
    table->describe();
}
