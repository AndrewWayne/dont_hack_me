//
//  main.cpp
//  dont_hack_me
//
//  Created by admin on 2018/8/20.
//  Copyright © 2018年 AndrewWayne(小黑AWM). All rights reserved.
//
#include "Header.h"
char inpath[100];//0-62
char outpath[100];
char pathout[100];
string temp;
stack<string> have;
stack<string> func;
string rand_str()
{
    string str="              ";
    int i;
    for(i=1;i<=12;++i)
    {
        switch((rand()%3))
        {
            case 1:
                str[i]='A'+rand()%26;
                break;
            case 2:
                str[i]='a'+rand()%26;
                break;
            default:
                str[i]='_';
                break;
        }
    }
    return str;
}
int main(int argc, const char * argv []) {
    srand(time(NULL));
    printf("Pls input the source file path:");
    cin>>inpath;
    printf("\n");
    printf("Pls input the target file path:");
    cin>>outpath;
    freopen(inpath,"r",stdin);
    freopen(outpath,"w",stdout);
    while(cin>>temp)
    {
        if(temp[0]=='#'){
            cout<<temp<<endl;
            continue;
        }
        have.push(temp);
        func.push(rand_str());
        cout<<func.top()<<endl;
    }
    printf("\n");
    while(!have.empty()){
        cout<<"#define "<<func.top()<<" "<<have.top()<<endl;
        func.pop();
        have.pop();
    }
    cerr<<"Probably Succeed!"<<endl;
    return 0;
}
