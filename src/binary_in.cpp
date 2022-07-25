#include "binary_in.h"
#include <iostream>

using namespace std;

Binary_In::Binary_In(string file_name)
{
    Open(file_name);
}

bool Binary_In::Open(string file_name)
{
    input_file.open(file_name.c_str(), ios::binary | ios::in);
    if (!input_file.is_open())
    {
        cout << "Could not open file." << endl;
        return false;
    }
    Set_Buffer();
    return true;
}

void Binary_In::Close()
{
    input_file.close();
}

void Binary_In::Set_Buffer()
{
    char ch;
    input_file >> ch;
    buffer = ch;
    buffer_size = 8;
    bits_retrieved += 8;
}

int Binary_In::Decode_Length()
{
    int data_length = 0;
    for (int i = 0; i < 4; i++)
    {
        char length_in_char_buffer = Get_Char();
        data_length <<= 8;
        data_length |= length_in_char_buffer;
    }
    return data_length;
}

char Binary_In::Get_Char()
{
    if (buffer_size == 8)
    {
        char get_char = buffer;
        Set_Buffer();
        return get_char;
    }
    char get_char = buffer;
    get_char <<= (8 - buffer_size);
    int curr_buffer_size = buffer_size;
    Set_Buffer();
    buffer_size = curr_buffer_size;

    unsigned char bit_mask = static_cast<unsigned char>(buffer);
    get_char |= (bit_mask >> buffer_size);

    return get_char;
}

bool Binary_In::Get_Bit()
{
    bits_retrieved++;
    buffer_size--;
    bool bit = ((buffer >> buffer_size) & 1) == 1;
    if (buffer_size == 0)
        Set_Buffer();
    return bit;
}

int Binary_In::Get_Bits_In()
{
    return bits_retrieved;
}

string Binary_In::Get_Bit_Stream_In()
{
    return bit_stream;
}

/*
To read our binary output as 0 & 1 use
xxd -b <filename> | head
or
xxd -b <filename> | tail
*/