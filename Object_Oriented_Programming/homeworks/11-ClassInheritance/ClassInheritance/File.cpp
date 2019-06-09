#include "File.h"
#include "Document.h"


// defalt pathname.
File::File()
{
	pathname = "default";
}


File::~File()
{
}

// construct file object with information.
File::File(string body, string path)
{
	pathname = path;
	setText(body);
}

// get pathname.
string File::getPathname()
{
	return pathname;
}

// set pathname.
void File::setPathname(string x)
{
	pathname = x;
}

// assignment overload.
File File::operator=(File& X)
{
	// use this to call father class fuction and use it operator overload 
	// to assign new Documnet information.
	Document::operator=(X);
	pathname = X.getPathname();

	return *this;
}
