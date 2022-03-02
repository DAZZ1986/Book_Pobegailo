#include <windows.h>
#include <iostream>
using namespace std;

/*
// 3.2. Создание потока
volatile int n;

DWORD WINAPI Add(LPVOID iNum)
{
    cout << "Thread is started." << endl;
    n += (int)iNum;
    cout << "Thread is started." << endl;

    return 0;
}
*/



// 3.3. Завершение потока
volatile UINT count;

void thread()
{
    for(;;)
    {
        ++count;
        Sleep(100); //немного отдохнем
    }
}


int main()
{   /*
    // 3.2. Создание потока
    int inc = 10;
    HANDLE hThread;
    DWORD IDThread;

    cout << "n = " << n << endl;

    //запускаем поток
    hThread = CreateThread(NULL, 0, Add, (void*)inc, 0, &IDThread);     //ЖЕНЯ - синтаксис 3 параметра (стр. 44)
    if (hThread == NULL)
        return GetLastError();

    //ждем пока поток Add закончит работу 
    WaitForSingleObject(hThread, INFINITE);

    //закрываем поток
    CloseHandle(hThread);

    cout << "n = " << n << endl;
    */




    // https://www.programmersforum.ru/showthread.php?t=219422
    // 3.3. Завершение потока
    HANDLE hThread;
    DWORD IDThread;
    char c;

    hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread, NULL, 0, &IDThread);

    if (hThread == NULL)
        return GetLastError();

    for (;;)
    {
        std::cout << "Input 'y' to display the count or any char to finish: ";
        cin >> c;
        if (c == 'y')
            cout << "count = " << count << endl;
        else
            break;
    }

    //прерываем выполнение потока thread 
    TerminateThread(hThread, 0);

    //закрываем дескриптор потока
    CloseHandle(hThread);










    return 0;
}
