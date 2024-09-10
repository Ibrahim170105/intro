#include <iostream>
#include<cstring>
using namespace std;

const int N = 25;
char instr[N];
char outstr[N];
char stack[N]; 
int top;
int rear;

void push(char newdata)
{
	top = top + 1;
	stack[top] = newdata;
}

char pop()
{
	char topData;
	topData = stack[top];
	top = top - 1;
	return topData;
}

char readTop()
{
	char topData;
	topData = stack[top];
	return topData;
}
int precedence(char op) 
{
    switch (op)
	{
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        //default:
           // return 0;	
    }
    return 0;
}

void append(char newdata)
{
	if(rear == N-1)
	{
		cout<<"\nError!Queue is full.";
	}
	else
	{
		rear = rear+1;
		outstr[rear] = newdata;
	//	cout<<"\n-"<<outstr[rear]<<"Sent to Output";
	}
}

void infix_to_postfix(char instr[])
{
	int i = 0;
	while(instr[i] != '\0')
	{	
	cout<<"\n----"<<instr[i]<<"-----";
		if(instr[i] == '{' || instr[i] == '[' || instr[i] == '(')
		{
			cout<<"\nCase 2(Left bracket) : \n Pushing "<<instr[i]<<" in the stack";
			push(instr[i]);
		//	cout<<"\n\tstack top: "<<stack[top];
		}
		else if(instr[i] == '+' || instr[i] == '-' || instr[i] == '*' || instr[i] == '/' || instr[i] == '^')
		{
			cout<<"\nCase 3(operators) :";
		//	cout<<"\n\tstack top: "<<stack[top];
		//	cout<<"\t instr[i]: "<<instr[i];
			while(precedence(stack[top]) >= precedence(instr[i]))
			{
				cout<<"\n\tRemoving "<<readTop()<<" from stack and sending to output.";
				append(pop());
			}
			cout<<"\n\tpushing "<<instr[i]<<" in the stack.";
			push(instr[i]);
		}
		else if(instr[i] == '}' || instr[i] == ']' || instr[i] == ')')
		{
			cout<<"\nCase 4 (right bracket)";
			while(stack[top] != '(' && stack[top]  != '[' && stack[top] != '{')
			{
				cout<<"\n\tRemoving "<<readTop()<<" from stack and sending to output.";
				append(pop());
			}
			cout<<"\n\tRemoving "<<readTop()<<"from stack.";
			pop();
		}
		else
		{
			cout<<"\nCase 1 (operand):";
			cout<<"\nSending "<<instr[i]<<" to output.";
			append(instr[i]);
		}
		i++;
   }
}


int main()
{
	top = -1;
	rear = -1;
	cout<<"Input String\n";
	strcpy(instr,"(3+(4+6*2)*((8-3)*(2-5)+4)-2*6)");
	cout<<instr<<endl;
	push('(');
	infix_to_postfix(instr);
	cout<<"\nOutput String\n";
	append('\0');
	cout<<outstr;
}