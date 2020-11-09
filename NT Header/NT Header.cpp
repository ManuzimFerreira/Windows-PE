// NT Header.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// PE DOS HEADER.cpp : This file contains the 'main' function. Program execution begins and ends there.


// Here we 're going to practice a little about this PE type.


//Choose your program nype. 

#include <vector>
#include <Windows.h>
#include <fstream>
#include <iostream>


using namespace std;

//Searching if the file is great for us;
//If you don't know what 're this path of c++ used in my nype, you can search or try to understand on my HeaderFiles;



//Here we are getting the bytes from the file and reading them using file operation snippets;
std::vector<uint8_t>ReadBytesFromFile(const std::string& filet) {
	std::ifstream file(filet, std::ios::binary); // Can also use std::ifstream::binary
	std::vector<uint8_t>bytes;

	if (!file.is_open()) {
		cout << "Failed to open file." << endl;
		return bytes;
	}

	uint32_t Send(const uint8_t * buffer, const std::size_t bufferSize);
	std::vector<uint8_t>buffer(std::istreambuf_iterator<char>(file), {});


	return buffer;
}


int main()
{
	auto fileBytes = ReadBytesFromFile(R"(C:\Users\manuz\OneDrive\Área de Trabalho\Estudando\Life of Binaries\pythondemo\R1Bins\Round1Q9.exe)");
	auto rawBytes = fileBytes.data();


	auto PeDosHeader = (IMAGE_DOS_HEADER*)rawBytes;  //pointer to dos headers

	cout << "                                                            *     PE DOS HEADER *                                                                     " << endl << endl;

	cout << "File Size: " << fileBytes.size() << endl;

	cout << "MagicNumber: " << hex << PeDosHeader->e_magic << endl;

	cout << "PE Header: 0x" << hex << PeDosHeader->e_lfanew << endl << endl;

	cout << "___________________________________________________________________________________________________________________________________________" << endl << endl;  


	auto NT_HEADER = (IMAGE_NT_HEADERS64*)(fileBytes.data() + PeDosHeader->e_lfanew);
	auto Signature = NT_HEADER->Signature;
	auto NTHeader = NT_HEADER->FileHeader;

	cout << "                                                       *     NT HEADER or PE Header *                                                                     " << endl << endl;

	cout << "Signature: " << Signature << endl;
	cout << "Machine: " << NTHeader.Machine << endl;
	cout << "NumberOfSections: " << NTHeader.NumberOfSections << endl;
	cout << "TimeDateStamp: " << NTHeader.TimeDateStamp << endl;
	cout << "Characteristics: " << NTHeader.Characteristics << endl;





	system("pause");

	// you can put here all you wanna know about the NT HEADER; 
}

