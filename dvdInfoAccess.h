#pragma once
#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

void AddDVDInfo(char* ISBN, char* title, int genre);
dvdInfo* GetDVDPtrByISBN(char* ISBN);
int IsRegistISBN(char* ISBN);

#endif