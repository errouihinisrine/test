#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((( unsigned char *)str)[i] == c)
			return (&((void *)str)[i]);
		i++;
	}
	return (NULL);
}
#include <stdio.h>
#include <stddef.h>

int main() {
    const char *myString = "Hello, World!";
    char myCharacter = 'W';
    size_t numBytes = 13; // La longueur de la chaîne myString

    // Utilisation de ft_memchr pour chercher 'W' dans myString
    const void *result = ft_memchr(myString, myCharacter, numBytes);

    if (result != NULL) {
        // Calcul de la position du caractère dans la chaîne
        printf("Caractère trouvé à la position : %s\n", result);
    } else {
        printf("Le caractère n'a pas été trouvé.\n");
    }

    return 0;
}
