//without using scanf
#include<stdio.h>
#include<math.h>

float z,x1,x2,acc=0.00001;

float series(float x)
{
  float t,sum,k;
  t=1.0;
  sum=1.0;
  k=1.0;
  do
    {
      t*=-(x*x)/(4*k*k);
      sum+=t;
      k+=1.0;
    }
  while(fabs(t/sum)>acc);
  return sum;
}

float series(float x);

float secant()
{
  float f1,f2,x3;
  do
    {
      f1 = series(x1);
      f2 = series(x2);
      x3 = (f2*x1 - x2*f1)/(f2-f1);
      x1 = x2;
      x2 = x3;
      z = fabs(f2);
    }
  while(z>acc);
  return x2;
}

float secant();

void main()
{
  float x,root;
  int i;
  FILE *fp=NULL;
  fp = fopen("q2.txt","w");
  for(x=0;x<=8;x+=0.1)
    {
      fprintf(fp,"%f\t%f\n",x,series(x));
      if(series(x)*series(x+0.1)<0)
	{
	  x1 = x;
	  x2 = x+0.1;
	  root = secant();
	  printf("root = %f\tf(x) = %f\n",root,series(root));
	}
    }
  fclose(fp);
}
