#include <iostream>
using namespace std;

void subsequence( string &str,string output,int index){
  if(index>=str.size()){
    cout<<output<<endl;
    return;
  }
 //include 
  output+=str[index];
  subsequence(str,output,index+1);
  output.pop_back();
  
//exclude 
  subsequence(str,output,index+1);

}
int main() {
  string str="abc";
  string output="";
  subsequence(str,output,0);

  return 0;
}
