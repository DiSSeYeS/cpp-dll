// SysProg2705_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

BOOL WINAPI DllMain(HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved) {

	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) int count = 0;
extern "C" __declspec(dllexport) void func(string filename, char chr) {
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cout << "error while opening" << endl;
		return;
	}

	ofstream outputFile("C:/Users/217104/source/repos/SysProg2705_2/temp.txt");
	if (!outputFile.is_open()) {
		cout << "error while creating tempfile" << endl;
		return;
	}

	string line;
	while (getline(inputFile, line)) {
		line.erase(remove(line.begin(),
			line.end(), chr), line.end());

		outputFile << line << endl;
	}

	inputFile.close();
	outputFile.close();

	remove(filename.c_str());

	rename("C:/Users/217104/source/repos/SysProg2705_2/temp.txt", filename.c_str());
	cout << "succes" << endl;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
