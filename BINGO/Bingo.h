#ifndef BINGO_H
#define BINGO_H
class Bingo {
public:
	Bingo();
	~Bingo();
	/// <summary>
	/// ゲームの準備
	/// </summary>
	void ReadyGame();
	void DrivingGame();
	bool HaveBall() {
		return (AppearedBalls == BALL);
	}
private:

	enum BINGO_LOGO {
		B,
		I,
		N,
		G,
		O,
	};

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


	/// <summary>
/// ビンゴカードの生成
/// </summary>
	void CreateBingoCard();
	/// <summary>
	/// カードの表示
	/// </summary>
	void ShowCard();
	/// <summary>
	/// 抽選された番号とカードの番号の照合
	/// </summary>
	void HitCheck();
	/// <summary>
	/// ビンゴの判定
	/// </summary>
	void BingoCheck();
	/// <summary>
	/// 縦方向にビンゴの判定
	/// </summary>
	void LineCheck();
	/// <summary>
	/// 斜め方向にビンゴの判定
	/// </summary>
	void ObliqueCheck();
	/// <summary>
	/// 横方向にビンゴの判定
	/// </summary>
	void RowCheck();


	void OpenCenter() {
		BingoCard[2][2] = 0;
	}

};
#endif
