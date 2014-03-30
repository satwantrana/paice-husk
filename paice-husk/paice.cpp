#include<bits/stdc++.h>
#include<vector>
#define pb push_back
using namespace std;
vector<string> stemrules;
bool isVowel(char c){
	return (c=='a' || c == 'e' || c == 'i' || c =='o' || c == 'u');
}
int main()
{
	string s,t;
	bool checkIntact,canContinue,isIntact,isMatch,containVowel;
	int numPos,partition,rulesFailed;

	ifstream rulesfile;
	rulesfile.open("rules.txt");
	while(rulesfile >> s){
		stemrules.pb(s);
	}
	rulesfile.close();
	
	while(cin >> s){
		isIntact = true;	
		canContinue = true;
		rulesFailed=0;
		while(canContinue && rulesFailed < stemrules.size()){
			for(int i = 0; i < stemrules.size(); i++){
				checkIntact = false;
				numPos=-1;
				rulesFailed++;
				for(int j = 0; j < stemrules[i].length(); j++){
					if(stemrules[i][j]=='*') checkIntact=true;
					if(stemrules[i][j]>='0' && stemrules[i][j]<='9') numPos = j;
				}
				if(checkIntact && !isIntact) continue;
				partition = numPos - checkIntact;
				isMatch=true;
				for(int j = 0; j < partition; j++){
					if(stemrules[i][j]!=s[s.size()-1-j]){
						isMatch = false;
						break;
					} 
				}
				if(!isMatch) continue;
				if(isVowel(s[0])){
					t = s.substr(0,s.size()-numPos) + stemrules[i].substr(numPos+1,stemrules[i].length()-2-numPos);
					if(t.length()<2) continue;
					s = t;
				}
				else{
					t = s.substr(0,s.size()-numPos) + stemrules[i].substr(numPos+1,stemrules[i].length()-2-numPos);
					if(t.length()<3) continue;
					containVowel=false;
					for(int j=0; j<t.size(); j++) if(isVowel(t[j])) containVowel=true;
					if(!containVowel) continue;
					s = t;
				}
				rulesFailed=0;
				isIntact = false;
				if(stemrules[i][stemrules[i].size()-1]=='.'){
					canContinue = false;
				}
				break;
			}
		}
		cout << s <<endl;
	}
	return 0;
}
