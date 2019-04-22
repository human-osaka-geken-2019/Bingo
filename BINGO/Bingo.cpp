#include "Bingo.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ends;


Bingo::Bingo()
{
}


Bingo::~Bingo()
{
}

void Bingo::CreateBingoCard() {
	//ビンゴカードの作成
	for (int i = 0; i < LINE_WIDTH; i++) {
		for (int j = 0; j < LINE_WIDTH; j++) {
			int BingoNum = rand() % 75 + 1;
			if (LineMin <= BingoNum && BingoNum <= LineMax) {
				int k = 0;
				do {
					if (BingoCard[k][i] != BingoNum) {
						OLcounter++;
					}k++;
				} while (k < j);
				if (OLcounter == j || j == 0) {
					BingoCard[j][i] = BingoNum;
					OLcounter = 0;
				}
				else {
					BingoNum = rand() % 75 + 1;
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
		LineMin = LineMin + 15;
		LineMax = LineMax + 15;
	}

}

void Bingo::ShowCard() {
	cout << "B ,I ,N ,G ,O ,\n" << endl;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			cout << BingoCard[j][i] << ends;
		}
		cout << endl;
	}
	cout << endl;
}

void Bingo::Game()
{
	while (AppearedBalls < BALL) {
		system("cls");
		//番号のドロー,過去のドローとの重複チェック
		PicNum[AppearedBalls] = rand() % 75 + 1;
		for (int g = 0; g < AppearedBalls; g++) {
			if (PicNum[g] == PicNum[AppearedBalls]) {
				PicNum[AppearedBalls] = rand() % 75 + 1;
				g--;
				continue;
			}
		}
		if (PicNum[AppearedBalls] <= 15) {
			cout << "Bの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 30 && PicNum[AppearedBalls] > 15) {
			cout << "Iの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 45 && PicNum[AppearedBalls] > 30) {
			cout << "Nの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 60 && PicNum[AppearedBalls] > 45) {
			cout << "Gの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 75 && PicNum[AppearedBalls] > 60) {
			cout << "Oの" << PicNum[AppearedBalls] << "がでました！\n" << endl;
		}
		//ビンゴカード再設定
		ShowCard();
		cout << "既出番号" << ends;
		for (int num = 0; num < AppearedBalls; ++num) {
			cout << PicNum[num] << ends;
		}
		cout << "\n" << endl;
		HitCheck();
		LineCheck();
		AppearedBalls++;
		getchar();
	}

}

void Bingo::PassOnCard(void func())
{
	for (int i = 0; i < LINE_WIDTH; i++) {
		for (int j = 0; j < LINE_WIDTH; j++) {
			func();
		}
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
void Bingo::LineCheck() {
	//ビンゴの判定
//同一行、列もしくは斜めの０の数を調べる
	ObliqueCheck();
	RowCheck();
	//列判定
	int BingoChecker = 0;
	for (int j = 0; j < 5; j++) {
		BingoChecker = 0;
		for (int i = 0; i < 5; i++) {
			if (BingoCard[j][i] == 0) {
				BingoChecker++;
			}
		}
		if (BingoChecker == 5) {
			cout << "\nLINE\nBINGO!!" << endl;
			BingoChecker = 0;
		}
		if (BingoChecker == 4) {
			cout << "\nLINE\nREACH!" << endl;
			BingoChecker = 0;
		}
	}
}
void Bingo::ObliqueCheck() {

	int BingoChecker = 0;
	//斜め判定 右下がり
	int h = 0;
	for (h; h < 5; h++) {
		BingoChecker = 0;
		if (BingoCard[h][h] == 0) {
			BingoChecker++;
		}
	}
	if (BingoChecker == 5) {
		cout << "\nOBLIQUE\nBINGO!!" << endl;
		BingoChecker = 0;
	}
	if (BingoChecker == 4) {
		cout << "\nOBLIQUE\nREACH!" << endl;
		BingoChecker = 0;
	}
	//斜め判定 右上がり
	int h = 4;
	for (int f = 0; f < 5; f++) {
		BingoChecker = 0;
		if (BingoCard[h][f] == 0) {
			BingoChecker++;
		}h--;
	}
	if (BingoChecker == 5) {
		cout << "\nOBLIQUE\nBINGO!!" << endl;
		BingoChecker = 0;
	}
	if (BingoChecker == 4) {
		cout << "\nOBLIQUE\nREACH!" << endl;
		BingoChecker = 0;
	}
}
void Bingo::RowCheck() {
	//行判定
	int BingoChecker = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (BingoCard[j][i] == 0) {
				BingoChecker++;
			}
		}
		if (BingoChecker == 5) {
			cout << "\nROW\nBINGO!!" << endl;
			BingoChecker = 0;
		}
		if (BingoChecker == 4) {
			cout << "\nROW\nREACH!" << endl;
			BingoChecker = 0;
		}
	}

}
