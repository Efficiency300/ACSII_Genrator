
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include<windows.h>
#include<mmsystem.h>
#include <sstream>
#pragma comment(lib, "winmm.lib")

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;
string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}
void draw(int frame) {
    setCursorPosition(0, 0);
    std::string m = readFileIntoString("texts/frame" + std::to_string(frame));
    std::cout << m;
}
int main()
{
    HWND console = GetConsoleWindow();
    MoveWindow(console, 0, 0, 20000, 20000, TRUE);
    std::cin.ignore();
    draw(1);
    std::cin.ignore();
    system("cls");
    std::cin.ignore();
    auto start = std::chrono::steady_clock::now();
    PlaySound(L"song.wav", NULL, SND_ASYNC);
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
    while (elapsed.count() < 212000) {
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
        draw(elapsed.count() / 40);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
