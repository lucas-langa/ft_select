/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <jrameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 20:50:04 by jrameau           #+#    #+#             */
/*   Updated: 2017/06/29 02:01:20 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
#define FT_SELECT

# include <stdlib.h>
# include <termcap.h>
# include <libft.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>

typedef enum		e_type
{
	FILE_T,
	DIR_T,
	TEXT_T
}					t_type;

typedef enum		e_dir
{
	UP_DIR,
	RIGHT_DIR,
	DOWN_DIR,
	LEFT_DIR,
	DEFAULT_DIR
}					t_dir;

typedef struct		s_args
{
	char			*value;
	int				is_selected;
	struct s_args	*prev;
	struct s_args	*next;
}					t_args;

typedef struct		s_select
{
	t_args			**active_arg;
	struct termios	saved_attr;
	int				args_per_row;
	int				argc;
	char			*term_name;
	t_args			*args;
}					t_select;

t_select			g_select;

void				print_usage(void);
void  				column_display();
void				init_args(char **av);
void				move(t_dir direction);
int					count_columns();
int					count_max_arg_len(void);
int					ft_printnbr(int nbr);
void				signal_handler(int signo);
void				init_custom_conf();
void				reset_default_conf(void);
void				free_args(void);
void				init_signal_handlers();
void				stop_signal_handler(void);
void				remove_arg(void);

#endif