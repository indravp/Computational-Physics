#include<stdio.h>
#include<math.h>

void main()
{
  float x,t,s,pi,acc=0.0001;
  int i;
  FILE *fp=NULL;
  fp = fopen("q2.txt","w");
  pi = 4*atan(1);//since tan inverse 1 is pi/4.
  for(x=0;x<=pi+0.1;x+=0.1)
    {
      t = 1;
      s = 1;
      i = 1;
      do
	{
	  t*=-(x*x)/(2.0*i*(2*i-1));
	  s+=t;
	  i+=1;
	}
      while(fabs(t/s)>acc);//fabs gives absolute value(modulus).
      fprintf(fp,"%f\t%f\t%f\n",x,s,cos(x));
    }
  fclose(fp);
}
