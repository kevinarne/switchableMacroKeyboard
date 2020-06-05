const String KEYBOARDS[][4][3] = {
                                  {{"7","8","9"},
                                   {"4","5","6"},
                                   {"1","2","3"},
                                   {"-","0","."}},

                                  {{"128&130&99&","128&129&107&","128&43&"}, // Stroke to path, break apart, union
                                   {"128&100&","128&103&","128&129&103&"}, // Duplicate, group, ungroup
                                   {"213&","212&","210&"}, // Lower to bottom, delete, raise to top
                                   {"128&122&","128&129&102&","128&129&97&"}} // Undo, fill and stroke, align and distribute
                                 };

const String KB_NAMES[] = {"Numbers", "Inkscape"};

const int NUM_KB = 2; 
