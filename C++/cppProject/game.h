// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#ifndef GAME_H
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c);

#define X_MAX 80	// x축 최대
#define Y_MAX 28	// y축 최대
#define WORD_NUM 5	// 단어개수
#define POSITION_GAME_MENU_X 50	// 메뉴 x축
#define POSITION_GAME_MENU_Y 10		// 메뉴 y축
#define WORD_INPUT_POSITION_X 38	// 단어 입력 x축
#define WORD_INPUT_POSITION_Y 28	// 단어 입력 y축
#define CREATER_X 40				// 제작자 x축
#define CREATER_Y 5					// 제작자 y축
#define SCORE_TABLE_X 110			// 점수판 최대 x축
#define SCORE_TABLE_Y 28			// 점수판 최대 y축
#define SCORE_PRINT_X 87			// 점수판 닉네임 등 x축
#define SCORE_PRINT_Y 7				// 점수판 닉네임 등 y축
#define GAME_TABLE_INTRO_SPEED 5	// 게임 인트로 화면 출력 속도
#define TRUE 1						// 단어 일치
#define FALSE 0						// 단어 불일치
#define RED 12						// 빨간색 글자
#define WHITE 15					// 흰색 글자
#define GREEN 10					// 초록색 글자
#define BLUE 9						// 파란색 글자
#define DROP -1						// 생명이 줄어듬
#define GAME_OVER_X 50				// 게임 오버시 나오는 문자열 x축
#define GAME_OVER_Y 10				// 게임 오버시 나오는 문자열 y축

string word_num[WORD_NUM] = {		// 게임에 나올 단어들
	"int", "char" ,"double", "float", "long"
};

void gotoxy(int x, int y);
void game_menu();					// 게임 메뉴 출력
int print_game_menu();				// 게임 시작 메뉴
void game_play();					// 게임 작동
void game_play_intro();				// 게임 화면 출력
void game_play_table();				// 게임 테이블
void CREATER_intro();				// 제작자 테이블
void game_score_table();			// 게임 점수 테이블
void game_score(int state);			// 게임 점수 출력
void set_letter_color(int color);	// 글자색 변경
void game_over();					// 게임 오버
void game_clear();					// 게임 클리어

#endif // !GAME_H



// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
