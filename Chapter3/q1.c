#include<stdio.h>

void main()
{
  double x,t,s;
  int n;
  printf("x\t\tsum\n");
  for(x=0.0;x<=2.1;x+=0.5)
    {
      t = 1/(x*x);
      s = t+1;
      for(n=3;n<=20;n++)
	{
	  t*=1/x;
	  s+=t;
	}
      printf("%f\t%12.5e\n",x,s);
    }
}
