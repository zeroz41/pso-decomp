#ifndef PSO_NETWORK_TTCPSOCKETTYPES_H
#define PSO_NETWORK_TTCPSOCKETTYPES_H

#include "types.h"

struct at_ip4_opt {
	u8 ttl;
	u8 svctype;
	u8 df_flag;
};

struct at_ip6_opt {
	u8 traffic_class;
	u32 flow_label;
	u8 hop_limit;
};

struct at_ip_option {
	u32 type;
	union {
		struct at_ip6_opt ip6;
		struct at_ip4_opt ip4;
	} ip46;
};

struct at_ip_addr {
	u32 type;
	union {
		u8 ip6[16];
		u32 ip4;
	} ip46;
};

#endif
