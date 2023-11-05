#include<stdio.h>
#include<math.h>

float f(float x,float y)
{
  return (pow(x,3)+pow(y,3)+x*y+1);
}

float f(float x,float y);

float secant(float x,float y1, float y2)
{
  float f1,f2,y3,z,acc=0.0001;
  do
    {
      //printf("1\n");
      f1 = f(x,y1);
      f2 = f(x,y2);
      y3 = (f2*y1-f1*y2)/(f2-f1);
      // printf("y3 %f\n",y3);
      y1 = y2;
      y2 = y3;
      z = fabs(f2);
      //printf("%f\n",z);
    }
  while(z>acc);
  return y2;
}

float secant(float x,float y1, float y2);

void main()
{
  float x,y,root;
  FILE *fp=NULL;
  fp = fopen("q3.txt","w");
  for(x=-1.5;x<=1.6;x+=0.1)
    {
      for(y=-2.0;y<=2.1;y+=0.1)
	{
	  if((f(x,y)*f(x,y+0.1))<0&&y<=2.0)
	    {
	      printf("%f\t%f\n",x,y);
	      root = secant(x,y,y+0.1);
	      fprintf(fp,"%f\t%f\n",x,root);
	    } 
	}
    }
  fclose(fp);
}
