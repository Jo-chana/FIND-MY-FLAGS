#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15
#define UIJUMP 8
#define USER "��"
#define FLAG "��"
#define EDGE "��"
#define MAX_X 68
#define MAX_Y 17

typedef enum CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void clrscr();
void gotoxy(int x, int y);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE c);
void textcolor(int fg_color, int bg_color);

void startUI();
void edgeUI();
void setmode();
void setlevel();
void notice(int);
void print_success();
void print_failure();
void show_history();

#define delay(n) Sleep(n)                              // n/1000�ʸ�ŭ �ð� ����
#define randomize() srand((unsigned)time(NULL))         // ���� �߻��� �ʱ�ȭ
#define random(n) (rand() % (n))                        //0~n-1������ ���� �߻�

// ȭ���� ��� �����.
void clrscr()
{
	system("cls");
}

// Ŀ���� x,y��ǥ�� �̵���Ų��.
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// Ŀ���� x ��ǥ�� �����Ѵ�.
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// Ŀ���� y��ǥ�� �����Ѵ�.
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

// Ŀ���� ����ų� �ٽ� ǥ���Ѵ�.
void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

void startUI() {
	edgeUI();
	setcursortype(NOCURSOR);
	textcolor(MAGENTA2, BLACK);
	// F ���
	gotoxy(5, 2);	printf("����");
	gotoxy(5, 3);	printf("��  ");
	gotoxy(5, 4);	printf("����");
	gotoxy(5, 5);	printf("��  ");
	gotoxy(5, 6);	printf("��");
	// I ���
	gotoxy(5 + UIJUMP, 2);	printf("����");
	gotoxy(5 + UIJUMP, 3);	printf("  ��");
	gotoxy(5 + UIJUMP, 4);	printf("  ��");
	gotoxy(5 + UIJUMP, 5);	printf("  ��");
	gotoxy(5 + UIJUMP, 6);	printf("����");
	// N ���
	gotoxy(5 + UIJUMP * 2, 2);	printf("����");
	gotoxy(5 + UIJUMP * 2, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 6);	printf("��  ��");
	// D ��� 
	gotoxy(5 + UIJUMP * 3, 2);	printf("���");
	gotoxy(5 + UIJUMP * 3, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 6);	printf("���");
	// M ���
	gotoxy(5 + UIJUMP * 4, 2);	printf("��  ��");
	gotoxy(5 + UIJUMP * 4, 3);	printf("����");
	gotoxy(5 + UIJUMP * 4, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP * 4, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP * 4, 6);	printf("��  ��");
	// Y ���
	gotoxy(5 + UIJUMP * 5, 2);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 4);	printf("  ��");
	gotoxy(5 + UIJUMP * 5, 5);	printf("  ��");
	gotoxy(5 + UIJUMP * 5, 6);	printf("  ��");
	// �̸� ���
	textcolor(GREEN2, BLACK);
	gotoxy(5 + UIJUMP * 6 + 4, 5); printf("v.1.0.0");
	gotoxy(5 + UIJUMP * 6 + 4, 6);	printf("by Jochana");

	textcolor(BLUE2, BLACK);
	// F ���
	gotoxy(5 + UIJUMP * 2, 8);	printf("����");
	gotoxy(5 + UIJUMP * 2, 9);	printf("��  ");
	gotoxy(5 + UIJUMP * 2, 10);	printf("����");
	gotoxy(5 + UIJUMP * 2, 11);	printf("��  ");
	gotoxy(5 + UIJUMP * 2, 12);	printf("��  ");
	// L ���
	gotoxy(5 + UIJUMP * 3, 8);	printf("��");
	gotoxy(5 + UIJUMP * 3, 9);	printf("��");
	gotoxy(5 + UIJUMP * 3, 10);	printf("��");
	gotoxy(5 + UIJUMP * 3, 11);	printf("��");
	gotoxy(5 + UIJUMP * 3, 12);	printf("����");
	// A ���
	gotoxy(5 + UIJUMP * 4, 8);	printf("����");
	gotoxy(5 + UIJUMP * 4, 9);	printf("��  ��");
	gotoxy(5 + UIJUMP * 4, 10);	printf("����");
	gotoxy(5 + UIJUMP * 4, 11);	printf("��  ��");
	gotoxy(5 + UIJUMP * 4, 12);	printf("��  ��");
	// G ���
	gotoxy(5 + UIJUMP * 5, 8);	printf("����");
	gotoxy(5 + UIJUMP * 5, 9);	printf("��  ");
	gotoxy(5 + UIJUMP * 5, 10);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 11);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 12);	printf("����");
	// S ���
	gotoxy(5 + UIJUMP * 6, 8);	printf("����");
	gotoxy(5 + UIJUMP * 6, 9);	printf("��");
	gotoxy(5 + UIJUMP * 6, 10);	printf("����");
	gotoxy(5 + UIJUMP * 6, 11);	printf("    ��");
	gotoxy(5 + UIJUMP * 6, 12);	printf("����");

	// Press any Key to start
	textcolor(YELLOW2, BLACK);
	gotoxy(5 + UIJUMP * 2, 15); printf("Press any Key to start");


}

