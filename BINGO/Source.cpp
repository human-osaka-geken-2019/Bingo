#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Bingo.h"


int main() {

	srand((unsigned int)time(NULL));
	Bingo bingo;
	bingo.ReadyGame();
	//�r���S�Q�[�����s
	getchar();
	bingo.DrivingGame();
	bool isEnd = false;
	if (bingo.HaveBall()) {
		std::cout << "�ʂ��o�s�����܂����B\n�I�����܂�" << std::endl;
		getchar();
		isEnd = true;
	}
	while (!isEnd);

	return 0;
}