#include<iostream>
using namespace std;

string caesarCypherEncryptor(string str, int key) {

    int slen=str.length();
    if(key>26)
    {
        key%=26;
    }
    for(int i=0;i<slen;i++)  
    {        
        int ascii=str[i];
        if((ascii+key)>=122)
        {
          ascii+=key;
          ascii-=26;
        }
        else
        {
            ascii+=key;
        }
    str[i] = char(ascii);
    }
  return str;
}

int main()
{
    cout<<caesarCypherEncryptor("ovmqkwtujqmfkao",52);
}