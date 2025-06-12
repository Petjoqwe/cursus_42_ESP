/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 21:47:08 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/25 18:40:22 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	*free_buffer_and_stash(char *buffer, char *stash)// libera el buffer y el stash
{
	if (buffer)
		free(buffer);
	if (stash)
		free(stash);
	return (NULL);
}

static char	*read_line(int fd, char *stash) // esta funcion lee del archivo y almacena en stash
{
	char		*buffer; // buffer para almacenar los datos leidos
	ssize_t		bytes_read; // cantidad de bytes leidos

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // +1 para el terminador nulo
	if (!buffer) 
		return (free_buffer_and_stash(NULL, stash));
	bytes_read = 1; // inicializamos bytes_read para entrar al bucle
	while (!ft_strchr(stash, '\n') && bytes_read > 0) // mientras no encontremos un salto de linea y bytes_read sea mayor que 0
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE); // leemos del archivo y almacenamos en buffer y almacenamos la cantidad de bytes leidos
		if (bytes_read == -1) // si hubo un error al leer y bytes_read es -1 
			return (free_buffer_and_stash(buffer, stash));	// liberamos el buffer y el stash
		buffer[bytes_read] = '\0'; // aseguramos que el buffer sea una cadena terminada en nulo
		stash = ft_strjoin(stash, buffer); // unimos el stash con el buffer y almacenamos el resultado en stash
		if (!stash)
			return (free_buffer_and_stash(buffer, NULL)); // si hubo un error al unir, liberamos el buffer y retornamos NULL
	}
	free(buffer); // liberamos el buffer ya que no lo necesitamos mas
	return (stash); // retornamos el stash que contiene la linea leida
}

static char	*extract_line(char *stash) // ºesta funcion extrae la linea del stash
{
	int		i;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*save_rest(char *stash)
{
	char	*rest;
	int		i;
	int		len;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n') // buscamos el salto de linea
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	len = ft_strlen(stash + i);
	rest = ft_substr(stash, i, len); // esta funcion crea una subcadena de stash desde el indice i hasta el final para guardar el resto de la cadena
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = save_rest(stash);
	return (line);
}
