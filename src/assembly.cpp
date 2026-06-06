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
    lower_intake_motors.setStopping(hold);
    if (Controller.ButtonB.pressing()) {
        lower_intake_motors.spin(fwd, 12, volt);
    } else if (Controller.ButtonX.pressing()) {
        lower_intake_motors.spin(fwd, -12, volt);
    } else {
        lower_intake_motors.stop();
    }
}

// Spins intake forward if R2 is being held, reverse if Button Down is being held; stops otherwise
void Assembly::conveyor_motors_control() {
    conveyor_motors.setStopping(hold);
    if (Controller.ButtonR1.pressing()) {
        conveyor_motors.spin(fwd, 12, volt);
    } else if (Controller.ButtonR2.pressing()) {
        conveyor_motors.spin(fwd, -12, volt);
    } else {
        conveyor_motors.stop();
    }
}

// toggle for the claw
void Assembly::claw_piston_control() {
    if (btnL1_new_press(Controller.ButtonL1.pressing())) {
        claw_piston.toggle();
    }
}

// toggle for the grip
void Assembly::grip_piston_control() {
    if (btnL2_new_press(Controller.ButtonL2.pressing())) {
        grip_piston.toggle();
    }
}