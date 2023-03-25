#include <string>
using namespace std;

#include "struct.h"
#include "array-handler.h"

unsigned int ArrayHandler::find(Model*arr, unsigned int size, bool (*	expression)(Model)) {
	unsigned int count = 0;
	while (count < size) {
		if (expression(arr[count])) {
			return count;
		}
		++count;
	}
}

unsigned int ArrayHandler::find(int* arr, unsigned int size, bool (*expression)(int)) {
	unsigned int count = 0;
	while (count < size) {
		if (expression(arr[count])) {
			return count;
		}
		++count;
	}
}

unsigned int ArrayHandler::find(string* arr, unsigned int size, bool (*expression)(string)) {
	unsigned int count = 0;
	while (count < size) {
		if (expression(arr[count])) {
			return count;
		}
		++count;
	}
}
