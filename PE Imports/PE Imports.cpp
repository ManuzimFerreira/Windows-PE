// PE Imports.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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


	cout << "___________________________________________________________________________________________________________________________________________" << endl << endl;

	auto OptionalHeader = NT_HEADER->OptionalHeader;
	// Magic, AddressOfEntryPoint, ImageBase, SectionAlignment, FileAlignment, SizeOfImage, DllCharacteristics, DataDirectory.
	cout << "                                                       *     Optional Header *                                                                     " << endl << endl;

	cout << "Magic: " << OptionalHeader.Magic << endl;
	cout << "AddressOfEntryPoint: " << OptionalHeader.AddressOfEntryPoint << endl;
	cout << "ImageBase: " << OptionalHeader.ImageBase << endl;
	cout << "SectionAlignment: " << OptionalHeader.SectionAlignment << endl;
	cout << "FileAlignment: " << OptionalHeader.FileAlignment << endl;
	cout << "Size Of Image: " << OptionalHeader.SizeOfCode << endl;
	cout << "DllCharacteristics: " << OptionalHeader.DllCharacteristics << endl;
	cout << "DataDirectory: " << OptionalHeader.DataDirectory << endl;

	cout << "___________________________________________________________________________________________________________________________________________" << endl << endl;

	cout << "                                                       *     Section Headers *                                                                     " << endl << endl;

	IMAGE_SECTION_HEADER* Header;
	Header = IMAGE_FIRST_SECTION(NT_HEADER);

	auto SectionHeaders = Header;

	cout << "Name: " << Header->Name << endl;
	cout << "Virtual Address: " << Header->VirtualAddress << endl;
	cout << "PointerToRawData: " << Header->PointerToRawData << endl;
	cout << "Virtual Size: " << Header->Misc.VirtualSize << endl;
	cout << "SizeOfRawData: " << Header->SizeOfRawData << endl;
	cout << "Characteristics: " << Header->Characteristics << endl;



	cout << "___________________________________________________________________________________________________________________________________________" << endl << endl;


	cout << "                                                       *     PE Imports *                                                                     " << endl << endl;

	// Makings just one import:


	system("pause");
}

