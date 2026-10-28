#include "types.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/object/TObjBgmColCtrl.h"
#include "pso/map/FloorArea.h"

struct Names_8017E1E4 { const char *name[2]; };

extern Names_8017E1E4 lbl_80443898[];
extern char lbl_804438A0[];
extern char lbl_804438B0[];
extern char lbl_804438C0[];
extern char lbl_804438D0[];
extern char lbl_804438DC[];
extern char lbl_804438EC[];
extern char lbl_804438F8[];
extern char lbl_80443904[];
extern u32 TLobby__event_theme_id;
extern u32 TObjBgmColCtrl__current_theme_id;
void TObjBgmColCtrl::play_lobby_theme_music() {
    Names_8017E1E4 names = lbl_80443898[0];
    const char *name;
    if (get_current_floor_area() == AREA_LOBBY) {
        name = names.name[1];
        TObjBgmColCtrl__current_theme_id = TLobby__event_theme_id;
    } else {
        name = names.name[0];
        TObjBgmColCtrl__current_theme_id = 0;
    }
    switch (TObjBgmColCtrl__current_theme_id) {
    case 1:
        play_area_music(lbl_804438A0);
        break;
    case 7:
        play_area_music(lbl_804438B0);
        break;
    case 3:
    case 9:
        play_area_music(lbl_804438C0);
        break;
    case 4:
        play_area_music(lbl_804438D0);
        break;
    case 5:
        play_area_music(lbl_804438DC);
        break;
    case 6:
        play_area_music(lbl_804438EC);
        break;
    case 12:
    case 14:
        play_area_music(lbl_804438F8);
        break;
    case 10:
        play_area_music(lbl_80443904);
        break;
    default:
        play_area_music((char *)name);
        break;
    }
}

void TObjBgmColCtrl::render() {  }
