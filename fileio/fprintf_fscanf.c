#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

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

	printf("학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d", name, std_no, major, grade);
	fprintf(stream, "학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d\n", name, std_no, major, grade);
	fprintf(stream, "학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d\n", name, std_no, major, grade);
	fprintf(stream, "학번 : %s, 이름 : %s, 전공 : %s, 학년 : %d\n", name, std_no, major, grade);


    fclose(stream); // 파일 닫기 

	return 0; 
}