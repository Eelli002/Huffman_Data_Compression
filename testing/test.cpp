#include "../src/huffman.h"
#include <gtest/gtest.h>
#include <iostream>


/*** Huffman Tree Creation Tests ***/
TEST(Build_Huffman_Tree, Get_Frequency_Map_Method)
{
    string data = "aeeiiioooouuuuu";
    map<char, int> frequency;
    Huffman frequency_test;
    frequency = frequency_test.Get_Frequency(data);

    EXPECT_EQ(frequency['a'], 1);
    EXPECT_EQ(frequency['e'], 2);
    EXPECT_EQ(frequency['i'], 3);
    EXPECT_EQ(frequency['o'], 4);
    EXPECT_EQ(frequency['u'], 5);
}

TEST(Build_Huffman_Tree, Get_Main_Tree)
{
    string data = "aeeiii";
    Huffman TreeTest;
    map<char, int> frequency = TreeTest.Get_Frequency(data);
    Huffman_Tree* TreeHead = TreeTest.Get_Main_Tree(frequency);
    
    EXPECT_EQ(TreeHead->weight, 6);
    EXPECT_EQ(TreeHead->left_child->weight, 3);
    EXPECT_EQ(TreeHead->right_child->weight, 3);
    EXPECT_EQ(TreeHead->right_child->key, 'i');
    EXPECT_EQ(TreeHead->left_child->left_child->key, 'a');
    EXPECT_EQ(TreeHead->left_child->left_child->weight, 1);
    EXPECT_EQ(TreeHead->left_child->right_child->key, 'e');
    EXPECT_EQ(TreeHead->left_child->right_child->weight, 2);
}

TEST(Build_Huffman_Tree, Get_Main_Tree_Single_Char)
{
    string data = "eeeeeeee";
    Huffman TreeTest;
    map<char, int> frequency = TreeTest.Get_Frequency(data);
    Huffman_Tree* TreeHead = TreeTest.Get_Main_Tree(frequency);
    EXPECT_EQ(TreeHead->key, 'e');
    // cout << "Tree weight: " << TreeHead->weight<< endl;
    // EXPECT_EQ(TreeHead->weight, 8);
    EXPECT_EQ(TreeHead->left_child, nullptr);
    EXPECT_EQ(TreeHead->right_child, nullptr);
    EXPECT_EQ(TreeHead->isLeaf(), true);
}

TEST(Build_Huffman_Tree, Is_Leaf_Test)
{
    string data = "aeeiii";
    Huffman TreeTest;
    map<char, int> frequency = TreeTest.Get_Frequency(data);
    Huffman_Tree* TreeHead = TreeTest.Get_Main_Tree(frequency);
    //EXPECT_EQ(TreeHead->isLeaf(), false);
    EXPECT_EQ(TreeHead->left_child->isLeaf(), false);
    EXPECT_EQ(TreeHead->right_child->isLeaf(), true);
    EXPECT_EQ(TreeHead->left_child->left_child->isLeaf(), true);
    EXPECT_EQ(TreeHead->left_child->right_child->isLeaf(), true);
}

TEST(Build_Huffman_Tree, Build_Dictionary_Method)
{
    string data = "aeeiiioooouuuuu";
    Huffman TreeTest;
    map<char, int> frequency = TreeTest.Get_Frequency(data);
    Huffman_Tree* TreeHead = TreeTest.Get_Main_Tree(frequency);
    vector<bool> code;
    TreeTest.Build_Dictionary(TreeHead, code);
    map <char, vector<bool>> dictionary = TreeTest.huffman_dictionary;

    vector<bool> a_code_expected {0,0,0};
    vector<bool> e_code_expected {0,0,1};
    vector<bool> i_code_expected {0,1};
    vector<bool> o_code_expected {1,0};
    vector<bool> u_code_expected {1,1};
    
    EXPECT_EQ(dictionary['a'], a_code_expected);
    EXPECT_EQ(dictionary['e'], e_code_expected);
    EXPECT_EQ(dictionary['i'], i_code_expected);
    EXPECT_EQ(dictionary['o'], o_code_expected);
    EXPECT_EQ(dictionary['u'], u_code_expected);
}


