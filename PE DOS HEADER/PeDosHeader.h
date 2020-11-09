#pragma once

//Let's add here some PE dos Header information that we already have from the article. 

#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <winnt.h>


// Explaining the std::Vector 

template<
    class T,
    class Allocator = std::allocator<T>
> class vector;
// std::vector is a sequence container that encapsulates dynamic size arrays.




// You may ask me, so, what it is the uint8_t???

// It's an following typedefs of fundamental integral types or extended integral types.

// The are two different's typedefs: the signed type and unsigned type.

// So you may question: What the diffence between than? 
// The best answer that I can make is: Rememeber in your school the differenct between INTEGER and NATURAL number?     -> So, the INTEGER = goes to negative values too (Signed); The NATURAL (unsigned)
// just goes to Positive number; 



// The data type const string& literally means “a reference to a string object whose contents will not be changed.”
// So, std::string const & is equivalent to const std::string &. const std::string& is the style adopted in Stroustrup's The C++ Programming Language and probably is "the traditional style"



// typedef basic_ifstream<char> ifstream;
//Input file stream class







typedef struct _IMAGE_DOS_HEADER {  // DOS .EXE header  // USHORT it's basically an hex like 0x00, 0x02, 0x04 etc..., can be for exemple, WORD e_magic; DWORD e_lfanew; 
    USHORT e_magic;         // Magic number
    USHORT e_cblp;          // Bytes on last page of file
    USHORT e_cp;            // Pages in file
    USHORT e_crlc;          // Relocations
    USHORT e_cparhdr;       // Size of header in paragraphs
    USHORT e_minalloc;      // Minimum extra paragraphs needed
    USHORT e_maxalloc;      // Maximum extra paragraphs needed
    USHORT e_ss;            // Initial (relative) SS value
    USHORT e_sp;            // Initial SP value
    USHORT e_csum;          // Checksum
    USHORT e_ip;            // Initial IP value
    USHORT e_cs;            // Initial (relative) CS value
    USHORT e_lfarlc;        // File address of relocation table
    USHORT e_ovno;          // Overlay number
    USHORT e_res[4];        // Reserved words
    USHORT e_oemid;         // OEM identifier (for e_oeminfo)
    USHORT e_oeminfo;       // OEM information; e_oemid specific
    USHORT e_res2[10];      // Reserved words
    LONG   e_lfanew;        // File address of new exe header
} IMAGE_DOS_HEADER, * PIMAGE_DOS_HEADER;


