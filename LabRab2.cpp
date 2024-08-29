#include <iostream>
#include <windows.h>

using namespace std;
int n1 = 0;
int n2 = 0;
int n3 = 0;

void thread1() {
	while (true) {n1++; Sleep(1);}
}

void thread2() {
	while (true) {n2++; Sleep(10);}
}

void thread3() {
	while (true) {n3++; Sleep(100);}
}

HANDLE hTh1, hTh2, hTh3;

int main() {

	setlocale(LC_ALL, "Russian");

	DWORD IDTh1;
	char ch;
	hTh1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)
		thread1, NULL, 0, &IDTh1);
	if (hTh1 == NULL) return GetLastError();
	
	DWORD IDTh2;
	hTh2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)
		thread2, NULL, 0, &IDTh2);
	if (hTh2 == NULL) return GetLastError();
	
	DWORD IDTh3;
	hTh3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)
		thread3, NULL, 0, &IDTh3);
	if (hTh3 == NULL) return GetLastError();

	do {
		cin >> ch;
		switch (ch) {
		case 'v': 
			if ((n1 > n2) && (n1 > n3))
				cout << " Номер потока 1 " << n1 << ' ' << n2 << ' ' << n3 << endl;
			else if ((n2 > n1) && (n2 > n3))
				cout << " Номер потока 2 " << n1 << ' ' << n2 << ' ' << n3 << endl;
			else if ((n3 > n1) && (n3 > n2))
				cout << " Номер потока 3 " << n1 << ' ' << n2 << ' ' << n3 << endl;
		}
	} while (ch != 'q');

	CloseHandle(hTh1);
	CloseHandle(hTh2);
	CloseHandle(hTh3);
}
