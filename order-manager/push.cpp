#include <string>
#include <functional>
using namespace std;

#include "struct.h"
#include "array-handler.h"

Model* ArrayHandler::push(Model* arr, unsigned int oldSize, Model newElement) {
	Model* newArr = new Model[oldSize + 1];

	/* Make a copy */
	for (short int c = 0; c < oldSize; c++) {
		newArr[c].id = arr[c].id;
		newArr[c].name = arr[c].name;
		newArr[c].price = arr[c].price;
		newArr[c].quantity = arr[c].quantity;
	}

	newArr[oldSize].id = newElement.id;
	newArr[oldSize].name = newElement.name;
	newArr[oldSize].price = newElement.price;
	newArr[oldSize].quantity = newElement.quantity;
	return newArr;
}

int* ArrayHandler::push(int* arr, unsigned int oldSize, int newElement) {
	int* newArr = new int[oldSize + 1];

	/* Make a copy */
	for (short int c = 0; c < oldSize; c++) {
		newArr[c] = arr[c];
	}

	newArr[oldSize] = newElement;
	return newArr;
}

string* ArrayHandler::push(string* arr, unsigned int oldSize, string newElement) {
	string* newArr = new string[oldSize + 1];

	/* Make a copy */
	for (short int c = 0; c < oldSize; c++) {
		newArr[c] = arr[c];
	}

	newArr[oldSize] = newElement;
	return newArr;
}
