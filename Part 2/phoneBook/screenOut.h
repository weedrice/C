/* Name: screenOut.h ver 1.1
 * Content: �ܼ� ����� ���� �Լ� ����
 * Implementation: YJW
 *
 * Last modified 2017/07/16
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "PhoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ShowPhoneInfoByPtr(phoneData * pPhone);

#endif
/* end of file */