#include <iostream>

using namespace std;
struct fenshu{
int fenzi;
int fenmu;
fenshu(int a,int b):fenzi(a),fenmu(b){}
}a[2]{{11,6},{7,2}};
int max_yin(int a,int b){                                    //辗转相除法求最大公因数
        while(1)
        {
        if(a>b) a=a % b;
        else
        b=b%a;
        if(a==0) return b;
        if(b==0) return a;
        }
}

fenshu operator + (fenshu a,fenshu b){
        int afenzi=a.fenzi*b.fenmu;
        int bfenzi=b.fenzi*a.fenmu;
        int sumfenzi=afenzi+bfenzi;
        int sumfenmu=a.fenmu*b.fenmu;
        int tempyue=max_yin(sumfenzi,sumfenmu);
  //      int tfz=sumfenzi/tempyue;                //约分后分子
  //      int tfm=sumfenmu/tempyue;               //约分后分母
        fenshu result(sumfenzi/tempyue,sumfenmu/tempyue);
        return result;
}
void printfenshu(fenshu a){
        if(a.fenmu==1)
                cout<<a.fenzi;
        else
                cout<<a.fenzi<<"/"<<a.fenmu;

}
int main()
{
        fenshu result=a[0]+a[1];
        printfenshu(result);
        return 0;
}
