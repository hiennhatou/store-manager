#include <string>
using namespace std;

#include "string-handler.h"

bool StringHandler::isNumber(string a) {
	for (string::iterator i = a.begin(); i != a.end(); i++) {
		if (isdigit(char(*i)) == 0) return false;
	}
	return true;
}
