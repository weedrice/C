#include <stdio.h>

int strLen(char * str) {
	int count = 0;
	while (*str != '\0') {
		str++;
		count++;
	}
	return count;
}

int strCpy(char *dest, char* source) {
	for (int i = 0; i < strLen(source)+1; i++) {
		dest[i] = source[i];
	}

	return strLen(source) + 1;
}

int strCat(char *dest, char* source) {
	int start = strlen(dest);
	for (int i = 0; i < strLen(source) + 1; i++) {
		dest[i+start] = source[i];
	}

	return start + strLen(source) + 1;
}

int strCmp(char * str1, char* str2) {
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 > *str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		else {
			str1++;
			str2++;
		}
	}
	return 0;
}

int main() {
	char str1[100] = "Good morning?";
	char str2[100] = "HaHaHa!";
	char buffString[100];

	printf("length of \"%s\": %d \n", str1, strLen(str1));
	printf("length of \"%s\": %d \n", str2, strLen(str2));

	strCpy(buffString, str1);
	printf("copy string: \"%s\" \n", buffString);

	strCat(buffString, str2);
	printf("concat string: \"%s\" \n", buffString);

	printf("cmp str1, str1: %d \n", strCmp(str1, str1));
	printf("cmp str2, str2: %d \n", strCmp(str2, str2));
	printf("cmp str1, str2: %d \n", strCmp(str1, str2));
	printf("cmp str2, str1: %d \n", strCmp(str2, str1));
}