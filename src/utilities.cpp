#include "utilities.h"

bool email_isvalid(char* email)
{
    regex emailCheck("(\\w+)(\\.|_|-|\\+|\\*|\\$|\\#|\\!|\\%|\\=)?(\\w*)@(gmail|yahoo|outlook|live|hotmail|aol|msn|rediffmail)+(\\.(com|org|gov|net|edu|int|mil|fr|state))+");
        bool match=regex_match(email,emailCheck);  //attempts to match a regular expression to an entire character sequence
        if(match)
        {

            return true;
        }
        else
           {
             return false;
           }
}

bool phoneNumber_isvalid(char* phone_number)
{
      int l;
      l=strlen(phone_number);
         if(l!=10 || phone_number[0]!='9' || (phone_number[1]>='a' && phone_number[10]<='z') || (phone_number[1]>='A' && phone_number[10]<='Z'))
          {
            return false;
          }
          else
            return true;

}

