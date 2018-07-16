/* Name: main.c ver1.1
 * Content: main 함수
 * Implementation: YJW
 *
 * Last modified 2017/07/17
 */

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, QUIT };

/* 함   수: int main(void)
 * 기   능: 사용자 선택 처리
 * 반   환: 정상 종료 시 0
 *
 */
int main(void) {
	LoadDataFromFile();

	int inputMenu = 0;

	while (1) {
		ShowMenu();
		fputs("선택하세요: ", stdout);
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu) {
		case INPUT:
			InputPhoneData();
			break;
		case SHOWALL:
			ShowAllData();
			break;
		case SEARCH:
			SearchPhoneData();
			break;
		case DELETE:
			DeletePhoneData();
			break;
		}

		if (inputMenu == QUIT) {
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}
	StoreDataToFile();
	return 0;
}

/* end of file */