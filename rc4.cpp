#include <iostream>
using namespace std;
int main()
{
int i, x;
char str[100];
cout &lt;&lt; &quot;Please enter a string:\t&quot;;
cin &gt;&gt; str;
cout &lt;&lt; &quot;\nPlease choose following options:\n&quot;;
cout &lt;&lt; &quot;1 = Encrypt the string.\n&quot;;
cout &lt;&lt; &quot;2 = Decrypt the string.\n&quot;;
cin &gt;&gt; x;
//using switch case statements
switch(x)
{
//first case for encrypting a string
case 1:
for(i = 0; (i &lt; 100 &amp;&amp; str[i] != &#39;\0&#39;); i++)
str[i] = str[i] + 2; //the key for encryption is 3 that is added to ASCII value
cout &lt;&lt; &quot;\nEncrypted string: &quot; &lt;&lt; str &lt;&lt; endl;
break;
//second case for decrypting a string
case 2:
for(i = 0; (i &lt; 100 &amp;&amp; str[i] != &#39;\0&#39;); i++)
str[i] = str[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value
cout &lt;&lt; &quot;\nDecrypted string: &quot; &lt;&lt; str &lt;&lt; endl;
break;
default:
cout &lt;&lt; &quot;\nInvalid Input !!!\n&quot;;
}
return 0;
}
