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
 void opcontrol() {
 	pros::Controller master(pros::E_CONTROLLER_MASTER);
   pros::lcd::initialize();

 	int liftPosition = 2;
 	int trayPosition = 0;
   int left, right;

   pros::Motor left1(1, MOTOR_GEARSET_06, true);
   pros::Motor left2(2, MOTOR_GEARSET_06, false);
   pros::Motor right1(3,MOTOR_GEARSET_06, false);
   pros::Motor right2(4,MOTOR_GEARSET_06, true);
   pros::Motor tilter(8, MOTOR_GEARSET_36, false);
   pros::Motor lift(5, MOTOR_GEARSET_36, false);
   pros::Motor intake1(6, MOTOR_GEARSET_18, true);
   pros::Motor intake2(7, MOTOR_GEARSET_18, false);

 	while (true) {

     pros::lcd::print(0, "Buttons Bitmap: %d\n", pros::lcd::read_buttons());

     left = master.get_analog(ANALOG_RIGHT_Y) + master.get_analog(ANALOG_RIGHT_X);
     right = master.get_analog(ANALOG_RIGHT_Y) - master.get_analog(ANALOG_RIGHT_X);

     right1.move(right);
     right2.move(right);
     left1.move(left);
     left2.move(left);

 		if(master.get_digital(DIGITAL_R1)){
 			if(master.get_digital(DIGITAL_R2)){
 				intake1.move(-60);
 				intake2.move(-60);
 			}else{
 				intake1.move(100);
 				intake2.move(100);
 			}
 		} else if(master.get_digital(DIGITAL_R2)){
 			intake1.move(-100);
 			intake2.move(-100);
 		} else {
 			intake1.move(0);
 			intake2.move(0);
 		}

   	tilter.move(master.get_analog(ANALOG_LEFT_Y));

 		if(master.get_digital(DIGITAL_L2)){
 			lift.move(60);
 		} else if(master.get_digital(DIGITAL_L1)){
 			lift.move(-10);
 		}

 		pros::delay(20);
 	}
 }
