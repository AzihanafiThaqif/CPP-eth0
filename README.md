# CPP-eth0
<h3>Assignment TCP/IP : Lecturer Dr. Anang</h3>
C++ code to find eth0 in linux

<h2> Group Member </h2>
1. Azihanafi Mohd Dakir 1111115003
2. Mohamad Thaqif bin Jamaludin 1112701034

<h2> Task That Have Been Carried Out </h2>
1. Install Git and Create account Github
2. Opening Terminal (or Git Bash)
3. Seeing Files, Moving to Folders
4. Make a Folder, Make a File
5. Git Respitory
6. Status Update
7. Staging
8. Committing
9. Telling Git about Github
10. A Push or A Shove

<h2>Work Distribution</h2>
All work distribution are equally divided among members

<h2>c++ code to view eth0 on linux</h2>
```c++
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


```

# CPP-eth0
<h2>Output result</h2>

inet: 10.0.2.15
