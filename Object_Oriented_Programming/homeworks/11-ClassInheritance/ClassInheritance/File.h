#pragma once
#include <string>
#include "Document.h"

class File:public Document
{
private:
	string pathname;
public:
	File();
	~File();
	File(string body, string path);

	string getPathname();
	void setPathname(string x);

	File operator= (File& X);
};

