#include<iostream>
using namespace std;

int main() {
   int money ;
   cin >> money ;
   int a = money/500000;
   int b= (money-a*500000)/200000;
   int c = (money - a*500000 - b*200000)/100000;
   int d = (money - a*500000 - b*200000 - c*100000)/50000;
   int e = (money - a*500000 - b*200000 -c*100000 - d*50000)/20000;
   int f = (money - a*500000 - b*200000 -c*100000 - d*50000 - e*20000)/10000;
   int g = (money - a*500000 - b*200000 -c*100000 - d*50000 - e*20000 - f*10000)/5000;
   int h = (money - a*500000 - b*200000 -c*100000 - d*50000 - e*20000 - f*10000-g*5000)/2000;
   int k = (money - a*500000 - b*200000 -c*100000 - d*50000 - e*20000 - f*10000-g*5000-h*2000)/1000;
   printf("500000 : %d \n",a);
   printf("200000 : %d \n",b);
   printf("100000 : %d \n",c);
   printf("50000 : %d \n",d);
   printf("20000 : %d \n",e);
   printf("10000 : %d \n",f);
   printf("5000 : %d \n",g);
   printf("2000 : %d \n",h);
   printf("1000 : %d \n",k);
    return 0;
}
