/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature REDSIG2 = vex::vision::signature (1, 6379, 8769, 7574, -803, 1, -401, 3.3, 0);
vex::vision::signature BLUESIG2 = vex::vision::signature (2, -2621, -1149, -1886, 5893, 9955, 7924, 1.4, 0);
vex::vision::signature GREENSIG2 = vex::vision::signature (3, -4585, -3761, -4174, -4791, -3925, -4358, 5.2, 0);
vex::vision::signature SIG_8 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_9 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_10 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_11 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision2 = vex::vision (vex::PORT4, 50, REDSIG2, BLUESIG2, GREENSIG2, SIG_8, SIG_9, SIG_10, SIG_11);
/*vex-vision-config:end*/