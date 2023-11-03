#include<stdio.h>
#include<math.h>

void main()
{
  float x,t,s,pi,acc=0.0001;
  int n;
  FILE *fp=NULL;
  fp = fopen("q4.txt","w");
  pi = 4*atan(1.0);
  for(x=0.0;x<=1.0;x+=0.1)
    {
      t = x;
      s = x;
      n = 1;
      do
	{
	  t*=-(pi*pi*pow(x,4))/(4*n+1);
	  s+=t;
	  n++;
	}
      while(fabs(t/s)>acc);
      fprintf(fp,"%f\t%f\n",x,s);
    }
  fclose(fp);
}
