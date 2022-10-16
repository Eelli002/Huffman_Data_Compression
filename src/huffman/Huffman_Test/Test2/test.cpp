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

    // data = "CS 100 is a course created to teach you one simple principle, “think twice, develop once”.";
    data = "eaa";

    cout << "Compressing File:" << endl;

    cout << "Data Length Pre Compression (bits): " << data.length() * 8 << endl;

    huffman_test.Encode(data, "Compressed.bin");

    string decompressed_data = huffman_test.Decode("Compressed.bin");
    cout << "Data Length: " << decompressed_data.length() << endl;
    cout << endl << decompressed_data << endl;

    return 0;
}