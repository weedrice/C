#pragma once
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu();
void ShowCustomerInfo(cusInfo* pCus);
void ShowDVDInfo(dvdInfo* pDvd);
void ShowHistoryDVD(char* cusID, int rentDay);
char* getGenre(int genre);

#endif