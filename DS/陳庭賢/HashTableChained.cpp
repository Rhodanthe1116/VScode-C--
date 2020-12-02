/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

#include "HashTableChained.h"

#include "Entry.h"

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
	tb_size = sizeEstimate * 4 / 3;
	table = new LinkedList<Entry<K, V>>[tb_size];
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
	table = new LinkedList<Entry<K, V>>[97];
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
    return code%(tb_size /2)+(tb_size/2);
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::size() {
    return count;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
    return count == 0;
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
	Entry<K, V> ent(key, value);
	hash<K> hashing;
	int id = compFunction(hashing(key));
	table[id].push(ent);
	count++;

}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {
	hash<K> hashing;
	int id = compFunction(hashing(key));
    return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void HashTableChained<K, V>::remove(const K&  key) {
    // Replace the following line with your solution.
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
    // Your solution here.
}
