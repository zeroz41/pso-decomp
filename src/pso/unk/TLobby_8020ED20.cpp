#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int generate_armor_shop_stock(void);

    extern int lbl_805D615C;
void TLobby::set_shop_armor_list_flag(int a0, int a1) { lbl_805D615C = a1; generate_armor_shop_stock(); }

}
