#include <iostream>
#include <string.h>
using namespace std;
#define maxlenth 100
#include <vector>

        int maxlen1(string a,string b){                //只返回长度
                char *a1=new char[maxlenth];
                char *b1=new char[maxlenth];
                strcpy(a1,a.c_str());
                strcpy(b1,b.c_str());
                int tempi=0,tempj=0;
                int templenth=0;
                int maxlen=0;

                for(int i=0;a1[i]!='\0';i++)
                        for(int j=0;b1[j]!='\0';j++){
                                if(a1[i]==b1[j]){
                                        tempi=i;
                                        tempj=j;
                                        while(a1[i]==b1[j]&&a[i]!='\0'){
                                                i++;
                                                j++;
                                                templenth++;
                                        }
                                        if(templenth>maxlen){
                                                maxlen=templenth;

                                        }
                                        templenth=0;
                                        i=tempi;
                                        j=tempj;
                                }
                }
                return maxlen;
        }
        int firstOf_a=-1;                               //不需要索引去掉即可
        int firstOf_b=-1;
        vector <char> result_array;
        int maxlen2(string a,string b){                   //返回长度，重复子序列放在vector中，最开始重复字母索引放在全局变量firstOf_a之中
                char *a1=new char[maxlenth];
                char *b1=new char[maxlenth];
                strcpy(a1,a.c_str());
                strcpy(b1,b.c_str());
                int tempi=0,tempj=0;
                int templenth=0;
                int maxlen=0;
                vector <char>temp;
                for(int i=0;a1[i]!='\0';i++)
                        for(int j=0;b1[j]!='\0';j++){
                                if(a1[i]==b1[j]){
                                        tempi=i;
                                        tempj=j;
                                        while(a1[i]==b1[j]&&a[i]!='\0'){
                                                temp.push_back(a[i]);
                                                i++;
                                                j++;
                                                templenth++;

                                        }
                                        if(templenth>maxlen){
                                                maxlen=templenth;
                                                firstOf_a=i-templenth;                  //不需要索引去掉即可
                                                firstOf_b=j-templenth;                  //
                                                result_array=temp;

                                        }
                                        templenth=0;
                                        temp.clear();
                                        i=tempi;
                                        j=tempj;
                                }
                }
                return maxlen;
        }


//3-2
//len(a)-len(max(相同子列2))
int main()
{
        string a;
        string b;
        cin>>a>>b;

        //int result=maxlen1(a,b);
        int result=maxlen2(a,b);

        cout<<result<<endl<<"showoff"<<endl;
        for(vector <char>::iterator it=result_array.begin();it!=result_array.end();it++)
                cout<<*it;
        cout<<endl<<"Index a"<<firstOf_a<<endl<<"Index b"<<firstOf_b<<endl;
        return 0;
}
