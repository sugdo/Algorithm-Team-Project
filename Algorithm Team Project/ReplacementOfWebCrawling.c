#include <stdio.h>
#include "ReplacementOfWebCrawling.h"
#include "Node.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)



/*
ICN ��õ ���� (�ѱ� )
CJU ���� ���� (�ѱ� )

AER ��ġ ���� ( ���þ� )
KZN ī�� ���� ( ���þ� )
CEK ÿ����ũ ���� (���þ� )
EGO ����Ʈ ���� (���þ� )

JGN �������� ���� ( �߱� )
KHN ��â ���� ( �߱� )
PEK ����¡ ���� (�߱� )

JFK ���̾ư������� �������� ( �̱� )
LAX LA ���� ( �̱� )
BNA ������ ���� (�̱� )
DTW ��Ʈ����Ʈ ���� ( �̱� )
MIA ���ֹ̾� ���� (�̱� )
PHX �ǵ� ���� (�̱�)

CDG ������� ���� ( ������ )
NCE �Ͻ� ���� ( ������ )
ORY ������ ���� ( ������ )

NRT ����Ÿ ���� ���� ( �Ϻ� )
NGO �ֺ� ���� ���� (�Ϻ�)
KIX ������ ���� ���� (�Ϻ�)
FUK �����ī ���� ���� (�Ϻ�)

MUC ���� ���� ���� (����)
FRA ����ũǪ��Ʈ ���� ���� (���� )
DUS �ڼ� ������ ���� ( ���� )


LHR ���ν� ���� (����)
BFS ���Ľ�Ʈ ���� ���� (���� )
GLA �۷����� ���� ���� ( ���� )
STN ���Ľ��׵� ���� ( ���� )


YYC Ķ�Ÿ� ���� ���� ( ĳ���� )
YHZ �۸��ѽ� ���� ���� (ĳ���� )
YUL ��Ʈ���� ���� ���� ( ĳ���� )
YOW ��Ÿ�� ���� ( ĳ���� )
YVR ����� ���� (ĳ���� )

DEL �ε�� ���� ( �ε� )
BOM ��Ʈ����Ƽ ���� (�ε� )
AMD �Ƹ޴ٹٵ� ���� (�ε�)
BBI ��Ʈ���� ���� ���� (�ε� )
BDQ �ٵ��ٶ� ���� (�ε� )

AKL �������� ���� ( �������� )
OOL ����ڽ�Ʈ ���� (�������� )

KUL ��˶���� ���� ���� ( �����̽þ� )
BKI ��ŸŰ���߷� ���� ���� (�����̽þ� )

FCO �ǿ��ġ�� ���� (��Ż���� )
PSA �ǻ� ���� ���� ( ��Ż���� )

ARN ����Ȧ�� ���� (������)
GOT ���׺��� ���� (������)

�� 47���� ������

*/




int getIndex(char * str) {

	int i;

	static char air[AIRNUM][4] = { { "ICN" },{ "CJU" } ,{ "AER" },{ "KZN" },{ "CEK" },{ "EGO" },{ "JGN" },{ "KHN" },{ "PEK" },{ "JFK" },{ "LAX" },{ "BNA" },{ "DTW" },{ "MIA" },{ "PHX" },{ "CDG" },{ "NCE" },{ "ORY" },{ "NRT" }
		,{ "NGO" },{ "KIX" },{ "FUK" },{ "MUC" },{ "FRA" },{ "DUS" },{ "LHR" },{ "BFS" },{ "GLA" },{ "STN" },{ "YYC" },{ "YHZ" },{ "YUL" },{ "YOW" },{ "YVR" },{ "DEL" },{ "BOM" },{ "AMD" },{ "BBI" },{ "BDQ" },{ "AKL" }
	,{ "OOL" },{ "KUL" },{ "BKI" },{ "FCO" },{ "PSA" },{ "ARN" },{ "GOT" } };

	/*
	0 : �ѱ��� �ִ� ����
	1 : ���þƿ� �ִ� ����
	2 : �߱��� �ִ� ����
	3 : �̱��� �ִ� ����
	4 : �������� �ִ� ����
	5 : �Ϻ��� �ִ� ����
	6 : ���Ͽ� �ִ� ����
	7 : ������ �ִ� ����
	8 : ĳ���ٿ� �ִ� ����
	9 : �ε��� �ִ� ����
	10 : �������忡 �ִ� ����
	11 : �����̽þƿ� �ִ� ����
	12 : ��Ż���ƿ� �ִ� ����
	13 : �������� �ִ� ����
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

	return -1;  //�� �� ���� ���� 
}




int getRandom(int type) {                // type 0 : �ð� , type 1: ���

	int result = 0;

	if (type == 0) {     // �ð��� ���������� ���Ѵ�

		result = rand() % 1440;  // �ð��� 0:0�� ~ 1440�б���
	}
	else {                 //����� ���� ������ ���Ѵ�.

		result = rand();
	}


	if (result == 0)        // �ð� Ȥ�� ����� 0�� ���̽��� �����Ѵ�
		result += 1;

	return result;
}


int extraction(FILE * fp) {            //���� ���� ���� : TRUE , ���� ���� : FALSE ��ȯ�Ѵ�. , type�� ����ڰ� ������ type


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