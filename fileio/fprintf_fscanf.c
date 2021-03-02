#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main_10(void) {

	FILE* stream;
	stream = fopen("student.txt", "w"); // 파일 열기 

	if (stream == NULL) {
		puts("파일이 정상적으로 열리지 않았습니다.");
		return 0;
	}

	char* name = "이종석";
	char* std_no = "9751003";
	char* major = "사회체육학";
	int grade = 3; 

	//printf("학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d", name, std_no, major, grade);
	fprintf(stream, "학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d\n", name, std_no, major, grade);
	fprintf(stream, "학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d\n", name, std_no, major, grade);
	fprintf(stream, "학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d\n", name, std_no, major, grade);

    fclose(stream); // 파일 닫기 

	FILE* stream2 = fopen("student2.txt", "w");

	const int std_count = 3; // 학생 수 상수 (3명)  
	char* name_a[3];
	char* std_no_a[3];
	char* major_a[3]; 

	// scanf 의 경우는, 직접 제공된 포인터변수에 값을 입력하는 함수, 
	// 제공한 포인터변수의 경우에는, 그 값의 크기는 존재해야한다. 

	char temp[100]; // scanf를 위한 100bytes 의 공간을 미리 확보 

	for (int i = 0; i < std_count; i++) {
	
		puts("학생이름을 입력해 주세요 > ");
		scanf("%s", temp);
		name_a[i] = _strdup(temp); // str dupplication 

		puts("학번을 입력해 주세요 > ");
		scanf("%s", temp);
		std_no_a[i] = _strdup(temp); // str dupplication 

		puts("전공을 입력해 주세요 > ");
		scanf("%s", temp);
		major_a[i] = _strdup(temp); // str dupplication 
	    
		fprintf(stream2, "학번 : %s, 이름 : %s, 전공 %s\n", name_a[i], std_no_a[i], major_a[i]); // file output (파일로 출력) 

		// file IO -> I : Input, O : Output 
		// printf() 인풋? 아웃풋? -> 화면에 '출력' - 아웃풋 
		// scanf() 인풋? 아웃풋? -> 사용자의 키보드에서 '입력' - 인풋  

	}


	fclose(stream2);
	return 0; 
}