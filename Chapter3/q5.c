#include<stdio.h>
#include<math.h>

void main()
{
  float x,t,s,pi,acc=0.0001;
  int k;
  FILE *fp=NULL;
  fp = fopen("q5.txt","w");
  pi = 4*atan(1.0);
  for(x=0.0;x<=5.1;x+=0.1)
    {
      t = 1/(2*sqrt(pi));
      s = t;
      k = 2;
      do
	{
	  t*=(2*x*x*(3-k))/(k*(k-1.0));//take the ratio of k and (k-2) term, as k is incremented by 2. Put n=2.
	  s+=t;
	  k+=2;
	}
      while(fabs(t/s)>acc);
      fprintf(fp,"%f\t%f\n",x,s);
    }
  fclose(fp);
}
