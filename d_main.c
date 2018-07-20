#include "d_common.h"
#include "d_screenOut.h"
#include "cusManager.h"

enum{CUS_REGIST = 1, CUS_SEARCH, DVD_REGIST, DVD_SEARCH, QUIT};

int main() {
	int inputMenu = 0;

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
		}

		if (inputMenu == QUIT) {
			puts("�̿��� �ּż� ������~");
			break;
		}
	}

	return 0;
}