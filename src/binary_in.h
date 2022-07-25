#ifndef _BINARY_IN_H
#define _BINARY_IN_H

#include <fstream>

using namespace std;

class Binary_In
{
    private:
        ifstream input_file;
        char buffer;
        int buffer_size;
        void Set_Buffer();
        // int bits_retrieved = 0;
        // string bit_stream = "";

    public:

        Binary_In();
        Binary_In(string file_name);
        bool Open(string file_name);
        void Close();
        int Decode_Length();
        char Get_Char();
        bool Get_Bit();

        int bits_retrieved = 0;
        string bit_stream = "";
        int Get_Bits_In();
        string Get_Bit_Stream_In();
};

#endif