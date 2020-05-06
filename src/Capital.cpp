#include"Capital.h"
char* capital(char a[20])//to make all the string in capital letter
{
   int l;
   l=strlen(a);
   for(int i=0;i<l;i++)
   {
       a[i]=toupper(a[i]);
   }
  return a;
}
