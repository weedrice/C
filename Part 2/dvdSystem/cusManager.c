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
		printf("ID �Է�: ");
		gets(ID);
		if(IsRegistID(ID)) {
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