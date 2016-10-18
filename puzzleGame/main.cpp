#include<iostream>

using namespace std;

typedef struct _updateData {
	char map[5][9];
	int posH;
	int posW;
}UPDATEDATA;



char getInput()
{
	char c;
	cin >> c;
	return c;
}

UPDATEDATA updateGame(char c,UPDATEDATA data) 
{
	int h = 0;
	int w = 0;

	if      (c == 'w'){h = -1;}
	else if (c == 's'){h =  1;}
	else if (c == 'a'){w = -1;}
	else if (c == 'd'){w =  1;}
	
	//移動先が壁#だった場合
	if (data.map[data.posH + h][data.posW + w] == '#')
	{
		return data;
	}
	//移動先に荷物o,Oがあった場合
	else if (data.map[data.posH + h][data.posW + w] == 'o'|| data.map[data.posH + h][data.posW + w] == 'O')
	{
		//荷物oの移動先に壁#、荷物oOがあった場合、何もしない
		if (data.map[data.posH + h+h][data.posW + w+w] == 'o' || data.map[data.posH + h + h][data.posW + w + w] == 'O' || data.map[data.posH + h + h][data.posW + w + w] == '#')
		{
			return data;
		}
		//荷物oを上に移動
		if (data.map[data.posH + h + h][data.posW + w + w] == '.')
		{
			data.map[data.posH+h+h][data.posW+w+w] = 'O';
		}
		else if (data.map[data.posH + h + h][data.posW + w + w] == ' ')
		{
			data.map[data.posH + h + h][data.posW + w + w] = 'o';
		}

		//プレイヤーpを移動
		if (data.map[data.posH + h][data.posW + w] == 'o')
		{
			data.map[data.posH + h][data.posW + w] = 'p';
		}
		else if (data.map[data.posH + h][data.posW + w] == 'O')
		{
			data.map[data.posH + h][data.posW + w] = 'P';
		}

		//プレイヤーpの元情報を消去
		if (data.map[data.posH][data.posW] == 'p') 
		{
			data.map[data.posH][data.posW] = ' ';
		}else if (data.map[data.posH][data.posW] == 'P')
		{
			data.map[data.posH][data.posW] = '.';
		}
	}
	//移動先に荷物o,Oがなかった場合
	else if (data.map[data.posH + h][data.posW + w] != 'o' || data.map[data.posH + h][data.posW + w] != 'O')
	{
		//1 pを上に移動(元消し、移動先出現）
		//1.1a pを消して.を打つ(Pの場合）
		if (data.map[data.posH][data.posW] == 'P')
		{
			data.map[data.posH][data.posW] = '.';
		}
		//1.1b pを消す(pの場合）
		else
		{
			data.map[data.posH][data.posW] = ' ';
		}
		//1.2a Pを新たに記入(.がある場合）
		if (data.map[data.posH + h][data.posW + w] == '.')
		{
			data.map[data.posH + h][data.posW + w] = 'P';
		}
		//1.2b pを新たに記入(.がない場合）
		else
		{
			data.map[data.posH + h][data.posW + w] = 'p';
		}
	}
	data.posH += h;
	data.posW += w;
	return data;

		

		//移動先に達成荷物Oがあった場合
			//荷物Oの移動先に壁#、荷物oOがなかった場合
	
}

void draw(char map[5][9])
{
	for (int i = 0; i <5; i++) {
		for (int j = 0; j < 9; j++) {
			cout<<map[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int posH = 1;
	int posW = 5;
	char map[5][9] = { "########","# .. p #","# oo   #","#      #","########" };
	char c;
	UPDATEDATA data;
	for (int i = 0; i <5; i++) {
		for (int j = 0; j < 9; j++) {
			data.map[i][j] = map[i][j];
		}
	}
	data.posH = posH;
	data.posW = posW;
	draw(data.map);

	int counter = 0;

	while (true) 
	{
		c=getInput();
		data=updateGame(c,data);
		draw(data.map);

		cout << counter << "回目の描画" << endl;
		counter++;
	}
}