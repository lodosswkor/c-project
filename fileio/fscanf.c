#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// scanf 
int main(void) {

	FILE* fp = fopen("excel.csv", "r");
	if (fp == NULL) {
		puts("파일이 열리지 않았습니다.");
		return 0; 
	}

	char buffer[100];

	//fscanf(fp, "%s,%s,%s", buffer)
	//fgets() 
	//문자열을 자른다. 
	
	char* aaa = "abc\0"; 

	char* p = NULL;
	char* name[10]; 
	char* std_no[10]; 
	char* major[10]; 
	char* point[10]; 

	int std_idx = 0; 

	while(fscanf(fp, "%s\n", buffer) != EOF) { // 이 loop 문이 돌수록 학생수는 늘어난다. 
		
		p = strtok(buffer, ",");
		name[std_idx] = _strdup(p);

		p = strtok(NULL, ",");
		std_no[std_idx] = _strdup(p);

		p = strtok(NULL, ",");
		major[std_idx] = _strdup(p);

		p = strtok(NULL, ","); 
		point[std_idx] = _strdup(p);
		
		std_idx++;
	}

	for (int i = 0; i < std_idx; i++) {
		printf("학번 %s, 이름 %s, 전공 %s, 점수 %s\n", std_no[i], name[i], major[i], point[i]);
	}
	
	/*
	char* test = _strdup("안녕하세여, 저는 이종석 입니다.\0");
	char* p = strtok(test, " ");
	while (p != NULL) {
		printf("%s\n", p); 
		p = strtok(NULL, " "); // 위에서 자른문자 다음부터 구분자를 찾기 시작한다.
	}
	*/
	

	// 안녕하세여, 
	// 저는
	// 이종석
	// 입니다.
	// '공백'기준으로 자르고 싶다. -> 토큰 4개 
	// ',' 기준으로 나눴다 ->  안녕하세요 / 저는 이종석 입니다. ( 토큰 2개 ) 
	// -> strtok() // str token

	
	fclose(fp);
	return 0; 
}