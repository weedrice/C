#include "d_common.h"
#include "d_screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"
#include "rentInfo.h"
#include "rentInfoAccess.h"

#define MAX_DVD 100

static dvdInfo *dvdList[MAX_DVD];
static int numOfDVD = 0;

void AddDVDInfo(char * ISBN, char * title, int genre)
{
	if (numOfDVD > MAX_DVD) {
		printf("등록 가능한 DVD 개수를 초과하였습니다.\n");
		return 0;
	}

	dvdInfo* temp;
	temp = (dvdInfo*)malloc(sizeof(dvdInfo));

	strcpy(temp->ISBN, ISBN);
	strcpy(temp->title, title);
	temp->genre =  genre;
	temp->rentState = RETURNED;
	dvdList[numOfDVD] = temp;
	numOfDVD++;

	//savepoint
	SaveDVDList();

	return numOfDVD;
}

dvdInfo * GetDVDPtrByISBN(char * ISBN) {
	for (int i = 0; i < numOfDVD; i++) {
		if (strcmp(ISBN, dvdList[i]->ISBN) == 0) {
			return dvdList[i];
		}
	}

	return NULL;
}

int IsRegistISBN(char * ISBN)
{
	dvdInfo* temp;
	temp = GetDVDPtrByISBN(ISBN);
	if (temp == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

int IsRented(char* ISBN) {
	dvdInfo* temp;
	temp = GetDVDPtrByISBN(ISBN);
	if (temp->rentState == RENTED) {
		return 1;
	}
	else {
		return 0;
	}
}

void SetRented(char* ISBN, char* ID, int rentDay) {
	dvdInfo* temp = GetDVDPtrByISBN(ISBN);
	temp->rentState = RENTED;
	AddRentList(ISBN, ID, rentDay);
	//savepoint
	SaveDVDList();
}

void SetReturned(char* ISBN) {
	dvdInfo* temp = GetDVDPtrByISBN(ISBN);
	temp->rentState = RETURNED;
	//savepoint
	SaveDVDList();
}

void SaveDVDList() {
	FILE* fp = fopen("dvdData.dat", "wb");
	if (fp == NULL)
		return;

	fwrite(&numOfDVD, sizeof(int), 1, fp);

	for (int i = 0; i < numOfDVD; i++) {
		fwrite(dvdList[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);
}

void LoadDVDList() {
	FILE* fp = fopen("dvdData.dat", "rb");
	if (fp == NULL)
		return;

	fread(&numOfDVD, sizeof(int), 1, fp);

	for (int i = 0; i < numOfDVD; i++) {
		dvdList[i] = (dvdInfo*)malloc(sizeof(dvdInfo));
		fread(dvdList[i], sizeof(dvdInfo), 1, fp);
	}

	fclose(fp);
}