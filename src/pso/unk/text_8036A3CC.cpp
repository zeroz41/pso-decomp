#pragma readonly_strings on
#include "types.h"
#include <string.h>
#include "pso/unk/text_8036A3CC.h"
#include "pso/object/collision/TObjBgmColCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct Inst_8036A3CC { u8 pad0[0x1155C]; u32 flags[2]; };

struct FlagLink_8036A514 {
    s32 flag;
    s32 linked;
};


// Song titles shown in the options jukebox, one per music flag.
const char *option_name_table[49] = {
    "A song for eternal story",
    "OPENING THEME -The whole new world-",
    "Prenotion",
    "Image of hero",
    "Day dawns",
    "Pioneer2",
    "Crossing3084",
    "Healing",
    "Chaotic bar",
    "Codes of silence",
    "Mother earth of dishonesty PART1",
    "Mother earth of dishonesty PART2",
    "Growl,from the depths of earth",
    "The kink in the wind and the way PART1",
    "The kink in the wind and the way PART2",
    "From seeing the rough wave",
    "Empty space out of control PART1",
    "Empty space out of control PART2",
    "The crazy program",
    "You have nowhere to go",
    "Revolution to the origin PART1",
    "Revolution to the origin PART2",
    "The nearest place to the heaven PART1",
    "The nearest place to the heaven PART2",
    "Pray, for \"IDOLA\" the distorted",
    "Cry, for \"IDOLA\" the holy",
    "Versus1 -Tricktrack-",
    "Versus2 -A longing to ancient times-",
    "Valentine",
    "Easter",
    "After the story1",
    "After the story2",
    "Can still see the light -ENDING THEME-",
    "The whole new world -EPISODE2-",
    "Silent palace",
    "A longing to ancient times PART1",
    "A longing to ancient times PART2",
    "Revive the secred of rough wave",
    "Tricktrack PART1",
    "Tricktrack PART2",
    "Growl, from the digital haze",
    "Jungle -A lush load-",
    "Jungle -A forest cage-",
    "The frenzy wilds",
    "Abysmal ball -intermission-",
    "Abysmal ball -banquet-",
    "\"IDOLA\" have the immortal feather",
    "\"IDOLA\" have the divine blade",
    "World with me -EPISODE2 ENDING THEME-",
};

// Stream file of each song, same order as option_name_table.
char *bgm_adx_filename_table[49] = {
    "title.adx",
    "opening.adx",
    "advr.adx",
    "CHARA.adx",
    "LOBBY.ADX",
    "city.adx",
    "GUILD.adx",
    "MEDICAL.adx",
    "SHOP.adx",
    "soutoku.adx",
    "forest_n.adx",
    "forest_b.adx",
    "dragon.adx",
    "cave_n.adx",
    "cave_b.adx",
    "delo.adx",
    "machin_n.adx",
    "machin_b.adx",
    "vol_opt1.adx",
    "vol_opt2.adx",
    "ship_n.adx",
    "ship_b.adx",
    "dark_b1.adx",
    "dark_b2.adx",
    "dark1.adx",
    "dark2.adx",
    "DUEL1.adx",
    "DUEL2.adx",
    "Valentine.adx",
    "Easter.adx",
    "epi1.adx",
    "epi2.adx",
    "ending.adx",
    "CUBE_OPENING.adx",
    "labo.adx",
    "R_N.adx",
    "R_B.adx",
    "delo2.adx",
    "S_N.adx",
    "S_B.adx",
    "dragon2.adx",
    "J_N.adx",
    "J_B.adx",
    "gryphon.adx",
    "W_N.adx",
    "W_B.adx",
    "proto1.adx",
    "proto2.adx",
    "CUBE_ENDING.adx",
};

// Unlocking .flag also unlocks .linked; ends with {-1, -1}.
const FlagLink_8036A514 music_flag_link_table[] = {
    {11, 10},
    {14, 13},
    {17, 16},
    {21, 20},
    {42, 41},
    {45, 44},
    {36, 35},
    {39, 38},
    {2, 0},
    {2, 1},
    {2, 33},
    {36, 27},
    {39, 26},
    {32, 28},
    {32, 4},
    {48, 29},
    {48, 4},
    {-1, -1},
};

const s32 music_sequencer_flag_ids[9] = {11, 14, 17, 21, 22, 42, 45, 36, 39};


u32 *get_flag_word_mask(s32 flag, u32 *mask) {
    s32 word;
    if (flag < 0) {
        return 0;
    }
    if (flag >= 0x31) {
        return 0;
    }
    word = flag / 32;
    if (word >= 2) {
        return 0;
    }
    *mask = 1 << (flag & 0x1F);
    return &((Inst_8036A3CC *)TAdSinglePlyChrSelectGC::get_instance())->flags[word];
}

void unlock_sequencer_flag(s32 program) {
    s32 flag;
    if ((program >= 0) && (program < 9)) {
        flag = music_sequencer_flag_ids[program];
        if (check_flag_index_set(flag) != 1) {
            unlock_music_flag(flag);
        }
    }
}


void TObjBgmColCtrl::update_all_zones(saddr arg0) {
    s32 i;

    i = 0;
    do {
        if (check_flag_index_set(i) != 1) {
            if (strcmp(get_bgm_filename(i), (const char *)arg0) == 0) {
                unlock_music_flag(i);
            }
        }
        i += 1;
    } while (i < 0x31);
}

void unlock_music_flag(s32 flag) {
    u32 mask;
    u32 *word;
    s32 i;

    if (check_flag_index_set(flag) != 1 && flag >= 0 && flag < 0x31) {
        word = get_flag_word_mask(flag, &mask);
        if (word != 0) {
            *word |= mask;
            for (i = 0; music_flag_link_table[i].flag != -1; i++) {
                if (flag == music_flag_link_table[i].flag) {
                    unlock_music_flag(music_flag_link_table[i].linked);
                }
            }
        }
    }
}

s32 check_flag_index_set(s32 flag) {
    s32 sp8;
    s32 *flag_word_mask;

    if (flag < 0) {
        return 0;
    }
    if (flag >= 0x31) {
        return 0;
    }
    flag_word_mask = (s32 *)get_flag_word_mask(flag, (u32 *)&sp8);
    if (flag_word_mask == NULL) {
        return 0;
    }
    return (*flag_word_mask & sp8) != 0;
}


s32 is_music_flag_unlocked_stub(s32 idx) {
    if (check_flag_index_set(idx) == 0) {
        return 1;
    }
    return 1;
}

char *get_bgm_filename(s32 arg0) {
    if (arg0 < 0) {
        return NULL;
    }
    if (arg0 >= 0x31) {
        return NULL;
    }
    return bgm_adx_filename_table[arg0];
}


s32 get_option_table_entry(s32 idx) {
    if (idx < 0) {
        return 0;
    }
    if (idx >= 0x31) {
        return 0;
    }
    return (saddr)option_name_table[idx];
}
