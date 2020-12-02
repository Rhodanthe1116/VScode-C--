#include "Double.h"
#include<type_traits>
using namespace std;

Double::Double(const double& d) {
    this->d = d;
}

double Double::getvalue() const {
    return d;
}


bool Double::equals(const Double& db) {
	return ((*this).hashCode() == db.hashCode());
}

int Double::hashCode() const{
	hash<double> hashing;
	int id = hashing(d);
	return id;
}
