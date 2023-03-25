#ifndef STRUCT_H
#define STRUCT_H
struct Model {
	string id;
	string name;
	unsigned long int price;
	unsigned int quantity;
};

struct PrudutLine {
	Model* models;
	unsigned int size;
};

struct Store {
	PrudutLine IPHONE_PRODUCT;
	PrudutLine MAC_PRODUCT;
};
#endif