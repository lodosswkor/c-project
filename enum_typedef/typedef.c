#include <stdio.h>

// typedef  
// typedef 기본자료형(int,char,struct,enum,union....) 내가 쓸 자료형 이름(Alias)  
typedef int AGE; // int AGE  
typedef char* NAME; // char* NAME
typedef enum _week { S, M, T, W, TH, F, Sat } WEEK; // 열거형 사용자 정의 데이터타입 
typedef struct _student {
	int hakno;
	char * name; 
} STUDENT;

int main(void) {

	AGE age = 20; // AGE 데이터 타입 
	NAME name = "이종석"; // NAME 데이터 타입 
	WEEK w = S;
	STUDENT std;

	std.hakno = 10000;
	std.name = "이종석";
	
	return 0;
}