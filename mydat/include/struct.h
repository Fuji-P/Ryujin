/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

//キャラクターに関する構造体
typedef struct {
	int flag;			//フラグ
	int cnt;			//カウンタ
	int power;			//パワー
	int point;			//ポイント
	int score;			//スコア
	int num;			//残機数
	int mutekicnt;		//無敵状態とカウント
	int shot_mode;		//ショットモード
	int money;			//お金
	int img;			//画像
	int slow;			//スローかどうか
	float x, y;			//座標
//	double x, y;		//座標
}ch_t;

//パッドに関する構造体
typedef struct{
	int key[PAD_MAX];
}pad_t;

//コンフィグに関する構造体
typedef struct{
	int left;
	int up;
	int right;
	int down;
	int shot;
	int bom;
	int slow;
	int start;
	int change;
}configpad_t;