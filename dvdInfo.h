#pragma once
#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#define ISBN_LEN 30
#define TITLE_LEN 30

enum { ACTION = 1, COMIC, SF, ROMANTIC };

typedef struct __dvdInfo {
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;
} dvdInfo;

#endif