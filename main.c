#include <mlx.h>
#include "so_long.h"
#define FONT_WIDTH 10
#define FONT_HEIGHT 20
#define SCALE_FACTOR 2 // Change this value to scale the text

void draw_scaled_char(void *mlx_ptr, void *win_ptr, int x, int y, int color, char c)
{
    int i, j;
    int scaled_width = FONT_WIDTH * SCALE_FACTOR;
    int scaled_height = FONT_HEIGHT * SCALE_FACTOR;

    for (i = 0; i < scaled_width; i++)
    {
        for (j = 0; j < scaled_height; j++)
        {
            if (/* condition to check if (i/SCALE_FACTOR, j/SCALE_FACTOR) is inside character c pixel map */)
            {
                mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
            }
        }
    }
}

void draw_scaled_string(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        draw_scaled_char(mlx_ptr, win_ptr, x + i * FONT_WIDTH * SCALE_FACTOR, y, color, str[i]);
    }
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return 1;

    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Scaled Text Example");
    if (win_ptr == NULL)
        return 1;

    draw_scaled_string(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF, "Hello, world!");

    mlx_loop(mlx_ptr);

    return 0;
}
