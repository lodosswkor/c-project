#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcmp(); strncmp() ..... ��� 
#include <stdlib.h> // malloc, calloc, realloc()

//-- �츮�� å�̸��� �۰��� ���� ���̴� (�迭��) 
//-- å���� ũ��� �� 100���� �� �� �ִ�.

#define MAX_CAPACITY 100 // 100������ �� �� �ִ� å�� 

char* book_name[MAX_CAPACITY]; // å�̸� 
char* book_author[MAX_CAPACITY]; // �۰��̸� 
int book_idx = 0; // �迭 �ε��� 

// �Լ� ����� 
void add();   // å�� �߰��ϴ� �Լ� 
void del();    // å�� �����ϴ� �Լ� 
void list();    // å ����� ����ϴ� �Լ� 
void find();   // å�� ã�� �Լ� 
void save();  // ������ �����ϴ� �Լ� 
void read();  // ������ �о���̴� �Լ� 
void help();  // ������ ����ϴ� �Լ� 
char* ex_strdup(char* ); // strdup ����

int main(void) {

	// add, list, del .... > add 
	char command[100]; 

	while (1) {

		printf("��ɾ �Է��ϼ��� > ");
		scanf("%s", command);
		// command = "add" �߰� ���� 
		// command = "find" �˻� ����
		// ���ڿ� �񱳽ÿ��� strcmp(); �Լ��� ����Ͽ� 
		// �����Ͱ� ����ġ�� ������ ���� ��ü�� ���ؾ��Ѵ�. 
		//if (*command == "add") {
		// strcmp ( �񱳹��ڿ�1, �񱳹��ڿ�2 ) 
		// ���࿡ ������ ���ڿ��̴� -> 0 / �׷�ġ ������ -1 
		// string compare 
		if (strcmp(command, "add") == 0) {
			add();
		}
		else if (strcmp(command, "del") == 0) {
			del();
		}
		else if (strcmp(command, "find") == 0) {
			find();
		}
		else if (strcmp(command, "list") == 0) {
			list();
		}
		else if (strcmp(command, "save") == 0) {
			save(); 
		}
		else if (strcmp(command, "read") == 0) {
			read();
		}
		else if (strcmp(command, "help") == 0) {
			help();
		}
		else if (strcmp(command, "q") == 0) { // ���α׷� ����
			break; 
		}
		else {
			printf("�´� ��ɾ �����ϴ�.\n");
		}
	}

	return 0;
}

// �Լ����Ǻ� 
void add() {
	//printf("add�Լ� ȣ��!\n");
	// add å�̸� �۰��� [����] 
	// add -> command ���� 
	// å�̸� -> buf1 hello
	// �۰��� -> buf2 
	char buf1[100], buf2[100]; // buf1 å�̸�, buf2�� �۰��� 

	scanf("%s", buf1);
	scanf("%s", buf2);


	// strcpy(), strdup()
	//book_name[book_idx] = buf1;
	//book_author[book_idx] = buf2; 

	// strdup(�����ҹ��ڿ�) -> return ���� ������ ���ڿ��� �����͸� �Ѱ��ݴϴ�.
	// strdup -> malloc (�޸� �����Ҵ�) �� ������ ���ڿ���ü�� �����ȴ�.
	// string duplication / string copy (strcpy) 
	// strcpy( ����� ����, ������ ���� ); 
	
	book_name[book_idx] = ex_strdup(buf1); // _strdup() 
	book_author[book_idx] = ex_strdup(buf2);
	
	//strcpy(book_name[book_idx], buf2);

	printf("'%s' �� �����Ͽ����ϴ�.\n", book_name[book_idx]);
	book_idx++;
}

//-- �迭�� �Էµ� ������ �˻��ؼ�, �ش� �迭 index�� ������ 
//-- �� index�� �ִ� ���� ����(NULL) 

void del() {

	//-- å�̸��� �˻��ϰ�, �� å�̸��� �ִ� �迭 index�� ����
	
	char search_txt[100];
	scanf("%s", search_txt);
	
	//-- ����ڷ� ���� ���� ��, '�˻���'�� book_names[x]�� �ִ� 'å�̸�'�� ��ġ�ϴ��� Ȯ�� 
	//-- �� index�� ���� 

	for (int i = 0; i < book_idx; i++) {
		//-- ���ڿ� �񱳰� �ʿ���. strcmp() 
		//-- �迭�� �ε����� 0���� �����Ѵ�.
		//-- ���� �迭�� "ũ��"(�� ���Ǽ���)�� 150�� 
		//-- �׷� �迭�� ������ �ε����� ���ϱ��? 
		//-- �迭�� ũ�Ⱑ 10�� �迭 
		//-- 0,1,2,3,4,5,6,7,8,9 ( 10 - 1 )
		//-- �迭�� ũ�Ⱑ 150�̶�� �ϸ� �迭�� ������ �ε����� 150 - 1 = 149 (�迭ũ�� - 1)
		if (strcmp(book_name[i], search_txt) == 0) { // book_name[i], search_text�� ������ ���� 
			book_name[i] = book_name[book_idx - 1]; 
			book_author[i] = book_author[book_idx - 1];
			printf("'%s'�� �����Ǿ����ϴ�.\n", search_txt);
			
			book_idx--; // book_idx = book_idx - 1; 
			//book_idx++; // book_idx = book_idx + 1; 
			return;
		}
	} // search_txt != book_name[i] ������������ i == book_idx
	// å�̸��� 'ABC', 'BBB', 'CCC', 'DDD' ��� �� 4���� ���� ��� 
	// search_txt = BBB ��� ��ȸ�� �ϸ� 

	printf("å �̸��� '%s'�� å�� �������� �ʽ��ϴ�.\n", search_txt);
}

void list() {
	for (int i = 0; i < book_idx; i++) {
		printf("%-10s %-10s\n", book_name[i], book_author[i]);
	}
}

void find() {
	//book_name[] = 10���� �ִ� .
	//10���� ���鼭 �����̸��� �ִ��� Ȯ���ϰ�, ������
	//�� index�� ����Ͽ� å�� ����Ѵ�
	// > find å�̸� [����]
	char buf1[100]; 
	scanf("%s", buf1); // buf1�� �˻���

	for (int i = 0; i < book_idx; i++) {
	    // ���ڿ� �񱳴�? strcmp 
		if (strcmp(buf1, book_name[i]) == 0) {
			printf("%-10s %-10s\n", book_name[i], book_author[i]);
			//break;
			return; // �Լ� ��ü�� �����Ѵ� 
		}
	}
	// ���� �̸��� ���� å�� ������ ����
	printf("å ��� ��, '%s'��� å�� �����ϴ�.\n", buf1);
}

void save() {
	printf("save �Լ� ȣ��!\n");
}

void read() {
	printf("read �Լ� ȣ��!\n");
}

void help() {
	printf("help �Լ� ȣ��!\n");
}

//--- strdup ���� ���� 
char* ex_strdup(char* source) {
	char* tmp = (char *)malloc(strlen(source)+1);
	if (tmp == NULL) {
		return NULL; 
	}
	strcpy(tmp, source);
	return tmp; 
}