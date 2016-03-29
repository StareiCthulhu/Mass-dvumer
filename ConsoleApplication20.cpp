// ConsoleApplication20.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 5;

void scanArr(int arr[][5], int m);
void scanArr(int arr[][N], int m);  // здесь должна быть глобальная константа
void arrPrint(int arr[][5], int m);
int column(int arr[][5], int m);
int line(int arr[][5], int m);

int main() {
	setlocale(LC_ALL, "rus");
	const int m = 3;
	const int n = 5;	
	int arr[m][n];
	scanArr(arr, m);
	arrPrint(arr, m);
	printf_s("Êîëè÷åñòâî ñòîëáöîâ ñ íóëåâûìè ýëåìåíòàìè, ðàâíûìè íóëþ - %i", column(arr, m));
	printf_s("\n"); 
	printf_s("Ñòðîêà ñ ñàìîé äëèííîé ñåðèåé ýëåìåíòîâ - %i", line(arr, m));
	int z;
	scanf_s("%i", &z);


	return 0;
}
void scanArr(int arr[][5], int m)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) {
			printf_s("Ââåäèòå %i %i ýëåìåíò", i, j);
			scanf_s("%i", &arr[i][j]);
		}
			
	}
}

void arrPrint(int arr[][5], int m) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) {
			printf_s("%3i", arr[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
}

int column(int arr[][5], int m) {
	int s = 0;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < m; i++) {
			if (arr[i][j] == 0) {
				s++; break;
			}
		}
	}
	return(s);
}

int line(int arr[][5], int m) {
	int l = 0; int c = 0; int d;
	for (int i = 0; i < m; i++) {
		int b = 0;
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == arr[i][j + 1])l++;
			else {
				if (l > b) {
					b = l; l = 0;
				}
			}
		}
		if (l > b) {
			b = l; l = 0;
		}
		if (b > c) {
			c = b; d = i;
		}
	}
	return(d);
}
