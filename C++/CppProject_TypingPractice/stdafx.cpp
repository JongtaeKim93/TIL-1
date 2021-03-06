// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// CppProjectFinish.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"

void setFontColor(int color) {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (info.wAttributes & 0xf0) | (color & 0xf));
}

void set_letter_color(int color) {	// 글씨 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c)
	{
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

void CppManager::menu_intro_and_progress()
{

	while (1) {
		VIEW_01 view01;
		VIEW_02 view02;
	}
}

float CppManager::usage_time(float start) {	//소요 시간 반환. 단위는 초
	gotoxy(TP_TABLE_X - 21, 12);
	float time = (float)(clock() - start) / CLOCKS_PER_SEC;
	return time;
}

void CppManager::game_over()
{
	int i;
	system("cls");
	string over = "G  A  M  E    O  V  E  R";
	string over2 = "아 무 키 나  입 력 해 주 세 요";

	set_letter_color(LIGHTRED);
	for (i = 0; i < over.length(); i++) {
		gotoxy(GAME_OVER_X - 6 + i, GAME_OVER_Y + 1);
		cout << over[i];
		Sleep(50);
	}
	set_letter_color(WHITE);

	set_letter_color(LIGHTCYAN);
	gotoxy(GAME_OVER_X + 2, GAME_OVER_Y + 4);
	cout << "점수 : " << SCORE;
	set_letter_color(WHITE);

	gotoxy(GAME_OVER_X - 8, GAME_OVER_Y + 7);
	cout << over2;
	_getch();
	system("cls");
}

void CppManager::game_clear()
{
	int i;
	system("cls");
	string over = "G  A  M  E    C  L  E  A  R";
	string over2 = "아 무 키 나  입 력 해 주 세 요";

	set_letter_color(LIGHTGREEN);
	for (i = 0; i < over.length(); i++) {
		gotoxy(GAME_OVER_X - 6 + i, GAME_OVER_Y + 1);
		cout << over[i];
		Sleep(50);
	}
	set_letter_color(WHITE);

	set_letter_color(LIGHTCYAN);
	gotoxy(GAME_OVER_X + 2, GAME_OVER_Y + 4);
	cout << "점수 : " << SCORE;
	set_letter_color(WHITE);

	gotoxy(GAME_OVER_X - 8, GAME_OVER_Y + 7);
	cout << over2;
	_getch();
}

void TypingPractice::tp_clear()
{
	int i;
	system("cls");
	string over = "T  Y  P  I  N  G    C  L  E  A  R";
	string over2 = "아 무 키 나  입 력 해 주 세 요";

	set_letter_color(LIGHTGREEN);
	for (i = 0; i < over.length(); i++) {
		gotoxy(GAME_OVER_X - 10 + i, GAME_OVER_Y + 1);
		cout << over[i];
		Sleep(50);
	}
	set_letter_color(WHITE);

	set_letter_color(LIGHTCYAN);
	gotoxy(GAME_OVER_X + 2, GAME_OVER_Y + 4);
	cout << "타자수 : " << this->WPM;
	set_letter_color(WHITE);

	gotoxy(GAME_OVER_X - 8, GAME_OVER_Y + 7);
	cout << over2;
	_getch();
}

void Game::game_menu() {	// 게임 메뉴 선택 함수

	while (1) {
		this->menu = print_game_menu();
		if (this->menu == 1) {
			this->game_play_intro();
			this->game_play();
		}
		else {
			system("cls");
			break;
		}
	}
	VIEW_02 view2;
}

int Game::print_game_menu() {
	char ch;		// 입력된 키 저장
	int num;		// 메뉴 번호 저장
	int out = 0;	// 메뉴에서 나가기 위함
	setcursortype(NOCURSOR);
	gotoxy(POSITION_GAME_MENU_X, POSITION_GAME_MENU_Y);
	cout << ("1. 게임하기");
	gotoxy(POSITION_GAME_MENU_X, POSITION_GAME_MENU_Y + 2);
	cout << ("2. 나가기");
	num = 1;
	set_letter_color(LIGHTRED);
	gotoxy(POSITION_GAME_MENU_X - 2, POSITION_GAME_MENU_Y);
	cout << ("▶");
	set_letter_color(WHITE);
	while (1)
	{
		ch = _getch();
		if (ch == 13) break;	// 엔터 입력시

		if (_kbhit()) {		// 키입력 확인
			ch = _getch();
			if (ch == 72) {	// 방향키 위에 입력
				set_letter_color(LIGHTRED);
				gotoxy(POSITION_GAME_MENU_X - 2, POSITION_GAME_MENU_Y);
				cout << ("▶");
				set_letter_color(WHITE);
				gotoxy(POSITION_GAME_MENU_X - 2, POSITION_GAME_MENU_Y + 2);
				cout << (" ");
				num = 1;
			}
			else if (ch == 80) {	// 방향키 아래 입력
				gotoxy(POSITION_GAME_MENU_X - 2, POSITION_GAME_MENU_Y);
				cout << (" ");
				set_letter_color(LIGHTRED);
				gotoxy(POSITION_GAME_MENU_X - 2, POSITION_GAME_MENU_Y + 2);
				cout << ("▶");
				set_letter_color(WHITE);
				num = 2;
			}

		}
	}
	system("cls");
	return num;
}

void Game::game_play()	// 게임 플레이
{
	Game game;
	int random_word = 0;
	int random_position = 0;
	int word_len = 0;
	int i, j = 1, k = 0;
	int ch;
	int cnt = 0;
	string input_word = "";
	string get;
	setcursortype(NOCURSOR);
	game.game_play_table();
	game.game_score_table();

	while (1)
	{
		random_word = rand() % WORD_NUM;
		word_len = word_num[random_word].length();
		random_position = rand() % (X_MAX - word_len - 1) + 1;
		gotoxy(random_position, 1);
		cout << word_num[random_word];
		gotoxy(WORD_INPUT_POSITION_X, WORD_INPUT_POSITION_Y - 1);
		while (1)
		{
			if (cnt % SPEED == 0) {
				word_len = word_num[random_word].length();
				if (j == Y_MAX - 3) {
					for (i = 0; i <= word_len; i++) {
						gotoxy(random_position + i, Y_MAX - 3);
						cout << ' ';
					}
					game_score(FALSE);
					game_score(DROP);
					break;
				}
				for (i = 0; i < word_len; i++) {
					gotoxy(random_position + i, j);
					cout << (" ");
				}
				j++;
				gotoxy(random_position, j);
				cout << word_num[random_word];
			}

			if (_kbhit()) {
				ch = _getch();
				if (ch >= 33 && ch <= 126) {
					input_word += char(ch);
					gotoxy(WORD_INPUT_POSITION_X, WORD_INPUT_POSITION_Y - 1);
					cout << input_word;
				}
				else if (ch == 8)
				{
					if (input_word.length() != 0) {
						input_word.pop_back();
						for (i = 0; i <= input_word.length(); i++) {
							gotoxy(WORD_INPUT_POSITION_X + i, WORD_INPUT_POSITION_Y - 1);
							cout << ' ';
						}
						gotoxy(WORD_INPUT_POSITION_X, WORD_INPUT_POSITION_Y - 1);
						cout << input_word;
					}
				}

				else if (ch == 13) {
					if (word_num[random_word] == input_word) {
						for (i = 0; i < word_len; i++) {
							gotoxy(random_position + i, j);
							cout << (" ");
						}
						for (i = 0; i <= input_word.length(); i++) {
							gotoxy(WORD_INPUT_POSITION_X + i, WORD_INPUT_POSITION_Y - 1);
							cout << ' ';
						}
						game_score(TRUE);
						input_word.clear();
						j = 1;
						break;
					}
					else {
						for (i = 0; i <= input_word.length(); i++) {
							gotoxy(WORD_INPUT_POSITION_X + i, WORD_INPUT_POSITION_Y - 1);
							cout << ' ';
						}
						input_word.clear();
					}
				}
				else if (ch == 27) {
					game_situation = 0;
					game_over();
					break;
				}
			}


			if (SCORE == LEVEL) {
				SPEED -= 1;
				LEVEL += 100;
				_LEVEL_ += 1;
			}

			if (life == 0) {
				game_situation = 0;
				break;
			}
			if (SPEED == 0) {
				game_situation = 0;
				game_clear();
				break;
			}
			cnt++;
			Sleep(10);
		}
		cnt = 0;
		j = 1;
		if (game_situation == 0) {
			break;
		}
	}
	life = 5;
	SCORE = 0;
	_LEVEL_ = 1;
	SPEED = 50;
	LEVEL = 500;
	game_situation = 1;
}

void Game::game_play_table() {
	int i;
	for (i = 1; i < X_MAX - 1; i++) {
		gotoxy(i, 0);
		cout << "─";
	}
	gotoxy(i + 1, 0);
	cout << "┐";
	for (i = 1; i < Y_MAX; i++) {
		gotoxy(X_MAX, i);
		cout << "│";
	}
	gotoxy(X_MAX, i);
	cout << "┘";
	for (i = X_MAX - 1; i > 0; i--) {
		gotoxy(i, Y_MAX);
		cout << "─";
	}
	gotoxy(0, Y_MAX);
	cout << "└";
	for (i = Y_MAX - 1; i >= 0; i--) {
		gotoxy(0, i);
		cout << "│";
	}
	gotoxy(0, 0);
	cout << "┌";
	for (i = 1; i <= X_MAX - 1; i++) {
		gotoxy(i, Y_MAX - 2);
		cout << "━";
	}
	set_letter_color(LIGHTGREEN);
	gotoxy(WORD_INPUT_POSITION_X - 14, WORD_INPUT_POSITION_Y - 1);
	cout << "Input word : ";
	set_letter_color(WHITE);
}

void Game::game_play_intro() {
	int i;
	for (i = 1; i < X_MAX - 1; i++) {
		gotoxy(i, 0);
		cout << "─";
		Sleep(GAME_TABLE_INTRO_SPEED);
	}
	gotoxy(i + 1, 0);
	cout << "┐";
	for (i = 1; i < Y_MAX; i++) {
		gotoxy(X_MAX, i);
		cout << "│";
		Sleep(GAME_TABLE_INTRO_SPEED);
	}
	gotoxy(X_MAX, i);
	cout << "┘";
	for (i = X_MAX - 1; i > 0; i--) {
		gotoxy(i, Y_MAX);
		cout << "─";
		Sleep(GAME_TABLE_INTRO_SPEED);
	}
	gotoxy(0, Y_MAX);
	cout << "└";
	for (i = Y_MAX - 1; i >= 0; i--) {
		gotoxy(0, i);
		cout << "│";
		Sleep(GAME_TABLE_INTRO_SPEED);
	}
	gotoxy(0, 0);
	cout << "┌";
}

void Game::CREATER_intro()
{
	int i;
	setcursortype(NOCURSOR);
	//string print0 = "C Language Manager";

	string print1 = "H a n b a t   U n i v e r s i t y";
	string print2 = "C + +  P r o g r a m m i n g";
	string print3 = "P r o j e c t";
	string print4 = "L e e  S a n g  M i n ★";
	string print5 = "K a n g  S u k  h y u n ★";
	string print6 = "K i m  K y u n g  A h ★";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	for (i = 0; i < print1.length(); i++) {
		gotoxy(CREATER_X + i, CREATER_Y);
		cout << print1[i];
		Sleep(15);
	}
	for (i = 0; i < print2.length(); i++) {
		gotoxy(CREATER_X + i, CREATER_Y + 2);
		cout << print2[i];
		Sleep(15);
	}
	for (i = 0; i < print3.length(); i++) {
		gotoxy(CREATER_X + i, CREATER_Y + 4);
		cout << print3[i];
		Sleep(15);
	}
	for (i = 0; i < print4.length(); i++) {
		gotoxy(CREATER_X + i + 3, CREATER_Y + 8);
		cout << print4[i];
		Sleep(15);
	}
	for (i = 0; i < print5.length(); i++) {
		gotoxy(CREATER_X + i + 3, CREATER_Y + 10);
		cout << print5[i];
		Sleep(15);
	}
	for (i = 0; i < print6.length(); i++) {
		gotoxy(CREATER_X + i + 3, CREATER_Y + 12);
		cout << print6[i];
		Sleep(15);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}

void Game::game_score_table() {
	int i;
	for (i = X_MAX + 1; i < SCORE_TABLE_X - 1; i++) {
		gotoxy(i, 0);
		cout << "─";
	}
	gotoxy(i + 1, 0);
	cout << "┐";
	for (i = 1; i < SCORE_TABLE_Y; i++) {
		gotoxy(SCORE_TABLE_X, i);
		cout << "│";
	}
	gotoxy(SCORE_TABLE_X, i);
	cout << "┘";
	for (i = SCORE_TABLE_X - 1; i > X_MAX; i--) {
		gotoxy(i, SCORE_TABLE_Y);
		cout << "─";
	}
	gotoxy(0, SCORE_TABLE_Y);
	cout << "└";
	for (i = SCORE_TABLE_Y - 1; i >= 0; i--) {
		gotoxy(0, i);
		cout << "│";
	}
	gotoxy(X_MAX + 1, 0);
	cout << "─";
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y);
	cout << "게임 종료 버튼  ";
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 1);
	cout << ": ESC";
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 5);
	cout << "생명  ";
	set_letter_color(LIGHTRED);
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 6);
	cout << LIFE_5;
	set_letter_color(WHITE);
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 10);
	cout << "점수  ";
	set_letter_color(LIGHTCYAN);
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 11);
	cout << SCORE;
	set_letter_color(WHITE);
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 13);
	cout << "단계 ";
	gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 14);
	cout << _LEVEL_;

}

