#include "dvdManager.h"
#include "d_common.h"
#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"
#include "d_screenOut.h"

void RegistDVD()
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	while (1) {
		printf("ISBN �Է�: ");
		gets(ISBN);
		if (IsRegistISBN(ISBN)) {
			printf("�ش� ISBN�� �̹� ��ϵǾ����ϴ�.\n");
			getchar();
		}
		else {
			break;
		}
	}

	printf("���� �Է�: ");
	gets(title);
	printf("�帣 �Է� (�׼� 1, �ڹ� 2, SF 3, �θ�ƽ 4): ");
	scanf("%d", &genre);
	getchar();

	AddDVDInfo(ISBN, title, genre);
	printf("����� �Ϸ�Ǿ����ϴ�.\n");
	getchar();
}

void SearchDVD()
{
	char* ISBN[ISBN_LEN];
	printf("ã�� ISBN �Է�: ");
	gets(ISBN);

	dvdInfo* temp;
	temp = GetDVDPtrByISBN(ISBN);

	if (temp != NULL) {
		ShowDVDInfo(temp);
	}
	else {
		printf("ã�� ISBN�� �����ϴ�.\n");
		getchar();
	}
}

void RentDVD()
{
	char* name[NAME_LEN];
	printf("�뿩 DVD ISBN �Է�: ");
	gets(name);

	if (IsRegistISBN(name)) {
		if (!IsRented(name)) {
			char* ID[ID_LEN];
			printf("�뿩 �� ID �Է�: ");
			gets(ID);
			if (IsRegistID(ID)) {
				unsigned int rentDay;
				printf("�뿩 ��¥ �Է�: ");
				scanf("%d", &rentDay);
				getchar();
				SetRented(name, ID, rentDay);

				printf("�뿩�� �Ϸ�Ǿ����ϴ�. \n");
				getchar();
			}
			else {
				printf("��ϵ� ���� �ƴմϴ�.\n");
				getchar();
			}

		}
		else {
			printf("�뿩���� DVD�Դϴ�.\n");
			getchar();
		}
	}
	else {
		printf("ã�� ISBN�� �����ϴ�.\n");
		getchar();
	}
}

void ReturnDVD() {
	char* name[NAME_LEN];
	printf("�ݳ� DVD ISBN �Է�: ");
	gets(name);

	if (IsRegistISBN(name)) {
		if (IsRented(name)) {
			SetReturned(name);
			printf("�ݳ��� �Ϸ�Ǿ����ϴ�. \n");
			getchar();
		}
		else {
			printf("�뿩���� DVD�� �ƴմϴ�.\n");
			getchar();
		}
	}
	else {
		printf("ã�� ISBN�� �����ϴ�.\n");
		getchar();
	}
}

void HistoryDVD() {
	char* name[NAME_LEN];
	printf("ã�� ISBN �Է�: ");
	gets(name);

	if (IsRegistISBN(name)) {
		dvdInfo* temp = GetDVDPtrByISBN(name);
		if (temp->numOfRentCus > 0) {
			ShowHistoryDVD(temp->rentList, temp->numOfRentCus);
		}
		else {
			printf("�뿩 ����� �����ϴ�.\n");
			getchar();
		}
	}
	else {
		printf("ã�� ISBN�� �����ϴ�.\n");
		getchar();
	}
}