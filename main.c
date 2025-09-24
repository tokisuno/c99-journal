#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define SLUG_LENGTH 8

const char * generate_slug(void)
{
  struct tm *tm;
  time_t t;
  t = time(NULL);
  tm = localtime(&t);

  int year = tm->tm_year;
  int month = tm->tm_mon;
  int day = tm->tm_mday;

  char* buffer[10];
  // sprintf(*buffer, "%02d%02d%02d", year, month, day);
  sprintf(*buffer, "%02d%02d%02d", year, month, day);

  printf("%s", *buffer);

  return "hi";
}

void write_to_file(void)
{

}

// int main(int argc, char *argv[]) {
int main(void)
{
  printf("Hello world\n");
  const char* datestring = generate_slug();

  printf("%s", datestring);

  return 0;
}
