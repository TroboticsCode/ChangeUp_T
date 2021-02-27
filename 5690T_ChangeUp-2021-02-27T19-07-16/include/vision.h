/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature REDSIG = vex::vision::signature (1, 6379, 8769, 7574, -803, 1, -401, 1.1, 0);
vex::vision::signature BLUESIG = vex::vision::signature (2, -2621, -1149, -1886, 5893, 9955, 7924, 1.4, 0);
vex::vision::signature GREENSIG = vex::vision::signature (3, -4585, -3761, -4174, -4791, -3925, -4358, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 3, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision1 = vex::vision (vex::PORT16, 50, REDSIG, BLUESIG, GREENSIG, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/