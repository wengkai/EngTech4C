#include "eval.h"
#include <string.h>

#define CH2DEC(x) ((x) - '0')

//  find the most right and lowest operator in the str
//  @return -1 if no any operators in the str; or
//  the index of the operator sepeicified in the str
static int findop(const char *str);

//  return the rank of the operator
//  @return -1 if the char ch is not an operator; or
//  the rank listed as 1 for * and /, 2 for + and -
static int oprank(char ch);

//  convert a string into a number.
//  The string should consist of all digits.
//  @return the converted number
static int str2int(const char *str);

//  calculate a op b.
//  It supports +-*/ as the op.
//  @return the result of a op b
static int calc(int a, char op, int b);

int eval(char *str)
{
    int ret = 0;
    //  find the most right and lowest operator
    int loc = findop(str);
    if (loc == -1)  //  no operator found
    { 
        ret = str2int(str);
    }
    else    //  split the str into two parts
    { 
        char op = str[loc];
        str[loc] = 0;
        int left = eval(str);
        int right = eval(str + loc + 1);
        ret = calc(left, op, right);
    }

    return ret;
}

//  internal functions
static int findop(const char *str)
{
    int ret = -1;   //  the location
    int lowestoprank = -1;  //  lowest rank found
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        int rank = oprank(str[i]);
        if (rank > lowestoprank)
        {
            ret = i;
            lowestoprank = rank;
        }
    }
    return ret;
}

static int oprank(char ch)
{
    int ret = -1;
    if (ch == '+' || ch == '-')
    {
        ret = 2;
    }
    else if (ch == '*' || ch == '/')
    {
        ret = 1;
    }
    return ret;
}

static int str2int(const char *str)
{
    int ret = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        ret = ret * 10 + CH2DEC(str[i]);
    }
    return ret;
}

static int calc(int a, char op, int b)
{
    int ret = 0;
    switch (op)
    {
    case '+':
        ret = a + b;
        break;
    case '-':
        ret = a - b;
        break;
    case '*':
        ret = a * b;
        break;
    case '/':
        ret = a / b;
        break;
    }
    return ret;
}

#ifdef _TEST_
//  for module test

#include <stdio.h>
int main()
{
    char str[] = "2+2-3+2";
    printf("%d\n", eval(str));
}

#endif