void Game::game_score(int state) {
	int i;
	if (state == FALSE) {
		SCORE -= 100;
		for (i = 0; i <= 15; i++) {
			gotoxy(SCORE_PRINT_X + i, SCORE_PRINT_Y + 11);
			cout << ' ';
		}
		set_letter_color(LIGHTCYAN);
		gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 11);
		cout << SCORE;
		set_letter_color(WHITE);
	}
	else if (state == TRUE) {
		SCORE += 100;
		for (i = 0; i <= 15; i++) {
			gotoxy(SCORE_PRINT_X + i, SCORE_PRINT_Y + 11);
			cout << ' ';
		}
		set_letter_color(LIGHTCYAN);
		gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 11);
		cout << SCORE;
		set_letter_color(WHITE);
		for (i = 0; i <= 15; i++) {
			gotoxy(SCORE_PRINT_X + i, SCORE_PRINT_Y + 14);
			cout << ' ';
		}
		gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 14);
		cout << _LEVEL_;
	}
	else if (state == DROP) {
		if (life == 5) {
			life -= 1;
			for (i = 0; i <= 15; i++) {
				gotoxy(SCORE_PRINT_X + i, SCORE_PRINT_Y + 6);
				cout << ' ';
			}
			set_letter_color(LIGHTRED);
			gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 6);
			cout << LIFE_4;
			set_letter_color(WHITE);
		}
		else if (life == 4) {
			life -= 1;
			for (i = 0; i <= 15; i++) {
				gotoxy(SCORE_PRINT_X + i, SCORE_PRINT_Y + 6);
				cout << ' ';
			}
			set_letter_color(LIGHTRED);
			gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 6);
			cout << LIFE_3;
			set_letter_color(WHITE);
		}
		else if (life == 3) {
			life -= 1;
			for (i = 0; i <= 15; i++) {
				gotoxy(SCORE_PRINT_X + i, SCORE_PRINT_Y + 6);
				cout << ' ';
			}
			set_letter_color(LIGHTRED);
			gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 6);
			cout << LIFE_2;
			set_letter_color(WHITE);
		}
		else if (life == 2) {
			life -= 1;
			for (i = 0; i <= 15; i++) {
				gotoxy(SCORE_PRINT_X + i, SCORE_PRINT_Y + 6);
				cout << ' ';
			}
			set_letter_color(LIGHTRED);
			gotoxy(SCORE_PRINT_X, SCORE_PRINT_Y + 6);
			cout << LIFE_1;
			set_letter_color(WHITE);
		}
		else if (life == 1) {
			game_over();
			game_situation = 0;
		}
	}
}

