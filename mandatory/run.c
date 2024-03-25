#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	mlx_parce_input(ac, av, &data.map);
	data.mlx = mlx_init(data.map.width * DM, data.map.height * DM, TILTEL, false);
	mlx_loop(data.mlx);
}
