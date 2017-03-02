//just to try using c for a cli calc
//tring for fun it would be very simple
//newbie in c practising.
#include<stdio.h>
char inputstr[4096]={0};
char hello_calc[]="calc:try to become a cli calculator! It would be very simple!\r\n\
type 'help' for supported functions\n";
char help[]="help\n";

void  Calc_StartWork()
{
    int len = 0;
    printf("%s",hello_calc);
    
    //printf("%s",help);

    while(1)
    {
     printf("%s",">>");

     scanf("%s", inputstr);

     //printf("%d\n",sizeof(inputstr));
     
     len = sizeof(inputstr); 
     //Calc_ProcInput(inutstr,len );
        Calc_AnalyzeStr(inputstr,len);
   Calc_Computing();
   Calc_OutputResult();

     Calc_CleanUp();
    }

}
int Calc_AnalyzeStr(inutstr,len)
{
    int ret = 0;
  if(strncmp(inputstr,"help",4) == 0)
  {
   printf("%s","now no help\n");
   return 0;
  }
  else if(strncmp(inputstr,"exit",4) ==0)
  {
    exit(0);
  }
  else
  {
  }
  
  return 0;
}

void   Calc_Computing()
{
}
void Calc_OutputResult()
{
}
void Calc_CleanUp()
{
 memset(inputstr, 0, 4096);

return 0;
}

int main()
{

  Calc_StartWork();

  return 0;
}