void TypingPractice::tp_table_out() {										// 타자 입력판 외부 테두리
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	for (int i = 1; i < TP_TABLE_Y; i++)
	{
		gotoxy(0, i);
		cout << "┃";
		gotoxy(TP_TABLE_X, i);
		cout << "┃";
	}
	gotoxy(0, TP_TABLE_Y);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

void TypingPractice::tp_table_in() {										// 타자 입력판 내부 테두리
	gotoxy(1, 1);
	cout << "┌───────────────────────────────*[연습할텍스트]*─────────────────────────────┐";
	for (int i = 2; i < TP_TABLE_Y - 1; i++)
	{
		gotoxy(1, i);
		cout << "│";
		gotoxy(TP_TABLE_X - 40, i);
		cout << "│";
	}
	gotoxy(1, TP_TABLE_Y - 1);
	cout << "└────────────────────────────────────────────────────────────────────────────┘";

	gotoxy(TP_TABLE_X - 39, 1);
	cout << "┌─────────────*[타자결과]*────────────┐";
	for (int i = 2; i < TP_TABLE_Y - 1; i++)
	{
		gotoxy(TP_TABLE_X - 39, i);
		cout << "│";
		gotoxy(TP_TABLE_X - 1, i);
		cout << "│";
	}
	gotoxy(TP_TABLE_X - 39, TP_TABLE_Y - 1);
	cout << "└─────────────────────────────────────┘";

	gotoxy(TP_TABLE_X - 33, 5);
	cout << "▶정확도 : ";
	gotoxy(TP_TABLE_X - 33, 12);
	cout << "▶소요시간 : ";
	gotoxy(TP_TABLE_X - 33, 19);
	cout << "▶타수  : ";
}

void TypingPractice::print_text(int j) {								// 연습할 텍스트 출력하기
	int i = 0;
	for (i = 0; i < 8; i++) {
		gotoxy(TP_PRACTICE_START_X, TP_PRACTICE_START_Y + i * 3);
		cout << load_txt[j] << endl;
		j++;
	}gotoxy(2, 3);
}

void TypingPractice::print_space() {											// 화면 지우기.
	int i = 0, j = 0;
	for (i = 0; i < WORD_INPUT_POSITION_Y - 3; i++) {
		gotoxy(TP_PRACTICE_START_X, TP_PRACTICE_START_Y + i);
		cout << "                                                                            " << endl;
		j++;
	}
}

void TypingPractice::tp_progress() {											// 타자 연습 진행

	this->tp_file_upload(this);
	print_text(line);
	while (line != line_max) {													// 입력한 라인 수가 라인 최대가 아닐때까지
		ch = _getch();
		if (ch >= 32 && ch <= 126) {											// 키보드 문자부분 입력 시
			input_word += char(ch);
			gotoxy(x, y);
			if (input_word.length() > load_txt[line].length()) {				// 입력한 문장이 더 길어질 시 
				input_word.pop_back();
				gotoxy(x + input_word.length(), y);
			}
			else
			{
				cout << input_word;
			}
		}
		else if (ch == 8) {														// BackSpace 입력 시
			if (input_word.length() != 0) {
				input_word.pop_back();
				gotoxy(x + input_word.length(), y);
				cout << " ";
			}
		}
		else if (ch == 9) {														// Tab 입력 시
			input_word += "    ";
			cout << "    ";
		}
		else if (ch == 13) {													// Enter 입력 시
			float time = (float)(clock() - start) / CLOCKS_PER_SEC;				// 현재까지 경과 시간 구하는 부분
			if (load_txt[line] == input_word) {									// 입력값과 불러온 문장이 맞을 시
				set_letter_color(LIGHTGREEN);
				cout << "  맞았습니다.";
				cnt += input_word.length();
				line++;
			}
			else if (load_txt[line] != input_word) {							// 입력값과 불러온 문장이 다를 시
				set_letter_color(LIGHTRED);
				cout << "  틀렸습니다.";
				gotoxy(x, y + 1);
				for (int i = 0; i < input_word.length(); i++) {
					if (load_txt[line][i] == input_word[i]) {
						cout << " ";
						cnt++;
					}
					else {
						cout << "^";
					}
				}
				line++;
			}
			if (line % 8 == 0) {												// 한 화면에 8줄이 출력되기 때문에 입력한 라인이 8 이상이면 
				set_letter_color(WHITE);										// 화면을 지우고 다음 화면을 출력한다.
				print_space();
				print_text(line);
				y = 0;
			}
			else if (line == this->line_max) {									//입력한 라인과 라인 최대값과 같아지면 클리어 화면 출력.
				tp_clear();
			}

			sum_size += load_txt[line - 1].length();
			cout << get_acc(cnt, sum_size, line) << " %";				// 정확도 출력.
			cout << usage_time(start) << " 초";							// 소요시간 출력.
			SCORE = get_WPM(start, cnt, sum_size, line);
			cout << SCORE << " 타";										// 타수 출력.
			gotoxy(x, y += 3);
			input_word.clear();
			set_letter_color(WHITE);
		}
		else if (ch == 27) {
			game_situation = 0;
			tp_clear();
			break;
		}
	}
	line = 0;
	WPM = 0;
	cnt = 0.0;
	x = 2;
	y = 3;
}

void TypingPractice::tp_input_filename() {								// 파일 선택 함수
	int n;

	while (1) {
		set_letter_color(LIGHTGREEN);
		gotoxy(POSITION_GAME_MENU_X - 8, POSITION_GAME_MENU_Y);
		cout << ("연습하실 파일 번호를 선택해주세요");
		gotoxy(POSITION_GAME_MENU_X - 13, POSITION_GAME_MENU_Y + 1);
		cout << ("( 1. 쉬운 코드 , 2. 보통 코드 , 3. 어려운 코드 )");
		gotoxy(POSITION_GAME_MENU_X - 5, POSITION_GAME_MENU_Y + 3);
		n = _getch();
		set_letter_color(WHITE);
		if (n == 49) {
			this->file = "1.txt";
			break;
		}
		else if (n == 50) {
			this->file = "2.txt";
			break;
		}
		else if (n == 51) {
			this->file = "3.txt";
			break;
		}
		else if (n == 27) {
			this->progress_situation = 0;
			break;
		}
		else {
			continue;
		}
	}
	system("cls");
}

void TypingPractice::tp_file_upload(TypingPractice *TYP)				// 텍스트 파일 읽어들이는 함수
{
	ifstream fin(TYP->file);
	string line;
	int i = 0;

	if (!fin) {
		cout << TYP->file << "파일을 열 수 없습니다." << endl;
		return;
	}
	while (true) {
		getline(fin, line);
		if (line[0] != '\n' && line != "") {
			load_txt[i] = line;
			i++;
		}
		if (fin.eof()) break;
	}
	TYP->line_max = i;
	fin.close();
}

double TypingPractice::get_acc(double cnt, int size, int line)	//정확도 계산, 단위는 %
{
	gotoxy(TP_TABLE_X - 22, 5);
	return (((cnt / size) * 100.0));

}

int TypingPractice::get_WPM(float start, double cnt, int size, int line) {	// 타자수 계산

	double n = usage_time(start) / 60.0; //시작시간을 이용 1분 단위로 계산
	this->WPM = ((double)size / n)*(get_acc(cnt, size, line) / 100.0); //타자수 계산 공식
	gotoxy(TP_TABLE_X - 22, 19);
	cout << "                  ";
	gotoxy(TP_TABLE_X - 22, 19);
	return WPM;
}

void TypingPractice::tp_menu()
{
	int menu;

	while (1)
	{
		this->tp_input_filename();
		if (this->progress_situation == 0) {
			break;
		}
		this->tp_table_out();
		this->tp_table_in();
		this->tp_progress();
		system("cls");
	}
	VIEW_02 view2;
	this->progress_situation = 1;
}

int GetKey()
{
	int ch = _getch();
	if (ch == 0 || ch == 0xE0) ch = _getch();

	return ch;
}

//저작권텍스트
void CopyRight(void)
{
	gotoxy(2, 28);
	cout << "Copyright 2018 KimKyoungA.LeeSanMing,KangSuckHyeon all rights reserved.";
}

//바깥라인
void outline_out() {
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	for (int i = 1; i < 26; i++)
	{
		gotoxy(0, i);
		cout << "┃";
		gotoxy(118, i);
		cout << "┃";
	}
	gotoxy(0, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}

void check_key(void) {
	int key = 0; //키값 초기화  
	if (_kbhit())
	{ //키입력이 있는 경우  
		key = _getch(); //키값을 받음
		if (key == 224) { //방향키인경우 
			do { key = _getch(); } while (key == 224);//방향키지시값을 버림 
			switch (key) {
			case DOWN: //아래쪽 방향키 눌렀을때-위와 동일하게 처리됨 
				setFontColor(15);
				//Text_01_TYPING_S();
				setFontColor(11);
				//Text_02_GAME_CH();
			}
		}
	}
	while (_kbhit()) _getch();	//버퍼에 있는 값 버리기
}

void PLUS_FIRST_S(void)
{
	//상단부
	int y = 1;
	setFontColor(3);
	gotoxy(20, y); cout << "■■";
	gotoxy(20, y + 1); cout << "■■";
	gotoxy(16, y + 2); cout << "■■■■■■";
	gotoxy(16, y + 3); cout << "■■■■■■";
	gotoxy(20, y + 4); cout << "■■";
	gotoxy(20, y + 5); cout << "■■";

	y = 5;
	setFontColor(11);
	gotoxy(8, y); cout << "■■";
	gotoxy(8, y + 1); cout << "■■";
	gotoxy(4, y + 2); cout << "■■■■■■";
	gotoxy(4, y + 3); cout << "■■■■■■";
	gotoxy(8, y + 4); cout << "■■";
	gotoxy(8, y + 5); cout << "■■";


	//하단부
	y = 20;
	setFontColor(3);
	gotoxy(96, y); cout << "■■";
	gotoxy(96, y + 1); cout << "■■";
	gotoxy(92, y + 2); cout << "■■■■■■";
	gotoxy(92, y + 3); cout << "■■■■■■";
	gotoxy(96, y + 4); cout << "■■";
	gotoxy(96, y + 5); cout << "■■";

	y = 16;
	setFontColor(11);
	gotoxy(108, y); cout << "■■";
	gotoxy(108, y + 1); cout << "■■";
	gotoxy(104, y + 2); cout << "■■■■■■";
	gotoxy(104, y + 3); cout << "■■■■■■";
	gotoxy(108, y + 4); cout << "■■";
	gotoxy(108, y + 5); cout << "■■";
}
void PLUS_SECOND_S(void)
{
	//상단부
	int y = 1;
	setFontColor(11);
	gotoxy(20, y); cout << "■■";
	gotoxy(20, y + 1); cout << "■■";
	gotoxy(16, y + 2); cout << "■■■■■■";
	gotoxy(16, y + 3); cout << "■■■■■■";
	gotoxy(20, y + 4); cout << "■■";
	gotoxy(20, y + 5); cout << "■■";

	y = 5;
	setFontColor(3);
	gotoxy(8, y); cout << "■■";
	gotoxy(8, y + 1); cout << "■■";
	gotoxy(4, y + 2); cout << "■■■■■■";
	gotoxy(4, y + 3); cout << "■■■■■■";
	gotoxy(8, y + 4); cout << "■■";
	gotoxy(8, y + 5); cout << "■■";

	//하단부
	y = 20;
	setFontColor(11);
	gotoxy(96, y); cout << "■■";
	gotoxy(96, y + 1); cout << "■■";
	gotoxy(92, y + 2); cout << "■■■■■■";
	gotoxy(92, y + 3); cout << "■■■■■■";
	gotoxy(96, y + 4); cout << "■■";
	gotoxy(96, y + 5); cout << "■■";

	y = 16;
	setFontColor(3);
	gotoxy(108, y); cout << "■■";
	gotoxy(108, y + 1); cout << "■■";
	gotoxy(104, y + 2); cout << "■■■■■■";
	gotoxy(104, y + 3); cout << "■■■■■■";
	gotoxy(108, y + 4); cout << "■■";
	gotoxy(108, y + 5); cout << "■■";
}
void VIEW_02::PLUS_TURN_UP_S(void)
{
	int cnt;
	for (cnt = 0;; cnt++) { //cnt를 1씩 증가시키면서 계속 반복__반짝이는 애니메이션효과 
		if (_kbhit()) break; //키입력이 있으면 무한루프 종료 
		if (cnt % 200 == 0) { PLUS_FIRST_S(); }//cnt가 200으로 나누어 떨어질때 첫번째
		if ((cnt % 200 - 100) == 0) { PLUS_SECOND_S(); }
		//위 카운트에서 100카운트 간격으로 두번째로 +로 바뀜
		Sleep(8); // 00.1초 딜레이  
	}
}

void VIEW_02::DrawMenuText(int selectedNum)
{
	dy = (selectedNum - 1) * 2; //이동할꺼. 만약 한번 입력하면 번 배열값,
								//2가 되면 2번째 배열, 3이 되면 4번 배열
								// dy는 글자가 한 줄씩 공백을 두었기에 방향키 한 번에 다음 위치로 이동 시키기 위한 변수  
								//메뉴텍스트 글자가 써있는건 0,2,4,6 의 짝수 번호.

	string MenuText[7] = { ("영 문  타 자 연 습"),(" "),("C + +  타 자 게 임"),(" "),("C + +  문 제 풀 기"),(" "),("종   료    하   기") };
	setFontColor(0);//밑에부터 앞의 화살표 다 없앤다.
	if (dy == 2 || dy == 4) {
		gotoxy(49, 11 + dy - 2);
		cout << "▶";
		gotoxy(49, 11 + dy + 2);
		cout << "▶";
	}
	else if (dy == 6) {
		gotoxy(49, 11 + dy - 2);
		cout << "▶";
		gotoxy(49, 11 + dy - 6);
		cout << "▶";
	}
	else if (dy == 0) {
		gotoxy(49, 11 + dy + 2);
		cout << "▶";
		gotoxy(49, 11 + dy + 6);
		cout << "▶";
	}

	setFontColor(15);
	for (int i = 0; i < 7; i++) {
		gotoxy(52, 11 + i);
		cout << MenuText[i];
	}
	//먼저 다 흰색으로 출력하고나서 
	// 메뉴수가 많지 않기에 전체를 다시 그려 이전 선택된 걸 복원한다. 

	// 새롭게 선택된 메뉴를 하이라이트 시킨다. 
	gotoxy(52, 11 + dy);	//그 선택된 배열로 가서 
	setFontColor(11);		//폰트 색깔 바꾸고 다시출력
	cout << MenuText[dy];
	gotoxy(49, 11 + dy);
	// 선택된 메뉴에만 이 문양이 들어가기 때문에 별도로 그려줘야 한다. 
	cout << "▶";
	setFontColor(15);		//다시 흰색으로 돌려놓음.
}

void VIEW_02::GetCommand(int max, int &selectedNum)
{
	int ch;
	TypingPractice TYP;
	Game GAME;


	while (1)
	{
		ch = GetKey();
		switch (ch)
		{
		case UP:
			if (selectedNum >= 2) {
				--selectedNum;
				DrawMenuText(selectedNum);
			}
			break;

		case DOWN:
			if (selectedNum <= 3) {
				++selectedNum;
				DrawMenuText(selectedNum);
			}
			break;
		case ENTER:
			if (selectedNum == 1) { // 타자 연습
				system("cls");
				setcursortype(NORMALCURSOR);
				TYP.tp_menu();
				selectedNum = 1;
				setcursortype(NOCURSOR);
			}
			else if (selectedNum == 2) {	// 타자 게임
				system("cls");
				GAME.game_menu();
				selectedNum = 1;
			}
			else if (selectedNum == 3) { // 타자 문제 풀기
				POP pop;
				char num;
				
				num = pop.pop_choose();
				
				if (num == -1) {
					system("cls");
					VIEW_02 view;
				}
				else if (num == 7)
				{
					CHAP07 chap07;
				}
				else if (num == 8)
					CHAP08 chap08;
				else if (num == 9)
					CHAP09 chap09;
				else if (num == 10)
					CHAP10 chap10;
				else if (num == 12)
					CHAP12 chap12;
				Sleep(3000);
				system("cls");
				VIEW_02 view;
			}
			else if (selectedNum == 4) {	// 게임 종료
				system("cls");
				exit(0);
				return;
			}
			break;
		}
		setcursortype(NOCURSOR);
	}

}

void VIEW_01::TITLE_DARK(void) {
	int x = 2; //타이틀화면이 표시되는 x좌표 
	int y = 2; //타이틀화면이 표시되는 y좌표 

			   //한 y값 기준으로 감. 
			   //노란색 부분
	setFontColor(BROWN);
	gotoxy(31, y + 0); cout << "■■■";
	gotoxy(23, y + 1); cout << "■■■■■■■";
	gotoxy(17, y + 2); cout << "■■■■■■■■■■";
	gotoxy(15, y + 3); cout << "■■■■■■■■■■■■";
	gotoxy(15, y + 4); cout << "■■■■■■■■■■■■";
	gotoxy(17, y + 5); cout << "■■■■■■■■";
	gotoxy(17, y + 6); cout << "■■■■■■";
	gotoxy(17, y + 7); cout << "■■";

	//빨간색 부분
	setFontColor(RED);
	gotoxy(9, y + 3); cout << "■■■";
	gotoxy(5, y + 4); cout << "■■■■■";
	gotoxy(5, y + 5); cout << "■■■■■■";
	gotoxy(5, y + 6); cout << "■■■■■■";
	gotoxy(7, y + 7); cout << "■■■■■";
	gotoxy(7, y + 8); cout << "■■■■■■";
	gotoxy(7, y + 9); cout << "■■■■■■";
	gotoxy(9, y + 10); cout << "■■■■■";
	gotoxy(9, y + 11); cout << "■■■■■■";
	gotoxy(9, y + 12); cout << "■■■■■■";
	gotoxy(9, y + 13); cout << "■■■■■■";
	gotoxy(11, y + 14); cout << "■■■";

	//파란색 부분
	setFontColor(BLUE);
	gotoxy(37, y + 10); cout << "■■";
	gotoxy(33, y + 11); cout << "■■■■";
	gotoxy(27, y + 12); cout << "■■■■■■■■";
	gotoxy(21, y + 13); cout << "■■■■■■■■■■■";
	gotoxy(17, y + 14); cout << "■■■■■■■■■■■■■";
	gotoxy(11, y + 15); cout << "■■■■■■■■■■■■■■■■";
	gotoxy(11, y + 16); cout << "■■■■■■■■■■■■■";
	gotoxy(13, y + 17); cout << "■■■■■■■■■";
	gotoxy(13, y + 18); cout << "■■■■■■";
	gotoxy(13, y + 19); cout << "■■■■";

	//플러스로 될 부분
	setFontColor(CYAN);
	gotoxy(33, y + 5); cout << "■■■";
	gotoxy(29, y + 6); cout << "■■■■■";
	gotoxy(29, y + 7); cout << "■■■■■";
	gotoxy(29, y + 8); cout << "■■■■■■";
	gotoxy(31, y + 9); cout << "■■■■■";
	gotoxy(31, y + 10); cout << "■■■■■";
	gotoxy(31, y + 11); cout << "■■■■■";
	gotoxy(31, y + 12); cout << "■■■■■■";
	gotoxy(33, y + 13); cout << "■■■■■";
	gotoxy(33, y + 14); cout << "■■■■■";
	gotoxy(33, y + 15); cout << "■■■■■";
	gotoxy(33, y + 16); cout << "■■";
}
//한밭대로고 밝아지며 나타나는 함수
void VIEW_01::TITLE_LIGHT(void)
{
	int x = 2; //타이틀화면이 표시되는 x좌표 
	int y = 2; //타이틀화면이 표시되는 y좌표 

			   //한 y값 기준으로 감. 위->아래로 밝아짐
	Sleep(100);
	{gotoxy(31, y + 0);	setFontColor(YELLOW); cout << "■■■";	Sleep(200); }
	{gotoxy(23, y + 1);	 cout << "■■■■■■■";	Sleep(190); }
	{gotoxy(17, y + 2); cout << "■■■■■■■■■■";	Sleep(180); }
	{gotoxy(15, y + 3); cout << "■■■■■■■■■■■■";
	setFontColor(LIGHTRED); gotoxy(9, y + 3); cout << "■■■";	Sleep(170); }

	{setFontColor(YELLOW); gotoxy(15, y + 4); cout << "■■■■■■■■■■■■";
	setFontColor(LIGHTRED); gotoxy(5, y + 4); cout << "■■■■■";	Sleep(160); }

	{setFontColor(YELLOW); gotoxy(17, y + 5); cout << "■■■■■■■■";
	setFontColor(LIGHTRED); gotoxy(5, y + 5); cout << "■■■■■■";
	setFontColor(BLACK);	gotoxy(33, y + 5); cout << "■■■"; Sleep(175); }

	{setFontColor(YELLOW); gotoxy(17, y + 6); cout << "■■■■■■";
	setFontColor(LIGHTRED); gotoxy(5, y + 6); cout << "■■■■■■";
	setFontColor(BLACK); gotoxy(29, y + 6); cout << "■■■■■";	Sleep(170); }

	{setFontColor(YELLOW); gotoxy(17, y + 7); cout << "■■";
	setFontColor(LIGHTRED); gotoxy(7, y + 7); cout << "■■■■■";
	setFontColor(BLACK); gotoxy(29, y + 7); cout << "■■■■■"; Sleep(150); }

	{setFontColor(LIGHTRED); gotoxy(7, y + 8); cout << "■■■■■■";
	setFontColor(BLACK);	gotoxy(29, y + 8); cout << "■■■■■■";	Sleep(140); }

	{setFontColor(LIGHTRED); gotoxy(7, y + 9); cout << "■■■■■■";
	setFontColor(BLACK); gotoxy(31, y + 9); cout << "■■■■■"; Sleep(130); }

	{setFontColor(LIGHTRED); gotoxy(9, y + 10); cout << "■■■■■";
	setFontColor(BLACK); gotoxy(31, y + 10); cout << "■■■";
	setFontColor(LIGHTBLUE); gotoxy(37, y + 10); cout << "■■"; Sleep(120); }

	{setFontColor(LIGHTRED); gotoxy(9, y + 11); cout << "■■■■■■";
	setFontColor(BLACK); gotoxy(31, y + 11); cout << "■";
	setFontColor(LIGHTBLUE); gotoxy(33, y + 11); cout << "■■■■"; Sleep(110); }

	{setFontColor(LIGHTRED); gotoxy(9, y + 12); cout << "■■■■■■";
	setFontColor(LIGHTBLUE); gotoxy(27, y + 12); cout << "■■■■■■■■"; Sleep(100); }

	{setFontColor(LIGHTRED); gotoxy(9, y + 13); cout << "■■■■■■";
	setFontColor(LIGHTBLUE); gotoxy(21, y + 13); cout << "■■■■■■■■■■■"; Sleep(90); }

	{setFontColor(LIGHTRED); gotoxy(11, y + 14); cout << "■■■";
	setFontColor(LIGHTBLUE); gotoxy(17, y + 14); cout << "■■■■■■■■■■■■■"; Sleep(80); }

	gotoxy(11, y + 15); cout << "■■■■■■■■■■■■■■■■"; Sleep(70);
	gotoxy(11, y + 16); cout << "■■■■■■■■■■■■■";	Sleep(60);
	gotoxy(13, y + 17); cout << "■■■■■■■■■";	Sleep(50);
	gotoxy(13, y + 18); cout << "■■■■■■";	Sleep(40);
	gotoxy(13, y + 19); cout << "■■■■";	Sleep(30);
}

//PLUS나타나기함수
void VIEW_01::PLUS(void)
{
	int y = 1;
	setFontColor(CYAN);
	gotoxy(53, y); cout << "■■■"; Sleep(50);
	gotoxy(53, y + 1); cout << "■■■"; Sleep(50);
	gotoxy(53, y + 2); cout << "■■■"; Sleep(50);
	gotoxy(47, y + 3); cout << "■■■■■■■■■"; Sleep(50);
	gotoxy(47, y + 4); cout << "■■■■■■■■■"; Sleep(50);
	gotoxy(47, y + 5); cout << "■■■■■■■■■"; Sleep(50);
	gotoxy(53, y + 6); cout << "■■■"; Sleep(50);
	gotoxy(53, y + 7); cout << "■■■"; Sleep(50);
	gotoxy(53, y + 8); cout << "■■■"; Sleep(50);

	y = 6;
	setFontColor(LIGHTCYAN);
	gotoxy(71, y); cout << "■■■"; Sleep(50);
	gotoxy(71, y + 1); cout << "■■■"; Sleep(50);
	gotoxy(71, y + 2); cout << "■■■"; Sleep(50);
	gotoxy(65, y + 3); cout << "■■■■■■■■■"; Sleep(50);
	gotoxy(65, y + 4); cout << "■■■■■■■■■"; Sleep(50);
	gotoxy(65, y + 5); cout << "■■■■■■■■■"; Sleep(50);
	gotoxy(71, y + 6); cout << "■■■"; Sleep(50);
	gotoxy(71, y + 7); cout << "■■■"; Sleep(50);
	gotoxy(71, y + 8); cout << "■■■";
}
//PLUS반짝이기_첫번째
void VIEW_01::PLUS_FIRST(void)
{
	int y = 1;
	setFontColor(CYAN);
	gotoxy(53, y); cout << "■■■";
	gotoxy(53, y + 1); cout << "■■■";
	gotoxy(53, y + 2); cout << "■■■";
	gotoxy(47, y + 3); cout << "■■■■■■■■■";
	gotoxy(47, y + 4); cout << "■■■■■■■■■";
	gotoxy(47, y + 5); cout << "■■■■■■■■■";
	gotoxy(53, y + 6); cout << "■■■";
	gotoxy(53, y + 7); cout << "■■■";
	gotoxy(53, y + 8); cout << "■■■";

	y = 6;
	setFontColor(LIGHTCYAN);
	gotoxy(71, y); cout << "■■■";
	gotoxy(71, y + 1); cout << "■■■";
	gotoxy(71, y + 2); cout << "■■■";
	gotoxy(65, y + 3); cout << "■■■■■■■■■";
	gotoxy(65, y + 4); cout << "■■■■■■■■■";
	gotoxy(65, y + 5); cout << "■■■■■■■■■";
	gotoxy(71, y + 6); cout << "■■■";
	gotoxy(71, y + 7); cout << "■■■";
	gotoxy(71, y + 8); cout << "■■■";

	gotoxy(63, 20);
	setFontColor(15);
	cout << "프로그램을 시작하려면 아무키나 누르시오 . . ." << endl;
}
//PLUS반짝이기_두번째
void VIEW_01::PLUS_SECOND(void)
{
	int y = 1;
	setFontColor(LIGHTCYAN);
	gotoxy(53, y); cout << "■■■";
	gotoxy(53, y + 1); cout << "■■■";
	gotoxy(53, y + 2); cout << "■■■";
	gotoxy(47, y + 3); cout << "■■■■■■■■■";
	gotoxy(47, y + 4); cout << "■■■■■■■■■";
	gotoxy(47, y + 5); cout << "■■■■■■■■■";
	gotoxy(53, y + 6); cout << "■■■";
	gotoxy(53, y + 7); cout << "■■■";
	gotoxy(53, y + 8); cout << "■■■";

	y = 6;
	setFontColor(CYAN);
	gotoxy(71, y); cout << "■■■";
	gotoxy(71, y + 1); cout << "■■■";
	gotoxy(71, y + 2); cout << "■■■";
	gotoxy(65, y + 3); cout << "■■■■■■■■■";
	gotoxy(65, y + 4); cout << "■■■■■■■■■";
	gotoxy(65, y + 5); cout << "■■■■■■■■■";
	gotoxy(71, y + 6); cout << "■■■";
	gotoxy(71, y + 7); cout << "■■■";
	gotoxy(71, y + 8); cout << "■■■";

	gotoxy(63, 20);
	setFontColor(BLACK);
	cout << "프로그램을 시작하려면 아무키나 누르시오 . . ." << endl;
}

//PLUS반짝반짝 계속
void VIEW_01::PLUS_TURN_UP(void)
{
	int cnt;
	for (cnt = 0;; cnt++) { //cnt를 1씩 증가시키면서 계속 반복__반짝이는 애니메이션효과 
		if (_kbhit()) { break; } //키입력이 있으면 무한루프 종료 
		if (cnt % 200 == 0) { PLUS_FIRST(); }//cnt가 200으로 나누어 떨어질때 첫번째
		if ((cnt % 200 - 100) == 0) { PLUS_SECOND(); }
		//위 카운트에서 100카운트 간격으로 두번째로 +로 바뀜
		Sleep(10); // 00.1초 딜레이  
	}
	while (_kbhit()) _getch(); //버퍼에 기록된 키값을 버림 
	system("cls");
}

void VIEW_02::Text_MENU()
{
	setFontColor(15);
	gotoxy(29, 3); cout << "▨▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▧";
	gotoxy(29, 23); cout << "▧▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▨";
	for (int i = 0; i <= 18; i++)
	{
		gotoxy(29, 4 + i); cout << "▥";
		gotoxy(89, 4 + i); cout << "▥";
	}
	gotoxy(54, 3); 	//흰색폰트
	cout << "≪ 메  뉴 ≫";
	gotoxy(39, 6); setFontColor(8);		//회색폰트
	cout << "※ [↓] [↑] 위 아래 방향키로 이동하시오";
}

// Quiz 구현부

void Quiz_Base::outline_out() {
	setFontColor(3);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	for (int i = 1; i < 26; i++)
	{
		gotoxy(0, i);
		cout << "┃";
		gotoxy(118, i);
		cout << "┃";
	}
	gotoxy(0, 26);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void Quiz_Base::Quiz_outline()
{
	//문제 출력 칸
	setFontColor(15);
	gotoxy(2, 2);
	cout << "／￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣*[  문  제  ]*￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣＼";
	for (int i = 3; i < 18; i++)
	{
		gotoxy(2, i);
		cout << "｜";
		gotoxy(114, i);
		cout << "｜";
	}
	gotoxy(2, 18);
	cout << "＼＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿／";


	//정답 출력 칸
	gotoxy(38, 22);
	setFontColor(3);
	cout << "정답을 입력하시오 ▶";
	setFontColor(11);
	gotoxy(62, 20);
	cout << "┌─────────────────┐";
	for (int i = 21; i < 24; i++)
	{
		gotoxy(62, i);
		cout << "│";
		gotoxy(80, i);
		cout << "│";
	}
	gotoxy(62, 24);
	cout << "└─────────────────┘";
}

int Quiz_Base::Quiz_ans_num()
{
	setFontColor(14);
	int ans;
	gotoxy(72, 22);
	cin >> ans;
	return ans;
}

string Quiz_Base::Quiz_ans_string()
{
	setFontColor(14);
	string ans;
	gotoxy(69, 22);
	cin >> ans;
	return ans;
}
void Quiz_Base::Quiz_O() {
	setFontColor(1);
	gotoxy(3, 2);
	cout << "■■■";
	for (int i = 3; i < 6; i++)
	{
		gotoxy(1, i);
		cout << "■";
		gotoxy(9, i);
		cout << "■";
	}
	gotoxy(3, 6);
	cout << "■■■";
}

void Quiz_Base::Quiz_X() {
	setFontColor(4);
	gotoxy(2, 2);
	cout << "■";
	gotoxy(10, 2);
	cout << "■";
	gotoxy(4, 3);
	cout << "■";
	gotoxy(8, 3);
	cout << "■";

	gotoxy(6, 4);
	cout << "■";

	gotoxy(4, 5);
	cout << "■";
	gotoxy(8, 5);
	cout << "■";
	gotoxy(2, 6);
	cout << "■";
	gotoxy(10, 6);
	cout << "■";
}
void Quiz_Base::outline_pop() {
	setFontColor(11);
	gotoxy(15, 6);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	for (int i = 7; i < 20; i++)
	{
		gotoxy(15, i);
		cout << "┃                                                                                        ┃";
	}
	gotoxy(15, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void Quiz_Base::Quiz_result_text() {
	setFontColor(15);
	gotoxy(46, 13);
	cout << "3개의 문제 중 맞은 개수는 ? ";
	for (int i = 0; i < 4; i++) {
		gotoxy(76, 13);
		cout << 1;
		Sleep(130);
		gotoxy(76, 13);
		cout << 2;
		Sleep(130);
		gotoxy(76, 13);
		cout << 3;
		Sleep(130);
	}
	Sleep(200);
}

void POP::outline_pop() {
	setFontColor(11);
	gotoxy(15, 6);
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	for (int i = 7; i < 20; i++)
	{
		gotoxy(15, i);
		cout << "┃                                                                                        ┃";
	}
	gotoxy(15, 20);
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
}
void POP::pop_text() {
	setFontColor(3);
	gotoxy(19, 7);
	cout << "＋───────────────────────────────────────────────────────────────────────────────＋";
	gotoxy(19, 13);
	cout << "＋───────────────────────────────────────────────────────────────────────────────＋";
	/*for (int i = 8;i < 12;i++)
	{
	gotoxy(18, i);
	cout << "│";
	gotoxy(84, i);
	cout << "│";
	}*/
	setFontColor(15);
	gotoxy(21, 8);
	cout << "Chap07. 프렌드와 연산자 중복\tChap10. 템플릿과 표준 템플릿 라이브러리(STL)";
	gotoxy(21, 10);
	cout << "Chap08. 상속\t\t\tChap12. C++ 파일 입출력";
	gotoxy(21, 12);
	cout << "Chap09. 가상 함수와 추상 클래스";

	setFontColor(11);
	gotoxy(41, 16);
	cout << "선택할 단원을 숫자로 입력하시오 : ";
	setFontColor(11);
	gotoxy(41, 17);
	cout << "종료 : -1";
	setFontColor(WHITE);
}

int POP::pop_choose() {
	int num;
	setFontColor(14);
	gotoxy(75, 16);
	cin >> num;
	setFontColor(15);
	return num;

}



// TODO: 필요한 추가 헤더는
// 이 파일이 아닌 STDAFX.H에서 참조합니다.
