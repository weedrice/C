#include "d_common.h"
#include "cusInfo.h"

void ShowMenu(void) {
	system("cls");

	printf("-------- 메   뉴 -------\n");
	printf(" 1. 신규가입 \n");
	printf(" 2. 고객검색 \n");
	printf(" 3. 종료 \n");
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