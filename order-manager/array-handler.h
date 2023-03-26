#ifndef ARRAY_HANDLER
#define ARRAY_HANDLER
class ArrayHandler {
public:
	/* push */
	static Model* push(Model* arr, unsigned int oldSize, Model newElement);
	static int* push(int* arr, unsigned int oldSize, int newElement);
	static string* push(string* arr, unsigned int oldSize, string newElement);
	
	/* remove */
	static Model* rm(Model* arr, unsigned int oldSize, unsigned int position);
	static int* rm(int* arr, unsigned int oldSize, unsigned int position);
	static string* rm(string* arr, unsigned int oldSize, unsigned int position);

	/* find */
	static int find(Model* arr, unsigned int size, function<bool(Model)> expression);
	static int find(int* arr, unsigned int size, bool (*expression)(int));
	static int find(string* arr, unsigned int size, bool (*expression)(string));
};
#endif
