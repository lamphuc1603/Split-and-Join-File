#include"JoinFile.h"
void join(const char* name, const long number_of_part, const char* file_type, const char* h)
{
    char s[1024];
    strcpy_s(s, h);
    int i, a;
    int n = 0;
    a = strlen(s);
    for (i = a - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            s[i] = '\0';

            break;
        }
    }
    ofstream ofile(name, ios::binary | ios::out);
    for (int i = 1; i <= number_of_part; i++)
    {
        ifstream ifile(s + to_string(i) + "." + file_type, ios::binary | ios::in);


        if (ifile.good() && ofile.good()) {

            ofile << ifile.rdbuf();
        }

        ifile.close();

    }
    ofile.close();
}
