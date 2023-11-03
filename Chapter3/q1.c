#include<stdio.h>

void main()
{
  float x,t,s;
  int n=1;
  for(x=0;x<=2.1;x+=0.5)
    {
      t = 1/(x*x);//taking the ratio of 2nd and 3rd terms.
      s = t+1;//since the first term is 1 and not considered for ratio hence it is added here
      do
	{
	  t*=1/x;
	  s+=t;
	  n++;
	}
      while(n<=18);//do while loop runs for one extra iteration as the condition is checked at the end.
      printf("x = %f\tsum = %f\n",x,s);
    }
}
