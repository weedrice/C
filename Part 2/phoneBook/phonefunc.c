/* Name: phoneFunc.c ver 1.7
* Content: ��ȭ��ȣ ��Ʈ�� �Լ�
* Implementation: YJW
*
* Last modified 2018/07/16
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData* phoneList[LIST_NUM];


void StoreDataToFileInStruct(void) {
	FILE *fp = fopen("phoneDataStruct.dat", "wb");

	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}
	fwrite(&numOfData, sizeof(int), 1, fp);

	for (int i = 0; i < numOfData; i++) {
		fwrite(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
}

void LoadDataFromFileInStruct(void) {
	FILE* fp = fopen("phoneDataStruct.dat", "rb");
	if (fp == NULL) {
		printf("�ҷ��� ������ �����ϴ�.\n");
		return;
	}

	fread(&numOfData, sizeof(int), 1, fp);
	for (int i = 0; i < numOfData; i++) {
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));

		fread(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
}

/* ��   ��: void ImputphoneData(void)
 * ��   ��: ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
 * ��   ȯ: void
 *
 */
void InputPhoneData(void) {
	if (numOfData > LIST_NUM) {
		printf("������ �Է� ���� �ʰ�!\n");
		return;
	}

	phoneData* temp = (phoneData*)malloc(sizeof(phoneData));

	printf("�̸� �Է�: ");
	gets(temp->name);
	printf("��ȭ��ȣ �Է�: ");
	gets(temp->phoneNum);

	for (int i = 0; i < numOfData; i++) {
		if (strcmp(temp->name, phoneList[i]->name) == 0) {
			if (strcmp(temp->phoneNum, phoneList[i]->phoneNum) == 0) {
				printf("�̹� �Էµ� ������ �Դϴ�.\n");
				getchar();
				StoreDataToFileInStruct();
				return;
			}
		}
	}

	phoneList[numOfData++] = temp;
	printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
	getchar();

	StoreDataToFileInStruct();
	return;
}

/* ��   ��: void ShowAllData(void)
 * ��   ��: ����� ������ ��ü ���
 * ��   ȯ: void
 *
 */
void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	printf("����� �Ϸ�Ǿ����ϴ�.\n");
	getchar();
}

void SearchPhoneData(void) {
	char searchName[NAME_LEN];
	printf("ã�� �̸���? ");
	gets(searchName);
	int count = 0;
	for (int i = 0; i < numOfData; i++) {
		if (strcmp(phoneList[i]->name, searchName) == 0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			count++;
		}
	}

	if (count > 0) {
		printf("�˻��� �Ϸ�Ǿ����ϴ�.\n");
		getchar();
	}
	else {
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
		getchar();
	}
	
}

void DeletePhoneData(void) {
	char searchName[NAME_LEN];
	printf("ã�� �̸���? ");
	gets(searchName);
	int searchLocation[LIST_NUM];
	int searchCount = 0;

	for (int i = 0; i < numOfData; i++) {
		if (strcmp(phoneList[i]->name, searchName) == 0) {
			searchLocation[searchCount++] = i;
		}
	}

	if (searchCount == 1) {
		for (int i = searchLocation[0] + 1; i <= numOfData; i++) {
			free(phoneList[i - 1]);
			phoneList[i - 1] = phoneList[i];
		}
		numOfData--;
		printf("������ �Ϸ�Ǿ����ϴ�.\n");
		getchar();

		StoreDataToFileInStruct();
		return;
	}
	else if(searchCount > 1) {
		int select;
		for (int i = 0; i < searchCount; i++) {
			printf("NUM.  %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[searchLocation[i]]);
		}
		printf("����: ");
		scanf("%d", &select);
		getchar();
		
		if (select < searchCount) {
			free(phoneList[searchLocation[select-1]]);
			for (int i = searchLocation[select-1] + 1; i <= numOfData; i++) {
				phoneList[i - 1] = phoneList[i];
			}
			numOfData--;
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			getchar();

			StoreDataToFileInStruct();
			return;
		}
		else {
			printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n");
			return;
		}
	}

	printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	getchar();
}

void StoreDataToFile(void) {
	FILE *fp = fopen("phoneData.dat", "w");
	if (fp == NULL) {
		printf("������ ������ �� ������ �߻��߽��ϴ�.\n");
		return;
	}

	fwrite(&numOfData, sizeof(int), 1, fp);
	for (int i = 0; i < numOfData; i++) {
		fprintf(fp, "%s\n%s\n", phoneList[i]->name, phoneList[i]->phoneNum);
		free(phoneList[i]);
	}

	fclose(fp);
}

void LoadDataFromFile(void) {
	FILE *fp = fopen("phoneData.dat", "r");
	if (fp == NULL) {
		printf("�о���� ������ �����ϴ�.\n");
		return;
	}

	fread(&numOfData, sizeof(int), 1, fp);

	for (int i = 0; i < numOfData; i++) {
		phoneList[i] = (phoneData*)malloc(sizeof(phoneData));
		fgets(phoneList[i]->name, NAME_LEN, fp);

		int temp = strlen(phoneList[i]->name);
		phoneList[i]->name[temp - 1] = 0;

		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);

		temp = strlen(phoneList[i]->phoneNum);
		phoneList[i]->phoneNum[temp - 1] = 0;
	}

	fclose(fp);
}

void ChangePhoneData(void) {
	char searchName[NAME_LEN];
	printf("���� ����� �̸���? ");
	gets(searchName);
	int searchLocation[LIST_NUM];
	int searchCount = 0;

	for (int i = 0; i < numOfData; i++) {
		if (strcmp(phoneList[i]->name, searchName) == 0) {
			searchLocation[searchCount++] = i;
		}
	}

	if (searchCount == 1) {
		printf("������ ��ȭ��ȣ��? ");
		char changeNum[PHONE_LEN];
		gets(changeNum);
		strcpy(phoneList[searchLocation[0]]->phoneNum, changeNum);
		printf("������ �Ϸ�Ǿ����ϴ�.\n");
		getchar();

		StoreDataToFileInStruct();
		return;
	}
	else if (searchCount > 1) {
		int select;
		for (int i = 0; i < searchCount; i++) {
			printf("NUM.  %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[searchLocation[i]]);
		}
		printf("����: ");
		scanf("%d", &select);
		getchar();

		if (select-1 < searchCount) {
			printf("������ ��ȭ��ȣ��? ");
			char changeNum[PHONE_LEN];
			gets(changeNum);
			strcpy(phoneList[searchLocation[select-1]]->phoneNum, changeNum);
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			getchar();

			StoreDataToFileInStruct();
			return;
		}
		else {
			printf("�߸��� ���� �Է��ϼ̽��ϴ�.\n");
			return;
		}
	}

	printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	getchar();
}


/* end of file */