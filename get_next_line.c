/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:10:50 by ffleitas          #+#    #+#             */
/*   Updated: 2023/10/22 17:38:22 by ffleitas         ###   ########.fr       */
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


void ft_leaks()
{
    system("leaks -q a.out");
}

char *ft_readfile(int fd, char *storage)  //Leer el archivo y almacenar la lectura en Storage
{
	char	*buffer;
	ssize_t  bytes_read;
	
	buffer = malloc(BUFFER_SIZE + 1); // Crear espacio en memoria para el buffer generado por el read + el carácter nulo
	if (!buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n')) // Bucle que se ejecuta mientras en el buffer no haya un salto de línea
	{
		bytes_read = read(fd,buffer, BUFFER_SIZE); 
		if (bytes_read == -1) // Sí es -1 (Error)
			return (free(buffer), NULL); //Libera la memoria del Buffer, y devuelve NULL;
		buffer[bytes_read] = '\0'; //Agrega el carácter nulo al final
		if (bytes_read == 0) //Sí no tiene bytes que leer porque ha llegado al final del archivo
			break; //Sal del bucle
		storage = ft_joinandfree(storage, buffer); //Almacena en  Storage, lo que esté en el Buffer hasta llegar a \n
	}
	free(buffer); //Libera la memoria del buffer
	return(storage); //Devuelve lo que se ha almacenado
}


char *ft_extractline(char *storage) //Extraer la línea almacenada en Storage
{
	char	*saved; 
	int		i;
		
	i = 0;	
	if (!storage) //Sí mi almacenamiento es nulo
		return (NULL); //Devuelve nulo
	while (storage[i] && storage[i] != '\n') //Mientras Storage no sea nulo y en Storage no se encuentre un salto de línea
		i++; //Itera a través de Storage, para obtener la longitud total de lo almacenado en Storage hasta \n
	saved = ft_substr(storage,0,i); //Mi variable saved, ahora va a almacenar una subcadena, en base a lo que está en Storage, de la longitud de i (longitud desde el inicio hasta el primer \n)
	if(!saved)						
		return (NULL);
	return(saved); //Devuelve la cadena creada
}


char *ft_nextline(char *storage) //Elimina la primera línea obtenida, y reinicia la línea para almacenar lo siguiente (EXPLICAR MEJOR)
{
	int 	i;
	int		j;
	char	*new_line;
	
	i = 0;
	j = 0;
	if (!storage)
		return (NULL);
	while(storage[i] != '\0' && storage[i] != '\n') //Sí mi Storage es distinto de nulo y del salto de línea
		i ++; //Itera para alcanzar la posición del \n
	if(storage[i] == '\0') // Se hace la comprobación en esta parte del codigo ya que i debe estar en la posición de '\0' después del bucle while
		return(free(storage),NULL);	
	i ++; // Sí en la posición de i es igual a \n hago i++, para saltar ese salto de línea, por ende, si mi i valía 5, ahora vale 6, y empiezo a copiar a partir de ahí
	new_line = malloc(ft_strlen(storage) - i + 1); //Crea un espacio en memoria equivalente a la longitud de Storage menos el espacio que hay entre
	if (!new_line)													// El inicio y el primer salto de línea, por ejemplo Hola/nComoEstás
		return (free(storage),NULL);									// 14 - 5 = 9. +1 Para el carácter nulo, así me quedarían 10 espacios, lo que necesito para almacenar lo siguiente al \n
	while(storage[i] != '\0') //Mientras mi Storage no sea nulo
	{
		new_line[j] = storage[i]; //Copio en la posición inicial de newline(0), desde la posición i de storage.
		j ++;
		i ++;
	}
	new_line[j] = '\0';
	free(storage);
	return(new_line);	//Devuelvo la línea copiada
}

char *get_next_line(int fd)
{
	static char *storage;
	char	*line;

	if (fd < 0 || read(fd,0,0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_readfile(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_extractline(storage);
	storage = ft_nextline(storage);
	return (line);
}
int main(void)
{
	int    fd;
	char  *line;
	int  count;

	atexit(ft_leaks);
	count = 1;
	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
	printf("[%d]:%s\n", count, line);
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	return (0);
}




// text:
// hola 
// como estas
// muy BIG_ENDIAN


// BUFFER_SIZE 1
// ft_storage hola\n 5x

// BUFFER_SIZE 3
// ft_storage hola\nc  2x
// hola\n
// c 

// BUFFER_SIZE 500
// ft_storage hola\ncomo estas\nmmmm  1x
// hola\n
// como estas\nmmmm



