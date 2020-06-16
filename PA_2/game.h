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
#define USER "◆"
#define FLAG "▶"
#define EDGE "▣"
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

#define delay(n) Sleep(n)                              // n/1000초만큼 시간 지연
#define randomize() srand((unsigned)time(NULL))         // 난수 발생기 초기화
#define random(n) (rand() % (n))                        //0~n-1까지의 난수 발생

// 화면을 모두 지운다.
void clrscr()
{
	system("cls");
}

// 커서를 x,y좌표로 이동시킨다.
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 커서의 x 좌표를 조사한다.
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// 커서의 y좌표를 조사한다.
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

// 커서를 숨기거나 다시 표시한다.
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
	// F 출력
	gotoxy(5, 2);	printf("■■■");
	gotoxy(5, 3);	printf("■  ");
	gotoxy(5, 4);	printf("■■■");
	gotoxy(5, 5);	printf("■  ");
	gotoxy(5, 6);	printf("■");
	// I 출력
	gotoxy(5 + UIJUMP, 2);	printf("■■■");
	gotoxy(5 + UIJUMP, 3);	printf("  ■");
	gotoxy(5 + UIJUMP, 4);	printf("  ■");
	gotoxy(5 + UIJUMP, 5);	printf("  ■");
	gotoxy(5 + UIJUMP, 6);	printf("■■■");
	// N 출력
	gotoxy(5 + UIJUMP * 2, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 2, 3);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 6);	printf("■  ■");
	// D 출력 
	gotoxy(5 + UIJUMP * 3, 2);	printf("■■");
	gotoxy(5 + UIJUMP * 3, 3);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 6);	printf("■■");
	// M 출력
	gotoxy(5 + UIJUMP * 4, 2);	printf("■  ■");
	gotoxy(5 + UIJUMP * 4, 3);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP * 4, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP * 4, 6);	printf("■  ■");
	// Y 출력
	gotoxy(5 + UIJUMP * 5, 2);	printf("■  ■");
	gotoxy(5 + UIJUMP * 5, 3);	printf("■  ■");
	gotoxy(5 + UIJUMP * 5, 4);	printf("  ■");
	gotoxy(5 + UIJUMP * 5, 5);	printf("  ■");
	gotoxy(5 + UIJUMP * 5, 6);	printf("  ■");
	// 이름 출력
	textcolor(GREEN2, BLACK);
	gotoxy(5 + UIJUMP * 6 + 4, 5); printf("v.1.0.0");
	gotoxy(5 + UIJUMP * 6 + 4, 6);	printf("by Jochana");

	textcolor(BLUE2, BLACK);
	// F 출력
	gotoxy(5 + UIJUMP * 2, 8);	printf("■■■");
	gotoxy(5 + UIJUMP * 2, 9);	printf("■  ");
	gotoxy(5 + UIJUMP * 2, 10);	printf("■■■");
	gotoxy(5 + UIJUMP * 2, 11);	printf("■  ");
	gotoxy(5 + UIJUMP * 2, 12);	printf("■  ");
	// L 출력
	gotoxy(5 + UIJUMP * 3, 8);	printf("■");
	gotoxy(5 + UIJUMP * 3, 9);	printf("■");
	gotoxy(5 + UIJUMP * 3, 10);	printf("■");
	gotoxy(5 + UIJUMP * 3, 11);	printf("■");
	gotoxy(5 + UIJUMP * 3, 12);	printf("■■■");
	// A 출력
	gotoxy(5 + UIJUMP * 4, 8);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 9);	printf("■  ■");
	gotoxy(5 + UIJUMP * 4, 10);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 11);	printf("■  ■");
	gotoxy(5 + UIJUMP * 4, 12);	printf("■  ■");
	// G 출력
	gotoxy(5 + UIJUMP * 5, 8);	printf("■■■");
	gotoxy(5 + UIJUMP * 5, 9);	printf("■  ");
	gotoxy(5 + UIJUMP * 5, 10);	printf("■  ■");
	gotoxy(5 + UIJUMP * 5, 11);	printf("■  ■");
	gotoxy(5 + UIJUMP * 5, 12);	printf("■■■");
	// S 출력
	gotoxy(5 + UIJUMP * 6, 8);	printf("■■■");
	gotoxy(5 + UIJUMP * 6, 9);	printf("■");
	gotoxy(5 + UIJUMP * 6, 10);	printf("■■■");
	gotoxy(5 + UIJUMP * 6, 11);	printf("    ■");
	gotoxy(5 + UIJUMP * 6, 12);	printf("■■■");

	// Press any Key to start
	textcolor(YELLOW2, BLACK);
	gotoxy(5 + UIJUMP * 2, 15); printf("Press any Key to start");


}

