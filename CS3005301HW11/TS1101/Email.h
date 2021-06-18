#pragma once
#include<iostream>
#include"Document.h"

class Email : public Document {
public:
	Email() :Document() { }
	Email(string theText, string theSender, string theRecipient, string theTitle)
		:Document(theText), sender(theSender), recipient(theRecipient), title(theTitle) { }
	Email(Email& theEmail) {
		setText(theEmail.getText());
		sender = theEmail.sender;
		recipient = theEmail.recipient;
		title = theEmail.title;
	}

	void setSender(string s) {
		sender = s;
	}
	void setRecipient(string s) {
		recipient = s;
	}
	void setTitle(string s) {
		title = s;
	}

	string getSender() const {
		return sender;
	}
	string getRecipient() const {
		return recipient;
	}
	string getTitle() const {
		return title;
	}

	Email operator=(Email in) {
		setText(in.getText());
		sender = in.sender;
		recipient = in.recipient;
		title = in.title;
		return *this;
	}

private:
	string sender;
	string recipient;
	string title;
};