void edgeUI() {
	// �׵θ� ���
	textcolor(WHITE, BLACK);
	for (int i = 0;i < MAX_X+1;i+=2) {
		gotoxy(i, 0);printf(EDGE);
		gotoxy(i, MAX_Y);printf(EDGE);
	}
	for (int i = 1;i < MAX_Y;i++) {
		gotoxy(0, i); printf(EDGE);
		gotoxy(MAX_X, i);printf(EDGE);
	}


}

void show_history() {
	clrscr();
	edgeUI();
	gotoxy(14 , 2); printf("����ߵ��� ���� �������� �������� �̾߱��");
	gotoxy(8 , 6); printf("�ܸ� �̻��ϴٴ� ������ ��ߵ鿡�� ���ݴ��� ������.");
	gotoxy(6 , 8); printf("��ߵ��� ������ ���ΰ�, Ż������ ���ϰ� �����ϰ� �־��.");
	gotoxy(8 , 10); printf("������ ������ ������ �����ϴ� ���� ��ߵ鵵 �ִ�ϴ�.");
	gotoxy(8 , 12); printf("��ߵ��� ������ Ż���� ����� \"��¥ �̸�\"�� ã������!");
	gotoxy(5 + UIJUMP * 2 + 4, 14); printf("Ż���Ϸ� ����: S key");

	char ch;
	while (ch = _getch()) {
		if (ch == 's')
			break;
	}
}

// ����Ű �̵�
void move(int* x, int* y) {
	int ch;
	gotoxy(*x, *y);

	textcolor(GREEN2, BLACK);
	printf(USER);
	ch = _getch();

	printf("\b\b  ");
	if (ch == 224)
		ch = _getch();
	switch (ch) {
	case 72:
		(*y)--;
		break;
	case 80:
		(*y)++;
		break;
	case 75:
		(*x)--;
		break;
	case 77:
		(*x)++;
		break;
	}
}

void setmode() {
	clrscr();
	edgeUI();
	textcolor(WHITE, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 2); printf("���� ��带 �����ϼ���");
	textcolor(MAGENTA2, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 5); printf("1. TIME ATTACK MODE");
	textcolor(YELLOW2, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 8); printf("2. LIMITED WALK MODE");
	textcolor(CYAN1, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 11); printf("3. DAMAGE TAKING MODE");
	textcolor(WHITE, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 14); printf("q. GAME QUIT");

}

void setlevel() {
	clrscr();
	edgeUI();
	textcolor(WHITE, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 2); printf("���� ���̵��� �����ϼ���");
	textcolor(CYAN1, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 5); printf("1. EASY LEVEL");
	textcolor(GREEN2, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 8); printf("2. MEDIUM LEVEL");
	textcolor(RED2, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 11); printf("3. HARD LEVEL");
	textcolor(RED1, BLACK);
	gotoxy(5 + UIJUMP * 2 + 4, 14); printf("4. EXTREME LEVEL");
}

