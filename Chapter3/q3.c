#include<stdio.h>
#include<math.h>

//defining a function fact which returns the factorial of a number n
float fact(int n)
{
  int i;
  float f=1;
  if(n==0)
    {
      f = 1;
    }
  else
    {
      for(i=1;i<=n;i++)
	{
	  f*=i;
	}
    }
  return f;
}

float fact(int n);//declaring the function before calling it in the main.

void main()
{
  float x,t,s,acc=0.0001;
  int k,n;
  FILE *fp=NULL;
  fp = fopen("q3.txt","w");
  for(n=0;n<=2;n++)
    {
      for(x=0;x<=10.1;x+=0.1)
	{
	  k = 1;
	  t = 1/fact(n);
	  s = t;
	  do
	    {
	      t*=-(x*x)/(4.0*k*(n+k));
	      s+=t;
	      k++;
	    }
	  while(fabs(t/s)>acc);
	  s*=pow((x/2),n);
	  fprintf(fp,"%f\t%f\n",x,s);
	}
    }
  fclose(fp);
}
