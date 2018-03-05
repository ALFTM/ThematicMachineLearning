#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
Start point to enter
*/

void glaDOSStartTalking(int milliseconds) {
	printf("Hello and, again, welcome to the Aperture Science computer-aided enrichment center.\n");
	Sleep(milliseconds);
	printf("We hope your brief detention in the relaxation vault has been a pleasant one.\n");
	Sleep(milliseconds);
	printf("Your specimen has been processed and we are now ready to begin the test proper.\n");
	Sleep(milliseconds);
	printf("Before we start, however, keep in mind that although fun and learning are the primary goals of all enrichment center activities, serious injuries may occur.\n");
}

int glaDOS() {
	glaDOSStartTalking(1000);
	return 0;
}