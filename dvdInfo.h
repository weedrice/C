#pragma once
#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30
#define RENT_LEN 100

enum { ACTION = 1, COMIC, SF, ROMANTIC };
enum { RENTED, RETURNED };

typedef struct __dvdRentInfo {
	char cusID[ID_LEN];
	unsigned int rentDay;
} dvdRentInfo;

typedef struct __dvdInfo {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	int rentState;
	int numOfRentCus;
	dvdRentInfo rentList[RENT_LEN];
} dvdInfo;

#endif