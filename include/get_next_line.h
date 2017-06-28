/*
** get_next_line.h for get_next_line in /home/Elden/Desktop/tech1/CPE/CPE_2016_getnextline
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Sun Jan  8 13:12:00 2017 Eythan Fellous
** Last update Mon Feb 13 14:32:38 2017 Groot
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

char	*get_next_line(const int fd);
int	my_strlen(char *str);

# ifndef READ_SIZE
#  define READ_SIZE (3)
# endif /* !READ_SIZE */

#endif /* !GET_NEXT_LINE_H_ */
