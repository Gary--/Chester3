#include <iostream>
#include "Position.h"
#include "BitBoard.h"
using namespace std;

int main(){
	int x;
	cin >> x;

	int y;
	y = __popcnt64(x);
	cout << y << endl;
	return 0;
}