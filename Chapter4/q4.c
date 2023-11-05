//without scanf
#include<stdio.h>
#include<math.h>

float f(float psi, float t)
{
  return (psi-0.8*sin(psi)-t);
}

float der_f(float psi, float t)
{
  return(1-0.8*cos(psi));
}

float f(float psi, float t);
float der_f(float psi, float t);

float newton(float psi, float t)
{
  float h,f1,f2;
  do
    {
      f1 = f(psi,t);
      f2 = der_f(psi,t);
      h = -f2/f1;
      psi+=h;
    }
  while((h/psi)>0.001);
  return psi;
}

void main()
{
  float psi,t,pi,root,x,y,r,c;
  FILE *fp=NULL;
  fp = fopen("q4.txt","w");
  pi = 4*atan(1.0);
  for(t=0.0;t<=2*pi;t+=0.1)
    {
      psi = t;
      root = newton(psi,t);
      r = 2*(1-0.8*cos(root));
      c = (cos(root)-0.8)/(1-0.8*cos(root));
      x = r*c;
      y = r*sqrt(1-c*c);
      fprintf(fp,"%f\t%f\n",x,y);
      fprintf(fp,"%f\t%f\n",x,-y);
    }
  fclose(fp);
}
