#pragma once
#ifndef __CUSACCESS_H__
#define __CUSACCESS_H__

#include "cusInfo.h"

void SaveCusList();
void LoadCusList();
int AddCusInfo(char* ID, char* name, char* num);
cusInfo* GetCusPtrByID(char* ID);
int IsRegistID(char* ID);

#endif