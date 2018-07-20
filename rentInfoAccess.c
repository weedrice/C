#include "d_common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "d_screenOut.h"
#include "rentInfoAccess.h"

#define RENT_LEN 100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus = 0;

void AddRentList(char* ISBN, char* cusID, int rentDay) {
	strcpy(rentList[numOfRentCus].cusID, cusID);
	strcpy(rentList[numOfRentCus].ISBN, ISBN);
	rentList[numOfRentCus].rentDay = rentDay;
	numOfRentCus++;

	SaveRentList();
}

void PrintOutRentAllCusInfo(char* ISBN) {
	for (int i = 0; i < numOfRentCus; i++) {
		if(strcmp(rentList[i].ISBN, ISBN) == 0)
			ShowHistoryDVD(rentList[i].cusID, rentList[i].rentDay);
	}
	printf("조회를 완료하였습니다.\n");
	getchar();
}

void PrintOutCusAllRentInfo(char* ID, unsigned int start, unsigned int end) {
	for (int i = 0; i < numOfRentCus; i++) {
		if (rentList[i].rentDay >= start && rentList[i].rentDay <= end) {
			if (strcmp(rentList[i].cusID, ID) == 0) {
				ShowHistoryDVD(ID, rentList[i].rentDay);
			}
		}
	}
	printf("조회를 완료하였습니다.\n");
	getchar();
}

void SaveRentList() {
	FILE* fp = fopen("rentData.dat", "wb");
	if (fp == NULL)
		return;

	fwrite(&numOfRentCus, sizeof(int), 1, fp);
	fwrite(rentList, sizeof(dvdInfo), numOfRentCus, fp);

	fclose(fp);
}

void LoadRentList() {
	FILE* fp = fopen("rentData.dat", "rb");
	if (fp == NULL)
		return;

	fread(&numOfRentCus, sizeof(int), 1, fp);
	fread(rentList, sizeof(dvdInfo), numOfRentCus, fp);

	fclose(fp);
}