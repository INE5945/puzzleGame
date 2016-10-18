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
	
	//�ړ��悪��#�������ꍇ
	if (data.map[data.posH + h][data.posW + w] == '#')
	{
		return data;
	}
	//�ړ���ɉו�o,O���������ꍇ
	else if (data.map[data.posH + h][data.posW + w] == 'o'|| data.map[data.posH + h][data.posW + w] == 'O')
	{
		//�ו�o�̈ړ���ɕ�#�A�ו�oO���������ꍇ�A�������Ȃ�
		if (data.map[data.posH + h+h][data.posW + w+w] == 'o' || data.map[data.posH + h + h][data.posW + w + w] == 'O' || data.map[data.posH + h + h][data.posW + w + w] == '#')
		{
			return data;
		}
		//�ו�o����Ɉړ�
		if (data.map[data.posH + h + h][data.posW + w + w] == '.')
		{
			data.map[data.posH+h+h][data.posW+w+w] = 'O';
		}
		else if (data.map[data.posH + h + h][data.posW + w + w] == ' ')
		{
			data.map[data.posH + h + h][data.posW + w + w] = 'o';
		}

		//�v���C���[p���ړ�
		if (data.map[data.posH + h][data.posW + w] == 'o')
		{
			data.map[data.posH + h][data.posW + w] = 'p';
		}
		else if (data.map[data.posH + h][data.posW + w] == 'O')
		{
			data.map[data.posH + h][data.posW + w] = 'P';
		}

		//�v���C���[p�̌���������
		if (data.map[data.posH][data.posW] == 'p') 
		{
			data.map[data.posH][data.posW] = ' ';
		}else if (data.map[data.posH][data.posW] == 'P')
		{
			data.map[data.posH][data.posW] = '.';
		}
	}
	//�ړ���ɉו�o,O���Ȃ������ꍇ
	else if (data.map[data.posH + h][data.posW + w] != 'o' || data.map[data.posH + h][data.posW + w] != 'O')
	{
		//1 p����Ɉړ�(�������A�ړ���o���j
		//1.1a p��������.��ł�(P�̏ꍇ�j
		if (data.map[data.posH][data.posW] == 'P')
		{
			data.map[data.posH][data.posW] = '.';
		}
		//1.1b p������(p�̏ꍇ�j
		else
		{
			data.map[data.posH][data.posW] = ' ';
		}
		//1.2a P��V���ɋL��(.������ꍇ�j
		if (data.map[data.posH + h][data.posW + w] == '.')
		{
			data.map[data.posH + h][data.posW + w] = 'P';
		}
		//1.2b p��V���ɋL��(.���Ȃ��ꍇ�j
		else
		{
			data.map[data.posH + h][data.posW + w] = 'p';
		}
	}
	data.posH += h;
	data.posW += w;
	return data;

		

		//�ړ���ɒB���ו�O���������ꍇ
			//�ו�O�̈ړ���ɕ�#�A�ו�oO���Ȃ������ꍇ
	
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

		cout << counter << "��ڂ̕`��" << endl;
		counter++;
	}
}