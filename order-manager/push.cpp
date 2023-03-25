#include <string>
using namespace std;

#include "struct.h"
#include "array-handler.h"

Model* ArrayHandler::push(Model* arr, unsigned int oldSize, Model newElement) {
	Model* newArr = new Model[oldSize + 1];

	/* Make a copy */
	for (short int c = 0; c < oldSize; c++) {
		newArr[c] = arr[c];
	}

	newArr[oldSize] = newElement;
	delete[] arr;
	return newArr;
}

int* ArrayHandler::push(int* arr, unsigned int oldSize, int newElement) {
	int* newArr = new int[oldSize + 1];

	/* Make a copy */
	for (short int c = 0; c < oldSize; c++) {
		newArr[c] = arr[c];
	}

	newArr[oldSize] = newElement;
	delete[] arr;
	return newArr;
}

string* ArrayHandler::push(string* arr, unsigned int oldSize, string newElement) {
	string* newArr = new string[oldSize + 1];

	/* Make a copy */
	for (short int c = 0; c < oldSize; c++) {
		newArr[c] = arr[c];
	}

	newArr[oldSize] = newElement;
	delete[] arr;
	return newArr;
}
