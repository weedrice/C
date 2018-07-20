#include "d_common.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "d_screenOut.h"
#include "cusManager.h"

void RegistCustomer() {
	char ID[ID_LEN];
	char name[NAME_LEN];
	char num[PHONE_LEN];

	while (1) {
		printf("ID 입력: ");
		gets(ID);
		if(IsRegistID(ID)) {
			printf("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해주세요.\n");
			getchar();
		}
		else {
			break;
		}
	}
	
	printf("이름 입력: ");
	gets(name);
	printf("전화번호 입력: ");
	gets(num);

	AddCusInfo(ID, name, num);
	printf("가입이 완료되었습니다.\n");
	getchar();
		
}

void SearchCusInfo() {
	char* ID[ID_LEN];
	printf("찾는 ID 입력: ");
	gets(ID);
	cusInfo* temp = GetCusPtrByID(ID);
	if (temp != NULL) {
		ShowCustomerInfo(temp);
	}
	else {
		printf("찾는 ID가 없습니다.\n");
		getchar();
	}

}