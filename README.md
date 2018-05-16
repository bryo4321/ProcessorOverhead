# ProcessorOverhead
Simple Linux program using system calls that reads/writes a file with a set buffer size and number of reads and writes. Used to estimate overhead time for processor for read/write instructions.


When looking at the data in the .csv, there is a clear pattern where time reduces as buffer size increases. This was done using an ubuntu virtual machine that was allowed only 1GB of RAM. Thus at the largest buffer size of 1mb, 2048 reads/writes were done, and the time to do this was smaller than any other buffer size. The reason that the 1mb buffer size was the fastest was due to the system call overhead of the read and write calls. By reducing the amount of system calls you have to make, you will be more efficiently reading and writing the data because you are sending and receiving the data in bigger chunks, instead of waiting for a large amount of system calls to finish moving small amounts of data. However, it is worth noting that if you were for example writing data to a mechanical hard disk drive, a larger buffer size may not always be better.Ê

By taking my shortest time with a 1kb buffer size and a write or read count of 2097152, I have calculated the system overhead for reads and writes to be somewhere around 40 ns. This is with a macbook that has an Intel I7-5557U cpu. Judging from what I could find for measurements on other older CPUs as well as new intel cpus, these system call overhead times seems to be fairly accurate and in line with other recent intel chips.


Use the following in a .sh to run on linux, modify to change your desired buffer size and read/write count


./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --write_count 2097152


./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --write_count 524280

./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --write_count 65536

./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --write_count 32760

./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --write_count 16384

./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --write_count 4096

./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --write_count 2048

./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152
./experiment >> result.txt --buffer_size 1 --file_name file.txt --read_count 2097152


./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280
./experiment >> result.txt --buffer_size 4 --file_name file.txt --read_count 524280

./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536
./experiment >> result.txt --buffer_size 32 --file_name file.txt --read_count 65536

./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760
./experiment >> result.txt --buffer_size 64 --file_name file.txt --read_count 32760

./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384
./experiment >> result.txt --buffer_size 128 --file_name file.txt --read_count 16384

./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096
./experiment >> result.txt --buffer_size 512 --file_name file.txt --read_count 4096

./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048
./experiment >> result.txt --buffer_size 1024 --file_name file.txt --read_count 2048

