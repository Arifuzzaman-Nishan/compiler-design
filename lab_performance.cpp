#include<bits/stdc++.h>
using namespace std;

stack <char> s;
char c;

bool parenthesis_check(string str)
{
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '(' || str[i] == '{'){
            s.push(str[i]);
            continue;
        }

        if(s.empty()){
            return false;
        }

        switch(str[i]){
            case ')':
                c = s.top();
                s.pop();

                if(c == '{'){
                    return false;
                }
                break;

            case '}':
                c = s.top();
                s.pop();

                if(c == '('){
                    return false;
                }
                break;
        }
    }

    return (s.empty());


}


int main()
{
    string str;
    getline(cin,str,'*');

    string ss;

    for(int i = 0 ; i < str.length() ; i++){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] == ' ') || (str[i] == '\n')){
            continue;
        }else ss += str[i];
    }

    string strn;

    for(int i = 0 ; i < ss.length() ; i++){
        if(str[i] == '"'){
            for(int j = i+1 ; j < ss.length() ; j++ ){
                if(str[j] == '"'){
                    strn += ss[i+1];
                }
            }
        }
    }

    cout << strn << endl;

    if(parenthesis_check(strn)){
        cout << "okay" << endl;
    }else cout << "Not okay" <<endl;



    return 0;
}