void notice(int mode) {
	clrscr();
	edgeUI();
	textcolor(YELLOW1, BLACK);
	// N ���
	gotoxy(5 + UIJUMP, 2);	printf("����");
	gotoxy(5 + UIJUMP, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP, 6);	printf("��  ��");
	// O ���
	gotoxy(5 + UIJUMP * 2, 2);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 2, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 6);	printf("  ��  ");
	// T ��� 
	gotoxy(5 + UIJUMP * 3, 2);	printf("����");
	gotoxy(5 + UIJUMP * 3, 3);	printf("  ��");
	gotoxy(5 + UIJUMP * 3, 4);	printf("  ��");
	gotoxy(5 + UIJUMP * 3, 5);	printf("  ��");
	gotoxy(5 + UIJUMP * 3, 6);	printf("  ��");
	// I ���
	gotoxy(5 + UIJUMP * 4, 2);	printf("����");
	gotoxy(5 + UIJUMP * 4, 3);	printf("  ��");
	gotoxy(5 + UIJUMP * 4, 4);	printf("  ��");
	gotoxy(5 + UIJUMP * 4, 5);	printf("  ��");
	gotoxy(5 + UIJUMP * 4, 6);	printf("����");
	// C ���
	gotoxy(5 + UIJUMP * 5, 2);	printf("  ���");
	gotoxy(5 + UIJUMP * 5, 3);	printf("��");
	gotoxy(5 + UIJUMP * 5, 4);	printf("��");
	gotoxy(5 + UIJUMP * 5, 5);	printf("��");
	gotoxy(5 + UIJUMP * 5, 6);	printf("  ���");
	// E ���
	gotoxy(5 + UIJUMP * 6, 2);	printf("����");
	gotoxy(5 + UIJUMP * 6, 3);	printf("��");
	gotoxy(5 + UIJUMP * 6, 4);	printf("����");
	gotoxy(5 + UIJUMP * 6, 5);	printf("��");
	gotoxy(5 + UIJUMP * 6, 6);	printf("����");

	gotoxy(5 + UIJUMP, 12);
	textcolor(RED1, BLACK);
	switch (mode) {
	case 49:
		printf("���� �ð� �� ��߷� ����� Ż�ⱸ�� ã�ƶ�!");
		gotoxy(5 + UIJUMP, 13); printf("����) �̰� ��ߵ��� ���������� ����մϴ�");
		break;
	case 50:
		printf("�̵��� �� �ִ� Ƚ���� ���ѵǾ� �ִ�.");
		gotoxy(5 + UIJUMP, 13); printf("�����ϰ� �̵��ؼ� ��߷� ����� Ż�ⱸ�� ã�ƺ���!");
		break;
	case 51:
		printf("��� ������� ���� ������ Ż�ⱸ�� ��������");
		gotoxy(5 + UIJUMP, 13); printf("����) �̰� ��ߵ��� ���� �ſ� ��������");
		break;
	}
	gotoxy(5 + UIJUMP, 15); printf("Press any Key to continue");
}

