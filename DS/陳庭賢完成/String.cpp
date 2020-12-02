#include "String.h"

String::String(const string& str) {
    this->str = str;
}

string String::getvalue() const {
    return str;
}

bool String::equals(const String& strg) {
	return ((*this).hashCode() == strg.hashCode());
}

int String::hashCode() const{
	hash<string>hashing;
	int id = hashing(str);
    return id;
}
