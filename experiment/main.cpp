
#include <unistd.h>
#include <sys/syscall.h>
#include <iostream>
#include "DefaultClock.h"
#include <fcntl.h>
#include <string.h>

 int main(int argc, char *argv[]) {
     int bufferSize = 2;
     char buffer[bufferSize];
     double numberOfWrites = 0;
     double numberOfReads = 0;
     long fileHandle;
     using AccurateClock::DefaultClock;
     using std::cout;
     using std::endl;
     auto clock = DefaultClock();


     if (argc != 1) {


         if (strcmp(argv[1], "--buffer_size") == 0) { bufferSize = atoi(argv[2]); }
         if (strcmp(argv[3], "--file_name") == 0) {
             fileHandle = syscall(SYS_open, argv[4], O_CREAT | O_TRUNC | O_RDWR);
         }
         if (strcmp(argv[5], "--write_count") == 0) { numberOfWrites = atof(argv[6]); }
         if (strcmp(argv[5], "--read_count") == 0) { numberOfReads = atof(argv[6]); }


         double totalWrite = numberOfWrites * bufferSize;
         double totalRead = numberOfReads * bufferSize;
         auto start = clock.getTime();

         for (int i = 0; i < numberOfWrites; i++) {

             syscall(SYS_write, fileHandle, &buffer[0], bufferSize);

         }
         if (argc != 1) {


             for (int j = 0; j < numberOfReads; j++) {

                 syscall(SYS_read, fileHandle, &buffer[0], bufferSize);

             }


             auto end = clock.getTime();
             auto duration = (end - start);

             cout << "Wrote a total of " << totalWrite << " bytes.\n";
             cout << "Read a total of " << totalRead << " bytes.\n";
             cout << "The process took ";
             duration.print(cout);
	     cout << "\n";


             syscall(SYS_close, fileHandle);


         }
     }


     return 0;
 }
