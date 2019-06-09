#pragma once
#include <string>
#include "Document.h"

class Email:public Document
{
private:
	string sender;
	string recipient;
	string title;
public:
	Email();
	~Email();
	Email(string body, string send, string receive, string top);

	string getSender();
	void setSender(string x);

	string getRecipient();
	void setRecipient(string x);

	string getTitle();
	void setTitle(string x);

	Email operator = (Email& X);

};

