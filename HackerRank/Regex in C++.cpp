  #include <cmath>
  #include <cstdio>
  #include <sstream>
  #include <map>
  #include <iostream>
  #include <string>
using namespace std;


int main() {

    int N, Q;
    string curr="";
    string attr_name;
    map<string,string>m;

    cin>>N>>Q;
    cin.ignore();

    for(int i=0; i<N; i++){
      string line, tag, extract;
      getline(cin, line); //gets the entire line before white space
      stringstream ss(line); //passed to a stringstream object
      while(getline(ss, extract, ' ')){
          if(extract[0]=='<'){
              //If it's an opening tag
              if(extract[1]!='/'){
                  tag=extract.substr(1);
                  //If it has no attributes
                  if(tag[tag.length()-1]=='>'){
                      tag.pop_back(); //erasing the last character of the string
                  }
            //Check if any nesting is needed
            if(curr.size()>0) {
                curr+= "." + tag;
            }
            else{
                curr=tag;
            }
        }

          else{
                 string ex =extract.substr(2);
                 tag= extract.substr(2,ex.length()-1);

                 size_t pos = curr.find("." + tag);
                 if(pos != string::npos){
                     //Remove the nested tag
                     curr = curr.substr(0,pos);
                 }
                 else{
                     curr="";
            }

            }
          }

          else if(extract[0]=='"'){
              size_t pos= extract.find_last_of('"');
              string attr_value=extract.substr(1,pos-1);

              m[attr_name]= attr_value;
          }
          else{
              if(extract != "="){
                  attr_name = curr + "~" + extract;
              }
          }
      }
    }

    string query;
    for(int i=0;i<Q;i++){
        getline(cin, query);
        map<string,string>::iterator itr= m.find(query);
        if(itr != m.end()){
            cout<<itr->second<<endl;
        }
        else{
            cout<<"Not Found!"<<endl;
        }
    }






    return 0;
}
