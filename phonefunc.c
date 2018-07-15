/* Name: phoneFunc.c ver 1.1
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

void SearchPhoneData(void) {
	char searchName[NAME_LEN];
	printf("ã�� �̸���? ");
	gets(searchName);
	for (int i = 0; i < numOfData; i++) {
		if (strcmp(phoneList[i].name, searchName) == 0) {
			ShowPhoneInfo(phoneList[i]);
			printf("�˻��� �Ϸ�Ǿ����ϴ�.\n");
			return;
		}
	}
	printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	getchar();
}

void DeletePhoneData(void) {
	char searchName[NAME_LEN];
	printf("ã�� �̸���? ");
	gets(searchName);
	for (int i = 0; i < numOfData; i++) {
		if (strcmp(phoneList[i].name, searchName) == 0) {
			if (i == numOfData) {
				numOfData--;
				printf("������ �Ϸ�Ǿ����ϴ�.\n");
				return;
			}
			else {
				for (int j = i + 1; j <= numOfData; j++) {
					phoneList[j - 1] = phoneList[j];
				}
				numOfData--;
				printf("������ �Ϸ�Ǿ����ϴ�.\n");
				return;
			}
		}
	}
	printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	getchar();
}
/* end of file */