#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

#define MOTOR_MAX_SPEED 100 // The motor has the 36 Gearset
#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10

void autonomous() {
    pros::Motor left_wheels (LEFT_WHEELS_PORT, MOTOR_GEARSET_36);
    pros::Motor right_wheels (RIGHT_WHEELS_PORT, MOTOR_GEARSET_36, true); // This reverses the motor

    std::cout << "Moving autonomous for 1000 tics at speed: ";
    std::cout << MOTOR_MAX_SPEED << " \n";       // Show to the terminal Debug info

    right_wheels.move_relative(1000, MOTOR_MAX_SPEED);
    left_wheels.move_relative(1000, MOTOR_MAX_SPEED);
}
