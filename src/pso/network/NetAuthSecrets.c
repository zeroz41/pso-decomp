/* The network stack's start-up and shutdown hooks and the peer secrets its CHAP and PAP authenticators check (a C
 * library, built with GC/1.2.5n). The file name is inferred from its contents. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"

#include "types.h"

/* inferred: a peer name and the secret the CHAP and PAP authenticators (chap_recv_response, pap_recv_auth_request)
 * expect from it. */
typedef struct PppAuthSecret {
    const char *name;
    const char *secret;
} PppAuthSecret;

/* The name/secret pairs TLobby__sub_803F7684 looks a peer up in: one test account. */
PppAuthSecret ppp_auth_secrets[] = {
    {"test", "hogehoge"},
    {NULL, NULL},
};

/* inferred: the shutdown hook ppp_term calls while it stops the stack */
void TLobby__sub_803F7678(void) {

}

/* inferred: the start-up hook ppp_init calls */
s32 TLobby__sub_803F767C(void) {
    return 0;
}

const char *TLobby__sub_803F7684(const char *name) {
    PppAuthSecret *p;
    for (p = ppp_auth_secrets; p->name != NULL; p++) {
        if (NetCompareStrings(name, p->name) == 0) {
            return p->secret;
        }
    }
    return NULL;
}
