#include <string>
using namespace std;

#include "struct.h"
#include "array-handler.h"

Model* ArrayHandler::rm(Model* arr, unsigned int oldSize, unsigned int position) {
	unsigned int oldCount = 0, newCount = 0;
	Model* newArr = new Model[oldSize - 1];

	while (oldCount < oldSize) {
		if (oldCount != position) {
			newArr[newCount] = arr[oldCount];
			++newCount;
		}
		++oldCount;
	}

	delete[] arr;
	return newArr;
}

int* ArrayHandler::rm(int* arr, unsigned int oldSize, unsigned int position) {
	unsigned int oldCount = 0, newCount = 0;
	int* newArr = new int[oldSize - 1];

	while (oldCount < oldSize) {
		if (oldCount != position) {
			newArr[newCount] = arr[oldCount];
			++newCount;
		}
		++oldCount;
	}

	delete[] arr;
	return newArr;
}

string* ArrayHandler::rm(string* arr, unsigned int oldSize, unsigned int position) {
	unsigned int oldCount = 0, newCount = 0;
	string* newArr = new string[oldSize - 1];

	while (oldCount < oldSize) {
		if (oldCount != position) {
			newArr[newCount] = arr[oldCount];
			++newCount;
		}
		++oldCount;
	}

	delete[] arr;
	return newArr;
}
