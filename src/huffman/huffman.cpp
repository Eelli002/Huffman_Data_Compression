#include "huffman.h"
#include <iostream>

using namespace std;

Huffman::Huffman()
{}


Huffman::~Huffman()
{
    if (!main_tree) Destroy_Tree(main_tree);
}


void Huffman::Destroy_Tree(Huffman_Tree* tree)
{
    if (tree->left_child != nullptr) Destroy_Tree(tree->left_child);
    if (tree->right_child != nullptr) Destroy_Tree(tree->right_child);
    delete tree;
}

map<char,int> Huffman::Get_Frequency(string& data)
{
    map<char, int> char_frequency;
    for (string::iterator i = data.begin(); i != data.end(); i++) 
        char_frequency[*i]++;
    return char_frequency;
}


Huffman_Tree* Huffman::Get_Main_Tree(map<char, int> frequency)
{
    priority_queue< Huffman_Tree*, vector<Huffman_Tree*>, Value_Comparison > node_queue;    
        // Min heap containing our huffman trees. Used to create main huffman tree.

    for (map<char,int>::iterator i = frequency.begin(); i != frequency.end(); i++)    
    {
        // Will iterate through frequency map creating HT nodes and pushing them to our priority queue.
        Huffman_Tree* node = new Huffman_Tree(nullptr, nullptr, i->first, i->second);
        node_queue.push(node);
    }

    while(node_queue.size() > 1)
    {
        Huffman_Tree* node_one = node_queue.top();
        node_queue.pop();

        Huffman_Tree* node_two = node_queue.top();
        node_queue.pop();

        int combination_weight = node_one->weight + node_two->weight;
        Huffman_Tree* combination_node = new Huffman_Tree(node_one, node_two, '\0', combination_weight);

        node_queue.push(combination_node);
            // Push new node into priority queue until only one is remaining, our main huffman tree
    }
    return node_queue.top();
}


void Huffman::Build_Tree(string& data)
{
    map<char, int> frequency = Get_Frequency(data);    
        // Create a map of all chars and their frequency in data string

    main_tree = Get_Main_Tree(frequency);    
        // Assign our private main_tree member variable;

    vector<bool> code;
    Build_Dictionary(main_tree, code);
}


void Huffman::Build_Dictionary(Huffman_Tree* main_tree, vector<bool>& code)
{
    if (main_tree->isLeaf()) huffman_dictionary[main_tree->key] = code;
    else
    {
        code.push_back(false);
        Build_Dictionary(main_tree->left_child, code);
        code.pop_back();
        code.push_back(true);
        Build_Dictionary(main_tree->right_child, code);
        code.pop_back();
    }
}


/************** Encode & Decode Tree Methods ***************/
void Huffman::Encode_Tree(Huffman_Tree* tree)
{
    if (tree->isLeaf())
    {
        binary_out->Write_Bit(true);
        binary_out->Write_Char(tree->key);
        return;
    }
    binary_out->Write_Bit(false);
    Encode_Tree(tree->left_child);
    Encode_Tree(tree->right_child);
}


Huffman_Tree* Huffman::Decode_Tree()
{
    bool is_leaf_bit = binary_in->Get_Bit();
    // cout << "BP1\n";
    if (is_leaf_bit) {
        // cout << "BP2 - True\n";
        return new Huffman_Tree(nullptr, nullptr, binary_in->Get_Char(), -1);
    }
    else {
        //cout << "BP2 - False\n";
        return new Huffman_Tree(Decode_Tree(), Decode_Tree(), '\0', -1);
    }
}


void Huffman::Encode_Data(string& data, int length)
{
    for (int i = 0; i < length; i++)    // Last, pass in the compressed data
    {
        vector<bool> code = huffman_dictionary[data[i]];
        for (vector<bool>::iterator i = code.begin(); i != code.end(); i++)
        {
            bool bit = *i;
            binary_out->Write_Bit(bit);
        }
    }
}


int Huffman::Encode_Length(string& data)
{
    int length = data.length();
    // cout << "Data Length: " << length << endl;
    binary_out->Write_Length(length);
    return length;
}


void Huffman::Encode(string& data, string fileName)
{
    Build_Tree(data);

    binary_out = new Binary_Out(fileName);

    Encode_Tree(main_tree);
        // First we pass in our huffman Tree to the beginning of the binary output.

    int length = Encode_Length(data);
        // Next we pass in the total length of our data to the binary output.

    Encode_Data(data, length);
        // Last, we encode our data.

    Set_Encode_Bit_Stream();
        // cout << Get_Encode_Bit_Stream() << endl;
    Set_Encode_Bit_Length();
        // cout << Get_Encode_Bit_Stream() << endl;
    Set_Decode_Bit_Length();

    binary_out->Close();
    delete binary_out;
    if (!main_tree) Destroy_Tree(main_tree);
}


string Huffman::Decode(string file_name)
{
    binary_in = new Binary_In(file_name);

    main_tree = Decode_Tree();
    // cout << "Bits retrieved for tree: " << binary_in->bits_retrieved << endl; 

    int length = binary_in->Decode_Length();
    // cout << "BinIn:File_Length: " << length << endl;

    string data;

    for (int i = 0; i < length; i++)
    {
        Huffman_Tree* x = main_tree;
        while (!x->isLeaf())
        {
            bool bit = binary_in->Get_Bit();
            if (bit) x = x->right_child;
            else x = x->left_child;
        }
        data += x->key;
    }
    delete binary_in;
    if (!main_tree) Destroy_Tree(main_tree);
    return data;
}








/*** Testing Bitstream Helper Functions ***/
void Huffman::Set_Encode_Bit_Stream()
{
    encode_bit_stream = binary_out->Get_Bit_Stream();
}

string Huffman::Get_Encode_Bit_Stream()
{
    return encode_bit_stream;
}

void Huffman::Set_Encode_Bit_Length()
{
    encode_bit_length = binary_out->Get_Bits_Out();
}

int Huffman::Get_Encode_Bit_Length()
{
    return encode_bit_length;
}

void Huffman::Set_Decode_Bit_Length()
{
    decode_bit_length = binary_in->Get_Bits_In();
}

int Huffman::Get_Decode_Bit_Length()
{
    return decode_bit_length;
}

/*** Testing Encoding Helper Functions ***/

void Huffman::Testing_Encode_Tree(string& data, string fileName)
{
    Build_Tree(data);

    binary_out = new Binary_Out(fileName);

    Encode_Tree(main_tree);

    Set_Encode_Bit_Stream();
    Set_Encode_Bit_Length();
    Set_Decode_Bit_Length();

    binary_out->Close();
    delete binary_out;
    if (!main_tree) Destroy_Tree(main_tree);
}


void Huffman::Testing_Encode_Length(string& data, string fileName)
{

    binary_out = new Binary_Out(fileName);

    int length = Encode_Length(data);

    Set_Encode_Bit_Stream();
    Set_Encode_Bit_Length();
    Set_Decode_Bit_Length();

    binary_out->Close();
    delete binary_out;
    if (!main_tree) Destroy_Tree(main_tree);
}