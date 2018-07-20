#include "d_common.h"
#include "d_screenOut.h"
#include "dvdInfo.h"
#include "dvdInfoAccess.h"

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
	temp->numOfRentCus = 0;
	dvdList[numOfDVD] = temp;
	numOfDVD++;

	return numOfDVD;
}

dvdInfo * GetDVDPtrByISBN(char * ISBN)
{
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
	strcpy(temp->rentList[temp->numOfRentCus].cusID, ID);
	temp->rentList[temp->numOfRentCus].rentDay = rentDay;
}

void SetReturned(char* ISBN) {
	dvdInfo* temp = GetDVDPtrByISBN(ISBN);

	temp->rentState = RETURNED;
	temp->numOfRentCus++;
}