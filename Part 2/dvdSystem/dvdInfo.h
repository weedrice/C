#pragma once
#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30

enum { ACTION = 1, COMIC, SF, ROMANTIC };
enum { RENTED, RETURNED };

typedef struct __dvdInfo {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
	int rentState;
} dvdInfo;

#endif