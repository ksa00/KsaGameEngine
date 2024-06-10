//インクルード
#include <Windows.h>
#include "Direct3D.h"
#include"Quad.h"
#include"Camera.h"
//リンカ
#pragma comment(lib, "d3d11.lib")
//定数宣言
const char* WIN_CLASS_NAME = "SampleGame";  //ウィンドウクラス名
const LPCSTR APP_NAME = "サンプルゲーム";  //ウィンドウクラス名
const int WINDOW_WIDTH = 800;  //ウィンドウの幅
const int WINDOW_HEIGHT = 600; //ウィンドウの高さ

//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//エントリーポイント
 int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
//ウィンドウクラス（設計図）を作成
    
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);             //この構造体のサイズ
    wc.hInstance = hInstance;                   //インスタンスハンドル
    wc.lpszClassName = WIN_CLASS_NAME;            //ウィンドウクラス名
    wc.lpfnWndProc = WndProc;                   //ウィンドウプロシージャ
    wc.style = CS_VREDRAW | CS_HREDRAW;         //スタイル（デフォルト）
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //アイコン
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);   //小さいアイコン
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);   //マウスカーソル
    wc.lpszMenuName = NULL;                     //メニュー（なし）
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景（白）
    RegisterClassEx(&wc);  //クラスを登録
    //ウィンドウサイズの計算
    RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
    int winW = winRect.right - winRect.left;     //ウィンドウ幅
    int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ

 //ウィンドウを作成
 HWND hWnd = CreateWindow(
       WIN_CLASS_NAME,         //ウィンドウクラス名
     APP_NAME,     //タイトルバーに表示する内容
        WS_OVERLAPPEDWINDOW, //スタイル（普通のウィンドウ）
        CW_USEDEFAULT,       //表示位置左（おまかせ）
        CW_USEDEFAULT,       //表示位置上（おまかせ）
     winW,               //ウィンドウ幅
     winH,               //ウィンドウ高さ
        NULL,                //親ウインドウ（なし）
        NULL,                //メニュー（なし）
        hInstance,           //インスタンス
        NULL                 //パラメータ（なし）
    );

 //ウィンドウを表示
 ShowWindow(hWnd, nCmdShow);


 //Direct3D初期化
 HRESULT hr= Direct3D::Initialize(winW, winH, hWnd);
 if (FAILED(hr))
 {
     MessageBox(NULL, "DirectXの初期化に失敗", NULL, MB_OK);
     return hr;
 }


 Camera::Initialize();

 Quad* quad;
 quad = new Quad();
 hr = quad->Initialize();
 if (FAILED(hr))
 {
     MessageBox(NULL, "Quadの初期化に失敗", NULL, MB_OK);
     return hr;
 }

 

 //メッセージループ（何か起きるのを待つ）
 MSG msg;
 ZeroMemory(&msg, sizeof(msg));
 while (msg.message != WM_QUIT)
 {
     //メッセージあり
     if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
     {
         TranslateMessage(&msg);
         DispatchMessage(&msg);
     }


     //メッセージなし
     else
     {


         //カメラを更新
         Camera::Update();

         //ゲームの処理
         Direct3D::BeginDraw();
       

         //描画処理
         //1度ずつ回転するための変数
         static float rot = 0;
         rot += 0.01f;
         //radian -> digree XMConvertToRadians
         //digree -> radian XMConvertToDegrees

         XMMATRIX rmat = XMMatrixRotationY(rot);

         static float factor = 0.0;
         factor += 0.001f;
         ////float scale = 1.5 + sin(factor);
         ////XMMATRIX smat = XMMatrixScaling(scale, scale, scale);
         //////ここに自前の描画処理を追加していく
         ////XMMATRIX tmat = XMMatrixTranslation(2.0*sin(factor), 0, 0);
         XMMATRIX tmat = XMMatrixTranslation(3.0f* cos(factor), 3.0f * sin(factor), 0);
         //XMMATRIX mat = smat * rmat * tmat;
         //単位行列は、数字の１と同じ
         XMMATRIX mat = XMMatrixIdentity();//Identityは単位行列って意味
        mat = rmat * tmat;
        quad->Draw(mat);



         Direct3D::EndDraw();
        
     }

 }
 //解放処理
 

 SAFE_DELETE(quad);
 Direct3D::Release();

 
	return 0;
}
//ウィンドウプロシージャ（何かあった時によばれる関数）
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);  //プログラム終了
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

