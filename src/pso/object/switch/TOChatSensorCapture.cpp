#include "pso/object/switch/TOChatSensorCapture.h"
#include "pso/ui/Language.h"

extern "C" {
s32 find_chat_keyword(char *, char (*)[0x20], s32);
char *strncpy(char *, const char *, size_t);
void *memset(void *, int, size_t);
void mem_free(void *);
void *mem_alloc(u32 size);
TOChatSensorCapture *TOChatSensorCapture__instance;
extern const char TOChatSensorCapture__class_name_string[];
const char *TOChatSensorCapture__class_name = TOChatSensorCapture__class_name_string;
}

s32 TOChatSensorCapture::check_keyword(u16 client, const char *keyword) {
    char buffer[0x20];
    s32 i;
    s32 c;
    if (TOChatSensorCapture__instance != NULL && client < 4) {
        strncpy(buffer, keyword, 0x20);
        for (i = 0; i < 0x20; i++) {
            c = buffer[i];
            if (c == 0) break;
            if (c == 10 || c == 11) {
                buffer[i] = 0;
                break;
            }
        }
        if (find_chat_keyword(TOChatSensorCapture__instance->messages[client],
                              (char (*)[0x20])buffer, current_language) > -1) return 1;
    }
    return 0;
}

void TOChatSensorCapture::capture_message(u16 client, const char *message) {
    if (TOChatSensorCapture__instance != NULL && client < 4) {
        strncpy(TOChatSensorCapture__instance->messages[client], message, 0x100);
        TOChatSensorCapture__instance->lifetime[client] = 0x78;
    }
}

void TOChatSensorCapture::run_task() {
    s32 i = 0;
    do {
        if (lifetime[i] != 0) {
            lifetime[i] = lifetime[i] - 1;
            if (lifetime[i] == 0) memset(messages[i], 0, 4);
        }
        i += 1;
    } while (i != 4);
}

TOChatSensorCapture::~TOChatSensorCapture() {
    for (int i = 0; i != 4; i++) mem_free(messages[i]);
    TOChatSensorCapture__instance = 0;
}

#pragma push
#pragma opt_common_subs off
TOChatSensorCapture::TOChatSensorCapture(TObject *parent) : TObject(parent) {
    m_name = TOChatSensorCapture__class_name;
    s32 i = 0;
    do {
        lifetime[i] = 0;
        messages[i] = (char *)mem_alloc(0x100);
        memset(messages[i], 0, 4);
        i += 1;
    } while (i != 4);
    TOChatSensorCapture__instance = this;
}
#pragma pop

void TOChatSensorCapture::create_instance(void *parent) {
    if (TOChatSensorCapture__instance == NULL) {
        new TOChatSensorCapture((TObject *)parent);
    }
}
