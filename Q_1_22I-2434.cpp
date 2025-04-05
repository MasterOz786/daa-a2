/*

  d-ary heap implementation - flexible child count

*/

#  include  <stdexcept>  
# include<iostream>  
#  include<fstream>
  #include <string> 
  #include<cmath>  

using namespace std;  

template<class T> class HeapX {

  T* data;  int cap;  int sz;  
  int d_kids; bool is_min;

  int getP(int i){return (i-1)/d_kids;}  
  int firstKid(int i){return d_kids*i+1;}  

  void swp(T& x,T& y){T t=x;x=y;y=t;}  

  void grow(){
    int new_cap = cap?cap*2:4;
    T* new_data=new T[new_cap];  
    for(int j=0;j<sz;j++)new_data[j]=data[j];  
    delete[] data; data=new_data; cap=new_cap;
  }

  void floatUp(int pos){
    while(pos>0){
      int p=getP(pos);  
      if( (is_min&&data[pos]<data[p]) || 
         (!is_min&&data[pos]>data[p]) ){
        swp(data[pos],data[p]); pos=p;  
      } else break;
    }
  }

  void sinkDown(int i){
    while(1){
      int kid=firstKid(i);  
      if(kid>=sz)return;  

      int extreme=kid;  
      for(int k=1;k<d_kids && kid+k<sz;k++){
        int curr=kid+k;  
        if( (is_min&&data[curr]<data[extreme]) || 
           (!is_min&&data[curr]>data[extreme]) )
          extreme=curr;
      }

      if( (is_min&&data[extreme]<data[i]) || 
         (!is_min&&data[extreme]>data[i]) ){
        swp(data[i],data[extreme]); i=extreme;  
      } else return;
    }
  }

public:

  HeapX(int d=2,bool min=true):d_kids(d),is_min(min){
    cap=0; sz=0; data=nullptr;  
  }

  ~HeapX(){delete[] data;}  

  void add(T val){
    if(sz>=cap)grow();  
    data[sz]=val;  
    floatUp(sz++);  
  }

  T popTop(){
    if(!sz)throw runtime_error("Empty heap!");  
    T top=data[0];  
    data[0]=data[--sz];  
    sinkDown(0);  
    return top;
  }

  void flipType(){
    is_min=!is_min;  
    for(int i=sz/2-1;i>=0;i--)sinkDown(i);  
  }

  void show(){
    if(!sz){cout<<"Empty\n";return;}  

    int lvl=0, start=0, cnt=1;  
    while(start<sz){
      int end=start+cnt;  
      if(end>sz)end=sz;  

      for(int j=start;j<end;j++){
        cout<<data[j];  
        if(j<end-1)cout<<" ";  
      }
      cout<<"\n";  

      start=end;  
      cnt*=d_kids;  
      lvl++;  
    }
  }
};

int main(int argc, char** argv) {

  if(argc<2){cerr<<"Need input file!\n";return 1;}  

  ifstream fin(argv[1]);  
  if(!fin){cerr<<"Can't open "<<argv[1]<<endl;return 2;}  

  int d; string type;  
  fin>>d>>type;  

  HeapX<int> h(d,type=="min");  

  string cmd;  
  while(fin>>cmd){
    if(cmd=="ins"){
      int x;  
      while(fin>>x){
        h.add(x);  
        if(fin.peek()=='\n'||fin.eof())break;  
      }
    } 
    else if(cmd=="extract"){
      try{h.popTop();}  
      catch(...){cerr<<"Failed extract\n";}  
    }
  }

  h.show();  
  fin.close();  

  return 0;
}