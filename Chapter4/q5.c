#include<stdio.h>
#include<math.h>

float f(float x)
{
  return (16*pow(x,4)-8*pow(x,3)-8*pow(x,2)+1);
}

float f(float x);

float secant(float x1,float x2)
{
  float f1,f2,x3,z;
  do
    {
      f1 = f(x1);
      f2 = f(x2);
      x3 = (f2*x1-f1*x2)/(f2-f1);
      x1 = x2;
      x2 = x3;
      z = fabs(f2);
    }
  while(z>0.0001);
  return x2;
}

float secant(float x1,float x2);

void main()
{
  float x,root;
  FILE *fp=NULL;
  fp = fopen("q5.txt","w");
  for(x=-1.0;x<=1.1;x+=0.1)
    {
      fprintf(fp,"%f\t%f\n",x,f(x));
      if(f(x)*f(x+0.1)<0)
	{
	  root = secant(x,x+0.1);
	  printf("root = %f\tf(x) = %f\n",root,f(root));
	}
    }
  fclose(fp);
}
