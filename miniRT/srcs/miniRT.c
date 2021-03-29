#include "miniRT.h"

static int	set_object_data(t_list *list, char *filename)
{
	int	fd;
	char	*line;
	int	result;

	if (!list)
		return (0);
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd, &line);
	if (!result)
		result = -1;
	while (result > 0)
	{
		if (!check_object(line, list))
		{
			result = -1;
			break ;
		}
		result = get_next_line(fd, &line);
	}
	if (fd != -1)
		close(fd);
	if (result == -1)
		return (0);
	return (1);
}

static void	test_print(t_list *list)
{
	printf("R x:%d, y:%d\n", list->R->x, list->R->y);
	printf("A range:%.2f, color:%08llX\n", list->A->range, list->A->color);
	if (list->c)
	{
		while (list->c)
		{
			printf("c x:%.2f, y:%.2f, z:%.2f, vx:%.2f, vy:%.2f, vz:%.2f, fov:%.2f\n", list->c->x, list->c->y, list->c->z, list->c->v->x, list->c->v->y, list->c->v->z, list->c->fov);
			list->c = list->c->next;
		}
	}
	if (list->l)
	{
		while (list->l)
		{
			printf("l x:%.2f, y:%.2f, z:%.2f, range:%.2f, color:%08llX\n", list->l->x, list->l->y, list->l->z, list->l->range, list->l->color);
			list->l = list->l->next;
		}
	}
	if (list->sp)
	{
		while (list->sp)
		{
			printf("sp x:%.2f, y:%.2f, z:%.2f, r:%.2f, color:%08llX\n", list->sp->x, list->sp->y, list->sp->z, list->sp->r, list->sp->color);
			list->sp = list->sp->next;
		}
	}
	if (list->pl)
	{
		while (list->pl)
		{
			printf("pl x:%.2f, y:%.2f, z:%.2f, vx:%.2f, vy:%.2f, vz:%.2f, color:%08llX\n", list->pl->x, list->pl->y, list->pl->z, list->pl->v->x, list->pl->v->y, list->pl->v->z, list->pl->color);
			list->pl = list->pl->next;
		}
	}
	if (list->sq)
	{
		while (list->sq)
		{
			printf("sq x:%.2f, y:%.2f, z:%.2f, vx:%.2f, vy:%.2f, vz:%.2f, size:%.2f, color:%08llX\n", list->sq->x, list->sq->y, list->sq->z, list->sq->v->x, list->sq->v->y, list->sq->v->z, list->sq->length, list->sq->color);
			list->sq = list->sq->next;
		}
	}
	if (list->cy)
	{
		while (list->cy)
		{
			printf("cy x:%.2f, y:%.2f, z:%.2f, vx:%.2f, vy:%.2f, vz:%.2f, r:%.2f, h:%.2f, color:%08llX\n", list->cy->x, list->cy->y, list->cy->z, list->cy->v->x, list->cy->v->y, list->cy->v->z, list->cy->r, list->cy->h, list->cy->color);
			list->cy = list->cy->next;
		}
	}
	if (list->tr)
	{
		while (list->tr)
		{
			printf("tr x1:%.2f, y1:%.2f, z1:%.2f, x2:%.2f, y2:%.2f, z2:%.2f, x3:%.2f, y3:%.2f, z3:%.2f, color:%08llX\n", list->tr->x1, list->tr->y1, list->tr->z1, list->tr->x2, list->tr->y2, list->tr->z2, list->tr->x3, list->tr->y3, list->tr->z3, list->tr->color);
			list->tr = list->tr->next;
		}
	}
}

//static void	make_image();

//static void	start_program();

int	main(int argc, char **argv)
{
	void	*mlx;
	//void	*image;
	t_list	*list;

	if (argc != 2)
		return (0);
	mlx = mlx_init();
	list = init_list();
	if (!set_object_data(list, *(++argv)))
		return (0);
	test_print(list);
	//make_image();
	//start_program();
	return (0);
}
