#include <iostream>
#include <stack>

using namespace std;
// making a function that checks for operators or brackets
bool isOperator(char check)
{
    switch(check)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}
// defines the precedence of each operator
int precedence(char operand)
{
    switch(operand)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int main()
{
	//creating a stack for the operators
    stack<char> op;
    //string that is going to be printed out at the end
    string output;
    string input;
    cout << "Input an infix expression: ";
    cin >> input;

	//making a for loop that loops until all characters have been checked
    for(int i = 0; i < input.length(); i++)
    {
        char toCheck = input.at(i);
        //if the character that is getting checked isn't an operator, it is added to the output
        if(!isOperator(toCheck))
        {
            output += toCheck;
        }
        else
        {
        	//if the stack is empty ||
        	//if the checked precednece is greater than the top of the stack ||
        	//if the input is an open breacket push into the top of the stack
            if(op.empty() || precedence(toCheck) > precedence(op.top()) || toCheck == '(')
            {
                op.push(toCheck);
            }
            //if the precedence of the checked character is equal to the top of the stack
            //pop the top and push in the checked character
            else if(precedence(toCheck) == precedence(op.top()))
            {
                output += op.top();
                op.pop();
                op.push(toCheck);
            }
            //if the checked value is a close bracket add all of the stack to the output
            //while popping them
            else if(toCheck == ')')
            {
                while(op.top() != '(')
                {
                    output += op.top();
                    op.pop();
                }
                op.pop();
            }
            else
            {
            	//if the precedence is less than the top of the stack
            	//pop the top output and push in the checked character
            	//if the top of the stack is equal then add to output and pop
            	//if the stack becomes empty add in the checked character
                while(precedence(toCheck) <= precedence(op.top()))
                {
                    output += op.top();
                    op.pop();
                    if(precedence(toCheck) > precedence(op.top()))
                    {
                        op.push(toCheck);
                        break;
                    }
                    if(precedence(toCheck) == precedence(op.top()))
                    {
                        output += op.top();
                        op.pop();
                    }

                    if(op.empty())
                    {
                        op.push(toCheck);
                        break;
                    }
                }
            }
        }

    }
    //prints out the rest of the stack once all characters have been checked
    while(!op.empty())
    {
        output += op.top();
        op.pop();
    }
    cout << output;
}
