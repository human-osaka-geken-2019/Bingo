#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Bingo.h"


int main() {

	bool isEnd = false;
	while (!isEnd) {
		srand((unsigned int)time(NULL));
		Bingo bingo;
		bingo.ReadyGame();
		getchar();
		bingo.DrivingGame();
		if (bingo.HaveBall()) {
			std::cout << "玉が出尽くしました。\n" << std::endl;
			getchar();
			int isRetry = 2;
			while (isRetry > 1) {
				std::cout << "もう一度やりますか？。\nYes　->　1\nNo　->　0" << std::endl;
				scanf_s("%d", &isRetry);

				if (isRetry < 2) {
					break;
				}
				getchar();
				std::cout << "Error  もう一度入力してください" << std::endl;
			}
			isEnd = (isRetry == 1) ? false : true;
		}
	};
	return 0;
}