#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Bingo.h"

using std::cout;
using std::endl;
using std::ends;




int main() {

	srand((unsigned int)time(NULL));
	Bingo bingo;
	bingo.CreateBingoCard();
	bingo.OpenCenter();
	bingo.ShowCard();
	
	//�r���S�Q�[�����s
	getchar();
	bingo.Game();
	bool isEnd = false;
	if (bingo.HaveBall()) {
		cout << "�ʂ��o�s�����܂����B\n�I�����܂�" << endl;
		getchar();
		isEnd = true;
	}
	while (!isEnd);

	return 0;
}