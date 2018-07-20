#include "dvdManager.h"
#include "d_common.h"
#include "dvdInfoAccess.h"
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
