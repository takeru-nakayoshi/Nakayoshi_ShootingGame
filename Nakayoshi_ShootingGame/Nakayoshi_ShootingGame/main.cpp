#include<DxLib.h>
#include"SceneManager.h"
#include"GameMainScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	// タイトルを test に変更
	SetMainWindowText("シューティングゲーム");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	//タイトル画像データの読み込み
	//if ((g_TitleImage = LoadGraph("images/Title.png")) == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定
	SceneManager sceneMng( dynamic_cast <AbstractScene*>(new GameMainScene()));

	// ゲームループ
	while (ProcessMessage() == 0) {

		

		ClearDrawScreen();		// 画面の初期化
		sceneMng.Update();		//シーンの更新
		sceneMng.Draw();		//シーンの描画

		if (sceneMng.ChangeScene() == nullptr) {//シーンの変更
			DxLib_End();	

			return 0;
		}

		ScreenFlip();			// 裏画面の内容を表画面に反映

	}


	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}