#include <string>
#include <functional>
using namespace std;

#include "struct.h"
#include "array-handler.h"

int ArrayHandler::find(Model*arr, unsigned int size, function<bool(Model)> expression) {
	unsigned int count = 0;
	while (count < size) {
		if (expression(arr[count])) {
			return count;
		}
		++count;
	}
	return -1;
}

int ArrayHandler::find(int* arr, unsigned int size, bool (*expression)(int)) {
	unsigned int count = 0;
	while (count < size) {
		if (expression(arr[count])) {
			return count;
		}
		++count;
	}
	return -1;
}

int ArrayHandler::find(string* arr, unsigned int size, bool (*expression)(string)) {
	unsigned int count = 0;
	while (count < size) {
		if (expression(arr[count])) {
			return count;
		}
		++count;
	}
	return -1;
}
