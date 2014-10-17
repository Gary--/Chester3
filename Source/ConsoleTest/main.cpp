#include <iostream>
#include "Position.h"
#include "BitBoard.h"
using namespace std;

int main(){
	while (true){
		cout << BitBoard::random().str() << endl;
		system("pause");
	}

	return 0;
}