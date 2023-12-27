#include<stdio.h>
#include<math.h>

float f4(float x)
{
  float s,t;
  int k;
  t=1.0;
  s=1.0;
  for(k=1;k<=10;k++)
    {
      t*=-x*x/(2.0*k*(2.0*k+1.0));
      s+=t;
    }
  return s;
}

float f4(float x);

float f1(float x,float y,float z)
{
  return (z);
}

float f2(float x,float y,float z)
{
  return (f4(x)-4*x*y-z);
}

float f1(float x,float y,float z);
float f2(float x,float y,float z);

void main()
{
  float x,y,z,k[4],m[4],h=0.01;
  FILE *fp=NULL;
  fp = fopen("q4.txt","w");
  x = 0;
  y = 0;
  z = 1;
  do
    {
      k[0] = h*f1(x,y,z);
      m[0] = h*f2(x,y,z);
      k[1] = h*f1(x+h/2.0,y+k[0]/2.0,z+m[0]/2.0);
      m[1] = h*f2(x+h/2.0,y+k[0]/2.0,z+m[0]/2.0);
      k[2] = h*f1(x+h/2.0,y+k[1]/2.0,z+m[1]/2.0);
      m[2] = h*f2(x+h/2.0,y+k[1]/2.0,z+m[1]/2.0);
      k[3] = h*f1(x+h,y+k[2],z+m[2]);
      m[3] = h*f2(x+h,y+k[2],z+m[2]);
      y+=(k[0]+2*(k[1]+k[2])+k[3])/6.0;
      z+=(m[0]+2*(m[1]+m[2])+m[3])/6.0;
      x+=h;
      fprintf(fp,"%f\t%f\n",x,y);
    }
  while(x<=1.1);
  fclose(fp);
}
