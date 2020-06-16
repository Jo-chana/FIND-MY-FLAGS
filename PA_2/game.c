#include "game.h"
#include <process.h>
struct flag {
	int size;
	int x; // x 좌표
	int y; // y 좌표
	int target; // 어떤 역할을 하는 깃발인지
};
struct message {
	int type;
	char condition[20];
	char penalty[100];
	char incentive[100];
};

void setting(int, int, struct message*, struct flag*);
void make_flags(struct flag*, int, float);
void print_flags(struct flag*, int);
void validation(struct flag*, struct message*, int*, int*);
void bad(int, int*, int*, struct flag*);
void good(int, int*, int*, struct flag*);
void goal();
void print_score(int);
void danger(int);
int quit, timenum, walk, health, threadUI;

unsigned _stdcall thread_time(void* arg) {
	while (1) {
		Sleep(1000);
		timenum--;
	}
}

unsigned _stdcall thread_startUI(void* arg) {
	while (threadUI) {
		if (threadUI == 1) {
			gotoxy(5 + UIJUMP * 2, 15); printf("Press any Key to start");
			Sleep(500);
			gotoxy(5 + UIJUMP * 2, 15); printf("                              ");
			Sleep(500);
		}
		else if (threadUI == 2) {
			gotoxy(5 + UIJUMP * 2, 15); printf("Press R Key to restart");
			Sleep(500);
			gotoxy(5 + UIJUMP * 2, 15); printf("                             ");
			Sleep(500);
		}
		else if (threadUI == 3) {
			gotoxy(5 + UIJUMP * 2, 18); printf("Press R Key to restart");
			Sleep(500);
			gotoxy(5 + UIJUMP * 2, 18); printf("                                ");
			Sleep(500);
		}
			
	}
}

int main() {
	int mode, level, x, y;
	struct flag flags[30];
	struct message msg;
	_beginthreadex(NULL, 0, thread_time, 0, 0, NULL);
	_beginthreadex(NULL, 0, thread_startUI, 0, 0, NULL);
	while (1) {
		threadUI = 1;
		clrscr();
		startUI();
		_getch();
		threadUI = -1;
		show_history();
		setmode();
		while (mode = _getch()) { //49, 50, 51
			if (mode == 'q') {
				clrscr();
				return;
			}
			if (mode >= 49 && mode <= 51)
				break;
		}
		setlevel();
		while (level = _getch()) { //49, 50, 51, 52
			if (level >= 49 && level <= 52)
				break;
		}
		notice(mode);
		_getch();
		while (1) {
			x = 2; y = 1;
			srand((unsigned int)time);
			setting(mode, level, &msg, flags);
			quit = 0;
			textcolor(WHITE, BLUE1);
			gotoxy(2, MAX_Y + 1); printf("%s", msg.condition);

			while (1) {
				gotoxy(14, MAX_Y + 1); print_score(msg.type);
				move(&x, &y); walk--;
				validation(flags, &msg, &x, &y);
				danger(msg.type);
				if (quit)
					break;
			}
			if (quit == -1) {
				threadUI = 2;
				print_failure();
				break;
			}
			else if (level < 52)
				level++;
			else if (level == 52) {
				threadUI = 3;
				print_success();
				break;
			}
		}
	}
}

void setting(int mode, int level, struct message* pmsg, struct flag* pflag) {
	switch (mode) {
	case 49: // 타임어택
		pmsg->type = 1;
		timenum = 30;
		strcpy(pmsg->condition, "남은 시간: ");
		strcpy(pmsg->penalty, "깃발이 쏜 테이저건에 맞아 마비됩니다..");
		strcpy(pmsg->incentive, "착한 깃발이 당신의 시간을 벌어줍니다!");
		break;
	case 50: // 이동제한
		pmsg->type = 2;
		walk = 70;
		strcpy(pmsg->condition, "남은 이동: ");
		strcpy(pmsg->penalty, "깃발이 당신을 이상한 곳으로 던져 버렸습니다!");
		strcpy(pmsg->incentive, "착한 깃발이 당신을 좋은 장소로 데려다 주었습니다!");
		break;
	case 51: // 데미지
		pmsg->type = 3;
		health = 100;
		strcpy(pmsg->condition, "현재 체력: ");
		strcpy(pmsg->penalty, "무서운 형님 깃발이 당신을 무자비하게 때립니다");
		strcpy(pmsg->incentive, "착한 깃발이 당신에게 안마를 해주었습니다!");
		break;
	}
	switch (level) {
	case 49:
		make_flags(pflag, 10, 0.3);
		break;
	case 50:
		make_flags(pflag, 15, 0.5);
		break;
	case 51:
		make_flags(pflag, 25, 0.5);
		break;
	case 52:
		make_flags(pflag, 30, 0.7);
		break;
	}
}

