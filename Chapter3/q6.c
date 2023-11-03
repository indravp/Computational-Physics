#include<stdio.h>
#include<math.h>

void main()
{
  float x,t,s,acc=0.0001;
  int n;
  FILE *fp=NULL;
  fp = fopen("q6.txt","w");
  for(x=-10.0;x<=0.1;x+=0.05)
    {
      t = 1;
      s = 1;
      n = 1;
      do
	{
	  t*=pow(x,3)/(3*n*(3*n-1));
	  s+=t;
	  n++;
	}
      while(fabs(t/s)>acc);
      s*=0.35503;
      fprintf(fp,"%f\t%f\n",x,s);
    }
  fclose(fp);
}
