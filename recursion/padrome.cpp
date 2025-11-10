#include<bits/stdc++.h>
#include<string>
using namespace std;

bool pallindrome(int i,string word)
{
if(i>=word.size()/2)
return true;
if(word[i]!=word[word.size()-i-1])
return false;

return true &&pallindrome(i+1,word) ;
}
int main()
{
string word="madam";
cout<<pallindrome(0,word);
}