#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <switch.h>

//The SD card is automatically mounted as the default device, usable with standard stdio. SD root dir is located at "/" (also "sdmc:/" but normally using the latter isn't needed).
//The default current-working-directory when using relative paths is normally the directory where your application is located on the SD card.

int main(int argc, char **argv)
{
    gfxInitDefault();
    consoleInit(NULL);

    printf("FALKI TEST SCRIPT FOR SHUTDOWN AND REBOOT...\n");
    printf("A    - Restart\n");
    printf("B    - Shutdown\n");
    printf("PLUS - Exit\n");

    // Main loop
    while(appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu
        if(kDown & KEY_A)
        {
            bpcInitialize();
            bpcRebootSystem();
        }
        if(kDown & KEY_B)
        {
            bpcInitialize();
            bpcShutdownSystem();
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    gfxExit();
    return 0;
}
