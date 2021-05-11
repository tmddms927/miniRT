#include "print.h"

double write_color(int t, t_color3 pixel_color)
{
	return (t << 24 | (int)(255.999 * pixel_color.x) << 16 | (int)(255.0 * pixel_color.y) << 8 | (int)(255.0 * pixel_color.z));
}