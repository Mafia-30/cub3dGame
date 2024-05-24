
#include "../cub3d_bonus.h"

static void	init_knif(t_game *game)
{
	char	*knife[5];

	knife[0] = "Bonus/assets/guns/knife_0.png";
	knife[1] = "Bonus/assets/guns/knife_1.png";
	knife[2] = "Bonus/assets/guns/knife_2.png";
	knife[3] = "Bonus/assets/guns/knife_3.png";
	knife[4] = "Bonus/assets/guns/knife_0.png";
	init_arm(game, knife);
}

static void	init_ak(t_game *game)
{
	char	*ak[5];

	ak[0] = "Bonus/assets/guns/rifle_0.png";
	ak[1] = "Bonus/assets/guns/rifle_1.png";
	ak[2] = "Bonus/assets/guns/rifle_2.png";
	ak[3] = "Bonus/assets/guns/rifle_3.png";
	ak[4] = "Bonus/assets/guns/rifle_0.png";
	init_arm(game, ak);
}

static void	init_pisto(t_game *game)
{
	char	*pisto[5];

	pisto[0] = "Bonus/assets/guns/pistol_0.png";
	pisto[1] = "Bonus/assets/guns/pistol_1.png";
	pisto[2] = "Bonus/assets/guns/pistol_2.png";
	pisto[3] = "Bonus/assets/guns/pistol_3.png";
	pisto[4] = "Bonus/assets/guns/pistol_0.png";
	init_arm(game, pisto);
}

static void	init_machine(t_game *game)
{
	char	*machine[5];

	machine[0] = "Bonus/assets/guns/SPR00431.png";
	machine[1] = "Bonus/assets/guns/SPR00432.png";
	machine[2] = "Bonus/assets/guns/SPR00433.png";
	machine[3] = "Bonus/assets/guns/SPR00434.png";
	machine[4] = "Bonus/assets/guns/SPR00435.png";
	init_arm(game, machine);
}

void	init_player_img(t_game *game)
{
	init_knif(game);
	init_pisto(game);
	init_ak(game);
	init_machine(game);
}
