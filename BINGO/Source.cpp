#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Bingo.h"


int main() {

	srand((unsigned int)time(NULL));
	Bingo bingo;
	bingo.ReadyGame();
	//ビンゴゲーム遂行
	getchar();
	bingo.DrivingGame();
	bool isEnd = false;
	if (bingo.HaveBall()) {
		std::cout << "玉が出尽くしました。\n終了します" << std::endl;
		getchar();
		isEnd = true;
	}
	while (!isEnd);

	return 0;
}