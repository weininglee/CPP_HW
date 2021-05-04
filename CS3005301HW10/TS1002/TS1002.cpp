/*#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main(){
	char grid[4][4];
    fstream file;
    string in;
    vector<string> wordsFound;
    vector<string> words;
    vector<vector<int> > locations;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			grid[i][j] = '0';
		}
	}
    file.open("words.txt");
    while (getline(file, in)) {
        words.push_back(in);
    }
    file.close();
	while (!cin.eof()) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; i < 4; j++) {
				cin >> grid[i][j];
			}
		}
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                //cout << grid[i][j] << " ";
                //for each word
                for (int k = 0; k < words.size(); k++) {
                    //check if grid letter equals the first letter of word
                    if (grid[i][j] == words[k][0]) {
                        //check horizontal vertical and diagonal
                        for (int l = 1; l <= words[k].size(); l++) {
                            if (
                                //break if no word was found
                                grid[i - l][j] != words[k][l] &&
                                grid[i + l][j] != words[k][l] &&
                                grid[i][j + l] != words[k][l] &&
                                grid[i][j - l] != words[k][l] &&
                                grid[i + l][j + l] != words[k][l] &&
                                grid[i - l][j - l] != words[k][l] &&
                                grid[i + l][j - l] != words[k][l] &&
                                grid[i - l][j + l] != words[k][l]) {
                                break;
                            }
                            else if (l == words[k].size() - 1) {
                                cout << words[k] << endl;
                                vector<int> location;
                                location.push_back(j + 1);
                                location.push_back(i + 1);
                                locations.push_back(location);
                                //add word to wordsFound
                                wordsFound.push_back(words[k]);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < wordsFound.size(); j++) {
                //loop to check if word in dictionary wasn't found and append to output.txt
                if (words[i] == wordsFound[j]) {
                    break;
                }
                else if (j == wordsFound.size() - 1) {
                    cout << words[i] << " was not found!" << endl;
                }
            }
        }
	}
}*/