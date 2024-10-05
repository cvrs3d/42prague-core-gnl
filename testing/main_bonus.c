/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yustinov <ev.ustinov03@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:12:01 by yustinov          #+#    #+#             */
/*   Updated: 2024/10/04 18:28:49 by yustinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int f1;
    int f2;
    char *line;

    if (argc == 3)
    {
        // Open the file passed as an argument
        f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[2], O_RDONLY);
        if (f1 < 0 || f2 < 0)
        {
            perror("Error opening file");
            return (1);
        }

        // Read lines using get_next_line and print them
        line = get_next_line(f1);
        printf("Line: %s", line);
        free(line);
        line = get_next_line(f2);
        printf("Line: %s", line);
        free(line);
        line = get_next_line(f1);
        printf("Line: %s", line);
        free(line);
        line = get_next_line(f2);
        printf("Line: %s", line);
        free(line);
        line = get_next_line(f1);
        printf("Line: %s", line);
        free(line);
	line = get_next_line(f1);
        printf("Line: %s", line);
        free(line);
        line = get_next_line(f2);
        printf("Line: %s", line);
        free(line);
        line = get_next_line(f1);
        printf("Line: %s", line);
        free(line);

        // Close the file
        close(f1);
	close(f2);
    }
    else
    {
        // No file passed as argument, reading from stdin
        printf("Reading from stdin (type Ctrl+D to end):\n");
        while ((line = get_next_line(STDIN_FILENO)) != NULL)
        {
            printf("Line: %s", line);
            free(line);  // Free the allocated line after printing
        }
    }

    return 0;
}

