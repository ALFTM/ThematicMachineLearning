#include <stdio.h>
#include <windows.h>
#include "GlaDOSInteractions.h"

void glaDOSStartTalking(int timeBetweenPhrases) {
	printf("Hello and, again, welcome to the Aperture Science computer-aided enrichment center.\n");
	Sleep(timeBetweenPhrases);
	printf("We hope your brief detention in the relaxation vault has been a pleasant one.\n");
	Sleep(timeBetweenPhrases);
	printf("Your specimen has been processed and we are now ready to begin the test proper.\n");
	Sleep(timeBetweenPhrases);
	printf("Before we start, however, keep in mind that although fun and learning are the primary goals of all enrichment center activities, serious injuries may occur.\n");
	Sleep(timeBetweenPhrases);
}

void glaDOSInitializeTestsTalking(int timeBetweenPhrases) {
	printf("The Enrichment Center promises to always provide a safe testing environment.");
	Sleep(timeBetweenPhrases);
}