/*** Encode Data Function Tests ***/
TEST(Encode_Tree_Tests, Encode_Tree_Single_Char_Bits_Out)
{
    string data = "aaa";
    Huffman EncodeTest;
    EncodeTest.Testing_Encode_Tree(data, "Compressed_Tree_Single.bin");

    string expected_bit_stream = "101100001";
    string real_bit_stream = EncodeTest.binary_out->Get_Bit_Stream();

    EXPECT_EQ(expected_bit_stream, real_bit_stream);
}

TEST(Encode_Tree_Tests, Encode_Tree_Single_Char_Stream_Length)
{
    string data = "aaa";
    Huffman EncodeTest;
    EncodeTest.Testing_Encode_Tree(data, "Compressed_Tree_Single_Length.bin");

    int expected_bits_output = 9;
    int real_bits_output = EncodeTest.binary_out->Get_Bits_Out();

    EXPECT_EQ(expected_bits_output, real_bits_output);
}

TEST(Encode_Tree_Tests, Encode_Tree_Multi_Char_Bits_Out)
{
    string data = "aeeiii";
    Huffman EncodeTest;

    EncodeTest.Testing_Encode_Tree(data, "Compressed_Tree.bin");

    string expected_bit_stream = "00101100001101100101101101001";
    string real_bit_stream = EncodeTest.binary_out->Get_Bit_Stream();

    EXPECT_EQ(expected_bit_stream, real_bit_stream);
}

TEST(Encode_Tree_Tests, Encode_Tree_Multi_Char_Stream_Length)
{
    string data = "aeeiii";
    Huffman EncodeTest;

    EncodeTest.Testing_Encode_Tree(data, "Compressed_Tree_Length.bin");

    int expected_bits_output = 29;
    int real_bits_output = EncodeTest.binary_out->Get_Bits_Out();

    EXPECT_EQ(expected_bits_output, real_bits_output);
}

TEST(Encode_Length_Tests, Encode_Length_Bits_Out)
{
    string data = "aeeiiioooouuuu";
    Huffman EncodeTest;

    EncodeTest.binary_out = new Binary_Out("Compressed.bin");
    map<char, int> frequency = EncodeTest.Get_Frequency(data);
    Huffman_Tree* TreeHead = EncodeTest.Get_Main_Tree(frequency);
    EncodeTest.Encode_Length(data);

    string expected_bit_stream = "00000000000000000000000000001110";
    string real_bit_stream = EncodeTest.binary_out->Get_Bit_Stream();

    EXPECT_EQ(expected_bit_stream, real_bit_stream);
}

TEST(Encode_Length_Tests, Encode_Length_Setter)
{
    string data = "aeeiiioooouuuu";
    Huffman EncodeTest;
    EncodeTest.Testing_Encode_Length(data, "Compressed_Length.bin");
}

TEST(Encode_Length_Tests, Encode_Length_Stream_Length)
{
    string data = "aeeiiioooouuuu";
    Huffman EncodeTest;
    EncodeTest.binary_out = new Binary_Out("Compressed.bin");
    map<char, int> frequency = EncodeTest.Get_Frequency(data);
    Huffman_Tree* TreeHead = EncodeTest.Get_Main_Tree(frequency);
    EncodeTest.Encode_Length(data);

    int expected_bits_output = 32;
    int real_bits_output = EncodeTest.binary_out->Get_Bits_Out();

    EXPECT_EQ(expected_bits_output, real_bits_output);
}

TEST(Encode_Data_Tests, Encode_Data_Bits_Out)
{
    string data = "aeeiii";
    Huffman EncodeTest;
    EncodeTest.binary_out = new Binary_Out("Compressed.bin");
    EncodeTest.Build_Tree(data);
    EncodeTest.Encode_Data(data, data.length());
    string expected_bit_stream = "000101111";
    string real_bit_stream = EncodeTest.binary_out->Get_Bit_Stream();
    EXPECT_EQ(expected_bit_stream, real_bit_stream);
}

