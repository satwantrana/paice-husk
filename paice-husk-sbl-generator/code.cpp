#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<string> stemrules;
int main()
{
	int posIntact,posNum;
	ifstream rulesfile;
	rulesfile.open("rules.txt");
	string s,str1,str2,str3,str4,str5;
	while(rulesfile >> s){
		stemrules.pb(s);
	}
	rulesfile.close();
	for(int i=0;i<stemrules.size();i++)
	{
		posIntact=-1;posNum=-1;
		for(int j=0;j<stemrules[i].length();j++){
			
			if(stemrules[i][j]>='0' && stemrules[i][j]<='9') posNum=j;
			if(stemrules[i][j]=='*') posIntact=j;
		}
		str1="";
		for(int j=posNum-1-(posIntact>=0);j>=0;j--) str1+=stemrules[i][j];
		str2="";
		if(posIntact!=-1) str2="(isIntact)";
		str4="";
		for(int j=posNum+1;j<stemrules[i].length()-1;j++) str4+=stemrules[i][j];
		str3=str1.substr(str1.length()-(stemrules[i][posNum]-'0'),(stemrules[i][posNum]-'0'));
		if(stemrules[i][stemrules[i].length()-1]=='>')str5="set";
		else str5="unset";
		cout<<"		( ( '"<<str1<<"' (test check) ) and ( "<<str2<<" (unset isIntact) (['"<<str3<<"'] delete) (insert '"<<str4<<"' ) ("<<str5<<" canContinue) ) )\n		or\n";
		//( ( 'inguish' (test check) ) and ( (isIntact) (unset isIntact) (['inguish'] delete) (insert 't' ) (unset canContinue) ) )
	}
	return 0;
}
