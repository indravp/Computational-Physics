#include<stdio.h>
#include<math.h>

float f1(float t,float theta, float z)
{
  return z;
}

float f2(float t,float theta,float z)
{
  return (-sin(theta));
}

float f1(float t,float theta, float z);
float f2(float t,float theta,float z);

float exact(float t,float a, float theta)
{
  return (a*cos(theta*t));
}

float exact(float t,float a,float theta);

void main()
{
  float z,t,theta,a,e,pi,k1,k2,k3,k4,m1,m2,m3,m4,h=0.01;
  FILE *fp=NULL;
  fp = fopen("q2.txt","w");
  pi = 4*atan(1.0);
  for(a=0.1;a<=1.1;a+=0.1)
    {
      theta = a;
      z = 0;
      t = 0;
      do
	{
	  k1 = h*f1(t,theta,z);
	  m1 = h*f2(t,theta,z);
	  k2 = h*f1(t+h/2.0,theta+k1/2.0,z+m1/2.0);
	  m2 = h*f2(t+h/2.0,theta+k1/2.0,z+m1/2.0);
	  k3 = h*f1(t+h/2.0,theta+k2/2.0,z+m2/2.0);
	  m3 = h*f2(t+h/2.0,theta+k2/2.0,z+m2/2.0);
	  k4 = h*f1(t+h,theta+k3,z+m3);
	  m4 = h*f2(t+h,theta+k3,z+m3);

	  theta+=(k1+2*(k2+k3)+k4)/6.0;
	  z+=(m1+2*(m2+m3)+m4)/6.0;
	  t+=h;
	  e = exact(t,a,theta);
	  if((fabs(a-0.1)<0.0001)||(fabs(a-0.5)<0.0001)||(fabs(a-1.0)<0.0001))
	    {
	      fprintf(fp,"%f\t%f\t%f\n",t,theta,e);
	    }
	}
      while(t<=8*pi);
    }
  fclose(fp);
 }
  
