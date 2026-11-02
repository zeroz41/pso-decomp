#include "types.h"
#include "pso/object/TObjLuker_801329B0.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjTombstone.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/Language.h"

#pragma readonly_strings on


struct E_80075D68 { u8 f0; u8 pad[0x2f]; };

struct O_80075D68 { u8 pad[0x110]; E_80075D68 e[6]; };

struct Vec_8007598C { f32 x, y, z; };

struct Obj_8007598C { u8 pad[0x38]; Vec_8007598C pos; };

struct Ply_8007598C { u8 pad[0x38]; Vec_8007598C pos; };

struct Obj_80075AE8 { u8 pad[0xF0]; char name[0xE0]; char buf[0x30]; };

struct Obj_80075BE0 { u8 pad[0xDC]; char name[0x94]; char buf[0x30]; };

struct Obj_80075C60 { u8 pad[0xC4]; s16 val; u8 pad2[0x7A]; char buf[0x30]; };

struct Obj_80075CB4 { u8 pad[0xAC]; s32 fac; u8 pad_b0[0x110 - 0xB0]; char name[0x30]; };

struct Ply_80075CB4 { u8 pad[0x85C]; char name[0x30]; };

struct Tomb_80075A00 {
    u8 pad0[0xAC];
    s32 owner;
    u8 padB0[0xC8 - 0xB0];
    u32 date;
    u8 padCC[0x200 - 0xCC];
    char text[1];
};

struct Tomb_80075B5C { u8 pad[0xCC]; s32 rt_index; u8 pad2[0x1A0 - 0xD0]; char text[0x30]; };

extern "C" {
void subtract_vector(Vec_8007598C *, Vec_8007598C *);
f32 vector_length(Vec_8007598C *);
extern s32 local_client_id;
extern const f32 TObjTombstone__data_805D9174;
int sprintf(char *, const char *, ...);
const char *TQuestVmDownLoadServer__sub_8006EF6C(s32);
Ply_8007598C * get_player_by_client_id(s32, void *);
char *strncpy(char *, const char *, unsigned long);
unsigned long strlen(const char *);
s32 check_height_ready__13TObjTombstoneFv();

void TObjTombstone::render() {
    s32 arg0 = (s32)this;

    if (check_height_ready__13TObjTombstoneFv() != 0) {
        ((TObjTombstone *)arg0)->update_render_flags();
        switch (TWindowSubStatusDisp::resolve_player_slot(-1)) {
        case 2:
        case 3:
            ((TObjTombstone *)arg0)->update_fade_by_distance();
            break;
        default:
            TObjTombstone::draw_name_labels((void *)arg0);
            break;
        }
    }
}

f32 TObjTombstone::get_distance_to_local_player_xz(void * _w1) {
    Obj_8007598C *self = (Obj_8007598C *)this;
    Ply_8007598C *p = get_player_by_client_id(local_client_id, _w1);
    if (p == 0) {
        return 65536.0f;
    }
    Vec_8007598C v = self->pos;
    subtract_vector(&v, &p->pos);
    v.y = TObjTombstone__data_805D9174;
    return vector_length(&v);
}

void TObjTombstone::format_date_text() {
    Tomb_80075A00 *self = (Tomb_80075A00 *)this;
    char *text;
    s32 month;
    s32 day;
    s32 hour;
    s32 minute;
    s32 year;
    u32 d;
    text = self->text;
    text[0] = 0;
    if (self->owner != local_client_id) {
        return;
    }
    d = self->date;
    year = d >> 28;
    month = (d >> 24) & 0xF;
    day = (d >> 16) & 0x1F;
    hour = (d >> 8) & 0x1F;
    minute = d & 0x3F;
    if (year == 15 || month <= 0 || month > 12 || day <= 0 || day > 31
        || hour < 0 || hour >= 24 || minute < 0 || minute >= 60) {
        return;
    }
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        sprintf(text, (char *)"%d/%02d/%02d %02d:%02d", year + 2000, month, day, hour, minute);
        break;
    default:
        sprintf(text, (char *)"%02d/%02d/%d %02d:%02d", month, day, year + 2000, hour, minute);
        break;
    }
}

void TObjTombstone::format_quoted_name() {
    Obj_80075AE8 *self = (Obj_80075AE8 *)this;
    char *buf = self->buf;
    if (self->name[0] == 0 || TWindowSubComCard::contains_profanity(self->name) != 0) {
        buf[0] = 0;
    } else {
        sprintf(buf, (char *)"\"%s\"", self->name);
    }
    buf[0x2F] = 0;
}

void TObjTombstone::format_enemy_text() {
    Tomb_80075B5C *self = (Tomb_80075B5C *)this;
    char fmt[0x30];
    char *text = self->text;
    s32 name;
    text[0] = 0;
    if (self->rt_index > 0) {
        name = enemy_name_for_rt_index(self->rt_index);
        if (name != 0) {
            strncpy(fmt, TQuestVmDownLoadServer__sub_8006EF6C(0x4E), 0x2F);
            fmt[0x2F] = 0;
            sprintf(text, fmt, name);
        }
    }
    text[0x2F] = 0;
}

void TObjTombstone::build_name_text() {
    Obj_80075BE0 *self = (Obj_80075BE0 *)this;
    char *buf = self->buf;
    if (self->name[0] == 0 || TWindowSubComCard::contains_profanity(self->name) != 0) {
        buf[0] = 0;
    } else {
        sprintf(buf, (char *)"%s%s", TQuestVmDownLoadServer__sub_8006EF6C(0x4C), self->name);
    }
    buf[0x2F] = 0;
}

void TObjTombstone::format_label() {
    Obj_80075C60 *self = (Obj_80075C60 *)this;
    sprintf(self->buf, (char *)"%s%d", TQuestVmDownLoadServer__sub_8006EF6C(0x4D), this->m_c4);
    self->buf[0x2F] = 0;
}

void TObjTombstone::format_player_name() {
    Obj_80075CB4 *self = (Obj_80075CB4 *)this;
    char buf[0x30];
    char *p;
    Ply_80075CB4 *ply;
    char *dst = self->name;
    ply = ((Ply_80075CB4 *)get_player_by_client_id(self->fac, self));
    dst[0] = 0;
    if (ply != NULL) {
        strncpy(buf, ply->name, 0x2F);
        buf[0x2F] = 0;
        for (p = buf + strlen(buf) - 1; p > buf && *p == ' '; p--) {
            *p = 0;
        }
        sprintf(dst, (char *)"< %s >", buf);
    }
    dst[0x2F] = 0;
}

void TObjTombstone::reset_entries_and_format_name() {
    O_80075D68 *self = (O_80075D68 *)this;
    s32 i;
    for (i = 0; i < 6; i++) {
        self->e[i].f0 = 0;
    }
    format_player_name();
}

}
