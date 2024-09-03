// SysProg2705_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    HMODULE hDll;
    int (*Add)(int);
    int (*Sub)(int);
    int* pCount;

    hDll = LoadLibrary("C:/Users/217104/source/repos/SysProg_Dll1/Debug/SysProg_Dll1.dll");
    if (!hDll) {
        cerr << "Load library failed" << endl;
        return GetLastError();
    }
    pCount = (int*)GetProcAddress(hDll, "count");
    if (!pCount) {
        cerr << "Get variable address failed." << endl;
        return GetLastError();
    }

    cout << "Initial count = " << (*pCount) << endl;

    Add = (int(*)(int))GetProcAddress(hDll, "Add");
    Sub = (int(*)(int))GetProcAddress(hDll, "Sub");

    if (!Add || !Sub) {
        cerr << "Get procedure address failed." << endl;
        return GetLastError();
    }

    cout << "count = " << Add(30) << endl;
    cout << "count = " << Sub(20) << endl;

    if (!FreeLibrary(hDll)) {
        cerr << "Free library failed." << endl;
        return GetLastError();
    }
    
    cout << "Press any key to exit";
    cin.get();
    return 0;
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
