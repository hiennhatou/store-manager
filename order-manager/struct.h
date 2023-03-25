#ifndef STRUCT_H
#define STRUCT_H
struct Model {
	string id;
	string name;
	unsigned long int price;
	unsigned int quantity;
};

struct PruductLine {
	Model* models;
	unsigned int size;
};

struct Store {
	PruductLine IPHONE_PRODUCT;
	PruductLine MAC_PRODUCT;
};
#endif