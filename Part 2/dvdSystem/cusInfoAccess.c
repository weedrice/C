#include "d_common.h"
#include "cusInfoAccess.h"
#include "cusInfo.h"

#define MAX_CUSTOMER 100

static cusInfo *cusList[MAX_CUSTOMER];
static int numOfCustomer = 0;

void SaveCusList() {
	FILE* fp = fopen("cusData.dat", "wb");
	if (fp == NULL)
		return;

	fwrite(&numOfCustomer, sizeof(int), 1, fp);

	for (int i = 0; i < numOfCustomer; i++) {
		fwrite(cusList[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);
}

void LoadCusList() {
	FILE* fp = fopen("cusData.dat", "rb");
	if (fp == NULL)
		return;

	fread(&numOfCustomer, sizeof(int), 1, fp);

	for (int i = 0; i < numOfCustomer; i++) {
		cusList[i] = (cusInfo*)malloc(sizeof(cusInfo));
		fread(cusList[i], sizeof(cusInfo), 1, fp);
	}

	fclose(fp);
}

int AddCusInfo(char *ID, char* name, char* num) {
	if (numOfCustomer > MAX_CUSTOMER) {
		printf("등록 가능한 ID를 초과하였습니다.\n");
		return 0;
	}

	cusInfo* temp;
	temp = (cusInfo*)malloc(sizeof(cusInfo));
	
	strcpy(temp->ID, ID);
	strcpy(temp->name, name);
	strcpy(temp->phoneNum, num);
	cusList[numOfCustomer] = temp;
	numOfCustomer++;

	//savepoint
	SaveCusList();

	return numOfCustomer;
}

cusInfo* GetCusPtrByID(char* ID) {
	for (int i = 0; i < numOfCustomer; i++) {
		if (strcmp(ID, cusList[i]->ID) == 0) {
			return cusList[i];
		}
	}

	return NULL;
}

int IsRegistID(char* ID) {
	for (int i = 0; i < numOfCustomer; i++) {
		if (strcmp(ID, cusList[i]->ID) == 0) {
			return 1;
		}
	}

	return 0;
}

