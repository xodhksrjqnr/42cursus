#include "texture.h"

t_texture		**set_texture(void *mlx, char **list)
{
	int			i;
	t_texture	*t;
	t_texture	**texture;

	texture = (t_texture **)malloc(sizeof(t_texture *) * 6);
	if (!texture)
		return (0);
	i = 0;
	while (i < 6)
		texture[i++] = 0;
	i = 0;
	while (i < 5)
	{
		texture[i] = malloc(sizeof(t_texture));
		if (!texture[i])
			return (0);
		t = texture[i];
		t->image = mlx_png_file_to_image(mlx, list[i], t->size, t->size + 1);
		t->adr = mlx_get_data_addr(t->image, &(t->bpp), &(t->leng), &(t->endi));
		t->bpp /= 8;
		i++;
	}
	return (texture);
}

unsigned int	t_color(char *ref, int y, t_texture *texture)
{
	char	*result;

	result = ref + (int)(y * texture->ratio[1]) * texture->leng;
	return (*(unsigned int *)result);
}

void			free_texture(t_texture **texture, void *mlx)
{
	int	i;

	i = 0;
	while (texture[i])
	{
		if (texture[i]->image)
			mlx_destroy_image(mlx, texture[i]->image);
		free(texture[i]);
		i++;
	}
	free(texture);
}
