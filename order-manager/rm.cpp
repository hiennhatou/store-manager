#include <string>
#include <functional>
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

	return newArr;
}
