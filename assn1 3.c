#include <stdio.h>
#include <math.h>
/////////////////////////////////////////////////////////////////////////////////////////////
float expfor_ln(float x)
{
	int acc = 200;
	
	float temp = (x-1)/(x+1);
	float ans = temp;
	int i ;
	for(i = 2 ; i<= acc ;i++)
	{
		
		temp = temp*((x-1)/(x+1))*((x-1)/(x+1));
		ans = ans+temp/(2*i - 1);
		
	}
	ans = ans*2;
	
	return ans;
	
}
///////////////////////////////////////////////////////////////////////////////////////////////
float expfor_ex( float p , float q)
{
	int acc = 200;
	float ans1 = 1;
	float temp = 1;
	int i ;
	float power = q*expfor_ln(p);
	for( i= 1; i<=acc ;i++)
	{
		temp = (temp*power)/i;
		ans1 = ans1 +temp;
	}
	
	return ans1;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
///////CASE 2////////////////////////////////////////////////////////////////////////////////////////
float XintYfloat(int a , float b) /// x integer y float
{
	if(b>0)
	{
		if(a>0)
		{
			return expfor_ex((float)a , (float)b);
		}
		else if(a<0)
		{
			printf("Not defined");
		}
		else
		{
			printf("0");
		}
	}
	else if(b<0)
	{
		if(a>0)
		{
			float ans1 = expfor_ex((float)a , (-1)*(float)b);
			float ans = pow(ans1 , -1);
			return ans;
		}
		else if(a<0)
		{
			printf("not defined \n");
		}
		else //a == 0
		{
			printf("Infinity \n");
		}
	}
	else //b === 0
	{
		if(a>0)
		{
			printf("1 \n");
		}
		else if(a<0)
		{
			printf("1 \n");
		}
		else //a == 0
		{
			printf("1 \n");
		}
	}
	
	
	
	
	
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////CASE 1?/////////////////////////////////////////////////////////////////////////////////
float XintYint(int a , int b)    ///    x integer y integer a = x   ,   y = b
{
	if(b>0)
	{
		if(a>0)
		{
			return (int)expfor_ex( (float)a , (float)b);
		}
		else if(a==0)
		{
			return 0;
		}
		else //a<0
		{
			if(b%2 == 0)
			{
				return (int)(expfor_ex( (-1)*(float)a , (float)b));
			}
			else
			{
				return (-1)*(expfor_ex( (-1)*(float)a , (float)b));
			}
		}
	}
	else if(b<0)
	{
		if(a>0)
		{
//			return (1/(expfor_ex( (float)a , (float)b)));
			float ans1 = expfor_ex((float)a , (-1)*(float)b);
			float ans = pow( ans1 , -1);
			return ans;
		}
		else if(a==0)
		{
			printf("Not defined");
			return 0;
		}
		else //a<0
		{
			if(b%2 == 0) //even power no -ve sign
			{
				float ans2 = (expfor_ex( (-1)*(float)a , (-1)*(float)b));
				float ans = pow(ans2 ,  -1);
				return ans;
			}
			else // odd power -ve sign
			{
				float ans2 = (expfor_ex( (-1)*(float)a , (-1)*(float)b));
				float ans = pow(ans2 ,  -1);
				return (-1)*ans;
			}
		}
	}
	else //b == 0
	{
		if(a > 0)
		{
			printf("1 \n");
			return 0;
		}
		if(a<0)
		{
			printf("1 \n");
			return ;
		}
		if(a == 0)
		{
			printf("Not defined \n");
			return ;
		}
	} 
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
int main(void) 
{
	// your code goes here
	
	printf("enter inputs for the form x^y \n");
	float x , y;
	
	printf("enter  x \n");
	scanf("%f" , &x);
	printf("enter y \n");
	scanf("%f" , &y);
	
	if(floor(y) == y)        ///// y is integer
	{
		float ans1 = XintYint(x , y);
		printf("%f" , ans1);			
		
	}
	
	else                     /// y is float
	{
		float case2ans = XintYfloat(x , y);
		printf("%f" , case2ans);
	}

	
}


