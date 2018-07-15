/* Name: phoneFunc.c ver 1.0
* Content: 전화번호 컨트롤 함수
* Implementation: YSW
*
* Last modified 2008/01/01
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

/* 함   수: void ImputphoneData(void)
 * 기   능: 전화번호 관련 데이터 입력 받아서 저장
 * 반   환: void
 *
 */
void InputPhoneData(void) {
	if (numOfData > LIST_NUM) {
		printf("데이터 입력 상한 초과!\n");
		return;
	}

	printf("이름 입력: ");
	gets(phoneList[numOfData].name);
	printf("전화번호 입력: ");
	gets(phoneList[numOfData++].phoneNum);
	printf("입력이 완료되었습니다.\n");
	getchar();
}

/* 함   수: void ShowAllData(void)
 * 기   능: 저장된 데이터 전체 출력
 * 반   환: void
 *
 */
void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		ShowPhoneInfo(phoneList[i]);
	}
	printf("출력이 완료되었습니다.\n");
	getchar();
}
/* end of file */