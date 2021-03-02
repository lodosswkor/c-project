#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// fgets(), fputs()  
// file get string(), file put string()
// ���δ����� �д´�. 

int main01(void) {

	FILE* p = fopen("data.txt", "r");

	if (p == NULL) {
		printf("file open error!!");
		return; 
	}

	char readLine[200]; 

	// fgets(����� ����(������), ������ ũ��, ����������(��Ʈ��)) 
	/*
	�� ���ξ� �д´�  
	fgets(readLine, sizeof(readLine), p); 
	printf("%s", readLine);
	fgets(readLine, sizeof(readLine), p);
	printf("%s", readLine);*/

	//-- Ŀ���� ���ϳ�(EOF - End Of File)�� �����ϸ� feof() �Լ��� '��'�� �����Ѵ�.
	while (!feof(p)) {  
		fgets(readLine, sizeof(readLine), p);
		printf("%s", readLine);
	}
   
	fclose(p);

	FILE* wp = fopen("data.txt", "a");

	// fput(����, ����������-��Ʈ��) 
	fputs("TEST�Դϴ�", wp);

	fclose(wp);


	while (1) {
		char direction = 0;
		direction = getc(stdin);
		printf("%d", direction);
	}

	return 0;
}



 