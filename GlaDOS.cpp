#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "GlaDOSInteractions.h"

/*
Start point to enter
*/

extern "C" {
	int glaDOS() {
		glaDOSStartTalking(1000);
		return 0;
	}
}
