#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
// File IO ( File Input / Output ) 
// ex) printf - std Output ->����� ��� ����? (�����) standard Output (stdout) 
// ex) scanf - std Input -> �Է��� ���� ����? (Ű����) Standard Input (stdin) 
// File IO ������� 
// 1. Ž���⸦ ���� -> 2. ������ ��ġ�� ã�´� -> 3. ������ ���� 
// -> 4. ������ ���� -> 5.���� �ݴ´� 

// C��� 
// ���Ͽ���/�ݱ� ( 1,2 -> 5 ) 
// fopen(), fclose();
// fopen("������ ��ġ-����Path", "���� ���") 
// fclose(���� ������);  

int main02(void) {

	FILE* stream; 
	stream = fopen("data.txt","a"); // ������ ���� 
	if (stream == NULL) {
		printf("������ �������� ���߽��ϴ�.");
		return; 
	}

	// fgetc(), fputc() 
	// file get char(); �б� file put char() // ����
	// fputc('������',����������-��Ʈ��); 
	fputc('h', stream);
	fputc('e', stream);
	fputc('l', stream);
	fputc('l', stream);
	fputc('o', stream);
	fputc('~', stream);
	fclose(stream); // ������ �׻� close 

	stream = fopen("data.txt", "r");
	int tmp; 
	tmp = fgetc(stream);
	printf('%d',tmp); // ���ܹ߻� 
	fclose(stream);
	return 0;
}