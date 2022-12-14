/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2022, The Linux Foundation. All rights reserved.
 */

#ifndef _SM6150_PORT_CONFIG
#define _SM6150_PORT_CONFIG

#include <soc/swr-common.h>

/*
 * Add port configuration in the format
 * { si, off1, off2, hstart, hstop, wd_len, bp_mode, bgp_ctrl, lane_ctrl}
 */

struct port_params wsa_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{7,  1,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{31, 2,  0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{63, 12, 31,   0xFF, 0xFF, 0xFF,  0x1, 0xFF, 0xFF},
	{7,  6,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{31, 18, 0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{63, 13, 31,   0xFF, 0xFF, 0xFF,  0x1, 0xFF, 0xFF},
	{15, 7,  0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
	{15, 10, 0,    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
};

struct port_params rx_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{3,  0,  0,  0xFF, 0xFF, 1,    0xFF, 0xFF, 1},
	{31, 0,  0,  3,    6,    7,    0,    0xFF, 0},
	{31, 11, 11, 0xFF, 0xFF, 4,    1,    0xFF, 0},
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 1,    0},
	{0,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0,    0},
};

struct port_params rx_frame_params_dsd[SWR_MSTR_PORT_LEN] = {
	{3,  0,  0,  0xFF, 0xFF, 1,    0xFF, 0xFF, 1},
	{31, 0,  0,  3,    6,    7,    0,    0xFF, 0},
	{31, 11, 11, 0xFF, 0xFF, 4,    1,    0xFF, 0},
	{7,  9,  0,  0xFF, 0xFF, 0xFF, 0xFF, 1,    0},
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 3,    0},
};

struct port_params tx_frame_params_default[SWR_MSTR_PORT_LEN] = {
	{1,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0},
	{1,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1},
	{3,  1,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0},
	{3,  0,  0,  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 1},
};

static struct swr_mstr_port_map sm_port_map[] = {
	{TX_MACRO, SWR_UC0, tx_frame_params_default},
	{RX_MACRO, SWR_UC0, rx_frame_params_default},
	{RX_MACRO, SWR_UC1, rx_frame_params_dsd},
	{WSA_MACRO, SWR_UC0, wsa_frame_params_default},
};

#endif /* _SM6150_PORT_CONFIG */ 
