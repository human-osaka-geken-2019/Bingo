#ifndef BINGO_H
#define BINGO_H
class Bingo {
public:
	enum BINGO_LOGO {
		B,
		I,
		N,
		G,
		O,
	};
	Bingo();
	~Bingo();
	void CreateBingoCard();

	void ShowCard();
	void Game();
	void OpenCenter() {
		BingoCard[2][2] = 0;
	}
	int GetAppearedBalls() {
		return AppearedBalls;
	}
	bool HaveBall() {
		return (AppearedBalls == BALL);
	}
	void PassOnCard(void func());
	void HitCheck();
	void LineCheck();
	void ObliqueCheck();
	void RowCheck();
private:
	static const int BALL = 75;
	static const int SPACE = 0;
	static const int LINE_WIDTH = 5;

	int LineMin = 1;
	int LineMax = 15;
	int OLcounter = 0;
	int AppearedBalls = 0;

	int PicNum[BALL];

	int BingoCard[LINE_WIDTH][LINE_WIDTH]{
	{100,200,300,400,500},
	{110,210,310,410,510},
	{120,220,320,420,520},
	{130,230,330,430,530},
	{140,240,340,440,540}
	};

};
#endif