void print_success() {
	clrscr();
	
	textcolor(CYAN1, BLACK);
	// S ���
	gotoxy(5, 2);	printf("����");
	gotoxy(5, 3);	printf("��");
	gotoxy(5, 4);	printf("��");
	gotoxy(5, 5);	printf("��");
	gotoxy(5, 6);	printf("��");
	gotoxy(5, 7); printf("����");
	gotoxy(5, 8); printf("    ��");
	gotoxy(5, 9); printf("    ��");
	gotoxy(5, 10); printf("    ��");
	gotoxy(5, 11); printf("    ��");
	gotoxy(5, 12); printf("����");
	// U ���
	gotoxy(5 + UIJUMP, 2);	printf("��  ��");
	gotoxy(5 + UIJUMP, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP, 6);	printf("��  ��");
	gotoxy(5 + UIJUMP, 7);	printf("��  ��");
	gotoxy(5 + UIJUMP, 8);	printf("��  ��");
	gotoxy(5 + UIJUMP, 9);	printf("��  ��");
	gotoxy(5 + UIJUMP, 10);	printf("��  ��");
	gotoxy(5 + UIJUMP, 11);	printf("��  ��");
	gotoxy(5 + UIJUMP, 12);	printf("����");
	// C ���
	gotoxy(5 + UIJUMP * 2, 2);	printf("����");
	gotoxy(5 + UIJUMP * 2, 3);	printf("��");
	gotoxy(5 + UIJUMP * 2, 4);	printf("��");
	gotoxy(5 + UIJUMP * 2, 5);	printf("��");
	gotoxy(5 + UIJUMP * 2, 6);	printf("��");
	gotoxy(5 + UIJUMP * 2, 7);	printf("��");
	gotoxy(5 + UIJUMP * 2, 8);	printf("��");
	gotoxy(5 + UIJUMP * 2, 9);	printf("��");
	gotoxy(5 + UIJUMP * 2, 10);	printf("��");
	gotoxy(5 + UIJUMP * 2, 11);	printf("��");
	gotoxy(5 + UIJUMP * 2, 12);	printf("����");
	// C ��� 
	gotoxy(5 + UIJUMP * 3, 2);	printf("����");
	gotoxy(5 + UIJUMP * 3, 3);	printf("��");
	gotoxy(5 + UIJUMP * 3, 4);	printf("��");
	gotoxy(5 + UIJUMP * 3, 5);	printf("��");
	gotoxy(5 + UIJUMP * 3, 6);	printf("��");
	gotoxy(5 + UIJUMP * 3, 7);	printf("��");
	gotoxy(5 + UIJUMP * 3, 8);	printf("��");
	gotoxy(5 + UIJUMP * 3, 9);	printf("��");
	gotoxy(5 + UIJUMP * 3, 10);	printf("��");
	gotoxy(5 + UIJUMP * 3, 11);	printf("��");
	gotoxy(5 + UIJUMP * 3, 12);	printf("����");
	// E ���
	gotoxy(5 + UIJUMP * 4, 2);	printf("����");
	gotoxy(5 + UIJUMP * 4, 3);	printf("��");
	gotoxy(5 + UIJUMP * 4, 4);	printf("��");
	gotoxy(5 + UIJUMP * 4, 5);	printf("��");
	gotoxy(5 + UIJUMP * 4, 6);	printf("��");
	gotoxy(5 + UIJUMP * 4, 7);	printf("����");
	gotoxy(5 + UIJUMP * 4, 8);	printf("��");
	gotoxy(5 + UIJUMP * 4, 9);	printf("��");
	gotoxy(5 + UIJUMP * 4, 10);	printf("��");
	gotoxy(5 + UIJUMP * 4, 11);	printf("��");
	gotoxy(5 + UIJUMP * 4, 12);	printf("����");
	// S ���
	gotoxy(5 + UIJUMP * 5, 2);	printf("����");
	gotoxy(5 + UIJUMP * 5, 3);	printf("��");
	gotoxy(5 + UIJUMP * 5, 4);	printf("��");
	gotoxy(5 + UIJUMP * 5, 5);	printf("��");
	gotoxy(5 + UIJUMP * 5, 6);	printf("��");
	gotoxy(5 + UIJUMP * 5, 7); printf("����");
	gotoxy(5 + UIJUMP * 5, 8); printf("    ��");
	gotoxy(5 + UIJUMP * 5, 9); printf("    ��");
	gotoxy(5 + UIJUMP * 5, 10); printf("    ��");
	gotoxy(5 + UIJUMP * 5, 11); printf("    ��");
	gotoxy(5 + UIJUMP * 5, 12); printf("����");

	gotoxy(5 + UIJUMP * 6, 2);	printf("����");
	gotoxy(5 + UIJUMP * 6, 3);	printf("��");
	gotoxy(5 + UIJUMP * 6, 4);	printf("��");
	gotoxy(5 + UIJUMP * 6, 5);	printf("��");
	gotoxy(5 + UIJUMP * 6, 6);	printf("��");
	gotoxy(5 + UIJUMP * 6, 7); printf("����");
	gotoxy(5 + UIJUMP * 6, 8); printf("    ��");
	gotoxy(5 + UIJUMP * 6, 9); printf("    ��");
	gotoxy(5 + UIJUMP * 6, 10); printf("    ��");
	gotoxy(5 + UIJUMP * 6, 11); printf("    ��");
	gotoxy(5 + UIJUMP * 6, 12); printf("����");

	// ! ���
	gotoxy(5 + UIJUMP * 7, 2);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 3);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 4);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 5);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 6);	printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 7); printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 8); printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 9); printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 10); printf("  ��  ");
	gotoxy(5 + UIJUMP * 7, 11); printf("");
	gotoxy(5 + UIJUMP * 7, 12); printf("  ��  ");


	textcolor(YELLOW2, BLACK);
	gotoxy(5 + UIJUMP * 2, 15); printf("�����ؿ�! ����� ������ ");
	textcolor(CYAN2, BLACK); printf("���̾Ƹ��"); 
	textcolor(YELLOW2, BLACK); printf("�Դϴ�.");
	textcolor(WHITE, BLACK);
	gotoxy(5 + UIJUMP * 2, 18); printf("Press R Key to restart");

	char ch;
	while (ch = _getch()) {
		if (ch == 'r')
			break;
	}

}
void print_failure() {
	clrscr();
	edgeUI();
	textcolor(RED2, BLACK);
	// G ���
	gotoxy(5 + UIJUMP, 2);	printf("����");
	gotoxy(5 + UIJUMP, 3);	printf("��");
	gotoxy(5 + UIJUMP, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP, 6);	printf("����");
	// A ���
	gotoxy(5 + UIJUMP * 2, 2);	printf("����");
	gotoxy(5 + UIJUMP * 2, 3);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 4);	printf("����");
	gotoxy(5 + UIJUMP * 2, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 6);	printf("��  ��");
	// M ��� 
	gotoxy(5 + UIJUMP * 3, 2);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 3);	printf("����");
	gotoxy(5 + UIJUMP * 3, 4);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 5);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 6);	printf("��  ��");
	// E ���
	gotoxy(5 + UIJUMP * 4, 2);	printf("����");
	gotoxy(5 + UIJUMP * 4, 3);	printf("��");
	gotoxy(5 + UIJUMP * 4, 4);	printf("����");
	gotoxy(5 + UIJUMP * 4, 5);	printf("��");
	gotoxy(5 + UIJUMP * 4, 6);	printf("����");

	textcolor(RED1, BLACK);
	// O ���
	gotoxy(5 + UIJUMP * 2, 8);	printf("  ��");
	gotoxy(5 + UIJUMP * 2, 9);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 10);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 11);	printf("��  ��");
	gotoxy(5 + UIJUMP * 2, 12);	printf("  ��");
	// V ���
	gotoxy(5 + UIJUMP * 3, 8);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 9);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 10);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 11);	printf("��  ��");
	gotoxy(5 + UIJUMP * 3, 12);	printf("  ��");
	// E ���
	gotoxy(5 + UIJUMP * 4, 8);	printf("����");
	gotoxy(5 + UIJUMP * 4, 9);	printf("��");
	gotoxy(5 + UIJUMP * 4, 10);	printf("����");
	gotoxy(5 + UIJUMP * 4, 11);	printf("��");
	gotoxy(5 + UIJUMP * 4, 12);	printf("����");
	// R ���
	gotoxy(5 + UIJUMP * 5, 8);	printf("���");
	gotoxy(5 + UIJUMP * 5, 9);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 10);	printf("���");
	gotoxy(5 + UIJUMP * 5, 11);	printf("��  ��");
	gotoxy(5 + UIJUMP * 5, 12);	printf("��  ��");

	gotoxy(5 + UIJUMP * 6, 12); printf("��  ��  ��");

	textcolor(YELLOW2, BLACK);
	gotoxy(5 + UIJUMP * 2, 15); printf("Press R Key to restart");

	char ch;
	while (ch = _getch()) {
		if (ch == 'r')
			break;
	}
}