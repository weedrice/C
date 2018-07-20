#include "d_common.h"
#include "cusInfo.h"
#include "dvdInfoAccess.h"
#include "d_screenOut.h"

void ShowMenu(void) {
	system("cls");

	printf("-------- 메   뉴 -------\n");
	printf(" 1. 신규가입 \n");
	printf(" 2. 고객검색 \n");
	printf("------------------------\n");
	printf(" 3. DVD 등록 \n");
	printf(" 4. DVD 검색 \n");
	printf("------------------------\n");
	printf(" 5. 종료 \n");
	printf("------------------------\n");
	printf("선택> ");
}

void ShowCustomerInfo(cusInfo* pCus) {
	system("cls");

	printf("┌---------------------------\n");
	printf("│ ▶ ID: %s \n", pCus->ID);
	printf("│ ▶ 이름: %s \n", pCus->name);
	printf("│ ▶ 전화번호: %s \n", pCus->phoneNum);
	printf("└---------------------------\n");

	getchar();
}

void ShowDVDInfo(dvdInfo* pDvd) {
	system("cls");

	printf("┌---------------------------\n");
	printf("│ ▶ ISBN: %s \n", pDvd->ISBN);
	printf("│ ▶ 제목: %s \n", pDvd->title);
	printf("│ ▶ 장르: %s \n", getGenre(pDvd->genre));
	printf("└---------------------------\n");

	getchar();
}

char* getGenre(int genre) {
	switch (genre) {
	case ACTION:
		return "액션";
	case COMIC:
		return "코믹";
	case SF:
		return "SF";
	case ROMANTIC:
		return "로맨틱";
	default:
		return "기타";
	}
}