/****************************************/
/* 製作主    ：Dixq                     */
/* サークル名：RemicalSoft              */
/* サイト名  ：龍神録プログラミングの館 */
/****************************************/

//graph.cpp
	//描画メイン
	GLOBAL void graph_main();

//ini.cpp
	GLOBAL void first_ini();

//key.cpp
	//現在のキー入力処理を行う
	GLOBAL int GetHitKeyStateAll_2();
	//受け取ったキー番号の現在の入力状態を返す
	GLOBAL int CheckStateKey(unsigned char Handle);

//laod.cpp
	//データのロード
	GLOBAL void load();
