/* Name: phoneFunc.c ver 1.5
* Content: 전화번호 컨트롤 함수
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

/* 함   수: void ImputphoneData(void)
 * 기   능: 전화번호 관련 데이터 입력 받아서 저장
 * 반   환: void
 *
 */
void InputPhoneData(void) {
	if (numOfData > LIST_NUM) {
		printf("데이터 입력 상한 초과!\n");
		return;
	}

	phoneData* temp = (phoneData*)malloc(sizeof(phoneData));

	printf("이름 입력: ");
	gets(temp->name);
	printf("전화번호 입력: ");
	gets(temp->phoneNum);

	for (int i = 0; i < numOfData; i++) {
		if (strcmp(temp->name, phoneList[i]->name) == 0) {
			if (strcmp(temp->phoneNum, phoneList[i]->phoneNum) == 0) {
				printf("이미 입력된 데이터 입니다.\n");
				getchar();
				return;
			}
		}
	}

	phoneList[numOfData++] = temp;
	printf("입력이 완료되었습니다.\n");
	getchar();
	return;
}

/* 함   수: void ShowAllData(void)
 * 기   능: 저장된 데이터 전체 출력
 * 반   환: void
 *
 */
void ShowAllData(void) {
	for (int i = 0; i < numOfData; i++) {
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	printf("출력이 완료되었습니다.\n");
	getchar();
}

void SearchPhoneData(void) {
	char searchName[NAME_LEN];
	printf("찾는 이름은? ");
	gets(searchName);
	int count = 0;
	for (int i = 0; i < numOfData; i++) {
		if (strcmp(phoneList[i]->name, searchName) == 0) {
			ShowPhoneInfoByPtr(phoneList[i]);
			count++;
		}
	}

	if (count > 0) {
		printf("검색이 완료되었습니다.\n");
		getchar();
	}
	else {
		printf("데이터가 존재하지 않습니다.\n");
		getchar();
	}
	
}

void DeletePhoneData(void) {
	char searchName[NAME_LEN];
	printf("찾는 이름은? ");
	gets(searchName);
	int searchLocation[LIST_NUM];
	int searchCount = 0;

	for (int i = 0; i < numOfData; i++) {
		if (strcmp(phoneList[i]->name, searchName) == 0) {
			searchLocation[searchCount++] = i;
			continue;
		}
	}

	if (searchCount == 1) {
		for (int i = searchLocation[0] + 1; i <= numOfData; i++) {
			free(phoneList[i - 1]);
			phoneList[i - 1] = phoneList[i];
		}
		numOfData--;
		printf("삭제가 완료되었습니다.\n");
		getchar();

		return;
	}
	else if(searchCount > 1) {
		int select;
		for (int i = 0; i < searchCount; i++) {
			printf("NUM.  %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[searchLocation[i]]);
		}
		printf("선택: ");
		scanf("%d", &select);
		getchar();
		
		if (select < searchCount) {
			free(phoneList[searchLocation[select-1]]);
			for (int i = searchLocation[select-1] + 1; i <= numOfData; i++) {
				phoneList[i - 1] = phoneList[i];
			}
			numOfData--;
			printf("삭제가 완료되었습니다.\n");
			getchar();

			return;
		}
		else {
			printf("잘못된 값을 입력하셨습니다.\n");
			return;
		}
	}

	printf("데이터가 존재하지 않습니다.\n");
	getchar();
}

void StoreDataToFile(void) {
	FILE *fp = fopen("phoneData.dat", "w");
	if (fp == NULL) {
		printf("파일을 저장할 때 에러가 발생했습니다.\n");
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
		printf("읽어들일 파일이 없습니다.\n");
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

/* end of file */