/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:50 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/16 22:35:21 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*• Se considera que get_next_line() tiene un comportamiento indeterminado si el
archivo al que apunta el fd ha cambiado desde la última vez que se llamó, siempre
que read() no haya llegado al final del archivo.

• Se considera que get_next_line() tiene un comportamiento indeterminado cuando lo que se lee es un archivo binario. Sin embargo, puedes inmplementar alguna
manera lógica de sortear este problema, si quieres.

Tu función deberá devolver la línea que se acaba de leer.
Si no hay nada más que leer o si ha ocurrido un error, deberá devolver NULL.

Intenta leer lo menos posible cada vez que se llame a
get_next_line(). Si encuentras un salto de línea, deberás devolver la
línea actual. No leas el archivo entero y luego proceses cada línea.

leer archivo
extraer contenido hasta el primer \n
conserva el contenido anterior y lo une con el restante
me será util strlen, strchr, strjoin, strdup


*char	*get_next_line(int fd)

int open(const char *Path, int flags);
ssize_t read(int fd, void *buf, size_t count);*/

int	ft_checkn(char *buffer) //me va a decir cuantos \n tengo al llamar a la función en un bucle
{
	int i;

	i = 0;
	while(*buffer)
	{
		if (*buffer == '\n')
			i ++;
		buffer ++;		
	}
	return (i);	
}
char *ft_getline(int fd)
{
	char *buffer;
	char *line;
	int i;
	int j;
	ssize_t nr_bytes;

	i = 0;
	j = 0;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return(NULL);
	nr_bytes = read(fd,buffer,BUFFER_SIZE);
	if (nr_bytes == -1)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		line[j ++] = buffer[i ++];
	if (buffer[i] == '\n')
		line[j ++] = buffer[i ++];
	line[j] = '\0';
	free(buffer);
	return(line);
}


int main() 
{
    int fd;
    char *str;
	int len;
	char *buffer;

    fd = open("texto.txt", O_RDONLY);
    if (fd <= 0) 
		return (0);

    str = ft_getline(fd);
    if (!str)
		return (0);
	len = ft_checkn(str);
   	printf("%s\n%d\n", str,len);
    free(str);
    close(fd);
    return (0);
}
/*char *get_next_line(int fd)
{
	
}*/

