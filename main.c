#include "get_next_line.h"

int main()
{
    char *str1 = "/Users/mohtakra/Desktop/G/gnlTester/files/alternate_line_nl_with_nl";
    int i = 0 ,fd = open(str1,O_RDONLY);
    char *str;
    while (i < 3)
    {
        str = get_next_line(fd);
        printf("%s",str);
        i++;
    }
    // while(1);
    return 0;
}