void make_flags(struct flag* pflag, int size, float ratio) {
	srand((unsigned int)time(0));
	int rate = (int)(size * ratio);
	for (int i = 0;i < size;i++) {
		pflag[i].x = rand() % 63+2;
		pflag[i].y = rand() % 14+1;
		if (i <= rate)
			pflag[i].target = -1; // 가짜 깃발
		else if (i == size - 1)
			pflag[i].target = 1; // 보물 깃발
		else
			pflag[i].target = 0;  // 착한 깃발
	}
	pflag[0].size = size;
	print_flags(pflag, size);
}

void print_flags(struct flag* pflag, int size) {
	clrscr();
	edgeUI();
	textcolor(MAGENTA1, BLACK);
	for (int i = 0;i < size;i++) {

		///* 테스트용 깃발 색칠*/
		//if (pflag[i].target == 0)
		//	textcolor(BLUE1, BLACK);
		//else if (pflag[i].target == -1)
		//	textcolor(RED1, BLACK);
		//else
		//	textcolor(GREEN2, BLACK);

		gotoxy(pflag[i].x, pflag[i].y);
		printf(FLAG);
	}
}

void validation(struct flag* pflag, struct message* pmsg, int* px, int* py) {
	for (int i = 0;i < pflag[0].size;i++) {
		if (*px == pflag[i].x && *py == pflag[i].y) {
			gotoxy(0, MAX_Y + 2);
			printf("                                                                  ");
			gotoxy(0, MAX_Y + 2);
			switch (pflag[i].target) {
			case 1:
				printf("축하합니다! 탈출구를 찾았습니다!");
				goal();
				break;
			case -1:
				textcolor(RED1, BLACK);
				printf("%s", pmsg->penalty);
				bad(pmsg->type,px,py, pflag);
				break;
			case 0:
				textcolor(CYAN2, BLACK);
				printf("%s", pmsg->incentive);
				good(pmsg->type,px,py,pflag);
				break;
			}
		}
	}
	if (*px <= 1 || *py <= 0 || *px >= MAX_X-1 || *py >= MAX_Y) {
		edgeUI();
		gotoxy(0, MAX_Y + 2);
		printf("                                                                  ");
		gotoxy(0, MAX_Y + 2);
		textcolor(WHITE, BLACK);
		printf("당신은 벽을 넘으려다 걸렸습니다..");
		*px = 2; *py = 1;
	}

}

void bad(int type, int* px, int* py, struct flag* pflag) {
	int x, y;
	switch (type) {
	case 1: // 타임어택
		x = *px; y = *py;
		Sleep(1500);
		timenum--;
		*px = x; *py = y;
		break;
	case 2: // 이동제한
		x = rand() % (MAX_X-3) + 2;
		y = rand() % (MAX_Y-2) + 1;
		*px = x; *py = y;
		break;
	case 3: // 데미지
		srand((unsigned int)time(0));
		health -= rand()%20+15;
		break;
	}
}
void good(int type, int* px, int* py, struct flag* pflag) {
	int x, y;
	switch (type) {
	case 1: // 타임어택
		timenum += 3;
		break;
	case 2: // 이동제한
		x = pflag[pflag[0].size - 1].x;
		y = pflag[pflag[0].size - 1].y;
		x = (int)(x + *px) / 2;
		y = (int)(y + *py) / 2;
		*px = x; *py = y;
		break;
	case 3: // 데미지
		srand((unsigned int)time(0));
		health += rand()%15+10;
		break;
	}
}
void goal() {
	Sleep(3000);
	quit = 1;
}

void print_score(int mode) {
	switch (mode) {
	case 1:
		printf("%2d", timenum);
		break;
	case 2:
		printf("%2d",walk);
		break;
	case 3:
		printf("%3d",health);
		break;
	}
}

void danger(int mode) {
	switch (mode) {
	case 1:
		if (timenum <= 0)
			quit = -1;
		break;
	case 2:
		if (walk <= 0)
			quit = -1;
		break;
	case 3:
		if (health <= 0)
			quit = -1;
		break;
	}
}