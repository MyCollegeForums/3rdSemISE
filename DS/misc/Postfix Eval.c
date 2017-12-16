#include <stdio.h>
#include <math.h>

#define ST_SIZE 20


void push ( double item, int *top, double * s);
char pop ( int *top, double * s);



double op( char symbol, double op1 , double op2 )
{
	switch( symbol )
 	{
		case '+': return op1+op2;
		case '-': return op1-op2;
		case '*': return op1*op2;
		case '/': return op1/op2;
		case '$': 
		case '^': return pow(op1,op2);
		default: return 0;
	}
}



void push ( double item, int *top, double * s)
{
	if( *top == ST_SIZE - 1 )
	{
		printf("Stack Overflow");
		return;	
	}
	s[++(*top)] = item;
}


char pop ( int *top, double * s)
{
	if( *top == -1 )
	{
		printf("Stack underflow");
		return 0;	
	}
	return s[(*top)--];
}

int isitdigit( char symbol )
{
	return (symbol >= '0' && symbol <='9');
}




int main ( void )
{
	double s[ST_SIZE], op1,op2, res;
	char postfix[ST_SIZE],symbol;
	int top=-1, i;
	printf("Enter Postfix Expression:");
	scanf("%s",postfix);
	for( i = 0; postfix[i]; i++ )
	{
		symbol=postfix[i];
		if( isitdigit(symbol) )
			push( symbol-'0',&top,s);
		else
		{
			op2 = pop(&top,s);
			op1 = pop(&top,s);
			res = op(symbol,op1,op2);
			push( res , &top , s);
		}
	}
	res = pop(&top,s);
	printf("Value of expression is: %lf\n",res);
	return 0;
}


