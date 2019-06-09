#include "Document.h"


// default nothing in the text.
Document::Document()
{
	text = "";
}

Document::~Document()
{
}

// construct with text.
Document::Document(string x)
{
	text = x;
}

// get the content by this function.
string Document::getText()
{
	return text;
}

// set content by this function.
void Document::setText(string x)
{
	text = x;
}

// operator overload.
Document Document::operator=(Document& X)
{
	text = X.text;
	return *this;
}

