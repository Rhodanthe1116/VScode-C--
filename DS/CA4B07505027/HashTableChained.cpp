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
#include "math.h"
#include <iostream>


using namespace std;
// Process prime
bool isPrime(int p)
{
    if (p <= 1)
        return false;
    if (p == 2 || p == 3)
        return true;

    // Divisibility Primality Test
    for (int i = 2; i <= sqrt(p) + 1; i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

int nearestUpperPrime(int num)
{
    if (isPrime(num))
    {
        return num;
    }
    else
    {
        return nearestUpperPrime(num + 1);
    }
}

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate)
{
    // Your solution here.
    bucket_number = nearestUpperPrime(sizeEstimate * 4 / 3);
    entry_number = 0;
    table.resize(bucket_number);
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained()
{
    // Your solution here.
    bucket_number = 101;
    entry_number = 0;
    table.resize(bucket_number);
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::compFunction(int code)
{
    // Replace the following line with your solution.
    return abs(code) % bucket_number;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::size()
{
    // Replace the following line with your solution.
    return entry_number;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::isEmpty()
{
    // Replace the following line with your solution.
    if (entry_number == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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
template <typename K, typename V>
void HashTableChained<K, V>::insert(const K &key, const V &value)
{
    // Replace the following line with your solution.
    int h = compFunction(key->hashCode());
    entry_number += 1;
    table[h].push_back(Entry<K, V>(key, value));
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
template <typename K, typename V>
bool HashTableChained<K, V>::find(const K &key)
{
    // Replace the following line with your solution.
    int h = compFunction(key->hashCode());
    
    for (auto entry_it = table[h].begin(); entry_it != table[h].end(); entry_it++)
    {
        if (entry_it->getkey()->equals(*key))
            return true;
    }

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
template <typename K, typename V>
void HashTableChained<K, V>::remove(const K &key)
{
    // Replace the following line with your solution.
    int h = compFunction(key->hashCode());
    entry_number -= 1;
    
    for (auto entry_it = table[h].begin(); entry_it != table[h].end(); entry_it++)
    {
        if (entry_it->getkey()->equals(*key))
        {
            table[h].erase(entry_it);
            return;
        }
    }

    return;
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void HashTableChained<K, V>::makeEmpty()
{
    // Your solution here.
    for (int i = 0; i < bucket_number; i++)
    {
        table[i].clear();
    }
    entry_number = 0;
    return;
}

template <typename K, typename V>
void HashTableChained<K, V>::describe()
{
    int collisions = 0;
    int longest_bucket_length = 0;
    cout << "----------------" << endl;
    cout << "HashTableChained" << endl;
    cout << "----------------" << endl;
    for (int i = 0; i < bucket_number; i++)
    {
        //cout << "bucket " << i << ": ";
        for (auto entry_it = table[i].begin(); entry_it != table[i].end(); entry_it++)
        {

            if(entry_it != table[i].begin())
            {
                collisions += 1;
            }
            //cout << "\"" << entry_it->getkey()->getvalue() << "\": " << entry_it->getvalue()->getvalue() << ", ";
        }
        //cout << endl;
        
        if (table[i].size() > longest_bucket_length)
        {
            longest_bucket_length = table[i].size();
        }
    }
    cout << "----------------" << endl;
    cout << "Is it empty? " << isEmpty() << endl;
    cout << "The number of bucekt: " << bucket_number << endl;
    cout << "The number of entry: " << size() << endl;
    cout << "The number of collisions: " << collisions << endl;
    cout << "Length of longest bucket: " << longest_bucket_length << endl;
    cout << endl;

}
