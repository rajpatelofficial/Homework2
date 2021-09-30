//
//  main.cpp
//  CompilerHomework
//
//  Created by Admin on 9/22/21.
//

#include <iostream>
#include <fstream>//i/o data files
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class LexAnalyzer{
private:
    vector<string> lexemes;  // source code file lexemes
    vector<string> tokens;   // source code file tokens
    map<string, string> tokenmap;  // valid lexeme/token pairs
    // other private methods
    
public:
    LexAnalyzer(istream& infile){
// pre: parameter refers to open data file consisting of token and
// lexeme pairs i.e.  s_and and t_begin begin t_int 27.  Each pair    // appears on its own input line.
// post: tokenmap has been populated
    
        string lexeme;
        string token;
        while(!infile.eof()){
            infile>>lexeme;
            infile>>token;
            tokenmap[lexeme]= token;
    }
        map<string,string>::iterator itr;
        for(itr = tokenmap.begin(); itr != tokenmap.end();itr++){
           // cout<<itr->first<< " : "<<itr->second<<endl;
    }
    }

    void scanFile(istream& infile, ostream& outfile){;
        char ch;
        char operators[] = "+-*/%";
        int i = 0;
        
        while(!infile.eof()){
           ch = infile.get();
            
            for(i=0;i<6;i++){
                if(ch == operators[i] && operators[i] == '+')
                    cout<<"s_plus : "<<ch<<endl;
                else if(ch == operators[i] && operators[i] == '-')
                    cout<<"s_minus : "<<ch<<endl;
                else if(ch == operators[i] && operators[i] == '*')
                    cout<<"s_mult : "<<ch<<endl;
                else if(ch == operators[i] && operators[i] == '/')
                    cout<<"s_div : "<<ch<<endl;
                else if(ch == operators[i] && operators[i] == '%')
                    cout<<"s_mod : "<<ch<<endl;
                    
            }
            
            
        }//end while
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    ifstream infile("tokens.txt");
    
    if(!infile){
        cout<<"unable to get file"<<endl;
        exit(-1);
    }
    
    ifstream infileSource("source.txt");
    
    if(!infileSource){
        cout<<"unable to get file"<<endl;
        exit(-1);
    }
    
    ofstream outfile("Result");
    if(!outfile){
        cout<<"Error: File can't be opened"<<endl;
        exit(-1);
    }
    
    LexAnalyzer lex(infile);
    lex.scanFile(infileSource, outfile);
    
    
    
    return 0;
};


