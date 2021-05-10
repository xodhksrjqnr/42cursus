#include "texture.h"

t_texture    **set_texture(void *mlx, char **list)
{
    int         i;
    t_texture   *cur;
    t_texture   **texture;

    texture = (t_texture **)malloc(sizeof(t_texture *) * 5);
    if (!texture)
        return (0);
    i = 0;
    while (i < 5)
    {
        *(texture + i) = malloc(sizeof(t_texture));
        cur = *(texture + i);
        cur->image = mlx_png_file_to_image(mlx, list[i], &(cur->size[0]), &(cur->size[1]));
        cur->adr = mlx_get_data_addr(cur->image, &(cur->bpp), &(cur->leng), &(cur->endian));
        i++;
    }
    return (texture);
}

unsigned int texture_color(char *ref, int y, t_texture *texture)
{
    return (*(unsigned int *)(ref + (int)(y * texture->ratio[1]) * texture->leng));
}