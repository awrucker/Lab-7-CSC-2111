#include "ReadFile.h"
#include <iostream>
#include <string>
using namespace CSC2110;

ReadFile::ReadFile(const char* file_name)
{
   input_file = new ifstream();
   input_file->open(file_name);
   closed = false;
   _eof = false;
}

ReadFile::~ReadFile()
{
   close();
   delete input_file;
}

bool ReadFile::eof()
{
   return _eof;
}

void ReadFile::close()
{
   if (!closed)
   {
      input_file->close();
      closed = true;
   }
}

String* ReadFile::readLine()
{
   if (closed) return NULL;
   if (_eof) return NULL;

   string text;
   _eof = !(getline(*input_file, text));

   String* str = new String((const char*) text.c_str());
   return str;
}

char* ReadFile::entireFile(const char* file_name)
{
	std::ifstream input_file(file_name, std::ifstream::binary);
	input_file.seekg(0, input_file.end);    // go to the end
	int length = input_file.tellg();           // report location (this is the length)
	input_file.seekg(0, input_file.beg);    // go back to the beginning
	char* buffer = new char[length+1];    // allocate memory for a buffer of appropriate dimension
	input_file.read(buffer, length);       // read the whole file into the buffer
	input_file.close();
	buffer[length] = 0;
	return buffer;
}
