/*
 * define.cpp
 *
 *  Created on: 2017年9月30日
 *      Author: juliana
 */
#include <stdio.h>

void define_3() {
#define LIMIT 20
}
void define_5() {
	const int LIM = 50;
	static int data1[LIMIT];
	static int data2[LIM];
	const int LIM1 = 2 * LIMIT;
	const int LIM2 = 2 * LIM;
	printf("%d\n", LIM2);
	printf("%d\n", LIM1);
}

#define PTV(x) printf("The square of " #x " is %d.\n", ((x)*(x)));
void define_6(){
	int z = 300;
	PTV(z);
	PTV(5+3);
	printf("%s\n","end "" end"" end");
}
