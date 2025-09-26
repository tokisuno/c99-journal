#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pwd.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

#define SLUG_LENGTH 8

static const char text_editor[] = "/bin/nvim";
static const char journal_folder[] = "Journal";

// int main(int argc, char *argv[]) {
int main(void)
{
  // PATH TO THE DIR THAT SHOULD EXIST
  struct passwd *info = getpwuid(getuid());
  char folder_path[50]; // <- probably really bad but wtv LMAO
  sprintf(folder_path, "%s/%s", info->pw_dir, journal_folder);
  printf("%s\n", folder_path);

  // GENERATE SLUG FOR FILENAME
  struct tm *time_ptr;
  time_t t;
  t = time(NULL);
  time_ptr = localtime(&t);
  int year = time_ptr->tm_year + 1900; // year since 1900
  int month = time_ptr->tm_mon + 1; // month ranges from 0,11
  int day = time_ptr->tm_mday;
  char filename[50];
  sprintf(filename, "%d_%02d_%02d.md", year, month, day);
  printf("%s\n", filename);

  // TESTS TO SEE IF THAT DIR EXISTS
  DIR* dir = opendir(folder_path);
  char today[100]; // <- again, probably a terrible idea LMAO
  if (dir) {
    printf("Folder exists!\n");
    // CHECK TO SEE IF TODAY'S ENTRY EXISTS YET
    sprintf(today, "%s/%s", folder_path, filename);
    execl(text_editor, today, NULL);
    closedir(dir);
  } else if (ENOENT == errno) {
    printf("[ERR] Directory doesn't exist!\n");
  } else {
    printf("[ERR] Folder-checking operation has failed for a mysterious reason\n");
  }

  return 0;
}
