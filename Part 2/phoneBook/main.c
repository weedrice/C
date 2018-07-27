/* Name: main.c ver 1.4
 * Content: main �Լ�
 * Implementation: YJW
 *
 * Last modified 2017/07/17
 */

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT };

/* ��   ��: int main(void)
 * ��   ��: ����� ���� ó��
 * ��   ȯ: ���� ���� �� 0
 *
 */
int main(void) {
	LoadDataFromFileInStruct();

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
		case CHANGE:
			ChangePhoneData();
			break;
		}

		if (inputMenu == QUIT) {
			StoreDataToFileInStruct();
			puts("�̿��� �ּż� ������~");
			break;
		}
	}

	return 0;
}

/* end of file */