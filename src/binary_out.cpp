#include "binary_out.h"
#include <iostream>
#include <bitset>

using namespace std;

Binary_Out::Binary_Out(string fileName)
{
    Open(fileName);
}


void Binary_Out::Open(string fileName)
{
    output_file.open(fileName.c_str(), ios::binary | ios::out);
    if (!output_file.is_open())
    {
        cout << "Could not open file: " << fileName << endl;
        return;
    }
}


void Binary_Out::Clear_Buffer()
{
    if (buffer_size == 0) return;
    if (buffer_size > 0) buffer <<= (8 - buffer_size);
    output_file << buffer;
    buffer_size = 0;
    buffer = 0;
}


void Binary_Out::Write_Bit(bool bit)
{
    if (bit) bit_stream += '1';
    else bit_stream += '0';

    bits_out++;
    buffer <<= 1;
    if (bit) buffer |= 1;
    buffer_size++;
    if (buffer_size == 8) Clear_Buffer();
}


void Binary_Out::Write_Char(char ch)
{
    if (buffer_size == 0)
    {
        Char_To_Bit_Stream(ch);
        bits_out += 8;
        output_file << ch;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        bool bit = ((ch >> (8 - i - 1)) & 1) == 1;
        Write_Bit(bit);
    }
}


void Binary_Out::Write_Length(int i)
{
    Write_Char((i >> 24) & 0xff);
    Write_Char((i >> 16) & 0xff);
    Write_Char((i >> 8) & 0xff);
    Write_Char((i >> 0) & 0xff);
}


void Binary_Out::Char_To_Bit_Stream(char ch)
{
    for (int i = 7; i >= 0; --i) 
        (ch & (1 << i)) ? bit_stream += '1' : bit_stream += '0';
    return;
}
int Binary_Out::Get_Bits_Out()
{
    return bits_out;
}


string Binary_Out::Get_Bit_Stream()
{
    return bit_stream;
}


void Binary_Out::Flush()
{
    Clear_Buffer();
    output_file.flush();
}


void Binary_Out::Close()
{
    Flush();
    output_file.close();
}