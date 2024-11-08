#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cmath>
#include "SplitFile.h"

using namespace std;

int main()
{
    char* fname = new char[1024];
    system("cls");
    cout << "\n[+] File Splitter" << endl
        << "<1> Specify file location: " << endl
        << "    -> ";
    cin.getline(fname, 1024);

    ifstream file(fname, ios::in);
    if (!file) {
        cout << "<!> Error: File doesn't exist. " << endl;
        return -1;
    }
    else {
        long fsize = fileSize(fname);
        char ftype[4];
        cout << "Type of File (txt, png, mp4,...):";
        cin >> ftype;
        cout << "<2> Size per part (in bytes): " << endl
            << "    -> ";
        long size;
        cin >> size;
        int n = (int)ceil((double)fsize / size);
        if (size <= 0 || size >= fsize) {
            cout << "<!> Error: Size invalid. " << endl;
            return -1;
        }
        else {
            cout << "[~] Start splitting files ... " << endl;
            split(fname, size, n, ftype);
            cout << "[!] Done splitting ! " << endl;
        }
    }
    return 0;
}