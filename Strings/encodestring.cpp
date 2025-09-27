/*Problem: Write a function that takes a non-empty string and returns its run-length encoding.
Concept: Run-Length Encoding (RLE) is a form of lossless data compression where sequences of identical, consecutive characters are replaced by a count and the character itself. For example, "AAA" becomes "3A".
Special Condition: To avoid ambiguity when decoding, runs of 10 or more characters must be split. For instance, a run of 12 "A"s should be encoded as "9A3A" instead of "12A", since "12A" could be decoded as "1AA" or "AAAAAAAAAAAA".
Example:
Sample Input: string = "AAAAAAAAAAAAABBCCCCDD"
Sample Output: "9A4A2B4C2D"*/

#include<iostream>
#include <string>
#include <sstream>
using namespace std;

string runLengthEncoding(string str) {
   ostringstream stream;
   int count=1;
   for(int i=1;i<str.length();i++)
   {
     if(str[i]!=str[i-1]||count==9)
     {stream<<count<<str[i-1];
     count=1;
   }
     else
       count++;
   }

  stream<<count<<str.back();
  return stream.str();

}
int main()
{
    cout<<runLengthEncoding("13aa33aabb");
    return 0;
}