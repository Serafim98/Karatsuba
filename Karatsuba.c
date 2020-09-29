#include <stdio.h>
#include <math.h>


long int Karatsuba(long int u, long int v, int n){
 double m, p, q, r, s, pr, qs,y , x;
 if(n<=3)
 	return(u*v);
 else 
    m = n/2;
    p = u/pow(10, m);
    q = u%(long int)pow(10, m);
    r = v/(pow(10, m));
    s = v%(long int)pow(10, m);
    pr = Karatsuba(p, r, m);
    qs = Karatsuba(q, s, m);
    y = Karatsuba(p+q, r+s, m+1);
    x = pr*(pow(10, 2*m)) + (y-pr-qs)*(pow(10, m)) + qs;
    return(x);
}

int main(void){
	long int u, v, n;
	scanf("%d %d %d", &u, &v, &n);
	printf("%d", Karatsuba(u, v, n));
	return(1);
}
