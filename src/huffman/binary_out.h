#ifndef _BINARY_OUT_H
#define _BINARY_OUT_H

#include <fstream>

using namespace std;

class Binary_Out
{
    private:
        char buffer;
        int buffer_size;
        ofstream output_file;
        void Clear_Buffer();
        void Flush();
        int bits_out = 0;

    public:
        string bit_stream = "";
        Binary_Out(string fileName);
        void Open(string fileName);
        void Write_Bit(bool bit);
        void Write_Char(char ch);
        void Write_Length(int i);
        void Close();

        int Get_Bits_Out();
        void Char_To_Bit_Stream(char ch);

        string Get_Bit_Stream();
};

#endif