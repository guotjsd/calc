//just to try using c for a cli calc
//tring for fun it would be very simple
//newbie in c practising.
#include<stdio.h>
char inputstr[4096]={0};
char* g_postStr = NULL;
char postStr[4096]={0};

char version[128]="	calc version 0.0\n";
char hello_calc[]="calc:try to become a cli calculator! It would be very simple!\r\n\
type 'help' for supported functions\n";
char help[]="help\n";

// press tab auto complition, press twice to show all commands that fit the expression
// now do not support it 
char assoc[][32]={"help","print","exit","sin","cos"};

void  Calc_StartWork()
{
    int len = 0;
    printf("%s",version);
    printf("%s",hello_calc);
    
    while(1)
    {
     //printf("%s",">>");
     //scanf("%s", inputstr);
     //printf("%d\n",sizeof(inputstr));
     
     //len = sizeof(inputstr); 
     //Calc_ProcInput(inutstr,len );
        Calc_AnalyzeInput(inputstr,&g_postStr);
   Calc_Computing();
   Calc_OutputResult();

     Calc_CleanUp();
    }

}
int Calc_AnalyzeInput(char* inutstr,char** ppostfix)
{
    int ret = 0;
    int len = 0;
    printf("%s",">>");
   
    len = scanf("%s",inputstr);

  if(strcmp(inputstr,"help") == 0)
  {
   printf("%s","now no help\n");
   *ppostfix = NULL;
   return 0;
  }
  else if(strcmp(inputstr,"exit") ==0)
  {
    exit(0);
  }
  else if(Calc_IsAllWhiteSpace(inputstr))
  {
    *ppostfix = NULL;
    return 0;
  }
  else
  {
   // not need to delete whitespace ?
   Calc_TrimWhiteSpace(inputstr);

   ret = Calc_CheckInput(inputstr);
   if(ret)
   *ppostfix = NULL;
  return 0;
  }
}

int Calc_IsAllWhiteSpace(char* pInput)
{
for(;*pInput == ' '; pInput++)
{}
return *pInput==0?1:0;
}

void Calc_TrimWhiteSpace(char* input)
{
	return;
}
int Calc_CheckInput(char * input)
{
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
void Calc_CleanUp()
{
 memset(inputstr, 0, 4096);
 memset(postStr, 0, 4096);

return 0;
}

int main()
{

  Calc_StartWork();

  return 0;
}
