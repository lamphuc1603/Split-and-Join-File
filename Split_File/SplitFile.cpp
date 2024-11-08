#include "SplitFile.h"
streampos fileSize(const char* filePath) {

    streampos fsize = 0;
    ifstream file(filePath, ios::binary);

    fsize = file.tellg();
    file.seekg(0, ios::end);
    fsize = file.tellg() - fsize;
    file.close();

    return fsize;
}

void split(const char* file_name, const long size_per_part, const int number_of_part, const char* file_type)
{

    ifstream ifile(file_name, ios::binary | ios::in);

    for (int i = 1; i <= number_of_part; i++) {

        ofstream outfile("00" + to_string(i) + "." + file_type, ios::trunc | ios::binary | ios::out);

        if (outfile.good() && ifile.good())
        {

            char buffer[500000];
            memset(buffer, NULL, size_per_part);
            ifile.read(buffer, size_per_part);
            outfile.write(buffer, ifile.gcount());
        }
        outfile.close();

    }
    ifile.close();
}