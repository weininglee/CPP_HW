#include "document.h"

Document::Document(string Body)
{
	text = Body;
}

const string Document::getText()
{
	return text;
}

void Document::setText(string Text)
{
	text = Text;
}

Document Document::operator=(Document document)
{
	text = document.text;
	return *this;
}