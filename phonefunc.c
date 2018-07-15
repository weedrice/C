/* Name: phoneFunc.c ver 1.0
* Content: ��ȭ��ȣ ��Ʈ�� �Լ�
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

/* ��   ��: void ImputphoneData(void)
 * ��   ��: ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
 * ��   ȯ: void
 *
 */
void InputPhoneData(void) {
	if (numOfData > LIST_NUM) {
		printf("������ �Է� ���� �ʰ�!\n");
		return;
	}

	printf("�̸� �Է�: ");
	gets(phoneList[numOfData].name);
	printf("��ȭ��ȣ �Է�: ");
	gets(phoneList[numOfData++].phoneNum);
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	getchar();
}

/* ��   ��: void ShowAllData(void)
 * ��   ��: ����� ������ ��ü ���
 * ��   ȯ: void
 *
 */
void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		ShowPhoneInfo(phoneList[i]);
	}
	printf("����� �Ϸ�Ǿ����ϴ�.\n");
	getchar();
}
/* end of file */