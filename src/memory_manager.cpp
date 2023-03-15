//deals with modifying memory
#include <iostream>

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

bool writeMemory(string pid, int offset){ //todo: write this propper
    
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