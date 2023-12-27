#include<stdio.h>
#include<math.h>

float fx(float t,float x,float y)
{
  return (-10*(x-y));
}

float fy(float t,float al,float x,float y,float z)
{
  return (al*x-x*z-y);
}

float fz(float t,float x,float y,float z)
{
  return (x*y-(8/3)*z);
}

float fx(float t,float x,float y);
float fy(float t,float al,float x,float y,float z);
float fz(float t,float x,float y,float z);

void main()
{
  float x,y,z,t,al,k[4],m[4],n[4],h=0.01;
  FILE *fp=NULL;
  fp = fopen("q5i.txt","w");
  x = 0.1;
  y = 0.2;
  z = 0.3;
  t = 0.0;
  al = 5.0;
  do
    {
      k[0] = h*fx(t,x,y);
      m[0] = h*fy(t,al,x,y,z);
      n[0] = h*fz(t,x,y,z);
      k[1] = h*fx(t+h/2.0,x+k[0]/2.0,y+m[0]/2.0);
      m[1] = h*fy(t+h/2.0,al,x+k[0]/2.0,y+m[0]/2.0,z+n[0]/2.0);
      n[1] = h*fz(t+h/2.0,x+k[0]/2.0,y+m[0]/2.0,z+n[0]/2.0);
      k[2] = h*fx(t+h/2.0,x+k[1]/2.0,y+m[1]/2.0);
      m[2] = h*fy(t+h/2.0,al,x+k[1]/2.0,y+m[1]/2.0,z+n[1]/2.0);
      n[2] = h*fz(t+h/2.0,x+k[1]/2.0,y+m[1]/2.0,z+n[1]/2.0);
      k[3] = h*fx(t+h/2.0,x+k[2]/2.0,y+m[2]/2.0);
      m[3] = h*fy(t+h/2.0,al,x+k[2]/2.0,y+m[2]/2.0,z+n[2]/2.0);
      n[3] = h*fz(t+h/2.0,x+k[2]/2.0,y+m[2]/2.0,z+n[2]/2.0);
      x+=(k[0]+2*(k[1]+k[2])+k[3])/6.0;
      y+=(m[0]+2*(m[1]+m[2])+m[3])/6.0;
      z+=(n[0]+2*(n[1]+n[2])+n[3])/6.0;
      t+=h;
      fprintf(fp,"%f\t%f\t%f\t%f\n",x,y,z,t);
    }
  while(t<=5.0);
  fclose(fp);
}
