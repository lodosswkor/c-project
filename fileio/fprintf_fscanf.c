#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	FILE* stream;
	stream = fopen("student.txt", "w"); // ���� ���� 

	if (stream == NULL) {
		puts("������ ���������� ������ �ʾҽ��ϴ�.");
		return 0;
	}

	char* name = "������";
	char* std_no = "9751003";
	char* major = "��ȸü����";
	int grade = 3; 

	printf("�й� : %s, �̸� : %s, ���� : %s, �г� : %d", name, std_no, major, grade);
	fprintf(stream, "�й� : %s, �̸� : %s, ���� : %s, �г� : %d\n", name, std_no, major, grade);
	fprintf(stream, "�й� : %s, �̸� : %s, ���� : %s, �г� : %d\n", name, std_no, major, grade);
	fprintf(stream, "�й� : %s, �̸� : %s, ���� : %s, �г� : %d\n", name, std_no, major, grade);


    fclose(stream); // ���� �ݱ� 

	return 0; 
}