#include <stdio.h>
#include "ReplacementOfWebCrawling.h"
#include "Node.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)



/*
ICN 인천 공항 (한국 )
CJU 제주 공항 (한국 )

AER 소치 공항 ( 러시아 )
KZN 카잔 공항 ( 러시아 )
CEK 첼랴빈스크 공항 (러시아 )
EGO 벨고르트 공항 (러시아 )

JGN 지아유관 공항 ( 중국 )
KHN 난창 공항 ( 중국 )
PEK 베이징 공항 (중국 )

JFK 나이아가라폴스 국제공항 ( 미국 )
LAX LA 공항 ( 미국 )
BNA 내슈빌 공항 (미국 )
DTW 디트로이트 공항 ( 미국 )
MIA 마이애미 공항 (미국 )
PHX 피딕스 공항 (미국)

CDG 샤를드골 공항 ( 프랑스 )
NCE 니스 공항 ( 프랑스 )
ORY 오를리 공항 ( 프랑스 )

NRT 나리타 국제 공항 ( 일본 )
NGO 주부 국제 공항 (일본)
KIX 간사이 국제 공항 (일본)
FUK 후쿠오카 국제 공항 (일본)

MUC 뭔헨 국제 공항 (독일)
FRA 프랑크푸르트 국제 공항 (독일 )
DUS 뒤셀 도르프 공항 ( 독일 )


LHR 히로스 공항 (영국)
BFS 벨파스트 국제 공항 (영국 )
GLA 글래스고 국제 공항 ( 영국 )
STN 스탠스테드 공항 ( 영국 )


YYC 캘거리 국제 공항 ( 캐나다 )
YHZ 핼리팩스 국제 공항 (캐나다 )
YUL 몬트리올 국제 공항 ( 캐나다 )
YOW 오타와 공항 ( 캐나다 )
YVR 벤쿠버 공항 (캐나다 )

DEL 인디라 공항 ( 인도 )
BOM 차트라파티 공항 (인도 )
AMD 아메다바드 공항 (인도)
BBI 파트나익 국제 공항 (인도 )
BDQ 바도다라 공항 (인도 )

AKL 오를랜드 공항 ( 뉴질랜드 )
OOL 골드코스트 공항 (뉴질랜드 )

KUL 쿠알라룸프 국제 공항 ( 말레이시아 )
BKI 코타키나발루 국제 공항 (말레이시아 )

FCO 피우미치노 공항 (이탈리아 )
PSA 피사 국제 공항 ( 이탈리아 )

ARN 스톰홀름 공항 (스웨덴)
GOT 예테보리 공항 (스웨덴)

총 47개의 공항임

*/




int getIndex(char * str) {

	int i;

	static char air[AIRNUM][4] = { { "ICN" },{ "CJU" } ,{ "AER" },{ "KZN" },{ "CEK" },{ "EGO" },{ "JGN" },{ "KHN" },{ "PEK" },{ "JFK" },{ "LAX" },{ "BNA" },{ "DTW" },{ "MIA" },{ "PHX" },{ "CDG" },{ "NCE" },{ "ORY" },{ "NRT" }
		,{ "NGO" },{ "KIX" },{ "FUK" },{ "MUC" },{ "FRA" },{ "DUS" },{ "LHR" },{ "BFS" },{ "GLA" },{ "STN" },{ "YYC" },{ "YHZ" },{ "YUL" },{ "YOW" },{ "YVR" },{ "DEL" },{ "BOM" },{ "AMD" },{ "BBI" },{ "BDQ" },{ "AKL" }
	,{ "OOL" },{ "KUL" },{ "BKI" },{ "FCO" },{ "PSA" },{ "ARN" },{ "GOT" } };

	/*
	0 : 한국에 있는 공항
	1 : 러시아에 있는 공항
	2 : 중국에 있는 공항
	3 : 미국에 있는 공항
	4 : 프랑스에 있는 공항
	5 : 일본에 있는 공항
	6 : 독일에 있는 공항
	7 : 영국에 있는 공항
	8 : 캐나다에 있는 공항
	9 : 인도에 있는 공항
	10 : 뉴질랜드에 있는 공항
	11 : 말레이시아에 있는 공항
	12 : 이탈리아에 있는 공항
	13 : 스웨덴에 있는 공항
	*/

	for (i = 0; i < AIRNUM; i++) {

		if (strncmp(str, air[i], 3) == 0 && i < 2)
			return 0;
		else if (strncmp(str, air[i], 3) == 0 && i < 6)
			return 1;
		else if (strncmp(str, air[i], 3) == 0 && i < 9)
			return 2;
		else if (strncmp(str, air[i], 3) == 0 && i < 15)
			return 3;
		else if (strncmp(str, air[i], 3) == 0 && i < 18)
			return 4;
		else if (strncmp(str, air[i], 3) == 0 && i < 22)
			return 5;
		else if (strncmp(str, air[i], 3) == 0 && i < 25)
			return 6;
		else if (strncmp(str, air[i], 3) == 0 && i < 29)
			return 7;
		else if (strncmp(str, air[i], 3) == 0 && i < 34)
			return 8;
		else if (strncmp(str, air[i], 3) == 0 && i < 39)
			return 9;
		else if (strncmp(str, air[i], 3) == 0 && i < 41)
			return 10;
		else if (strncmp(str, air[i], 3) == 0 && i < 43)
			return 11;
		else if (strncmp(str, air[i], 3) == 0 && i < 45)
			return 12;
		else if (strncmp(str, air[i], 3) == 0 && i < 47)
			return 13;
	}

	return -1;  //알 수 없는 공항 
}




int getRandom(int type) {                // type 0 : 시간 , type 1: 비용

	int result = 0;

	if (type == 0) {     // 시간의 랜덤벨류를 원한다

		result = rand() % 1440;  // 시간은 0:0분 ~ 1440분까지
	}
	else {                 //비용의 랜덤 벨류를 원한다.

		result = rand();
	}


	if (result == 0)        // 시간 혹은 비용이 0인 케이스는 제외한다
		result += 1;

	return result;
}


int extraction(FILE * fp) {            //파일 추출 성공 : TRUE , 추출 실패 : FALSE 반환한다. , type은 사용자가 결정한 type


	char str[100];
	FILE * n_fp = fopen("result.txt", "wt");
	long num;
    int j;
	long i;
	char * ptr;
	char * temp;
	int temp_idx;
	int result;
	int index;

	if (n_fp == NULL) {
		printf("Wrong Input!\n");
		return FALSE;
	}

	srand(time(NULL));
	num = 60000;
	j = rand() % 7;

	for (i = 0; i < num; i++) {

		if (i%j == 0)
			continue;

		fscanf(fp, "%s", str);
		if (strlen(str) < 30)
			continue;

		ptr = strtok(str, ",");

		ptr = strtok(NULL, ",");
		ptr = strtok(NULL, ",");

		index = getIndex(ptr);

		if (index == -1)
			continue;

		temp = ptr;
		temp_idx = index;

		ptr = strtok(NULL, ",");
		ptr = strtok(NULL, ",");

		index = getIndex(ptr);

		if (index == -1)
			continue;

			fprintf(n_fp, "%s %d ", temp, temp_idx);

			fprintf(n_fp, "%s ", ptr);
			fprintf(n_fp, "%d ", index);
			result = getRandom(0);
			fprintf(n_fp, "%d ", result);
			result = getRandom(1);
			fprintf(n_fp, "%d ", result);
			fprintf(n_fp, "\n");
		


	}
	fclose(fp);
	fclose(n_fp);
	return TRUE;
}