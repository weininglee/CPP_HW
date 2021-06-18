#pragma once
#include<iostream>
#include"Document.h"

class File : public Document {
public:
	File() :Document() { }
	File(string theText, string thePath) :Document(theText), pathname(thePath) { }
	File(File& theFile) {
		setText(theFile.getText());
		pathname = theFile.pathname;
	}

	void setPathname(string s) {
		pathname = s;
	}

	string getPathname() const {
		return pathname;
	}

	File operator=(File in) {
		setText(in.getText());
		pathname = in.pathname;
		return *this;
	}

private:
	string pathname;
};