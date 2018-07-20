#include "d_common.h"
#include "d_screenOut.h"
#include "blManager.h"

enum { CUS_REGIST = 1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, DVD_RENT, DVD_RETURN, DVD_HISTORY, DVD_SELECTCUSDVD, QUIT };

int main() {
	int inputMenu = 0;
	LoadData();

	while (1) {
		ShowMenu();
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu) {
		case CUS_REGIST:
			RegistCustomer();
			break;
		case CUS_SEARCH:
			SearchCusInfo();
			break;
		case DVD_REGIST:
			RegistDVD();
			break;
		case DVD_SEARCH:
			SearchDVD();
			break;
		case DVD_RENT:
			RentDVD();
			break;
		case DVD_RETURN:
			ReturnDVD();
			break;
		case DVD_HISTORY:
			HistoryDVD();
			break;
		case DVD_SELECTCUSDVD:
			SearchDVDByCUS();
			break;
		}

		if (inputMenu == QUIT) {
			puts("이용해 주셔서 고마워요~");
			break;
		}
	}

	return;
}