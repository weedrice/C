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