void edgeUI() {
	// 테두리 출력
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
	gotoxy(14 , 2); printf("▶깃발들의 성에 갇혀버린 마름모의 이야기◆");
	gotoxy(8 , 6); printf("외모가 이상하다는 이유로 깃발들에게 감금당한 마름모.");
	gotoxy(6 , 8); printf("깃발들은 마름모를 가두고, 탈출하지 못하게 감시하고 있어요.");
	gotoxy(8 , 10); printf("하지만 마름모를 남몰래 응원하는 착한 깃발들도 있답니다.");
	gotoxy(8 , 12); printf("깃발들의 성에서 탈출해 당신의 \"진짜 이름\"을 찾으세요!");
	gotoxy(5 + UIJUMP * 2 + 4, 14); printf("탈출하러 가기: S key");

	char ch;
	while (ch = _getch()) {
		if (ch == 's')
			break;
	}
}

// 방향키 이동
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
	gotoxy(5 + UIJUMP * 2 + 4, 2); printf("게임 모드를 선택하세요");
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
	gotoxy(5 + UIJUMP * 2 + 4, 2); printf("게임 난이도를 선택하세요");
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
	// N 출력
	gotoxy(5 + UIJUMP, 2);	printf("■■■");
	gotoxy(5 + UIJUMP, 3);	printf("■  ■");
	gotoxy(5 + UIJUMP, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP, 6);	printf("■  ■");
	// O 출력
	gotoxy(5 + UIJUMP * 2, 2);	printf("  ■  ");
	gotoxy(5 + UIJUMP * 2, 3);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 6);	printf("  ■  ");
	// T 출력 
	gotoxy(5 + UIJUMP * 3, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 3, 3);	printf("  ■");
	gotoxy(5 + UIJUMP * 3, 4);	printf("  ■");
	gotoxy(5 + UIJUMP * 3, 5);	printf("  ■");
	gotoxy(5 + UIJUMP * 3, 6);	printf("  ■");
	// I 출력
	gotoxy(5 + UIJUMP * 4, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 3);	printf("  ■");
	gotoxy(5 + UIJUMP * 4, 4);	printf("  ■");
	gotoxy(5 + UIJUMP * 4, 5);	printf("  ■");
	gotoxy(5 + UIJUMP * 4, 6);	printf("■■■");
	// C 출력
	gotoxy(5 + UIJUMP * 5, 2);	printf("  ■■");
	gotoxy(5 + UIJUMP * 5, 3);	printf("■");
	gotoxy(5 + UIJUMP * 5, 4);	printf("■");
	gotoxy(5 + UIJUMP * 5, 5);	printf("■");
	gotoxy(5 + UIJUMP * 5, 6);	printf("  ■■");
	// E 출력
	gotoxy(5 + UIJUMP * 6, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 6, 3);	printf("■");
	gotoxy(5 + UIJUMP * 6, 4);	printf("■■■");
	gotoxy(5 + UIJUMP * 6, 5);	printf("■");
	gotoxy(5 + UIJUMP * 6, 6);	printf("■■■");

	gotoxy(5 + UIJUMP, 12);
	textcolor(RED1, BLACK);
	switch (mode) {
	case 49:
		printf("제한 시간 내 깃발로 위장된 탈출구를 찾아라!");
		gotoxy(5 + UIJUMP, 13); printf("주의) 이곳 깃발들은 테이저건을 사용합니다");
		break;
	case 50:
		printf("이동할 수 있는 횟수는 제한되어 있다.");
		gotoxy(5 + UIJUMP, 13); printf("신중하게 이동해서 깃발로 위장된 탈출구를 찾아보자!");
		break;
	case 51:
		printf("깃발 병사들을 피해 숨겨진 탈출구로 대피하자");
		gotoxy(5 + UIJUMP, 13); printf("주의) 이곳 깃발들은 아주 매우 폭력적임");
		break;
	}
	gotoxy(5 + UIJUMP, 15); printf("Press any Key to continue");
}

