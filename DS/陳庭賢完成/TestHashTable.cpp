/**
 * test if tables work well in specific way
 *
 * @author 			陳庭賢
 * @ID 				B07505019
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 * TestHashTable.cpp
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

#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "HashTableChained.cpp"
#include "CheckerBoard.h"
using namespace std;
template<typename V>
void initTable(HashTableChained<CheckerBoard*, V>* table, int numBoards);
template<typename V>
void initTable(HashTableChained<String*, V>* table, int numStrings);
template<typename V>
void initTable(HashTableChained<Double*, V>* table, int numDoubles);

String* randomString(const int len);
Double* randomDouble(double min, double max);
CheckerBoard* randomBoard();

int main() {

	// initialize random seed:
	srand(time(NULL));

	cout << " _   _           _   _____     _     _        _            _   \n";
	cout << "| | | |         | | |_   _|   | |   | |      | |          | |  \n";
	cout << "| |_| | __ _ ___| |__ | | __ _| |__ | | ___  | |_ ___  ___| |_ \n";
	cout << "|  _  |/ _` / __| '_ \\| |/ _` | '_ \\| |/ _ \\ | __/ _ \\/ __| __|\n";
	cout << "| | | | (_| \\__ \\ | | | | (_| | |_) | |  __/ | ||  __/\\__ \\ |_ \n";
	cout << "\\_| |_/\\__,_|___/_| |_\\_/\\__,_|_.__/|_|\\___|  \\__\\___||___/\\__|\n\n";
	int num = 0;
	cout << "--------------------\n";
	cout << "    String table    \n";
	cout << "--------------------\n";
	cout << "預期產生entry數量:";
	cin >> num;
	HashTableChained<String*, Integer*>* string_table = new HashTableChained<String*, Integer*>(num+2);
	initTable(string_table, num);
	String* eso = new String("eso");
	String* soe = new String("soe");
	Integer* i_eso = new Integer(550*rand());
	Integer* i_soe = new Integer(100*rand());
	string_table->insert(eso, i_eso);
	string_table->insert(soe, i_soe);
	string_table->printTable();
	string_table->printContent();
	cout << "純加入後table size" << string_table->size() << "\n";
	cout << "尋找eso:" << ((string_table->find(eso))?"成功":"失敗") << "\n";
	cout << "尋找soe:" << ((string_table->find(soe))?"成功":"失敗") << "\n";
	cout << "移除eso..." << "\n"; string_table->remove(eso);
	cout << "移除soe..." << "\n"; string_table->remove(soe);
	cout << "尋找eso:" << ((string_table->find(eso))?"成功":"失敗") << "\n";
	cout << "尋找soe:" << ((string_table->find(soe))?"成功":"失敗") << "\n";
	cout << "尋找、移除測試後table size:" << string_table->size() << "\n";
	cout << "\n清空...\n"; string_table->makeEmpty();
	string_table->printTable();
	cout << "清空測試後table size:" << string_table->size() << "\n\n\n";
	delete string_table;
	cout << "--------------------\n";
	cout << "    Double table    \n";
	cout << "--------------------\n";
	cout << "預期產生entry數量:";
	cin >> num;
	HashTableChained<Double*, Integer*>* double_table = new HashTableChained<Double*, Integer*>(num + 2);
	initTable(double_table, num);
	Double* dan = new Double(2.71*rand());
	Double* don = new Double(2.71*rand());
	Integer* i_dan = new Integer(550 * rand());
	Integer* i_don = new Integer(100 * rand());
	double_table->insert(dan, i_dan);
	double_table->insert(don, i_don);
	double_table->printTable();
	double_table->printContent();
	cout << "純加入後table size" << double_table->size() << "\n";
	cout << "尋找dan:" << ((double_table->find(dan)) ? "成功" : "失敗") << "\n";
	cout << "尋找don:" << ((double_table->find(don)) ? "成功" : "失敗") << "\n";
	cout << "移除dan..." << "\n"; double_table->remove(dan);
	cout << "移除don..." << "\n"; double_table->remove(don);
	cout << "尋找dan:" << ((double_table->find(dan)) ? "成功" : "失敗") << "\n";
	cout << "尋找don:" << ((double_table->find(don)) ? "成功" : "失敗") << "\n";
	cout << "尋找、移除測試後table size:" << double_table->size() << "\n";
	cout << "\n清空...\n"; double_table->makeEmpty();
	double_table->printTable();
	cout << "清空測試後table size:" << double_table->size() << "\n\n\n";
	delete double_table;
	cout << "------------------------\n";
	cout << "   CheckerBoard table   \n";
	cout << "------------------------\n";
	cout << "預期產生entry數量:";
	cin >> num;
	HashTableChained<CheckerBoard*, Integer*>* checker_board_table = new HashTableChained<CheckerBoard*, Integer*>(num + 2);
	initTable(checker_board_table, num);
	CheckerBoard* cheg = new CheckerBoard();
	CheckerBoard* chec = new CheckerBoard();
	Integer* i_cheg = new Integer(550 * rand());
	Integer* i_chec = new Integer(100 * rand());
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (x == y) {
				cheg->setElementAt(x, y, 0);
				chec->setElementAt(x, y, 1);
			}
			else
			{
				cheg->setElementAt(x, y, 1);
				chec->setElementAt(x, y, 0);
			}
		}
	}
	checker_board_table->insert(cheg, i_cheg);
	checker_board_table->insert(chec, i_chec);
	checker_board_table->printTable();
	checker_board_table->printContent();
	cout << "純加入後table size" << checker_board_table->size() << "\n";
	cout << "尋找cheg:" << ((checker_board_table->find(cheg)) ? "成功" : "失敗") << "\n";
	cout << "尋找chec:" << ((checker_board_table->find(chec)) ? "成功" : "失敗") << "\n";
	cout << "移除cheg..." << "\n"; checker_board_table->remove(cheg);
	cout << "移除chec..." << "\n"; checker_board_table->remove(chec);
	cout << "尋找cheg:" << ((checker_board_table->find(cheg)) ? "成功" : "失敗") << "\n";
	cout << "尋找chec:" << ((checker_board_table->find(chec)) ? "成功" : "失敗") << "\n";
	cout << "尋找、移除測試後table size:" << checker_board_table->size() << "\n";
	cout << "\n清空...\n"; checker_board_table->makeEmpty();
	checker_board_table->printTable();
	cout << "清空測試後table size:" << checker_board_table->size() << "\n";
	delete checker_board_table;
	system("pause");
}
String* randomString(const int len) {
	char *s = new char[len];
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
	return new String(s);
}
Double * randomDouble(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	return new Double(min + f * (max - min));
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
template<typename V>
void initTable(HashTableChained<CheckerBoard*, V>* table, int numBoards) {
	table->makeEmpty();
	for (int i = 0; i < numBoards; i++) {
		table->insert(randomBoard(), new Integer(i));
	}
}
template<typename V>
void initTable(HashTableChained<String*, V>* table, int numStrings) {
	table->makeEmpty();
	for (int i = 0; i < numStrings; i++) {
		table->insert(randomString(3), new Integer(i));
	}
}
template<typename V>
void initTable(HashTableChained<Double*, V>* table, int numDoubles) {
	table->makeEmpty();
	for (int i = 0; i < numDoubles; i++) {
		table->insert(randomDouble(0,100), new Integer(i));
	}
}