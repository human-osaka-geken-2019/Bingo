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
	
	//ビンゴゲーム遂行
	getchar();
	bingo.Game();
	bool isEnd = false;
	if (bingo.HaveBall()) {
		cout << "玉が出尽くしました。\n終了します" << endl;
		getchar();
		isEnd = true;
	}
	while (!isEnd);

	return 0;
}