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
