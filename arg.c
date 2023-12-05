/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:15:10 by ner-roui          #+#    #+#             */
/*   Updated: 2023/12/02 20:20:19 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include<stdio.h>

#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 32

// Fonction qui lit le fichier jusqu'à trouver un caractère de nouvelle ligne '\n'
char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int	rd_bytes;

	// Allocation dynamique d'un buffer
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);

	// Initialisation de la variable de lecture
	rd_bytes = 1;

	// Tant qu'on n'a pas trouvé '\n' dans les données lues et qu'on n'a pas atteint la fin du fichier
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		// Lecture des données du fichier dans le buffer
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			// Gestion de l'erreur de lecture
			free(buff);
			return (NULL);
		}

		// Ajout d'un caractère de fin de chaîne pour terminer la chaîne de caractères lue
		buff[rd_bytes] = '\0';

		// Concaténation des données lues avec les données restantes de la ligne précédente
		left_str = ft_strjoin(left_str, buff);
	}

	// Libération de la mémoire allouée pour le buffer
	free(buff);

	// Retourne les données lues et concaténées
	return (left_str);
}

// Fonction principale get_next_line qui renvoie une ligne à la fois
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str; // Variable statique pour stocker les données restantes d'une ligne précédente

	// Vérification des paramètres d'entrée
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	// Appel à la fonction qui lit le fichier jusqu'à trouver une nouvelle ligne
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);

	// Appel à des fonctions non fournies ici (ft_get_line, ft_new_left_str)
	// Ces fonctions seraient responsables de récupérer une ligne à partir des données lues et de mettre à jour les données restantes.

	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);

	// Retourne la ligne lue
	return (line);
}
