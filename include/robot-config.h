using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor armright;
extern motor backleft;
extern motor frontright;
extern motor backright;
extern motor backlift;
extern motor armleft;
extern motor frontleft;
extern controller Controller1;
extern digital_out dig1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );