
#include <iostream>
using namespace std;

bool isSubSeq(string str1, string str2){
int s1len= str1.size();
int s2len= str2.size();

int i=0;
int j =0;

while(i<s1len && j<s2len){
if(str1[i]==str2[i]){
i++;
}
j++;

}

if(s1len==i){
return true;
}
return false;
}


int main(){



    return 0;

}