#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main_10(void) {

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

	//printf("�й� : %s, �̸� : %s, ���� : %s, �г� : %d", name, std_no, major, grade);
	fprintf(stream, "�й� : %s, �̸� : %s, ���� : %s, �г� : %d\n", name, std_no, major, grade);
	fprintf(stream, "�й� : %s, �̸� : %s, ���� : %s, �г� : %d\n", name, std_no, major, grade);
	fprintf(stream, "�й� : %s, �̸� : %s, ���� : %s, �г� : %d\n", name, std_no, major, grade);

    fclose(stream); // ���� �ݱ� 

	FILE* stream2 = fopen("student2.txt", "w");

	const int std_count = 3; // �л� �� ��� (3��)  
	char* name_a[3];
	char* std_no_a[3];
	char* major_a[3]; 

	// scanf �� ����, ���� ������ �����ͺ����� ���� �Է��ϴ� �Լ�, 
	// ������ �����ͺ����� ��쿡��, �� ���� ũ��� �����ؾ��Ѵ�. 

	char temp[100]; // scanf�� ���� 100bytes �� ������ �̸� Ȯ�� 

	for (int i = 0; i < std_count; i++) {
	
		puts("�л��̸��� �Է��� �ּ��� > ");
		scanf("%s", temp);
		name_a[i] = _strdup(temp); // str dupplication 

		puts("�й��� �Է��� �ּ��� > ");
		scanf("%s", temp);
		std_no_a[i] = _strdup(temp); // str dupplication 

		puts("������ �Է��� �ּ��� > ");
		scanf("%s", temp);
		major_a[i] = _strdup(temp); // str dupplication 
	    
		fprintf(stream2, "�й� : %s, �̸� : %s, ���� %s\n", name_a[i], std_no_a[i], major_a[i]); // file output (���Ϸ� ���) 

		// file IO -> I : Input, O : Output 
		// printf() ��ǲ? �ƿ�ǲ? -> ȭ�鿡 '���' - �ƿ�ǲ 
		// scanf() ��ǲ? �ƿ�ǲ? -> ������� Ű���忡�� '�Է�' - ��ǲ  

	}


	fclose(stream2);
	return 0; 
}