TEST(Encode_Data_Tests, Encode_Data_Stream_Length)
{
    string data = "aeeiii";
    Huffman EncodeTest;
    EncodeTest.binary_out = new Binary_Out("Compressed.bin");
    EncodeTest.Build_Tree(data);
    EncodeTest.Encode_Data(data, data.length());

    int expected_bits_output = 9;
    int real_bits_output = EncodeTest.binary_out->Get_Bits_Out();

    EXPECT_EQ(expected_bits_output, real_bits_output);
}

TEST(Encode_Tests_Total, Encode_Total_Bits_Out)
{
    string data = "aeeiii";
    Huffman EncodeTest;

    EncodeTest.Encode(data, "Compressed_Total_Short_String.bin");

    string expected_bit_stream = "0010110000110110010110110100100000000000000000000000000000110000101111";
    string real_bit_stream = EncodeTest.Get_Encode_Bit_Stream();

    EXPECT_EQ(expected_bit_stream, real_bit_stream);
}

TEST(Encode_Tests_Total, Decode_Total_Longer_Setter)
{
    string data = "CS 100 is a course created to teach you one simple principle, think twice, develop once";
    Huffman EncodeTest;
    EncodeTest.Encode(data, "Compressed_Total_Longer_String.bin");
}


TEST(Encode_Tests_Total, Encode_Total_Stream_Length)
{
    string data = "aeeiii";
    Huffman EncodeTest;

    EncodeTest.Encode(data, "Compressed.bin");

    int expected_bits_output = 70;
    int real_bits_output = EncodeTest.Get_Encode_Bit_Length();

    EXPECT_EQ(expected_bits_output, real_bits_output);
}


/*** Decode Data Function Tests ***/
TEST(Decode_Tree_Tests, Decode_Tree_Multi_Char)
{
    string data = "aeeiii";

    Huffman DecodeTest;
    DecodeTest.binary_in = new Binary_In("Compressed_Tree.bin");
    DecodeTest.main_tree = DecodeTest.Decode_Tree();

    // int real_bits_output = DecodeTest.binary_in->Get_Bits_In();
    // cout << "Decode Tree Bits In: " << real_bits_output << endl;

    EXPECT_EQ(DecodeTest.main_tree->right_child->key, 'i');
    EXPECT_EQ(DecodeTest.main_tree->left_child->left_child->key, 'a');
    EXPECT_EQ(DecodeTest.main_tree->left_child->right_child->key, 'e');
}

TEST(Decode_Tree_Tests, Decode_Tree_Single_Char)
{
    string data = "aaa";

    Huffman DecodeTest;
    DecodeTest.binary_in = new Binary_In("Compressed_Tree_Single.bin");
    DecodeTest.main_tree = DecodeTest.Decode_Tree();

    EXPECT_EQ(DecodeTest.main_tree->key, 'a');
    EXPECT_EQ(DecodeTest.main_tree->left_child, nullptr);
    EXPECT_EQ(DecodeTest.main_tree->right_child, nullptr);
    EXPECT_EQ(DecodeTest.main_tree->isLeaf(), true);
}


TEST(Decode_Length_Tests, Decode_Length)
{
    string data = "aeeiiioooouuuu";
    Huffman DecodeTest;

    DecodeTest.binary_in = new Binary_In("Compressed_Length.bin");
    int data_length = DecodeTest.binary_in->Decode_Length();

    EXPECT_EQ(data_length, 14);
}

TEST(Decode_Total, Decode_Data)
{
    string data = "aeeiii";
    Huffman DecodeTest;

    string decoded_data = DecodeTest.Decode("Compressed_Total_Short_String.bin");

    EXPECT_EQ(data, decoded_data);
}

TEST(Decode_Total, Decode_Data_Longer_String)
{
    string data = "CS 100 is a course created to teach you one simple principle, think twice, develop once";
    Huffman DecodeTest;

    string decoded_data = DecodeTest.Decode("Compressed_Total_Longer_String.bin");

    EXPECT_EQ(data, decoded_data);
}

/*** Run All Tests Driver ***/
int runTest(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}