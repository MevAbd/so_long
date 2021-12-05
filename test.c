#include "./mlx/mlx.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('x');
}

int	main()
{
	void	*ptr;
	void	*win_ptr;

	ptr = mlx_init();
	win_ptr = mlx_new_window(ptr, 500, 500, "test");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(ptr);
}
