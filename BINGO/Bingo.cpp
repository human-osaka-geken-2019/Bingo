#include "Bingo.h"
#include <iostream>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::ends;


Bingo::Bingo()
{
}


Bingo::~Bingo()
{
}

void Bingo::ReadyGame()
{
	for (int i = 0; i < CARD_NUM_LIMIT; ++i) {
		PicNum[i] = i+1;
	}
	CreateBingoCard();
	OpenCenter();
	ShowCard();
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	std::shuffle(PicNum.begin(), PicNum.end(), engine);

}

void Bingo::CreateBingoCard() {
	//ビンゴカードの作成
	for (int i = 0; i < LINE_WIDTH; i++) {
		for (int j = 0; j < LINE_WIDTH; j++) {
			int BingoNum = rand() % CARD_NUM_LIMIT + 1;
			if (LineMin <= BingoNum && BingoNum <= LineMax) {
				int k = 0;
				do {
					if (BingoCard[k][i] != BingoNum) {
						OLcounter++;
					}
					k++;
				} while (k < j);
				if (OLcounter == j || j == 0) {
					BingoCard[j][i] = BingoNum;
					OLcounter = 0;
				}
				else {
					BingoNum = rand() % CARD_NUM_LIMIT + 1;
					OLcounter = 0;
					j--;
					continue;
				}
			}
			else {
				j--;
				continue;
			}
		}
		LineMin = LineMin + LINE_NUM_RANGE;
		LineMax = LineMax + LINE_NUM_RANGE;
	}

}

void Bingo::ShowCard() {
	cout << "B ,I ,N ,G ,O ,\n" << endl;
	for (int j = 0; j < LINE_WIDTH; j++) {
		for (int i = 0; i < LINE_WIDTH; i++) {
			int cardNum = BingoCard[j][i];
			if (cardNum < 10) {
				cout << " " << cardNum << ends;
			}
			else cout << cardNum << ends;
		}
		cout << endl;
	}
	cout << endl;
}

void Bingo::DrivingGame()
{
	while (AppearedBalls < BALL) {
		system("cls");
		//番号のドロー,過去のドローとの重複チェック
		//int DrawNum = rand() % CARD_NUM_LIMIT + 1;
		//bool isSameNum = true;
		//while (isSameNum) {
		//	for (auto& num : PicNum) {
		//		if (num != DrawNum) {
		//			continue;
		//		}
		//		isSameNum = true;
		//	}
		//	if (isSameNum) {
		//		DrawNum = rand() % CARD_NUM_LIMIT + 1;
		//	}
		//}
		if (PicNum[AppearedBalls] <= LINE_NUM_RANGE) {
			cout << "Bの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= I_LINE_MIN && PicNum[AppearedBalls] > LINE_NUM_RANGE) {
			cout << "Iの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= N_LINE_MIN && PicNum[AppearedBalls] > I_LINE_MIN) {
			cout << "Nの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= G_LINE_MIN && PicNum[AppearedBalls] > N_LINE_MIN) {
			cout << "Gの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= CARD_NUM_LIMIT && PicNum[AppearedBalls] > G_LINE_MIN) {
			cout << "Oの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		//ビンゴカード再設定
		ShowCard();
		cout << "既出番号" << endl;
		for (int num = 0; num <= AppearedBalls; ++num) {
			if (!(num % 10)) {
				cout << endl;
			}
			cout << PicNum[num] << ends;
		}
		cout << "\n" << endl;
		HitCheck();
		BingoCheck();
		AppearedBalls++;
		getchar();
	}

}

void Bingo::HitCheck() {
	//番号とカードの重複チェック＆穴あけ
	for (int i = 0; i < LINE_WIDTH; i++) {
		for (int j = 0; j < LINE_WIDTH; j++) {
			if (PicNum[AppearedBalls] == BingoCard[j][i]) {
				BingoCard[j][i] = SPACE;
				switch (i) {
				case B:
					cout << "Bの" << PicNum[AppearedBalls] << "が当たり！\n" << ends;
					break;
				case I:
					cout << "Iの" << PicNum[AppearedBalls] << "が当たり！\n" << ends;
					break;
				case N:
					cout << "Nの" << PicNum[AppearedBalls] << "が当たり！\n" << ends;
					break;
				case G:
					cout << "Gの" << PicNum[AppearedBalls] << "が当たり！\n" << ends;
					break;
				case O:
					cout << "Oの" << PicNum[AppearedBalls] << "が当たり！\n" << ends;
					break;
				}
			}
		}
	}

}
void Bingo::BingoCheck()
{
	ObliqueCheck();
	RowCheck();
	ColumnCheck();
}
void Bingo::ColumnCheck() {
	//列判定
	int BingoChecker = 0;
	for (int j = 0; j < LINE_WIDTH; j++) {
		BingoChecker = 0;
		for (int i = 0; i < LINE_WIDTH; i++) {
			if (BingoCard[j][i] == 0) {
				BingoChecker++;
			}
		}
		if (BingoChecker == LINE_WIDTH) {
			cout << "\nCOLUMN\nBINGO!!" << endl;
		}
		if (BingoChecker == LINE_WIDTH - 1) {
			cout << "\nCOLUMN\nREACH!" << endl;
		}
		BingoChecker = 0;
	}
}
void Bingo::ObliqueCheck() {

	int BingoChecker = 0;
	//斜め判定 右下がり
	int h = 0;
	for (h; h < LINE_WIDTH; h++) {
		BingoChecker = 0;
		if (BingoCard[h][h] == 0) {
			BingoChecker++;
		}
	}
	if (BingoChecker == LINE_WIDTH) {
		cout << "\nOBLIQUE\nBINGO!!" << endl;
	}
	if (BingoChecker == LINE_WIDTH - 1) {
		cout << "\nOBLIQUE\nREACH!" << endl;
	}
	BingoChecker = 0;
	//斜め判定 右上がり
	h = LINE_WIDTH - 1;
	for (int f = 0; f < LINE_WIDTH; f++) {
		if (BingoCard[h][f] == 0) {
			BingoChecker++;
		}
		h--;
	}
	if (BingoChecker == LINE_WIDTH) {
		cout << "\nOBLIQUE\nBINGO!!" << endl;
	}
	if (BingoChecker == LINE_WIDTH - 1) {
		cout << "\nOBLIQUE\nREACH!" << endl;
	}
	BingoChecker = 0;
}
void Bingo::RowCheck() {
	//行判定
	int BingoChecker = 0;
	for (int i = 0; i < LINE_WIDTH; i++) {
		for (int j = 0; j < LINE_WIDTH; j++) {
			if (BingoCard[j][i] == 0) {
				BingoChecker++;
			}
		}
		if (BingoChecker == LINE_WIDTH) {
			cout << "\nROW\nBINGO!!" << endl;
		}
		if (BingoChecker == LINE_WIDTH-1) {
			cout << "\nROW\nREACH!" << endl;
		}
		BingoChecker = 0;

	}

}
