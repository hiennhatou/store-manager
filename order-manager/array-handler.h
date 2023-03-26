#ifndef ARRAY_HANDLER
#define ARRAY_HANDLER
class ArrayHandler {
public:
	static Model* push(Model* arr, unsigned int oldSize, Model newElement);
	static Model* rm(Model* arr, unsigned int oldSize, unsigned int position);
	static int find(Model* arr, unsigned int size, function<bool(Model)> expression);
};
#endif
