#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

string random(unsigned short int leng) {
	int list[2][2] = { {48, 10}, {65, 26} };
	string result = "";
	for (unsigned short int a = 0; a < leng; a++) {
		short int o = rand() % 2;
		short int p = rand() % list[o][1] + list[o][0];
		result += char(p);
	}
	return result;
}