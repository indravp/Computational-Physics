#include<stdio.h>
#include<math.h>

void main()
{
  float x,a;
  int count;
  FILE *fp=NULL;
  fp = fopen("q6.txt","w");
  for(a=0.0;a<=4.1;a+=0.05)
    {
      x = 0.7;
      count = 0;
      do
	{
	  x = a*x*(1-x);
	  count++;
	  if(count>10000)
	    {
	      fprintf(fp,"%f\t%f\n",a,x);
	    }
	}
      while(count<10100);
    }
  fclose(fp);
}
