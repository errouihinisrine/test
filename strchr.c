#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (!(char)(c))
		return ((char *)str);
	return (0);
}

int main() {
    const char *myString = "Hello, World!";
    int myCharacter = 'W';

    char *result = ft_strchr(myString, myCharacter);

    if (result != NULL) {
        printf("Caractère trouvé à  : %s\n", result );
    } else {
        printf("Le caractère n'a pas été trouvé.\n");
    }

    return 0;
}
