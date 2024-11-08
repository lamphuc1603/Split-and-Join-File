#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"JoinFile.h"

using namespace std;


int main()
{
    long long n;
    char i, j;
    cout<<"Number of File to join:";
    cin >> n;
    char name[1024];
    char type[50];
    cout << "Input File name:";
    string s;
    cin.ignore();
    getline(cin, s);
    char k = 92;
    
    int a;
    
    while (s.find(k) != -1) {
        int t = s.find(k);
        s.erase(s.find(k), 1);
        s.insert(t, "//");
    }
    for (a = 0; a < s.size(); a++) {
        if (s[a] == '/') s[a] = 92;
    }
    s.erase(0, 1);
    s.erase(s.size() - 1, 1);
    for (a = 0; a < s.size(); a++)
    {
        name[a] = s[a];
    }
    name[a] = '\0';
    cout << "Input File type (mp4,txt,png,...):";
    cin >> type;
    char na[50] = { 'J','o','i','n','.' };
    for ( i = 0; na[i] != '\0'; ++i);
    for (j = 0; type[j] != '\0'; ++j, ++i)
    {
        na[i] = type[j];
    }
    na[i] = '\0';
    join(na, n, type, name);
    cout << "Done!";
    return 0;
}