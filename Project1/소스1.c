#include<stdio.h>
#pragma warning(disable : 4996)
void f(int n) {
	if (n > 1) f(n / 2);
	printf("%d", n % 2);
}
int main() {
	unsigned fpid, lpid, sid, root, pxor, ftid, tid, ltid, txor, shiny;
	unsigned ec, pid;
	int hp, atk, def, spa, spd, spe, height, weight, scale;
	char tera[10], nature[10];
	printf("sid를 입력해 주세요\n");
	scanf("%d", &sid);
	printf("tid를 입력해 주세요\n");
	scanf("%d", &tid);
	root = sid * 1000000 + tid;
	printf("%d\n", root);
	printf("당신의 번호는 %x 입니다\n", root);
	ftid = root / 65536;
	ltid = root % 65536;
	printf("당신의 럭키번호 ");
	txor = ftid ^ ltid;
	f(txor);
	printf("\n");

	FILE* fp;
	fp = fopen("asdf.txt", "r");
	if (fp == NULL)
	{
		printf("개버그");
		return(1);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%*x %*s %*s %x %x %s %d %d %d %d %d %d %*s %s %*s %d %d %d %*d",
			&ec, &pid, tera, &hp, &atk, &def, &spa, &spd, &spe, nature, &height, &weight, &scale);
		fpid = pid / 65536;
		lpid = pid % 65536;
		pxor = fpid ^ lpid;
		shiny = pxor ^ txor;
		if (0 <= shiny && shiny <= 15) {
			printf("\n");
			if (0 == shiny)printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
			printf("%08X\n", pid);
			if (0 == shiny)printf("%X = %X\n", pxor, txor);
			printf("%08X %s %d %d %d %d %d %d %s %d %d %d\n", ec, nature, hp, atk, def, spa, spd, spe, tera, height, weight, scale);
			if (0 == shiny)printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
		}
	}
}