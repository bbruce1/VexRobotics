#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor armright = motor(PORT1, ratio18_1, false);
motor backleft = motor(PORT2, ratio18_1, false);
motor frontright = motor(PORT3, ratio18_1, true);
motor backright = motor(PORT4, ratio18_1, true);
motor backlift = motor(PORT7, ratio18_1, false);
motor armleft = motor(PORT8, ratio18_1, true);
motor frontleft = motor(PORT9, ratio18_1, false);
controller Controller1 = controller(primary);
digital_out dig1 = digital_out(Brain.ThreeWirePort.B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}