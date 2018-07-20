#include "d_common.h"
#include "cusInfo.h"
#include "dvdInfoAccess.h"
#include "d_screenOut.h"

void ShowMenu(void) {
	system("cls");

	printf("-------- ��   �� -------\n");
	printf(" 1. �ű԰��� \n");
	printf(" 2. ���˻� \n");
	printf("------------------------\n");
	printf(" 3. DVD ��� \n");
	printf(" 4. DVD �˻� \n");
	printf("------------------------\n");
	printf(" 5. ���� \n");
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

void ShowDVDInfo(dvdInfo* pDvd) {
	system("cls");

	printf("��---------------------------\n");
	printf("�� �� ISBN: %s \n", pDvd->ISBN);
	printf("�� �� ����: %s \n", pDvd->title);
	printf("�� �� �帣: %s \n", getGenre(pDvd->genre));
	printf("��---------------------------\n");

	getchar();
}

char* getGenre(int genre) {
	switch (genre) {
	case ACTION:
		return "�׼�";
	case COMIC:
		return "�ڹ�";
	case SF:
		return "SF";
	case ROMANTIC:
		return "�θ�ƽ";
	default:
		return "��Ÿ";
	}
}