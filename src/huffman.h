#include <string>
#include <map>
#include <queue>

#include "binary_out.h"
#include "binary_in.h"

using namespace std;

struct Huffman_Tree
{
    Huffman_Tree* left_child;
    Huffman_Tree* right_child;
    int weight;
    char key;

    Huffman_Tree(Huffman_Tree* left, Huffman_Tree* right, char key, int weight)
    {
        left_child = left;
        right_child = right;
        this->key = key;
        this->weight = weight;
    }

    bool isLeaf()
    {
        return left_child == nullptr && right_child == nullptr;
    }
};


class Value_Comparison
{
    public:
        bool operator() (const Huffman_Tree* tree_one, const Huffman_Tree* tree_two)
        {
            return tree_one->weight >= tree_two->weight;
        }
};

class Huffman
{
    private: 
        // map<char,vector<bool> > huffman_dictionary;    
            // Dictionary containing chars with their respective code.
        // Huffman_Tree* main_tree;    
            // Huffman tree created by Build_Tree().
        // Binary_Out* binary_out;
            // ofstream (ios::binary) - Opens file to write encoding.
        // Binary_In* binary_in;
            // ifstream (ios::binary) - Opens file to read encoding.
        string encode_bit_stream = "";
        int encode_bit_length = 0;

        int decode_bit_length = 0;

        /*** Huffman Tree Functions ***/
        // map<char, int> Get_Frequency(string& data);
            // Gets data, returns dictionary containing chars and their freq.
        // Huffman_Tree* Get_Main_Tree(map<char,int> freq);
            // Uses huffman algo to construct tree from freq dictionary.
        // void Build_Dictionary(Huffman_Tree* main_tree, vector<bool> &code);
            // Uses main tree to construct codes for each char.
        // void Build_Tree(string &data);
            // Driver for entire huffman algo.
        void Destroy_Tree(Huffman_Tree* tree);
            // Deep copy destructor of tree.

        /*** Huffman Encoding Functions ***/
        // void Encode_Tree(Huffman_Tree* tree);
        // int Encode_Length(string& data);
        // void Encode_Data(string& data, int length);

        // Huffman_Tree* Decode_Tree();

    public:
        Huffman();
        ~Huffman();
        void Encode(string& input_data, string output_file);
        string Decode(string fileName);


    /*** Modifying Access for Testing ***/
        /*** Member Variables ***/
        map<char,vector<bool> > huffman_dictionary;  
        Huffman_Tree* main_tree; 
        Binary_Out* binary_out;
        Binary_In* binary_in;

        /*** Testing Functions for Tree Building ***/
        map<char, int> Get_Frequency(string& data);
        Huffman_Tree* Get_Main_Tree(map<char,int> freq);
        void Build_Dictionary(Huffman_Tree* main_tree, vector<bool> &code);
        void Build_Tree(string &data);

        /*** Testing Functions for Binary Output ***/
        void Encode_Tree(Huffman_Tree* tree);
        int Encode_Length(string& data);
        void Encode_Data(string& data, int length);

        void Testing_Encode_Tree(string& input_data, string output_file);
        void Testing_Encode_Length(string& input_data, string output_file);
        void Testing_Encode_Data(string& input_data, string output_file);

        void Set_Encode_Bit_Stream();
        string Get_Encode_Bit_Stream();
        void Set_Encode_Bit_Length();
        int Get_Encode_Bit_Length();

        int Get_Decode_Bit_Length();
        void Set_Decode_Bit_Length();

        Huffman_Tree* Decode_Tree();
};