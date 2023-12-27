#include<stdio.h>
#include<math.h>

float fx(float t,float x,float y)
{
  return (0.25*x-0.01*x*y);
}

float fy(float t,float x,float y)
{
  return (-y+0.01*x*y);
}

float fx(float t,float x,float y);
float fy(float t,float x,float y);

void main()
{
  float x,y,i,t,k[4],m[4],h=0.01;
  FILE *fp=NULL;
  fp = fopen("q3.txt","w");
  for(i=5.0;i<=25.1;i+=5.0)
    {
      x = 100;
      t = 0;
      y = i;
      do
	{
	  k[0] = h*fx(t,x,y);
	  m[0] = h*fy(t,x,y);
	  k[1] = h*fx(t+h/2.0,x+k[0]/2.0,y+m[0]/2.0);
	  m[1] = h*fy(t+h/2.0,x+k[0]/2.0,y+m[0]/2.0);
	  k[2] = h*fx(t+h/2.0,x+k[1]/2.0,y+m[1]/2.0);
	  m[2] = h*fy(t+h/2.0,x+k[1]/2.0,y+m[1]/2.0);
	  k[3] = h*fx(t+h,x+k[3],y+m[3]);
	  m[3] = h*fy(t+h,x+k[3],y+m[3]);
	  x+=(k[0]+2*(k[1]+k[2])+k[3])/6.0;
	  y+=(m[0]+2*(m[1]+m[2])+m[3])/6.0;
	  t+=h;
	  fprintf(fp,"%f\t%f\n",x,y);
	}
      while(t<=20.1);
    }
  fclose(fp);
}
