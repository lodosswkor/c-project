#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// scanf 
int main(void) {

	FILE* fp = fopen("excel.csv", "r");
	if (fp == NULL) {
		puts("������ ������ �ʾҽ��ϴ�.");
		return 0; 
	}

	char buffer[100];

	//fscanf(fp, "%s,%s,%s", buffer)
	//fgets() 
	//���ڿ��� �ڸ���. 
	
	char* aaa = "abc\0"; 

	char* p = NULL;
	char* name[10]; 
	char* std_no[10]; 
	char* major[10]; 
	char* point[10]; 

	int std_idx = 0; 

	while(fscanf(fp, "%s\n", buffer) != EOF) { // �� loop ���� ������ �л����� �þ��. 
		
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
		printf("�й� %s, �̸� %s, ���� %s, ���� %s\n", std_no[i], name[i], major[i], point[i]);
	}
	
	/*
	char* test = _strdup("�ȳ��ϼ���, ���� ������ �Դϴ�.\0");
	char* p = strtok(test, " ");
	while (p != NULL) {
		printf("%s\n", p); 
		p = strtok(NULL, " "); // ������ �ڸ����� �������� �����ڸ� ã�� �����Ѵ�.
	}
	*/
	

	// �ȳ��ϼ���, 
	// ����
	// ������
	// �Դϴ�.
	// '����'�������� �ڸ��� �ʹ�. -> ��ū 4�� 
	// ',' �������� ������ ->  �ȳ��ϼ��� / ���� ������ �Դϴ�. ( ��ū 2�� ) 
	// -> strtok() // str token

	
	fclose(fp);
	return 0; 
}