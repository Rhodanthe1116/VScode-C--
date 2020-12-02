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
#include "HashTableChained.h"
#include "CheckerBoard.h"

int main() {

    // initialize random seed:
    srand(time(NULL));

    int numBoards = 100;

    HashTableChained<CheckerBoard*, Integer*>* table = new HashTableChained<CheckerBoard*, Integer*>(numBoards);
    initTable(table, numBoards);

    // To test your hash function, add a method to your HashTableChained class
    // that counts the number of collisions--or better yet, also prints
    // a histograph of the number of entries in each bucket.  Call this method
    // from here.
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


/**
 *  Empties the given table, then inserts "numBoards" boards into the table.
 *  @param table is the hash table to be initialized.
 *  @param numBoards is the number of random boards to place in the table.
 **/
template<typename K, typename V>
void initTable(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(randomBoard(), new Integer(i));
    }
}
