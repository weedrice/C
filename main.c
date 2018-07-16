/* Name: main.c ver1.1
 * Content: main �Լ�
 * Implementation: YJW
 *
 * Last modified 2017/07/17
 */

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, QUIT };

/* ��   ��: int main(void)
 * ��   ��: ����� ���� ó��
 * ��   ȯ: ���� ���� �� 0
 *
 */
int main(void) {
	LoadDataFromFile();

	int inputMenu = 0;

	while (1) {
		ShowMenu();
		fputs("�����ϼ���: ", stdout);
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
			puts("�̿��� �ּż� ������~");
			break;
		}
	}
	StoreDataToFile();
	return 0;
}

/* end of file */