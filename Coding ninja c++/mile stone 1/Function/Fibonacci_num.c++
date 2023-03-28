#include<iostream>
using namespace std;


int main(){

  int n; 
  cin >> n ;
  if(checkMember(n)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }

}


bool checkMember(int n){

  if(n==0 || n==1){
      return true;
  }
    int a=1,b=1,c=1;
    
	while(c<=n){
        c=a+b;
        if(c==n){
            return true;
        }
        a=b;
        b=c;
    }
    return false;
}


