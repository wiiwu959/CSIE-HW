#pragma once
#include <string>

using std::string;

class Document
{
private:
	// stores any textual content for the document.
	string text;

public:
	Document();
	~Document();
	Document(string x);

	// returns the text field.
	string getText();
	void setText(string x);
	
	Document operator = (Document &X);
};

