#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <streambuf>
#include "huffman/huffman.h"
#include "huffman/Huffman_Test/googletest/googletest/include/gtest/gtest.h"

#include <iostream>
using namespace std;

TEST(File_IO_Tests, Correct_Data_Input)
{
    string fileName = "TestTextFile.txt";
    string data;
    string input_buffer;
    ifstream data_input;
    
    data_input.open(fileName);

    if (!data_input.is_open())
    {
        cout << "Error opening file";
    }


    while (!data_input.eof())
    {
        data_input >> input_buffer;
        data += input_buffer;
    }

    string fileContents = data;

    EXPECT_EQ(fileContents, "abcdefghijklmnopqrstuvwxyzabcdeabcdefgabcdefghabcdefghijk");
}

TEST(File_IO_Tests, BinaryOutput)
{
    string fileName = "CompressedText.bin";
    string data;
    string input_buffer;
    ifstream data_input;
    
    data_input.open(fileName);

    if (!data_input.is_open())
    {
        cout << "Error opening file";
    }


    while (!data_input.eof())
    {
        data_input >> input_buffer;
        data += input_buffer;
    }

    string fileContents = data;

    EXPECT_EQ(fileContents, "abcdefghijklmnopqrstuvwxyzabcdeabcdefgabcdefghabcdefghijk");
}

void IOTest()
{
    Huffman IO_Test;
    // string data;
    string data_file = "IO_Test_data.txt";
    string file_name = "IO_Test";
    ifstream data_input;


    ifstream t;
    t.open("../IO_Test_data.txt");
    if (!t.is_open())
    {
        cout << "Could not open file!\n";
    }
    stringstream buffer;
    buffer << t.rdbuf();

    string data = buffer.str();

    cout << "Data from file: " << data << "\n\n";

    IO_Test.Encode(data, file_name);

    string decoded_data = IO_Test.Decode(file_name);
    cout << "Decoded Data: " << decoded_data << "\n\n";

    return;
}