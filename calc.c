//just to try using c for a cli calc
//tring for fun it would be very simple
//newbie in c practising.
#include<stdio.h>
#include<string.h>
//#include<unistd.h>
#include<stdlib.h>
char inputStr[4096]={0};
char* g_postStr = NULL;
char postStr[4096]={0};
char postexp[4096]={0};
typedef struct tagStack{
	char symbol[1024];
	char vars[256][1024];
}Stack;

char version[128]="	calc version 0.01\n";
char hello_calc[]="calc:try to become a cli calculator! It would be very simple!\r\n\
type 'help' for supported functions\n";
char help[]="help\n";

// press tab auto complition, press twice to show all commands that fit the expression
// now do not support it 
char assoc[][32]={"help","print","exit","sin","cos"};



int g_stack_symbols=0;

int Stack_Push(char* pStack, char symbol)
{
int index = 0;
*(pStack +g_stack_symbols) = symbol;
g_stack_symbols++;
return g_stack_symbols;
}
int Stack_Pop(char* pStack)
{
char symbolToPop = 0;
g_stack_symbols--;
 symbolToPop = *(pStack + g_stack_symbols );
 *(pStack+g_stack_symbols)=0;
 return symbolToPop;
}
// +   -   *  /      (  )  ^  !  !!
// 2b 2d   2a 2f    28  29 5e 21 
// +2  0   0x15 10 0x31 30 -0x10  
int Calc_OperatorWeigh(char operator)
{
switch (operator)
{
	case '+':
	return  operator+2;
	case '-':
        return  operator;

	case '*':
	return operator+ 0x15;
	case '/':
	return operator +0x10;

	case '(':
	return  operator +0x31;
	case ')':
	return  operator + 0x30;

	case '^':
	return  operator-0x10;
	default:
	return operator;
}
}
int Calc_GetOperatorPriority(char operator1,char operator2)
{
return Calc_OperatorWeigh(operator1)-Calc_OperatorWeigh(operator2);
}
//while(Calc_
int Calc_IsAllWhiteSpace(char* pInput)
{
for(;*pInput == ' '; pInput++)
{}
return *pInput==0?1:0;
}

//do not need to trim just ignore
void Calc_TrimWhiteSpace(char* input)
{
	return;
}
// suppose to identify 010 0x12fb 
int Calc_CheckInput(char * input)
{
	return 0;
}



int Calc_TransInputToPostexp(char* inputstr,char**ppostexp)
{
 int ret = 0;
 int index = 0;
 Stack* pStack = NULL;
 char*  pPostExp=NULL;
 int StackSize = sizeof(Stack);
 int postExpSize = sizeof(inputStr);

 pStack  = malloc(StackSize);
 memset(pStack, 0, StackSize);
 pPostExp = malloc(postExpSize);
 memset(pPostExp, 0, postExpSize);

 char *tmp= inputstr;
 //for(;*(inputstr+index);index++)
 for(;*tmp!= 0;tmp++)
 {
	 //if(*tmp==
 } 
 
 return 0;
}
 

void   Calc_Computing(char* postStr)
{
	if(postStr==NULL)
        return;

}
void Calc_OutputResult()
{
}
int Calc_CleanUp()
{
 memset(inputStr, 0, 4096);
 memset(postStr, 0, 4096);
 memset(postexp, 0, 4096);
 g_stack_symbols = 0;

return 0;
}

int Calc_AnalyzeInput(char* inutstr,char** ppostexp)
{
    int ret = 0;
    int len = 0;
    int ch = 0;
    printf("%s",">>");
   
    //len = scanf("%s",inputstr);
    while((ch=getchar())!='\n')
    {
	inputStr[len++]=ch;
    }

  if(strcmp(inputStr,"help") == 0)
  {
   printf("%s","now no help\n");
   *ppostexp = NULL;
   return 0;
  }
  else if(strcmp(inputStr,"exit") ==0)
  {
    exit(0);
  }
  else if(Calc_IsAllWhiteSpace(inputStr))
  {
    *ppostexp = NULL;
    return 0;
  }
  else
  {
   ret = Calc_CheckInput(inputStr);
   if(ret)
   *ppostexp = NULL;
   
  ret = Calc_TransInputToPostexp(inputStr,ppostexp);

  return 0;
  }
}


void  Calc_StartWork()
{
    int len = 0;
    printf("%s",version);
    printf("%s",hello_calc);
    
    while(1)
    {
        Calc_AnalyzeInput(inputStr,&g_postStr);
   Calc_Computing(g_postStr);
   Calc_OutputResult();

     Calc_CleanUp();
    }
}
int main()
{

  Calc_StartWork();

  return 0;
}
