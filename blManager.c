#include "blManager.h"
#include "d_common.h"
#include "cusInfo.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "cusInfoAccess.h"
#include "d_screenOut.h"

void RegistCustomer() {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char num[PHONE_LEN];

	while (1) {
		printf("ID �Է�: ");
		gets(ID);
		if (IsRegistID(ID)) {
			printf("�ش� ID�� ��� �߿� �ֽ��ϴ�. �ٸ� ID�� �������ּ���.\n");
			getchar();
		}
		else {
			break;
		}
	}

	printf("�̸� �Է�: ");
	gets(name);
	printf("��ȭ��ȣ �Է�: ");
	gets(num);

	AddCusInfo(ID, name, num);

	//savepoint

	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	getchar();

}

void SearchCusInfo() {
	char* ID[ID_LEN];
	printf("ã�� ID �Է�: ");
	gets(ID);
	cusInfo* temp = GetCusPtrByID(ID);
	if (temp != NULL) {
		ShowCustomerInfo(temp);
	}
	else {
		printf("ã�� ID�� �����ϴ�.\n");
		getchar();
	}

}

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

	//savepoint

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

				//savepoint

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

			//savepoint

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

	PrintOutRentAllCusInfo(name);
}

void SearchDVDByCUS() {
	char* ID[NAME_LEN];
	printf("ã�� ID �Է�: ");
	gets(ID);

	unsigned int start, end;
	printf("�뿩 �Ⱓ �Է�: ");
	scanf("%d %d", &start, &end);
	getchar();

	PrintOutCusAllRentInfo(ID, start, end);
}

void LoadData() {
	LoadCusList();
	LoadDVDList();
	LoadRentList();
}