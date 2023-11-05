//Newton-Raphson is not working correctly.
#include<stdio.h>
#include<math.h>

float a,b,x1,x2,z,acc=0.0001;
//global variables, can be used anywhere in the program without defining in other code fragments



float f(float x)
{
  return (exp(a*x)-b*x*x);//given function
}

float derivative_f(float x)
{
  return (a*exp(a*x)-2*b*x);//derivative of the function
}

float f(float x);
float derivative_f(float x);

float bisection(float x)
{
  float xm,xl,xr;
  if(f(x)*f(x+0.1)<0)
    {
      xl = x;
      xr = x+0.1;
      do
	{
	  xm = (xl+xr)/2.0;
	  if(f(xm)*f(xl)>0)
	    {
	      xl = xm;
	    }
	  if(f(xm)*f(xl)<0)
	    {
	      xr = xm;
	    }
	  z = fabs((xl-xr)/(xl+xr));
	}
      while(z>acc);
    }
  return xm;
}

float bisection(float x);

float secant()
{
  float f1,f2,x3;
  do
    {
      f1 = f(x1);
      f2 = f(x2);
      x3 = (f2*x1 - x2*f1)/(f2-f1);
      x1 = x2;
      x2 = x3;
      z = fabs(f2);
    }
  while(z>acc);
  return x2;
}

float secant();

float newton(float x)
{
  float f1,f2,h;
  do
    {
      f1 = f(x);
      f2 = derivative_f(x);
      h = -f1/f2;
      x+=h;
    }
  while(fabs(h/x)>acc);
  return f1;
}

float newton(float x);

void main()
{
  int i,n,m;
  float x,root;
  FILE *fp=NULL;
  fp = fopen("q1.txt","w");
  printf("Enter a,b\n");
  scanf("%f,%f",&a,&b);
  printf("x\t\tf(x)\n");
  for(x=-1.0;x<=1.1;x+=0.1)
    {
      printf("%f\t%f\n",x,f(x));
      fprintf(fp,"%f\t%f\n",x,f(x));
    }
  printf("Enter Number of roots :\n");
  scanf("%d",&n);
  printf("Enter:\n1 for bisection method.\n2 for secant method.\n3 for newton-raphson method\n");
  scanf("%d",&m);
  for(i=1;i<=n;i++)
    {
      if(m==1)
	{
	  printf("Enter x1,x2:\n");
	  scanf("%f,%f",&x1,&x2);
	  for(x=x1;x<=x2;x+=0.1)
	    {
	      root = bisection(x);
	    }
	  printf("root = %f\tf(x) = %f\n",root,f(root));
	}
      else if(m==2)
	{
	  printf("Enter x1,x2:\n");
	  scanf("%f,%f",&x1,&x2);
	  root = secant();
	  printf("root = %f\tf(x) = %f\n",root,f(root));
	}
      else if(m==3)
	{
	  printf("Enter x:\n");
	  scanf("%f",&x);
	  root = newton(x);
	  printf("root = %f\tf(x) = %f\n",root,f(root));
	}
    }
}
