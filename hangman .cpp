#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

const int MAX_TRIES=5;
int letterfill (char,string,string&);
int main()
{
	string name;
	char letter;
	int num_of_wrong_guess=0;
	string word;
	string words[]=
	{
		"india",
		"usa",
		"france",
		"iran",
		"bombay",
		"new york",
		"oman",
	};
	srand(time(NULL));
	int n=rand()%10;
	word=words[n];
	
	string unknown(word.length(),'*');
	cout<<"\n welcome to hangman...guess acountry name";
	cout<<"\n each letter is represented by a star";
	cout<<"\n you have to type only one letter at onr time";
	cout<<"\n you have"<<MAX_TRIES<<cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~";
	
	while (num_of_wrong_guess <MAX_TRIES)
	{
		cout<<"\n\n"<<unknown;
		cout<<"\n\n guess letter:";
		cin>>letter;
		if(letterfill(letter,word,unknown)==0)
		{
		  cout<<endl<<"whoops that letter is not there!"<<endl;
		  num_of_wrong_guess++;
	    }
	    else
	    {
	    	cout<<endl<<"you found a lette that eciting"<<endl;
	    	
		}
		cout<<"you have"<<MAX_TRIES-num_of_wrong_guess;
		cout<<"guesses left"<<endl;
		
		if(word==unknown)
		{
			cout<<word<<endl;
			cout<<"yeah you got it";
			break;
		}
    }
    if(num_of_wrong_guess==MAX_TRIES)
    {
    	cout<<"\n sorry, you lose....you have been hanged"<<endl;
    	cout<<"the word was:"<<word<<endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}
int letterFill(char guess,string secretword,string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for(i=0;i<len;i++)
	{
		if(guess==guessword[i])
		return 0;
		
		if(guess==secretword[i])
		{
			guessword[i]=guess;
			matches++;
		}
	}
return matches;
}

