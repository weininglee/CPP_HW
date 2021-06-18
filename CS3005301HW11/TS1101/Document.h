#pragma once
#include<iostream>
#include<string>
using namespace std;

class Document {
public:
	Document() { }
	Document(string theText) {
		text = theText;
	}
	Document(Document& theDocument) {
		text = theDocument.text;
	}

	void setText(string s) {
		text = s;
	}

	string getText() const {
		return text;
	}

	Document operator=(Document in) {
		text = in.text;
		return *this;
	}

private:
	string text;
};