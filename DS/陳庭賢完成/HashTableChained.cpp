/**
 * regulate how a hash table dealing collisions by chaining should work
 *
 * @author 			陳庭賢
 * @ID 				B07505019
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * HashTableChained.cpp
 * version 8.7
 */
 /***
  *               _             _            _                _______      _                _______      _       _           _
  *              / /\         / /\         / /\              / ___  /\   / /\              / ___  /\   / /\     / /\       / /\
  *             / /  \       / /  \       / /  \            / /\__\ \ \ / /  \            / /\__\ \ \ / /  \   / /  \     / /  \
  *            / / /\ \     / / /\ \     / / /\ \          / / /   \_\// / /\ \          / / /   \_\// / /\ \ /_/ /\ \   / / /\ \
  *           / / /\ \ \   / / /\ \ \   / / /\ \ \        / / /       / / /\ \ \        / / /       / / /\ \ \\_\/\ \ \ /_/ /\ \ \
  *          / / /\ \_\ \ /_/ /  \ \ \ /_/ /  \ \ \       \ \ \      /_/ /  \ \ \       \ \ \      /_/ /  \ \ \    \ \ \\ \ \_\ \ \
  *         / / /\ \ \___\\ \ \   \ \ \\_\/    \ \ \       \ \ \     \ \ \   \ \ \       \ \ \     \ \ \   \ \ \    \ \ \\ \/__\ \ \
  *        / / /  \ \ \__/ \ \ \   \ \ \        \ \ \       \ \ \     \ \ \   \ \ \       \ \ \     \ \ \   \ \ \    \ \ \\_____\ \ \
  *       / / /____\_\ \    \ \ \___\ \ \        \ \ \  ____/ / /      \ \ \___\ \ \  ____/ / /      \ \ \___\ \ \  __\ \ \___   \ \ \
  *      / / /__________\    \ \/____\ \ \        \ \ \/_____/ /        \ \/____\ \ \/_____/ /        \ \/____\ \ \/___\_\/__/\   \ \ \
  *      \/_____________/     \_________\/         \_\/\_____\/          \_________\/\_____\/          \_________\/\_________\/    \_\/
  *
  */
#include "String.h"
#include "Double.h"
#include <typeinfo>
#include "HashTableChained.h"
#include "Entry.h"
#include<iostream>
#include<iomanip>
#include <math.h> 


template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
	tb_size = sizeEstimate * 4 / 3;
	table = new forward_list<Entry<K, V>*>[tb_size];
}

template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
	tb_size = 97;
	table = new forward_list<Entry<K, V>*>[tb_size];
}
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
	return (code%tb_size + tb_size) / 2;
}


/***
 *       _____ ___________   _____    ______
 *      / ___// ____/  _/ | / /   |  / ____/
 *      \__ \/ /_   / //  |/ / /| | / __/
 *     ___/ / __/ _/ // /|  / ___ |/ /___
 *    /____/_/   /___/_/ |_/_/  |_/_____/
 *
 */

/* 
template <typename T>
class has_hashCode
{
	typedef char one;
	struct two { char x[2]; };

	template <typename C> static one test(decltype(&C::hashCode));
	template <typename C> static two test(...);

public:
	enum { value = sizeof(test<T>(0)) == sizeof(char) };
};


template<typename T>
typename enable_if<has_hashCode<T>::value, int>::type
CallHashCode(T * t) {
	return t->hashCode();
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value, int>::type
CallHashCode(T * t)
{
	hash<int> hashing;
	int hc = hashing(t);
	return hc;
}

int CallHashCode(...) {
	return 0;
}*/

template<typename K, typename V>
int HashTableChained<K, V>::size() {
    return count;
}

template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
    return count == 0;
}

template<class K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
	int id = 0;
	id = compFunction(key->hashCode());
	table[id].push_front(new Entry<K, V>(key, value));
	count++;

	}


template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {
	int id = 0;
	id = compFunction(key->hashCode());
	for (auto& elm : table[id]) {
		if (elm->getkey()->equals(*key)) {
			return true;
		}
	}
    return false;
}

template<typename K, typename V>
void HashTableChained<K, V>::remove(const K&  key) {
	int id = 0;
	id = compFunction(key->hashCode());
	table[id].pop_front();
	count--;
}

template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
	for (int i = 0; i < tb_size; i++) {
		table[i].clear();
	}
	count = 0;
}

template<typename K, typename V>
void HashTableChained<K, V>::printTable()
{
	std::cout << "\n=======模糊列印=======\n\n";
	int collides = 0, m_n = 0;
	for (int i = 0; i < tb_size; i++) {
		int ct = 0;
		std::cout  << std::setw(3) << i << "]:";
		for (auto& elm : table[i]) {
			std::cout << "*";
			ct++;
		}
		std::cout << std::setw(10-ct)<< "(" <<ct<< ")"<< "\n";
		if (ct > 1)collides+=(ct-1);
		m_n += ct;
	}
	std::cout << "\n=======統計結果=======\n";
	std::cout << "collisions:" << collides << "\n";	
	std::cout << "expected collisions:" << count - tb_size + tb_size * pow(1.0 - (double)(1.0 / tb_size), count) << "\n";
	std::cout << "average list length:" << (double)m_n/tb_size << "\n";
	std::cout << "======================\n\n";
}

template<typename K, typename V>
void HashTableChained<K, V>::printContent() {
	std::cout << "\n=======清晰列印=======\n\n";
	for (int i = 0; i < tb_size; i++) {
		int ct = 0;
		std::cout << std::setw(3) << i << "]:";
		for (auto& elm : table[i]) {
			std::cout <<"<"<< elm->getkey()->getvalue() << ">,";
			ct++;
		}
		std::cout << "(" << ct << ")" << "\n";
	}
	std::cout << "\n======================\n\n";
}

