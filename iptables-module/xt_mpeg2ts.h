/*
 * Header file for MPEG2 TS match extension "mpeg2ts" for Xtables.
 *
 * Copyright (c) Jesper Dangaard Brouer <hawk@comx.dk>, 2009-2011+
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License; either
 * version 2 of the License, or any later version, as published by the
 * Free Software Foundation.
 *
 */
#ifndef _LINUX_NETFILTER_XT_MPEG2TS_MATCH_H
#define _LINUX_NETFILTER_XT_MPEG2TS_MATCH_H 1

/* XT_MODULE_NAME could be replaced by KBUILD_MODNAME, if this version
   info were only used the kernel module, but we also use it in
   userspace.
*/
#define XT_MODULE_NAME		"xt_mpeg2ts"
#define XT_MODULE_VERSION	"0.7.0"
#define XT_MODULE_RELDATE	"Apr 20, 2011"
#define PFX			XT_MODULE_NAME ": "

static char version[] =
	XT_MODULE_NAME ".c:v" XT_MODULE_VERSION " (" XT_MODULE_RELDATE ")";

enum {
	XT_MPEG2TS_DETECT_DROP = 1 << 0,
	XT_MPEG2TS_MAX_STREAMS = 1 << 1,
	XT_MPEG2TS_PARAM_NAME  = 1 << 2,
};

/* Details of this hash structure is hidden in kernel space xt_mpeg2ts.c */
struct xt_rule_mpeg2ts_conn_htable;

struct mpeg2ts_cfg {

	/* Hash table setup */
	__u32 size;		/* how many hash buckets */
	__u32 max;		/* max number of entries */
	__u32 max_list;	/* warn if list searches exceed this number */
};


struct xt_mpeg2ts_mtinfo {
	__u16 flags;

	/* FIXME:

	   I need to fix the problem, where I have to reallocated data
	   each time a single rule change occur.

	   The idea with rule_name and rule_id is that the name is
	   optional, simply to provide a name in /proc/, the rule_id
	   is the real lookup-key in the internal kernel list of the
	   rules associated dynamic-allocated-data.

	 */
	char rule_name[IFNAMSIZ];

	struct mpeg2ts_cfg cfg;

	/** Below used internally by the kernel **/
	__u32 rule_id;

	/* Hash table pointer */
	struct xt_rule_mpeg2ts_conn_htable *hinfo __attribute__((aligned(8)));
};

#endif /* _LINUX_NETFILTER_XT_MPEG2TS_MATCH_H */
