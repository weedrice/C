#include "d_common.h"
#include "cusInfo.h"

void ShowMenu(void) {
	system("cls");

	printf("-------- ��   �� -------\n");
	printf(" 1. �ű԰��� \n");
	printf(" 2. ���˻� \n");
	printf(" 3. ���� \n");
	printf("------------------------\n");
	printf("����> ");
}

void ShowCustomerInfo(cusInfo* pCus) {
	system("cls");

	printf("��---------------------------\n");
	printf("�� �� ID: %s \n", pCus->ID);
	printf("�� �� �̸�: %s \n", pCus->name);
	printf("�� �� ��ȭ��ȣ: %s \n", pCus->phoneNum);
	printf("��---------------------------\n");

	getchar();
}