#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/CreationMotion.h"

extern CharacterAppearanceFields* creation_player_character;
s32 creation_motion_group() {
    if(creation_player_character->classFlags&1)return 0;
    s32 group=1;
    if((s32)creation_player_character->classId==6)group=2;
    return group;
}
