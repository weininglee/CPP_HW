#include <iostream>
#include <string>
using namespace std;

int main() {
	string in;
	while (getline(cin,in))
	{
		for (int i = 0; i < 3; i++) 
		{
			for (int j = 0; j < in.size(); j++)
			{
				if (in[j] < 48 || in[j] > 57)
				{
					continue;
				}
				if (i == 0)
				{
					if (in[j] == 49 || in[j] == 52)
					{
						cout << "   ";
					}
					else
					{
						cout << " _ ";
					}
				}
				else if (i == 1)
				{
					switch (in[j])
					{
					case 48:
						cout << "| |";
						break;
					case 49:
						cout << "  |";
						break;
					case 50:
						cout << " _|";
						break;
					case 51:
						cout << " _|";
						break;
					case 52:
						cout << "|_|";
						break;
					case 53:
						cout << "|_ ";
						break;
					case 54:
						cout << "|_ ";
						break;
					case 55:
						cout << "  |";
						break;
					case 56:
						cout << "|_|";
						break;
					case 57:
						cout << "|_|";
						break;
					default:
						break;
					}
				}
				else if (i == 2) 
				{
					switch (in[j])
					{
					case 48:
						cout << "|_|";
						break;
					case 49:
						cout << "  |";
						break;
					case 50:
						cout << "|_ ";
						break;
					case 51:
						cout << " _|";
						break;
					case 52:
						cout << "  |";
						break;
					case 53:
						cout << " _|";
						break;
					case 54:
						cout << "|_|";
						break;
					case 55:
						cout << "  |";
						break;
					case 56:
						cout << "|_|";
						break;
					case 57:
						cout << " _|";
						break;
					default:
						break;
					}
				}
			}
			cout << endl;
		}
		in.clear();
	}
}