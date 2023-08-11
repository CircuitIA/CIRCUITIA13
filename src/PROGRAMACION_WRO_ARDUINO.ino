/*!
 * MindPlus
 * uno
 *
 */
#include <DFRobot_HuskyLens.h>
#include <DFRobot_Libraries.h>
// Create an object
DFRobot_HuskyLens huskylens;
DFRobot_Servo360  servo360_8;
DFRobot_Servo360  servo360_9;


// Main program start
void setup() {
	servo360_8.attach(8);
	servo360_9.attach(9);
	huskylens.beginI2CUntilSuccess();
	huskylens.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION);
	huskylens.request();
	delay(1000);
	if (huskylens.isAppear(1,HUSKYLENSResultBlock)) {
		servo360_8.speed(50);
		delay(1);
	}
	else {
		servo360_9.speed(100);
		delay(3000);
		servo360_8.speed(50);
		delay(1);
		servo360_9.speed(100);
	}
}
void loop() {

}
