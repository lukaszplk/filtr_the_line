#include <iostream>
#include <string>
#include <vector>

using namespace std;

string filter(string str){
    string newstr;
    for(int i=0;i<str.length();i++){
        //replace capital letters with small ones
        if(int(str[i])<=90 && int(str[i])>=65 && !(((int(newstr[newstr.size()-2])==33 || int(newstr[newstr.size()-2])==46 || int(newstr[newstr.size()-2])==63)) && int(newstr[newstr.size()-1])==32)){
            newstr.push_back(char(int(str[i])+32));
        //remove space at the end of line
        }else if(i==str.length()-1 && int(str[i])==32){
            continue;
        //remove double space or space before punctuation mark
        }else if(int(str[i])==32 && (int(str[i+1])==32||int(str[i+1])==33||int(str[i+1])==44||int(str[i+1])==46||int(str[i+1])==63)){
            continue;
        //put space after punctuation mark unless next sign is not one of them
        }else if((int(str[i])==33||int(str[i])==46||int(str[i])==63) && int(str[i+1])!=32 && int(str[i+1])!=33 && int(str[i+1])!=46 && int(str[i+1])!=63 && i!=str.length()-1){
            
            newstr.push_back(str[i]);
            newstr.push_back(' ');
        //make capital letter after punctuation mark
        }else if((int(newstr[newstr.size()-2])==33 || int(newstr[newstr.size()-2])==46 || int(newstr[newstr.size()-2])==63)&& int(newstr[newstr.size()-1])==32){
            if(int(str[i])<=122 && int(str[i])>=97){
                newstr.push_back(char(int(str[i])-32));
            }else{
                newstr.push_back(str[i]);
            }
        }else{
            newstr.push_back(str[i]);
        }
    }
    return newstr;
}

int main(){
    int n;
    string line;
    vector<string> vec;
    cin>>n;
    cin.ignore();
    char last='.';
    for(int i=0;i<n;i++){
        
        if(last == '.'||last == '?'||last == '!'){
            getline(cin,line);
            //remove space at the beginning of line
            while(int(line[0])==32){
                line = line.substr(1, line.size()-1);
            }
            string head, tail;
            
            
            head = line[0];
            //make the first letter capitalized
            if(int(head[0])<=122 && int(head[0])>=97){
                head = char(int(head[0]) - 32);
            }

            // filter the line ignoring the first character
            tail = line.substr(1,line.size()-1);
            tail = filter(tail);

            //concat filtered line with first char
            for(int i=0;i<tail.size();i++){
                head.push_back(tail[i]);
            }
            
            //update last char
            last = head[head.size()-1];

            vec.push_back(head);
            
        }else{
            //execute if line is not first and previous line is not ended with punctuation mark
            getline(cin,line);
            //remove space from the beggining of line
            while(int(line[0])==32){
                line = line.substr(1, line.size()-1);
            }
            line = filter(line);
            
            last = line[line.size()-1];
            
            vec.push_back(line);   
        }   
    }

    for(int i=0;i<vec.size() ;i++){
        cout<<vec[i]<<endl;        
    }
}