#pragma once

#include "vex.h"

using namespace vex;

// The internals of this class is example code and can be deleted

// This is example code for a push back robot with two 5.5W motors on the lower intake,
// 11W motor on the top intake, a scraper, and wing

class Assembly {
public:
/* Create your devices here */
    static mik::motor_group lower_intake_motors;
    static mik::piston claw_piston;
    static mik::piston grip_piston;
    static mik::motor_group conveyor_motors;

/* Examples of other vex devices you may need */
    static vex::rotation rotation_sensor;
    static vex::optical optical_sensor;
        
    void init();
    void control();

    void lower_intake_control();
    void conveyor_motors_control();
    void claw_piston_control();
    void grip_piston_control();
    
};