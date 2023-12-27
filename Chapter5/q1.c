#include<stdio.h>
#include<math.h>

float f(float x,float y)
{
  return (x+y);
}

float f(float x, float y);

float exact(float x)
{
  return (2*exp(x)-x-1);
}

float exact(float x);

void main()
{
  float x,y,z,k1,k2,k3,k4,h,e;
  int n,count;
  FILE *fp=NULL;
  fp = fopen("q1.txt","w");
  printf("Enter step size :\n");
  scanf("%f",&h);
  x = 0;
  y = 1;
  z = 1; //using z as y for Euler's method.
  n = (int)(0.1/h);
  count = 0;
  printf("x\t|\ty(x)\n-------------------------\n");
  do
    {
      //RK-4 Method.
      k1 = h*f(x,y);
      k2 = h*f(x+h/2.0,y+k1/2.0);
      k3 = h*f(x+h/2.0,y+k2/2.0);
      k4 = h*f(x+h,y+k3);

      z+=h*f(x,z);//Euler's method.

      e = exact(x);
      y+=(k1+2*(k2+k3)+k4)/6.0;
      x+=h;
      count++;
      fprintf(fp,"%f\t%f\t%f\t%f\n",x,y,e,z);
      if(x>1&&(count%n==0))
	{
	  printf("%2.1f\t|\t%f\n",x,y);
	}
    }
  while(x<=5);
  fclose(fp);
}
