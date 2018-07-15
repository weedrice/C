/* Name: screenOut.c ver 1.0
 * Content: �ܼ� ����� ���� �Լ� ����
 * Implementation: YSW
 *
 * Last modified 2008/01/01
 */

#include "common.h"
#include "phoneData.h"

/* ��   ��: void ShowMenu(void)
 * ��   ��: ������ ���� �޴� ���
 * ��   ȯ: void
 *
 */

void ShowMenu(void) {
	system("cls");	// stdlib.h

	printf("--------- ��  �� --------\n");
	printf(" 1. ��ȭ��ȣ �Է� \n");
	printf(" 2. ��ü ���� ��� \n");
	printf(" 3. ��ȭ��ȣ �˻� \n");
	printf(" 4. ��ȭ��ȣ ���� \n");
	printf(" 5. ���� \n");
	printf("-------------------------\n");
	printf("����> \n");
}

/* ��   ��: void ShowPhoneInfo(phoneData phone)
 * ��   ��: �̸��� ��ȭ��ȣ ���� ���
 * ��   ȯ: void
 *
 */
void ShowPhoneInfo(phoneData phone) {
	printf("��---------------------------\n");
	printf("�� �� �̸�: %s \n", phone.name);
	printf("�� �� ��ȭ��ȣ: %s\n", phone.phoneNum);
	printf("��---------------------------\n\n");
}

/* end of file */