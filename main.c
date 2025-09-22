#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SLUG_LENGTH 8

char* generate_slug(void)
{
  char name[SLUG_LENGTH];
  time_t rawtime;
  time ( &rawtime );

  struct tm *timeinfo = localtime( &rawtime );

  int year = timeinfo->tm_year;
  int month = timeinfo->tm_mon;
  int day = timeinfo->tm_mday;

  sprintf(name, "%d%02d%02d", year, month, day);

  // char *word = malloc(SLUG_LENGTH + 1);

  return "hi";
}

bool file_exists(const char *filename)
{
  FILE *fp = fopen(filename, "r");

  bool is_exist = false;

  if (fp != NULL) {
    is_exist = true;
    fclose(fp);
  }

  return is_exist;
}

void write_to_file(void)
{
}

// int main(int argc, char *argv[]) {
int main(void)
{
  printf("Hello world\n");

  char *slug[SLUG_LENGTH];
  *slug = generate_slug();

  return 0;
}
