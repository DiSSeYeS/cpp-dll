// SysProg2705_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    HMODULE hDll;
    void (*func)(string, char);

    hDll = LoadLibrary("C:/Users/217104/source/repos/SysProg_Dll1/Debug/SysProg_Dll1.dll");
    if (!hDll) {
        cerr << "Load library failed" << endl;
        return GetLastError();
    }

    func = (void(*)(string, char))GetProcAddress(hDll, "func");

    func("C:/Users/217104/source/repos/SysProg2705_2/textfile.txt", 'd');

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
