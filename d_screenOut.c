#include "d_common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
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
	printf(" 5. DVD �뿩 \n");
	printf(" 6. DVD �ݳ� \n");
	printf("------------------------\n");
	printf(" 7. DVD �뿩�� ��ü ��ȸ \n");
	printf(" 8. ���� \n");
	printf("------------------------\n");
	printf("����> ");
}

void ShowCustomerInfo(cusInfo* pCus) {

	printf("��---------------------------\n");
	printf("�� �� ID: %s \n", pCus->ID);
	printf("�� �� �̸�: %s \n", pCus->name);
	printf("�� �� ��ȭ��ȣ: %s \n", pCus->phoneNum);
	printf("��---------------------------\n");
}

void ShowDVDInfo(dvdInfo* pDvd) {

	printf("��---------------------------\n");
	printf("�� �� ISBN: %s \n", pDvd->ISBN);
	printf("�� �� ����: %s \n", pDvd->title);
	printf("�� �� �帣: %s \n", getGenre(pDvd->genre));
	printf("��---------------------------\n");

}

void ShowHistoryDVD(dvdRentInfo* pDvdRent, int numRentCus) {
	for (int i = 0; i < numRentCus; i++) {
		printf("�뿩��: %d\n", pDvdRent[i].rentDay);
		ShowCustomerInfo(GetCusPtrByID(pDvdRent[i].cusID));
	}
	printf("��ȸ�� �Ϸ��Ͽ����ϴ�.\n");
	getchar();
	system("cls");
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