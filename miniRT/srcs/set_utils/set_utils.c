#include "set_utils.h"

t_list	*init_list()
{
	t_list	*list;

	list = malloc(sizeof(list));
	if (!list)
		return (0);
	list->R = 0;
	list->A = 0;
	list->c = 0;
	list->l = 0;
	list->sp = 0;
	list->pl = 0;
	list->sq = 0;
	list->cy = 0;
	list->tr = 0;
	return (list);
}

void	list_free(t_list *list)
{
	if (list->R)
		free(list->R);
	if (list->A)
		free(list->A);
	if (list->c)
		free_c(list->c);
	if (list->l)
		free_l(list->l);
	if (list->sp)
		free_sp(list->sp);
	if (list->pl)
		free_pl(list->pl);
	if (list->sq)
		free_sq(list->sq);
	if (list->cy)
		free_cy(list->cy);
	if (list->tr)
		free_tr(list->tr);
	free(list);
}

static int	parse_basic(char *line, t_list *list)
{
	int	result;

	result = 0;
	if (*(line + 1) != ' ')
		return (result);
	if (*line == 'R')
		result = parse_R(line, &(list->R));
	else if (*line == 'A')
		result = parse_A(line, &(list->A));
	else if (*line == 'c')
		result = parse_c(line, &(list->c));
	else if (*line == 'l')
		result = parse_l(line, &(list->l));
	return (result);
}

static int	parse_figure(char *line, t_list *list)
{
	int	result;

	result = 0;
	if (*(line + 2) != ' ')
		return (result);
	if (*line == 's' && *(line + 1) == 'p')
		result = parse_sp(line, &(list->sp));
	else if (*line == 'p' && *(line + 1) == 'l')
		result = parse_pl(line, &(list->pl));
	else if (*line == 's' && *(line + 1) == 'q')
		result = parse_sq(line, &(list->sq));
	else if (*line == 'c' && *(line + 1) == 'y')
		result = parse_cy(line, &(list->cy));
	else if (*line == 't' && *(line + 1) == 'r')
		result = parse_tr(line, &(list->tr));
	return (result);
}

int	check_object(char *line, t_list *list)
{
	char	*save;
	int	result;

	save = line;
	result = 0;
	if (!*line)
		result = 1;
	else if (*line == 'R' || *line == 'A' || (*line == 'c' && *(line + 1) == ' ') || *line == 'l')
		result = parse_basic(line, list);
	else if (*line == 's' || *line == 'p' || *line == 'c' || *line == 't')
		result = parse_figure(line, list);
	free(save);
	if (!result)
		list_free(list);
	return (result);
}
