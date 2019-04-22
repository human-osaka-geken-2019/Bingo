#ifndef BINGO_H
#define BINGO_H
class Bingo {
public:
	Bingo();
	~Bingo();
	/// <summary>
	/// �Q�[���̏���
	/// </summary>
	void ReadyGame();
	void Game();
	void PassOnCard(void func());
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
/// �r���S�J�[�h�̐���
/// </summary>
	void CreateBingoCard();
	/// <summary>
	/// �J�[�h�̕\��
	/// </summary>
	void ShowCard();
	/// <summary>
	/// ���I���ꂽ�ԍ��ƃJ�[�h�̔ԍ��̏ƍ�
	/// </summary>
	void HitCheck();
	/// <summary>
	/// �r���S�̔���
	/// </summary>
	void BingoCheck();
	/// <summary>
	/// �c�����Ƀr���S�̔���
	/// </summary>
	void LineCheck();
	/// <summary>
	/// �΂ߕ����Ƀr���S�̔���
	/// </summary>
	void ObliqueCheck();
	/// <summary>
	/// �������Ƀr���S�̔���
	/// </summary>
	void RowCheck();


	void OpenCenter() {
		BingoCard[2][2] = 0;
	}

};
#endif
