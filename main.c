/* Name: main.c ver1.0
 * Content: main �Լ�
 * Implementation: YSW
 *
 * Last modified 2008/01/01
 */

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, QUIT };

/* ��   ��: int main(void)
 * ��   ��: ����� ���� ó��
 * ��   ȯ: ���� ���� �� 0
 *
 */
int main(void) {
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
		}

		if (inputMenu == QUIT) {
			puts("�̿��� �ּż� ������~");
			break;
		}
	}
	return 0;
}

/* end of file */