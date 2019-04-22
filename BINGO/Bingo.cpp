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
	//�r���S�J�[�h�̍쐬
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
		//�ԍ��̃h���[,�ߋ��̃h���[�Ƃ̏d���`�F�b�N
		PicNum[AppearedBalls] = rand() % 75 + 1;
		for (int g = 0; g < AppearedBalls; g++) {
			if (PicNum[g] == PicNum[AppearedBalls]) {
				PicNum[AppearedBalls] = rand() % 75 + 1;
				g--;
				continue;
			}
		}
		if (PicNum[AppearedBalls] <= 15) {
			cout << "B��" << PicNum[AppearedBalls] << "���ł܂����I\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 30 && PicNum[AppearedBalls] > 15) {
			cout << "I��" << PicNum[AppearedBalls] << "���ł܂����I\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 45 && PicNum[AppearedBalls] > 30) {
			cout << "N��" << PicNum[AppearedBalls] << "���ł܂����I\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 60 && PicNum[AppearedBalls] > 45) {
			cout << "G��" << PicNum[AppearedBalls] << "���ł܂����I\n" << endl;
		}
		if (PicNum[AppearedBalls] <= 75 && PicNum[AppearedBalls] > 60) {
			cout << "O��" << PicNum[AppearedBalls] << "���ł܂����I\n" << endl;
		}
		//�r���S�J�[�h�Đݒ�
		ShowCard();
		cout << "���o�ԍ�" << ends;
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
	//�ԍ��ƃJ�[�h�̏d���`�F�b�N��������
	for (int i = 0; i < LINE_WIDTH; i++) {
		for (int j = 0; j < LINE_WIDTH; j++) {
			if (PicNum[AppearedBalls] == BingoCard[j][i]) {
				BingoCard[j][i] = SPACE;
				switch (i) {
				case B:
					cout << "B��" << PicNum[AppearedBalls] << "��������I\n" << ends;
					break;
				case I:
					cout << "I��" << PicNum[AppearedBalls] << "��������I\n" << ends;
					break;
				case N:
					cout << "N��" << PicNum[AppearedBalls] << "��������I\n" << ends;
					break;
				case G:
					cout << "G��" << PicNum[AppearedBalls] << "��������I\n" << ends;
					break;
				case O:
					cout << "O��" << PicNum[AppearedBalls] << "��������I\n" << ends;
					break;
				}
			}
		}
	}

}
void Bingo::LineCheck() {
	//�r���S�̔���
//����s�A��������͎΂߂̂O�̐��𒲂ׂ�
	ObliqueCheck();
	RowCheck();
	//�񔻒�
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
	//�΂ߔ��� �E������
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
	//�΂ߔ��� �E�オ��
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
	//�s����
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
