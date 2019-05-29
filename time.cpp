// difftime example
#include <stdio.h>      // printf 
#include <time.h>       // time_t, struct tm, difftime, time, mktime

int main ()
{
  time_t now;
  struct tm newyear;
  double seconds;

  time(&now);  // get current time; same as: now = time(NULL)

  newyear = *localtime(&now);

  newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
  newyear.tm_mon = 0;  newyear.tm_mday = 1;

  seconds = difftime(now,mktime(&newyear));

  printf ("%.f seconds since new year in the current timezone.\n", seconds);

  return 0;
  
}
/* localtime example
#include <stdio.h>      // puts, printf
#include <time.h>       // time_t, struct tm, time, localtime /*

int main ()
{
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);
  printf ("Current local time and date: %s", asctime(timeinfo));

  return 0;
} */