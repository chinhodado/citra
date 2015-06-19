// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <string>

enum Button {
    A, B, X, Y, L, R, ZL, ZR,
    DUp, DDown, DLeft, DRight,
    SUp, SDown, SLeft, SRight,
    CUp, CDown, CLeft, CRight,
    Start, Select, Home,
    NUM_BUTTONS
};

namespace Settings {

struct Values {
    // Controls
    int pad_a_key;
    int pad_b_key;
    int pad_x_key;
    int pad_y_key;
    int pad_l_key;
    int pad_r_key;
    int pad_zl_key;
    int pad_zr_key;
    int pad_start_key;
    int pad_select_key;
    int pad_home_key;
    int pad_dup_key;
    int pad_ddown_key;
    int pad_dleft_key;
    int pad_dright_key;
    int pad_sup_key;
    int pad_sdown_key;
    int pad_sleft_key;
    int pad_sright_key;
    int pad_cup_key;
    int pad_cdown_key;
    int pad_cleft_key;
    int pad_cright_key;
    int input_mappings[Button::NUM_BUTTONS];

    // Core
    int frame_skip;

    // Data Storage
    bool use_virtual_sd;

    // System Region
    int region_value;

    // Renderer
    bool use_hw_renderer;

    float bg_red;
    float bg_green;
    float bg_blue;

    std::string log_filter;
} extern values;

}
