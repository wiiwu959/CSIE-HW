#include "Email.h"



Email::Email()
{
	sender = "default";
	recipient = "default";
	title = "default";
}


Email::~Email()
{
}

Email::Email(string body, string send, string receive, string top)
{
	setText(body);
	sender = send;
	recipient = receive;
	title = top;
}

string Email::getSender()
{
	return sender;
}

void Email::setSender(string x)
{
	sender = x;
}

string Email::getRecipient()
{
	return recipient;
}

void Email::setRecipient(string x)
{
	recipient = x;
}

string Email::getTitle()
{
	return title;
}

void Email::setTitle(string x)
{
	title = x;
}

// overload operator, same as class file.
Email Email::operator=(Email & X)
{
	Document::operator=(X);
	title = X.getTitle();
	sender = X.getSender();
	recipient = X.getRecipient();

	return *this;
}
