#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <streambuf>
#include "huffman/huffman.h"
#include "encryption/RSA.h"
#include "encryption/decrypt_driver.h"

using namespace std;
//prints options
void Display_Main_Menu(string userFile);
void Display_Menu_Post_Compression(string userFile);

string Open_File(string userFile);

void Compression(string data);
void Decompression();

void Encryption();
void Decryption();


int main(int argc, char *argv[ ]){

//takes .txt file name from terminal input
string userFile = argv[1];
//writes text to a string to be passed to huffman class
string fileContents = Open_File(userFile);

Display_Main_Menu(userFile);
int first_choice;

cout << "Enter your choice(1-4):";
cin >> first_choice;

switch (first_choice){
//huffman compression
case 1: Compression(fileContents); break;
//huffman decompression
case 2: Decompression();break;
//encryption
case 3: Encryption(); break;
//decryption
case 4: Decryption(); break;
default: cout << "invalid"; break;
}

cout << endl;

if(first_choice == 1 || first_choice == 2){

int save_choice;
Display_Menu_Post_Compression(userFile);

cout<<"Enter your choice(1 or 2):";
cin >> save_choice;

    switch (save_choice){
    //encrypt and save file
    case 1: Encryption(); break;
    //quits program, user has an unencrypted file
    case 2: break;
    default: cout << "invalid"; break;
    } 
    cout << "type xxd -b <filename> | head to read binary output" << endl;
}

return 0;
}


void Display_Main_Menu(string userFile){
cout<<"===================================================== \n";
cout<<" \t\tFILE UPLOADED: " << userFile << "\t \n ";
cout<<"===================================================== \n";
cout<<" 1. Compress " << userFile << "\n";
cout<<" 2. Decompress " << userFile << "\n";
cout<<" 3. Encrypt " << userFile << " \n";
cout<<" 4. Decrypt " << userFile << "\n";
}

void Display_Menu_Post_Compression(string userFile){
cout<<"===================================================== \n";
cout<<" \t\tFILE COMPRESSED: " << userFile << "\t \n ";
cout<<"===================================================== \n";
cout<<" 1. Encrypt and save new file \n";
cout<<" 2. Keep unencrypted file \n";
}

// //maybe can just launch windows explorer here instead of doing any of this below
// void Rename_File(string userFile){
// cout<<"===================================================== \n";
// cout<<" \t\tPlease rename " << userFile << " before saving:\t \n ";
// cout<<"===================================================== \n";
// string newFileName;
// cin >> newFileName;
// Save_File(newFileName);
// return;
// }

// void Save_File(string newFileName){
// ifstream newFile;
// newFile.open (newFileName, ios::in | ios::binary);
// }

//opens .txt for input, passes text into data. returns data to be compressed
string Open_File(string userFile){
string data;
    string input_buffer;
    ifstream data_input;
    
    data_input.open(userFile);

    if (!data_input.is_open())
    {
        cout << "Error opening file";
        return "file failed to open";
    }


    stringstream buffer;
    buffer << data_input.rdbuf();

    data = buffer.str();
   
return data;
}

void Compression(string data){
    Huffman huffman_tree;
     huffman_tree.Encode(data, "CompressedText.bin");
}
void Decompression(){
    Huffman huffman_tree;
    string output = huffman_tree.Decode("CompressedText.bin");

    //writes to new file
    ofstream outputFile;
    outputFile.open("DecompressedText.txt");
    if(!outputFile.is_open())
    {
        cout << "Error opening file";
    }
    outputFile << output;
    outputFile.close();
    return;
}


void Encryption(){
cout << "this feature is still in testing" << endl;
return;
}
void Decryption(){
cout << "this feature is still in testing" << endl;
return;
}
