/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:53:59 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/12 15:58:41 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define CMD 0
# define PLINE 1
# define WORD 2
# define REDI 3

typedef struct s_word
{
	char	*text;
}			t_word;

typedef struct s_redi
{
	char	*op;
	char	*file;
}	t_redi;

typedef struct s_suff
{
	int				type;
	t_word			*word;
	t_redi			*redi;
	struct s_suff	*prev;
	struct s_suff	*next;
}	t_suff;

typedef struct s_cmd
{
	int		w_size;
	int		r_size;
	t_word	*name;
	t_suff	*suffix;
}			t_cmd;

typedef struct s_pline
{
	t_cmd	*prev;
	t_cmd	*now;
	t_cmd	*next;
}	t_pline;

t_word	*new_word(char	*text);
t_redi	*new_redi(char *op, char *file);
t_suff	*new_suff(int type, char *text, char *op, char *file);
t_cmd	*new_cmd(void);

void	perror_n_exit(char *s, int status);
int		is_pipe_included(char *in);

void	*parsing_input(int type, char **in, char **env);
t_cmd	*make_cmd(char **in, char **env);
void	make_suffix(t_cmd *cmd, int idx, char **in);

t_suff	*suffix_in_quote(t_cmd *cmd, char *in);
void	remove_quote(char *s);

int		is_sep(char n);
int		count_word(char *s);
int		get_word_len(char *s, int *idx);
char	*init_word(char *s, int *idx);
char	**split_input(char *s);

#endif

/*

경우 1 : pipeline 없음
ex) echo $USER > zzz; cat zzz
name : echo
suff : 	$USER
		> zzz;
		cat
		zzz

실행부((void *)cmd, CMD);

t_cmd	*cmd			cmd->name->text : "echo"
{						cmd->name->exp : NULL
	t_word *name;		
	t_suff *suffix;		
}

t_suff	*suffix					cmd->suffix->type : WORD
{								cmd->suffix->prev : NULL
	int				type;		cmd->suffix->now->text : "$USER"
	struct s_suff	*prev;		cmd->suffix->now->exp : {arg:"USER", start:1, end:5}
	void			*now;		
	struct s_suff	*next;		cmd->suffix->next->type : REDI
}								cmd->suffix->next->prev : cmd->suffix
								cmd->suffix->next->now->op : ">"
								cmd->suffix->next->now->file : "zzz;"
								
								cmd->suffix->next->next->type : WORD
								cmd->suffix->next->next->prev : cmd->suffix->next
								cmd->suffix->next->next->now->text : "cat"
								cmd->suffix->next->next->now->exp : NULL
								
								cmd->suffix->next->next->next->type : WORD
								cmd->suffix->next->next->next->prev : cmd->suffix->next->next
								cmd->suffix->next->next->next->now->text : "zzz"
								cmd->suffix->next->next->next->now->exp : NULL
								cmd->suffix->next->next->next->next : NULL

----------
경우 2 : pipeline 있음
ex) echo $USER | rev | cat > zzz
name : echo
suff : 	$USER

name : rev
suff :

name : cat
suff : 	{>, zzz}

실행부((void *)pline, PLINE);

t_pline	*pline			pline->prev : NULL
{						pline->now->name->text : "echo"
	t_cmd	*prev;		pline->now->name->exp : NULL
	t_cmd	*now;		pline->now->suffix->type : WORD
	t_cmd	*next;		pline->now->suffix->prev : NULL
}						pline->now->suffix->now->text : "$USER"
						pline->now->suffix->now->exp : {arg:"USER", start:1, end:5}

						pline->next->name->text : "rev"
						pline->next->name->exp : NULL
						pline->next->suffix : NULL

						pline->next->next->name->text : "cat"
						pline->next->next->name->exp : NULL
						pline->next->next->suffix->type : REDI
						pline->next->next->suffix->prev : NULL
						pline->next->next->suffix->now->op : ">"
						pline->next->next->suffix->now->file : "zzz;"

*/
