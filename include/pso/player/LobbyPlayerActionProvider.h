#ifndef PSO_PLAYER_LOBBYPLAYERACTIONPROVIDER_H
#define PSO_PLAYER_LOBBYPLAYERACTIONPROVIDER_H
#include "types.h"
#include "pso/player/PlayerActionProvider.h"

class LobbyPlayerActionProvider : public PlayerActionProvider {
public:
    LobbyPlayerActionProvider();
    virtual s32 get_cell_address(s32, s32);
    virtual ~LobbyPlayerActionProvider();
    virtual const s32 *vfunc_8(s32, s32);
    virtual int vfunc_9(s32, s32, s32);
    virtual int vfunc_12();
    virtual int vfunc_13();
    virtual int vfunc_11();
    virtual int vfunc_5(s32);
    virtual int vfunc_6(s32, s32, s32);
    virtual BmlMotionEntry *vfunc_76();
    virtual int vfunc_75();
    virtual int vfunc_72();
    virtual int vfunc_71();
    virtual int vfunc_70();
    virtual int vfunc_69();
    virtual int vfunc_68();
    virtual int vfunc_67();
    virtual int vfunc_66();
    virtual int vfunc_65();
    virtual int vfunc_64();
    virtual int vfunc_63();
    virtual int vfunc_62();
    virtual int vfunc_61();
    virtual int vfunc_60();
    virtual int vfunc_59();
    virtual int vfunc_58();
    virtual int vfunc_57();
    virtual int vfunc_56();
    virtual int vfunc_55();
    virtual int vfunc_54();
    virtual int vfunc_53();
    virtual int vfunc_52();
    virtual int vfunc_51();
    virtual int vfunc_50();
    virtual int vfunc_49();
    virtual int vfunc_48();
    virtual int vfunc_47();
    virtual int vfunc_46();
    virtual int vfunc_45();
    virtual int vfunc_44();
    virtual int get_death_action();
    virtual int vfunc_43();
    virtual int vfunc_42();
    virtual int vfunc_41();
    virtual int vfunc_40();
    virtual int vfunc_39();
    virtual int vfunc_20();
    virtual int vfunc_38();
    virtual int vfunc_37();
    virtual int vfunc_36();
    virtual int vfunc_35();
    virtual int vfunc_34();
    virtual int vfunc_33();
    virtual int vfunc_32();
    virtual int vfunc_31();
    virtual int get_use_item_action();
    virtual int get_interact_action();
    virtual int get_hurt_action();
    virtual int get_knockdown_action();
    virtual int vfunc_4();
    virtual int vfunc_10();
    virtual int vfunc_7(s32, s32);
    virtual int vfunc_23();
    virtual int vfunc_22();
    virtual int get_run_action();
    virtual s32 *get_state_table(s32);
};
LAYOUT_ASSERT(LobbyPlayerActionProvider_size, sizeof(LobbyPlayerActionProvider) == 0xC);

#endif
