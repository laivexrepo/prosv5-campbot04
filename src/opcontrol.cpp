#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10

void opcontrol() {
	bool autoRun = true;

	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(LEFT_WHEELS_PORT);
	pros::Motor right_mtr(RIGHT_WHEELS_PORT, true);	// reverse motor


	// Manual VEXNET code to be removed for competition

	/* OPCONTROL will run a controller read loop, wait for the
	   Y button to be pressed to run atuonomous or the A button
		 to be pressed to run the opcontrol routine
	*/

	std::cout << "VEXnet Manual section \n";
	while(autoRun) {
		 // CODE To test Autonomous without VEXnet switch
		 // This should never be part of production code
		 if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
				 std::cout << "Calling autonomous function \n";
				 autonomous();
		 } else if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
				 autoRun = false;
				 std::cout << "Calling opcontrol function \n";
		 }
		 pros::delay(20);				// Slow the thread down
	}

	// Here we run the normal opcontrol Code
	while (true) {
		left_mtr.move(master.get_analog(ANALOG_LEFT_Y));
		right_mtr.move(master.get_analog(ANALOG_RIGHT_Y));
		pros::delay(20);
	}
}
