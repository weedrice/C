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
		printf("ISBN 입력: ");
		gets(ISBN);
		if (IsRegistISBN(ISBN)) {
			printf("해당 ISBN은 이미 등록되었습니다.\n");
			getchar();
		}
		else {
			break;
		}
	}

	printf("제목 입력: ");
	gets(title);
	printf("장르 입력 (액션 1, 코믹 2, SF 3, 로맨틱 4): ");
	scanf("%d", &genre);
	getchar();

	AddDVDInfo(ISBN, title, genre);
	printf("등록이 완료되었습니다.\n");
	getchar();
}

void SearchDVD()
{
	char* ISBN[ISBN_LEN];
	printf("찾는 ISBN 입력: ");
	gets(ISBN);

	dvdInfo* temp;
	temp = GetDVDPtrByISBN(ISBN);

	if (temp != NULL) {
		ShowDVDInfo(temp);
	}
	else {
		printf("찾는 ISBN이 없습니다.\n");
		getchar();
	}
}

void RentDVD()
{
	char* name[NAME_LEN];
	printf("대여 DVD ISBN 입력: ");
	gets(name);

	if (IsRegistISBN(name)) {
		if (!IsRented(name)) {
			char* ID[ID_LEN];
			printf("대여 고객 ID 입력: ");
			gets(ID);
			if (IsRegistID(ID)) {
				unsigned int rentDay;
				printf("대여 날짜 입력: ");
				scanf("%d", &rentDay);
				getchar();
				SetRented(name, ID, rentDay);

				printf("대여가 완료되었습니다. \n");
				getchar();
			}
			else {
				printf("등록된 고객이 아닙니다.\n");
				getchar();
			}

		}
		else {
			printf("대여중인 DVD입니다.\n");
			getchar();
		}
	}
	else {
		printf("찾는 ISBN이 없습니다.\n");
		getchar();
	}
}

void ReturnDVD() {
	char* name[NAME_LEN];
	printf("반납 DVD ISBN 입력: ");
	gets(name);

	if (IsRegistISBN(name)) {
		if (IsRented(name)) {
			SetReturned(name);
			printf("반납이 완료되었습니다. \n");
			getchar();
		}
		else {
			printf("대여중인 DVD가 아닙니다.\n");
			getchar();
		}
	}
	else {
		printf("찾는 ISBN이 없습니다.\n");
		getchar();
	}
}

void HistoryDVD() {
	char* name[NAME_LEN];
	printf("찾는 ISBN 입력: ");
	gets(name);

	if (IsRegistISBN(name)) {
		dvdInfo* temp = GetDVDPtrByISBN(name);
		if (temp->numOfRentCus > 0) {
			ShowHistoryDVD(temp->rentList, temp->numOfRentCus);
		}
		else {
			printf("대여 기록이 없습니다.\n");
			getchar();
		}
	}
	else {
		printf("찾는 ISBN이 없습니다.\n");
		getchar();
	}
}