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
	double x, y;		//座標
}ch_t;

//敵に関する構造体
typedef struct {
	int flag;			//フラグ
	int cnt;			//カウンタ
	int pattern;		//移動パターン
	int muki;			//向き
	int knd;			//敵の種類
	int hp;				//HP
	int hp_max;			//HP最大値
	int item_n[6];		//落とすアイテム
	int img;			//
	double x;			//座標
	double y;			//座標
	double vx;			//速度x成分
	double vy;			//速度y成分
	double sp;			//スピード
	double ang;			//角度
	int bltime;			//弾幕開始時間
	int blknd;			//弾幕の種類
	int blknd2;			//弾の種類
	int col;			//色
	int state;			//状態
	int wtime;			//待機時間
	int wait;			//停滞時間
}enemy_t;

typedef struct {
	int cnt;			//カウンタ
	int pattern;		//移動パターン
	int knd;			//敵の種類
	double x;			//初期座標
	double y;			//初期座標
	double sp;			//移動スピード
	int bltime;			//弾幕開始時間
	int blknd;			//弾幕の種類
	int col;			//色
	int hp;				//体力
	int blknd2;			//弾の種類
	int wait;			//停滞時間
	int item_n[6];		//アイテム(6種類)
}enemy_order_t;

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