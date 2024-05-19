
#include "../cub3d_bonus.h"

void draw_line(mlx_image_t *img, int x1, int y1, int x2, int y2)
{
	t_point delta;
	t_point increment;
	double longest;
	double i;

	delta.x = x2 - x1;
	delta.y = y2 - y1;
    longest = fabs(delta.y);
	if (fabs(delta.x) > fabs(delta.y))
		longest = fabs(delta.x);
    increment.x = delta.x/longest;
    increment.y = delta.y/longest;
    i = 0;
    while (i < longest)
    {
        mlx_put_pixel(img, x1, y1, 0xff0000ff);
        x1 += increment.x;
        y1 += increment.y;
        i++;
    }
}
