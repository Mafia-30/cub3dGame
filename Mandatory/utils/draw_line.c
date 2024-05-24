
#include "../cub3d.h"

void draw_line(mlx_image_t *img, double x1, double y1, double x2, double y2)
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
    increment.x = delta.x / longest;
    increment.y = delta.y / longest;
    i = 0;
    while (i < longest)
    {
        mlx_put_pixel(img, x1, y1, 0xff0000ff);
        x1 += increment.x;
        y1 += increment.y;
        i++;
    }
}
