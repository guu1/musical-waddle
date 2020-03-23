#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>



#include "error.h"
#include "file_utils.h"
#include "receive.h"
#include "send.h"



void create_file(int sock);



void create_file(int sock)
{
        char file[1024];
        
        receive_nstr(sock, &file[0]);
        
        // TODO: get options for file mode bits

        FILE *fp = fopen_file(file, "w");

        if (fp) {
                send_message(sock, "File created successfuly");
                fclose(fp);
        } 

}


