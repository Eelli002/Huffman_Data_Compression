#include "../../huffman.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    Huffman huffman_test;
    string data;
    string input_buffer;
    ifstream data_input;

    cout << "Compressing File:" << endl;
    
    data_input.open("Huffman_Test/Transcript.txt");

    if (!data_input.is_open())
    {
        cout << "Error opening file";
        return 1;
    }


    while (!data_input.eof())
    {
        // data_input.unsetf(std::ios::skipws);
        data_input >> input_buffer;
        data += input_buffer;
    }

    cout << "Data Length Pre Compression (bits): " << data.length() * 8 << endl;

    huffman_test.Encode(data, "Compressed.bin");

    string decompressed_data = huffman_test.Decode("Compressed.bin");
    cout << "Data Length: " << decompressed_data.length() << endl;
    cout << endl << decompressed_data << endl;

    return 0;
}