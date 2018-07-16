/* Name: phonefunc.h ver 1.3
 * Content: 전화번호 컨트롤 함수들의 선언
 * Implementation: YJW
 *
 * Last modified 2017/07/16
 */
#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__

#include "phoneData.h"

void InputPhoneData(void);
void ShowAllData(void);
void SearchPhoneData(void);
void DeletePhoneData(void);
void StoreDataToFile(void);
void LoadDataFromFile(void);
void ChangePhoneData(void);

#endif
/* end of file */