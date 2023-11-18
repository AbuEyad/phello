#include "../include/so_long.h"

int colors[] = {0xFF0000, 0xFF4500, 0xFFD700, 0xFFFF00,
    0x9ACD32, 0x32CD32, 0x00FF00, 0x00FA9A, 0x00FFFF, 
    0x1E90FF, 0x0000FF, 0x8A2BE2, 0xA52A2A, 0xFF69B4, 
    0xFF1493, 0xFFC0CB, 0xFFB6C1, 0xFFDAB9, 0xFAEBD7, 
    0xF0E68C, 0xDAA520, 0xCD853F, 0x8B4513, 0x808080, 
    0xA9A9A9, 0xD3D3D3, 0x000000, 0xFFFFFF, 0x800000, 
    0x008000, 0x000080, 0x800080, 0x008080, 0xC0C0C0, 
    0x808000, 0x800080, 0x008080, 0xC0C0C0};

int random_color()
{
    srand(time(NULL));
	int colors_size = sizeof(colors) / sizeof(int);
	int random_index = rand() % colors_size;
	int random_color = colors[random_index];
    return(random_color);
}


int get_color()
{  
    static int index = 0;
    int colors_size = sizeof(colors) / sizeof(int);
    if (index >= (int)colors_size)
        index = 0;
	return (colors[index++]);
}

int rand_num(int max)
{
    // srand(time(NULL));
    return(rand() % max);
}


