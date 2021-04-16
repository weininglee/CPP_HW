# Subject: Array To Interger
## Description:
Write a class that convert a string into an integer. For example, given the string “1234” the function should return the integer 1234.If you do some research, you will find that there is a function named atoi and also the stringstream class that can do this conversion for you. However, in this Programming Project, you should write your own code to do the conversion. Also write a suitable test program.

!!!Using class.

```
class Atoi {
private:
	string beTrans;
	char sign;
public:
	Atoi();
	Atoi(string s);
	void SetString(string s);
	const string GetString();
	int Length();
	bool IsDigital();
	int StringToInteger();
};

```


## Input:
input_main.cpp，input.txt

## Output:
output.txt<br>
**要輸出atoi前+20的數字和直接atoi的數字**<br>
Length()是多少個數字<br>
StringToInteger()是印出轉換後的數字<br>



## 第一組測資與輸出	
### Sample Input	
input_main.cpp<br>
05<br>
11<br>
23<br>
-10<br>
-11<br>
8946	<br>
### Sample Output
4<br>
520<br>
4<br>
2<br>
5<br>
4<br>
4<br>
1120<br>
4<br>
2<br>
11<br>
4<br>
4<br>
2320<br>
4<br>
2<br>
23<br>
4<br>
4<br>
-1020<br>
4<br>
2<br>
-10<br>
4<br>
4<br>
-1120<br>
4<br>
2<br>
-11<br>
4<br>
6<br>
894620<br>
4<br>
4<br>
8946<br>
4

## 第二組	
### Sample Input
input_main.cpp<br>
46506<br>
-096504<br>
56400<br>
00494	<br>
### Sample Output
7<br>
4650620<br>
4<br>
5<br>
46506<br>
4<br>
8<br>
-9650420<br>
4<br>
6<br>
-96504<br>
4<br>
7<br>
5640020<br>
4<br>
5<br>
56400<br>
4<br>
7<br>
49420<br>
4<br>
5<br>
494<br>
4

- [ ]  Eazy,Only basic programming syntax and structure are required.
- [ ]  Medium,Multiple programming grammars and structures are required.
- [x] Hard,Need to use multiple program structures or complex data types.
