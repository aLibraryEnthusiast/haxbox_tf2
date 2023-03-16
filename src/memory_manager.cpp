//deals with modifying memory
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

auto getPID(string program_name){
    char buf[512];
    string tosee = "pidof -s " + program_name;
    FILE *cmd_pipe = popen(tosee.c_str(), "r");

    fgets(buf, 512, cmd_pipe);
    pid_t pid = strtoul(buf, NULL, 10);

    pclose( cmd_pipe );  
    return pid;
}

int readMemory(ptrdiff_t offset, pid_t pid){
    std::ifstream mem("/proc/" + to_string(pid) + "/mem", ios::in | ios::binary);
    if(!mem.is_open()){
        cerr << "failed to open memory of TF2, try running as sudo\n";
        return -1;
    }

    if(mem.seekg(to_string(offset) == "-1")){
        cerr << "failed to seek to specified point\n";
        return 6;
    }
    char buffer[4];
    //read 4 bytes at specified memory address
    if(!mem.read(buffer, sizeof(buffer))){
        cerr << "failed to read memory\n";
        return 6;
    }
    int data = *reinterpret_cast<int*>(buffer);
    cout << "Data at memory location: " << data <<"\n";

    mem.close(); //close pipe to memory
    return 0;
}

bool writeMemory(int offset, pid_t pid){ //todo: write this propper
    
    if(true == true){
        //if it worked
        return true;
    }
    else{
        //if it failed
        return false;
    }
    //if you somehow escaped the thing
    return NULL;
}

auto connectToProgram(string program_name){
    auto pid = getPID(program_name);
    return pid;
}