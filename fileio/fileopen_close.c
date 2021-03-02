#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
// File IO ( File Input / Output ) 
// ex) printf - std Output ->출력을 어디에 하죠? (모니터) standard Output (stdout) 
// ex) scanf - std Input -> 입력을 뭘로 받죠? (키보드) Standard Input (stdin) 
// File IO 사람기준 
// 1. 탐색기를 연다 -> 2. 파일의 위치를 찾는다 -> 3. 파일을 연다 
// -> 4. 내용을 본다 -> 5.파일 닫는다 

// C언어 
// 파일열고/닫기 ( 1,2 -> 5 ) 
// fopen(), fclose();
// fopen("파일의 위치-파일Path", "읽을 방식") 
// fclose(파일 포인터);  

int main02(void) {

	FILE* stream; 
	stream = fopen("data.txt","a"); // 파일을 오픈 
	if (stream == NULL) {
		printf("파일을 오픈하지 못했습니다.");
		return; 
	}

	// fgetc(), fputc() 
	// file get char(); 읽기 file put char() // 쓰기
	// fputc('쓸문자',파일포인터-스트림); 
	fputc('h', stream);
	fputc('e', stream);
	fputc('l', stream);
	fputc('l', stream);
	fputc('o', stream);
	fputc('~', stream);
	fclose(stream); // 파일은 항상 close 

	stream = fopen("data.txt", "r");
	int tmp; 
	tmp = fgetc(stream);
	printf('%d',tmp); // 예외발생 
	fclose(stream);
	return 0;
}