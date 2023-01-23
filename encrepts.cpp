#include <iostream>
#include <fstream>
#include <string>

// Class for file encryption and decryption
class FileEncryption {
public:
    // Function to encrypt a file using a given password
    void encryptFile(std::string fileName, std::string password) {
        std::ifstream inFile(fileName, std::ios::binary);
        std::ofstream outFile(fileName + ".enc", std::ios::binary);

        // Check if the input file is open
        if (!inFile.is_open()) {
            std::cout << "Error: Unable to open file " << fileName << std::endl;
            return;
        }

        // Check if the output file is open
        if (!outFile.is_open()) {
            std::cout << "Error: Unable to create file " << fileName + ".enc" << std::endl;
            return;
        }

        // Read the input file and encrypt the data
        char c;
        int i = 0;
        while (inFile.get(c)) {
            outFile.put(c ^ password[i % password.length()]);
            i++;
        }

        inFile.close();
        outFile.close();
        std::cout<<"File Encrypted Successfully!"<<std::endl;
    }

    // Function to decrypt a file using a given password
    void decryptFile(std::string fileName, std::string password) {
        std::ifstream inFile(fileName, std::ios::binary);
        std::ofstream outFile(fileName.substr(0, fileName.length() - 4), std::ios::binary);

        // Check if the input file is open
        if (!inFile.is_open()) {
            std::cout << "Error: Unable to open file " << fileName << std::endl;
            return;
        }

        // Check if the output file is open
        if (!outFile.is_open()) {
            std::cout << "Error: Unable to create file " << fileName.substr(0, fileName.length() - 4) << std::endl;
            return;
        }

        // Read the input file and decrypt the data
        char c;
        int i = 0;
        while (inFile.get(c)) {
            outFile.put(c ^ password[i % password.length()]);
            i++;
        }

        inFile.close();
        outFile.close();
        std::cout<<"File Decrypted Successfully!"<<std::endl;
    }
};

int main() {
    // Create a file encryption object
    FileEncryption encryption;

    // Get the file name from the user
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    // Get the password from the user
    std::string password;
    std::cout << "Enter the
