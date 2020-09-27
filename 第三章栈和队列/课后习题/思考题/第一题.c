#include<stdio.h>
#include<math.h>

/*递归*/
double sqrt1(double A,double p,double e){
    if(fabs(p*p-A)<e)
        return p;
    else {
        return sqrt1(A, (p + A / p) / 2, e);
    }
}

/*非递归*/
double sqrt2(double A,double p,double e){
    while (fabs(p*p-A)>=e)
    {
        p = (p + A / p) / 2;
    }
    return p;
}

int main(){
    printf("%f,%f", sqrt1(2, 10, 0.0001), sqrt2(2, 1.4, 0.0001));
    return 0;
}