//
//  eth0.cpp
//  Eth0
//
//  Created by azihanafi on 8/20/15.
//  Copyright (c) 2015 azihanafithaqif. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    FILE *fp;
    
    char returnData[64];
    
    fp = popen("/sbin/ifconfig eth0", "r");
    
    while (fgets(returnData, 63, fp) != NULL)
    {
        if (returnData[0] == '\n') {
            continue;
        }
        
        char test[60], test2[60];
        strcpy(test, strtok(returnData, " "));
	if (strcmp("inet", test) != 0) {
            continue;
        }

        strcpy(test2, strtok(NULL, " "));
        printf("%s: %s\n", test, test2);

    }
    
    return 0;
}


