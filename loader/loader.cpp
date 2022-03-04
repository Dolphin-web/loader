#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <urlmon.h> 
#include <algorithm>


#pragma comment (lib, "urlmon.lib") 

using namespace std;

void Remove(char charRemove, std::string& string) {
    auto it = std::remove_if(std::begin(string), std::end(string),
        [=](char c) { return c == charRemove; });
    string.erase(it, std::end(string));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true) {
        string appdata = getenv("APPDATA");
        string urlDown;
        cin >> urlDown;
        string urlDownFile = urlDown;
        Remove(':', urlDownFile); Remove('/', urlDownFile);
        appdata += "\\";
        appdata += urlDownFile.c_str();

        HRESULT hr = URLDownloadToFileA(NULL, urlDown.c_str(), appdata.c_str(), 0, 0);
        if (hr == S_OK)
        {

            cout << "Файл скачан, открытие\n";
            cout << "Путь: " + appdata << endl;
            ShellExecuteA(NULL, "open", appdata.c_str(), NULL, NULL, SW_HIDE); // открываем его
        }
        else {
            cout << "Файл не скачан\n\n";
        }
    }
}



