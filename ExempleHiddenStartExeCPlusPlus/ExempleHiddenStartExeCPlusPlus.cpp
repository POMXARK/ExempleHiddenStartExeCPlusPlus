// ExempleHiddenStartExeCPlusPlus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h> 
#include <stdio.h> 

int main()
{
    HINSTANCE load;
    load = LoadLibrary(L"HiddenStartExe.dll");
    typedef void (*hidden_start) (const char*);
    hidden_start HiddenStart;
    HiddenStart = (hidden_start)GetProcAddress(load, "HiddenStart");
    const char*  prog_name = "main.exe";
    HiddenStart(prog_name);
    std::cout << "Hello World!\n";
    FreeLibrary(load);
}

