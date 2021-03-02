#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// fgets(), fputs()  
// file get string(), file put string()
// 라인단위로 읽는다. 

int main01(void) {

	FILE* p = fopen("data.txt", "r");

	if (p == NULL) {
		printf("file open error!!");
		return; 
	}

	char readLine[200]; 

	// fgets(저장될 변수(포인터), 변수의 크기, 파일포인터(스트림)) 
	/*
	한 라인씩 읽는다  
	fgets(readLine, sizeof(readLine), p); 
	printf("%s", readLine);
	fgets(readLine, sizeof(readLine), p);
	printf("%s", readLine);*/

	//-- 커서가 파일끝(EOF - End Of File)에 도달하면 feof() 함수는 '참'을 리턴한다.
	while (!feof(p)) {  
		fgets(readLine, sizeof(readLine), p);
		printf("%s", readLine);
	}
   
	fclose(p);

	FILE* wp = fopen("data.txt", "a");

	// fput(변수, 파일포인터-스트림) 
	fputs("TEST입니다", wp);

	fclose(wp);


	while (1) {
		char direction = 0;
		direction = getc(stdin);
		printf("%d", direction);
	}

	return 0;
}



 