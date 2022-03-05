#include <windows.h>
#include <iostream>
#include <conio.h>
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
/*
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
*/
/*
//3.4. Приостановка и возобновление потоков
volatile UINT nCount;
volatile DWORD dwCount;

void thread()
{
    for (;;)
    {   
        nCount++;
        Sleep(100); //приостанавливаем поток на 100 миллисекунд
    }
}
*/
/*
//3.6. Функция для вывода сообщения об ошибке в MessageBox
void ErrorMessageBox()
{
    LPVOID IpMsgBuf;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        GetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  //язык по умолчанию
        (LPTSTR) &IpMsgBuf,
        0,
        NULL
    );

    //показать ошибку в MessageBox
    MessageBox(
        NULL,
        (LPCTSTR) IpMsgBuf,
        "Ошибка Win32 API",
        MB_OK | MB_ICONINFORMATION
    );

    //освободить буффер
    LocalFree(IpMsgBuf);
}
*/

/*
//3.8. Пример перекодировки русских букв для вывода на консоль
BOOL CharToOem(
    LPCTSTR IpszSrc,    //сторока для перекодировки
    LPSTR IpszDst       //перекодированная строка
);
*/

/*
//3.9. Функция для вывода сообщения об ошибке на консоль на русском языке
void()
{
    char prefix[] = "Ошибка в Win32 API";
    LPVOID IpMsgBuf;

    CharToOem(prefix, prefix);  //перекодируем заголовок

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        GetLastError(),
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  //язык по умолчанию
        (LPTSTR)&IpMsgBuf,
        0,
        NULL
    );

    //перекодируем русские буквы
    CharToOem((char*)IpMsgBuf, (char*)IpMsgBuf);

    //выводим сообщение об ошибке на консоль
    cout << prefix << (char*)IpMsgBuf << endl;

    //освобождаем буфер
    LocalFree(IpMsgBuf);
}
*/

/*
//3.10. Пример вывода сообщения об ошибке на консоль
//прототип функции
void CountErrorMessage();
*/





int main(int argc, char *argv[])
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



    /*
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
    */


    /*
    //3.4. Приостановка и возобновление потоков
    HANDLE hThread;
    DWORD IDThread;
    char c;

    hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread, NULL, 0, &IDThread);

    if (hThread == NULL)
        return GetLastError();

    for (;;)
    {
        cout << "Input: " << endl;
        cout << "\t'n' to exit " << endl;
        cout << "\t'y' to display the count " << endl;
        cout << "\t's' to suspend thread " << endl;
        cout << "\t'r' to resume thread " << endl;
        cin >> c;



        if (c == 'n')
            break;

        switch (c)
        {
        case 'y':
            cout << "count = " << nCount << endl;
            break;
        case 's':
            //приостанавливаем поток thread
            dwCount = SuspendThread(hThread);
            cout << "Thread suspend count = " << dwCount << endl;
            break;
        case 'r':
            //возобновляем поток thread
            dwCount = ResumeThread(hThread);
            cout << "Thread suspend count = " << dwCount << endl;
            break;
        }
    }

    TerminateThread(hThread, 0);    //прерываем выполнение потока thread

    CloseHandle(hThread);   //закрываем дескриптор потока thread
    */

    /*
    //3.5. Пример работы функции GetCurrentThread
    HANDLE hThread;                //создаем дескриптор
    hThread = GetCurrentThread();  //получаем псевдодескриптор текущего потока
    cout << hThread << endl;       //выводим псевдодескриптор на консоль
    */

    /*
    //3.6. Функция для вывода сообщения об ошибке в MessageBox
    HANDLE hThread;                //создаем дескриптор
    hThread = GetCurrentThread();  //получаем псевдодескриптор текущего потока
    cout << hThread << endl;       //выводим псевдодескриптор на консоль
    */

    /*
    //3.7. Пример вывода сообщения об ошибке в MessageBox
    HANDLE hHandle = NULL;

    //неправильный вызов функции закрытия дескриптора
    if (!CloseHandle(hHandle))
        ErrorMessageBox();
    */

    /*
    //3.8. Пример перекодировки русских букв для вывода на консоль
    char big[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    char sml[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    CharToOem(big,big);
    CharToOem(sml, sml);

    cout << big << endl;
    cout << sml << endl;
    */

    //3.9. Функция для вывода сообщения об ошибке на консоль на русском языке
    //код над функцией main

    /*
    //3.10. Пример вывода сообщения об ошибке на консоль
    HANDLE hHandle = NULL;
    //неправильный вызов функции закрытия дескриптора
    if (!CloseHandle(hHandle))
        CountErrorMessage();
    */



    /*
    //Листинг 4.1. Программа которая выводит на консоль свое имя и параметры.
    int i;

    _cputs("I'am created.");
    _cputs("\nMy name is: ");
    _cputs(argv[0]);

    for (i = 1; i < argc; ++i)
        _cprintf("\n My %d parametr = %s", i, argv[i]);

    _cputs("\nPress any key to finish.\n");
    _getch();
    */


    //Листинг 4.2. Программа процесса, который создает процесс с новой консолью
    wchar_t IpszAppName[] = L"C:\\Book_Pobegailo.exe";

    STARTUPINFO si;
    PROCESS_INFORMATION piApp;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    //создаем новый консольный процесс
    if (!CreateProcess(IpszAppName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
    {
        _cputs("The new process is not created.\n");
        _cputs("Check a name of the process.\n");
        _cputs("Press any key to finish.\n");
        _getch();
        return 0;
    }

    _cputs("The new process is created.\n");

    //ждем завершения созданного процесса
    WaitForSingleObject(piApp.hProcess, INFINITE);

    //закрываем дескрипторы этого процесса в текущем процессе
    CloseHandle(piApp.hThread);
    CloseHandle(piApp.hProcess);


    //стр 61





    return 0;
}
