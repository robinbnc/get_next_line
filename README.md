# get_next_line

| Project Name | Inception |
| :-: | :-: |
| Description | Reading a file descriptor line by line using a buffer |
| Technologies | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| External libraries | read(), malloc(), free() |
| Final grade | 125/125 |

## Usage
```
git clone https://github.com/robinbnc/get_next_line.git
cd get_next_line
touch test.c
```
Now insert the following code inside the file test.c :
```c
#include "get_next_line_bonus.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
  char  *line;
  int fd;
 
  if (argc != 1)
    return 1;
  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    return 1;
  while ((line = get_next_line(fd)) != NULL)
  {
    printf("%s", line);
    free(line);
  }
  return 0;
}
```
Compile the files with the BUFFER_SIZE of your choice :
```
$(CC) $(CFLAGS) -DBUFFER_SIZE=42 test.c get_next_line_bonus.c get_next_line_utils_bonus.c -o GNL
```
