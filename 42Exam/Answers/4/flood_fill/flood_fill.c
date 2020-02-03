#include "flood_fill.h"

void actual_flood_fill(char **tab,char color, t_point size, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (x >= size.x || y >= size.y)
		return ;
	if (tab[y][x] != color)
		return ;
	tab[y][x] = 'F';
	actual_flood_fill(tab, color, size, x + 1, y);
	actual_flood_fill(tab, color, size, x - 1, y);
	actual_flood_fill(tab, color, size, x, y + 1);
	actual_flood_fill(tab, color, size, x, y - 1);
}

void flood_fill(char **tab, t_point size, t_point begin)
{
	actual_flood_fill(tab, tab[begin.y][begin.x], size, begin.x, begin.y);
}

int main(void)
{
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"
	};

	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}