void print_success() {
	clrscr();
	
	textcolor(CYAN1, BLACK);
	// S 출력
	gotoxy(5, 2);	printf("■■■");
	gotoxy(5, 3);	printf("■");
	gotoxy(5, 4);	printf("■");
	gotoxy(5, 5);	printf("■");
	gotoxy(5, 6);	printf("■");
	gotoxy(5, 7); printf("■■■");
	gotoxy(5, 8); printf("    ■");
	gotoxy(5, 9); printf("    ■");
	gotoxy(5, 10); printf("    ■");
	gotoxy(5, 11); printf("    ■");
	gotoxy(5, 12); printf("■■■");
	// U 출력
	gotoxy(5 + UIJUMP, 2);	printf("■  ■");
	gotoxy(5 + UIJUMP, 3);	printf("■  ■");
	gotoxy(5 + UIJUMP, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP, 6);	printf("■  ■");
	gotoxy(5 + UIJUMP, 7);	printf("■  ■");
	gotoxy(5 + UIJUMP, 8);	printf("■  ■");
	gotoxy(5 + UIJUMP, 9);	printf("■  ■");
	gotoxy(5 + UIJUMP, 10);	printf("■  ■");
	gotoxy(5 + UIJUMP, 11);	printf("■  ■");
	gotoxy(5 + UIJUMP, 12);	printf("■■■");
	// C 출력
	gotoxy(5 + UIJUMP * 2, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 2, 3);	printf("■");
	gotoxy(5 + UIJUMP * 2, 4);	printf("■");
	gotoxy(5 + UIJUMP * 2, 5);	printf("■");
	gotoxy(5 + UIJUMP * 2, 6);	printf("■");
	gotoxy(5 + UIJUMP * 2, 7);	printf("■");
	gotoxy(5 + UIJUMP * 2, 8);	printf("■");
	gotoxy(5 + UIJUMP * 2, 9);	printf("■");
	gotoxy(5 + UIJUMP * 2, 10);	printf("■");
	gotoxy(5 + UIJUMP * 2, 11);	printf("■");
	gotoxy(5 + UIJUMP * 2, 12);	printf("■■■");
	// C 출력 
	gotoxy(5 + UIJUMP * 3, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 3, 3);	printf("■");
	gotoxy(5 + UIJUMP * 3, 4);	printf("■");
	gotoxy(5 + UIJUMP * 3, 5);	printf("■");
	gotoxy(5 + UIJUMP * 3, 6);	printf("■");
	gotoxy(5 + UIJUMP * 3, 7);	printf("■");
	gotoxy(5 + UIJUMP * 3, 8);	printf("■");
	gotoxy(5 + UIJUMP * 3, 9);	printf("■");
	gotoxy(5 + UIJUMP * 3, 10);	printf("■");
	gotoxy(5 + UIJUMP * 3, 11);	printf("■");
	gotoxy(5 + UIJUMP * 3, 12);	printf("■■■");
	// E 출력
	gotoxy(5 + UIJUMP * 4, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 3);	printf("■");
	gotoxy(5 + UIJUMP * 4, 4);	printf("■");
	gotoxy(5 + UIJUMP * 4, 5);	printf("■");
	gotoxy(5 + UIJUMP * 4, 6);	printf("■");
	gotoxy(5 + UIJUMP * 4, 7);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 8);	printf("■");
	gotoxy(5 + UIJUMP * 4, 9);	printf("■");
	gotoxy(5 + UIJUMP * 4, 10);	printf("■");
	gotoxy(5 + UIJUMP * 4, 11);	printf("■");
	gotoxy(5 + UIJUMP * 4, 12);	printf("■■■");
	// S 출력
	gotoxy(5 + UIJUMP * 5, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 5, 3);	printf("■");
	gotoxy(5 + UIJUMP * 5, 4);	printf("■");
	gotoxy(5 + UIJUMP * 5, 5);	printf("■");
	gotoxy(5 + UIJUMP * 5, 6);	printf("■");
	gotoxy(5 + UIJUMP * 5, 7); printf("■■■");
	gotoxy(5 + UIJUMP * 5, 8); printf("    ■");
	gotoxy(5 + UIJUMP * 5, 9); printf("    ■");
	gotoxy(5 + UIJUMP * 5, 10); printf("    ■");
	gotoxy(5 + UIJUMP * 5, 11); printf("    ■");
	gotoxy(5 + UIJUMP * 5, 12); printf("■■■");

	gotoxy(5 + UIJUMP * 6, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 6, 3);	printf("■");
	gotoxy(5 + UIJUMP * 6, 4);	printf("■");
	gotoxy(5 + UIJUMP * 6, 5);	printf("■");
	gotoxy(5 + UIJUMP * 6, 6);	printf("■");
	gotoxy(5 + UIJUMP * 6, 7); printf("■■■");
	gotoxy(5 + UIJUMP * 6, 8); printf("    ■");
	gotoxy(5 + UIJUMP * 6, 9); printf("    ■");
	gotoxy(5 + UIJUMP * 6, 10); printf("    ■");
	gotoxy(5 + UIJUMP * 6, 11); printf("    ■");
	gotoxy(5 + UIJUMP * 6, 12); printf("■■■");

	// ! 출력
	gotoxy(5 + UIJUMP * 7, 2);	printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 3);	printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 4);	printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 5);	printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 6);	printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 7); printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 8); printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 9); printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 10); printf("  ■  ");
	gotoxy(5 + UIJUMP * 7, 11); printf("");
	gotoxy(5 + UIJUMP * 7, 12); printf("  ■  ");


	textcolor(YELLOW2, BLACK);
	gotoxy(5 + UIJUMP * 2, 15); printf("축하해요! 당신은 진정한 ");
	textcolor(CYAN2, BLACK); printf("다이아몬드"); 
	textcolor(YELLOW2, BLACK); printf("입니다.");
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
	// G 출력
	gotoxy(5 + UIJUMP, 2);	printf("■■■");
	gotoxy(5 + UIJUMP, 3);	printf("■");
	gotoxy(5 + UIJUMP, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP, 6);	printf("■■■");
	// A 출력
	gotoxy(5 + UIJUMP * 2, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 2, 3);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 4);	printf("■■■");
	gotoxy(5 + UIJUMP * 2, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 6);	printf("■  ■");
	// M 출력 
	gotoxy(5 + UIJUMP * 3, 2);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 3);	printf("■■■");
	gotoxy(5 + UIJUMP * 3, 4);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 5);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 6);	printf("■  ■");
	// E 출력
	gotoxy(5 + UIJUMP * 4, 2);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 3);	printf("■");
	gotoxy(5 + UIJUMP * 4, 4);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 5);	printf("■");
	gotoxy(5 + UIJUMP * 4, 6);	printf("■■■");

	textcolor(RED1, BLACK);
	// O 출력
	gotoxy(5 + UIJUMP * 2, 8);	printf("  ■");
	gotoxy(5 + UIJUMP * 2, 9);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 10);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 11);	printf("■  ■");
	gotoxy(5 + UIJUMP * 2, 12);	printf("  ■");
	// V 출력
	gotoxy(5 + UIJUMP * 3, 8);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 9);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 10);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 11);	printf("■  ■");
	gotoxy(5 + UIJUMP * 3, 12);	printf("  ■");
	// E 출력
	gotoxy(5 + UIJUMP * 4, 8);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 9);	printf("■");
	gotoxy(5 + UIJUMP * 4, 10);	printf("■■■");
	gotoxy(5 + UIJUMP * 4, 11);	printf("■");
	gotoxy(5 + UIJUMP * 4, 12);	printf("■■■");
	// R 출력
	gotoxy(5 + UIJUMP * 5, 8);	printf("■■");
	gotoxy(5 + UIJUMP * 5, 9);	printf("■  ■");
	gotoxy(5 + UIJUMP * 5, 10);	printf("■■");
	gotoxy(5 + UIJUMP * 5, 11);	printf("■  ■");
	gotoxy(5 + UIJUMP * 5, 12);	printf("■  ■");

	gotoxy(5 + UIJUMP * 6, 12); printf("■  ■  ■");

	textcolor(YELLOW2, BLACK);
	gotoxy(5 + UIJUMP * 2, 15); printf("Press R Key to restart");

	char ch;
	while (ch = _getch()) {
		if (ch == 'r')
			break;
	}
}