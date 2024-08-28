// Tetris_cmd.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is a project made to practice C++ with github.

#include <iostream>
#include <vector>
#include <thread>
#include <windows.h>

using namespace std;

wstring tetris_shapes[7];// array to save tetris shapes
// screen and field width and hight
int screenWidth = 80;
int screenHeight = 30;
int FieldWidth = 12;
int FieldHeight = 18;

unsigned char* pField = nullptr; // pointer to elements of field in unsinged char array, that will be allocated dynamically
 
int main()
{
    // append tetris shapes
    tetris_shapes[0].append(L"..X...X...X...X.");
    tetris_shapes[1].append(L"..X..XX...X.....");
    tetris_shapes[2].append(L".....XX..XX.....");
    tetris_shapes[3].append(L"..X..XX..X......");
    tetris_shapes[4].append(L".X...XX...X.....");
    tetris_shapes[5].append(L".X...X...XX.....");
    tetris_shapes[6].append(L"..X...X..XX.....");

    // calculate screen and Field size
    int screenSize = screenWidth * screenHeight;
    int FieldSize = FieldWidth * FieldHeight;
    // Create screen Buffer
    wchar_t* screen = new wchar_t[screenSize];
    for (int i = 0; i < screenSize; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    //Creating play Field Buffer
    pField = new unsigned char[FieldSize]; 
    //Board Boundary setup 
    for (int x = 0; x < FieldWidth;x++) {
        for (int y = 0; y < FieldHeight;y++) {
            pField[y * FieldWidth + x] = ( (x == 0) || (x == FieldWidth - 1) || (y == FieldHeight - 1)) ? 9 : 0;
            // in this setup, boundry is 9 , empty is 0;
        }
    }

}

