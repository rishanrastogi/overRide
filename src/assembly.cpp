#include "vex.h"

// The code in this file is example and can be deleted

// This is example code for a push back robot with two 5.5W motors on the lower intake,
// 11W motor on the top intake, a scraper, and wing

// This function is called once at the start of user control
void Assembly::init() {
    // You can declare a task that you want to always run in user control.

    // For example a task that is always checking if the intake is moving forward while being told to,
    // and detected not, then the intake will move in reverse to unjam itself
} 

// You want to put this function inside the user control loop in main.
void Assembly::control() {
    static bool initialized = false;

    if (!initialized) {
        init();
        initialized = true;
    }

    lower_intake_control();
    conveyor_motors_control();
    claw_piston_control();
    grip_piston_control();
}


// Spins intake forward if L1 is being held, reverse if L2 is being held; stops otherwise
void Assembly::lower_intake_control() {
    if (Controller.ButtonL1.pressing()) {
        lower_intake_motors.spin(fwd, 12, volt);
    } else if (Controller.ButtonL2.pressing()) {
        lower_intake_motors.spin(fwd, -12, volt);
    } else {
        lower_intake_motors.stop();
    }
}

// Spins intake forward if R2 is being held, reverse if Button Down is being held; stops otherwise
void Assembly::conveyor_motors_control() {
    if (Controller.ButtonR2.pressing()) {
        conveyor_motors.spin(fwd, 12, volt);
    } else if (Controller.ButtonDown.pressing()) {
        conveyor_motors.spin(fwd, -12, volt);
    } else {
        conveyor_motors.stop();
    }
}

// Extends piston when button R1 is pressed, releases otherwise 
void Assembly::claw_piston_control() {
    if (Controller.ButtonR1.pressing()) {
        claw_piston.open();
    } else {
        claw_piston.close();
    }
}

// Extends or retracts piston when button A is pressed, 
// can only extend or retract again until button A is released and pressed again
void Assembly::grip_piston_control() {
    if (btnA_new_press(Controller.ButtonA.pressing())) {
        grip_piston.toggle();
    }
}