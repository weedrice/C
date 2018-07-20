#pragma once
#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu();
void ShowCustomerInfo(cusInfo* pCus);
void ShowDVDInfo(dvdInfo* pDvd);
char* getGenre(int genre);

#endif