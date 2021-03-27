#include "miniRT.h"

static int	set_object_data(t_list *list)
{
	int	fd;
	char	*line;
	int	result;

	if (!list)
		return (0);
	fd = open("../scenes/test.rt", O_RDONLY);
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
	printf("R x:%f, y:%f\n", list->R->x, list->R->y);
	printf("A range:%f, color:%08x\n", list->A->range, list->A->color);
	if (!list->c)
	{
		while (list->c)
		{
			printf("c x:%f, y:%f, z:%f, vx:%f, vy:%f, vz:%f, fov:%f\n", list->c->x, list->c->y, list->c->z, list->c->v->x, list->c->v->y, list->c->v->z, list->c->fov);
			list->c = list->c->next;
		}
	}
	if (!list->l)
	{
		while (list->l)
		{
			printf("l x:%f, y:%f, z:%f, range:%f, color:%08x\n", list->l->x, list->l->y, list->l->z, list->l->range, list->l->color);
			list->l = list->l->next;
		}
	}
	if (!list->sp)
	{
		while (list->sp)
		{
			printf("sp x:%f, y:%f, z:%f, r:%f, color:%08x\n", list->sp->x, list->sp->y, list->sp->z, list->sp->r, list->sp->color);
			list->sp = list->sp->next;
		}
	}
	if (!list->pl)
	{
		while (list->pl)
		{
			printf("pl x:%f, y:%f, z:%f, vx:%f, vy:%f, vz:%f size:%f, color:%08x\n", list->pl->x, list->pl->y, list->pl->z, list->pl->v->x, list->pl->v->y, list->pl->v->z, list->pl->size, list->pl->color);
			list->pl = list->pl->next;
		}
	}
	if (!list->sq)
	{
		while (list->sq)
		{
			printf("sq x:%f, y:%f, z:%f, vx:%f, vy:%f, vz:%f, size:%f, color:%08x\n", list->sp->x, list->sp->y, list->sp->z, list->sp->v->x, list->sp->v->y, list->sp->v->z, list->sp->size, list->sp->color);
			list->sq = list->sq->next;
		}
	}
	if (!list->cy)
	{
		while (list->cy)
		{
			printf("cy x:%f, y:%f, z:%f, vx:%f, vy:%f, vz:%f, r:%f, h:%f, color:%08x\n", list->cy->x, list->cy->y, list->cy->z, list->cy->v->x, list->cy->v->y, list->cy->v->z, list->cy->r, list->cy->h, list->cy->color);
			list->cy = list->cy->next;
		}
	}
	if (!list->tr)
	{
		while (list->tr)
		{
			printf("tr x1:%f, y1:%f, z1:%f, x2:%f, y2:%f, z2:%f, x3:%f, y3:%f, z3:%f, color:%08x\n", list->tr->x1, list->tr->y1, list->tr->z1, list->tr->x2, list->tr->y2, list->tr->z2, list->tr->x3, list->tr->y3, list->tr->z3, list->l->color);
			list->tr = list->tr->next;
		}
	}
}

//static void	make_image();

//static void	start_program();

int	main(void)
{
	void	*mlx;
	void	*image;
	t_list	*list;

	mlx = mlx_init();
	list = init_list();
	set_object_data(list);
	test_print(list);
	//make_image();
	//start_program();
	return (0);
}
