#include <iostream>
#include <math.h>
using namespace std;

float triangle(float a[][3]){                      //判断三角形是否在三维空间存在，存在计算面积，不存在返回0
        //a坐标a[0][1]a[0][2]a[0][3]
        float lenth1=sqrt(pow((a[0][0]-a[1][0]),2)+pow((a[0][1]-a[1][1]),2)+pow((a[0][2]-a[1][2]),2));
        float lenth2=sqrt(pow((a[0][0]-a[2][0]),2)+pow((a[0][1]-a[2][1]),2)+pow((a[0][2]-a[2][2]),2));
        float lenth3=sqrt(pow((a[1][0]-a[2][0]),2)+pow((a[1][1]-a[2][1]),2)+pow((a[1][2]-a[2][2]),2));
        if (lenth1+lenth2<lenth3||lenth3+lenth2<lenth1||lenth1+lenth3<lenth2)
                return 0;
        float p=lenth1+lenth2+lenth3;
        p=p/2;
        float sum=sqrt(p*(p-lenth1)*(p-lenth3)*(p-lenth2));
        return sum;
}

        int zuhe(int a,int b){                                  //排列组合，a小b大
                if(a==0)
                        return 1;
                else{
                        int tempb=1;
                        int tempa=1;
                                for(int i=0;i<a;i++){
                                        tempb=tempb*(b-i);
                                        tempa=tempa*(a-i);
                                }
                        return tempb/tempa;
                }

        }

        int cal(int a,int b, int c,int d){                    //C(a,b)*C(c,d)
                int temp=1;
                temp=zuhe(a,b)*zuhe(c,d);
                return temp;
        }

        int jiecheng(int a){                                 //阶乘
                if(a==0)
                        return 1;
                long long temp=a;
                for(int i=a-1;i>0;i--)
                        temp=temp*i;
                return temp;
        }
int main()
{
        float a[3][3]={{0,0,0},{0,1,0},{1,0,0}};
        cout << triangle(a)<<endl;
        cout<<jiecheng(0);
        return 0;
}
