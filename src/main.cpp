//tf2 cheat engine for tux/linux
//if and when you fork this, change the data in version_info.h

#include <iostream>
#include "./header_files/version_info.h"
#include "./header_files/Vector3.h" 
#include "./header_files/fuck_you_VAC.h" //changes the sha256sum of the program ;)
#include "./memory_manager.cpp"
#include "./header_files/offsets.h" //offsets for TF2
#include "updater.cpp"
#include <SDL2/SDL_messagebox.h>

#define debug true

using namespace std;


constexpr Vector3 CalculateAngle(
    const Vector3& localPositon,
    const Vector3& enemyPosition,
    const Vector3& viewAngles) noexcept
    {
        return ((enemyPosition - localPositon).ToAngle() - viewAngles);
    }

int main(int argc, char* argv[]){
	didCheck = version_checker(haxbox_version_identifier, haxbox_update_identifier);
	didTF2Check = tf2_updated_checker(tf2_update_identifier, tf2_update_true, tf2_update_false);
    cout << haxbox_identifier << " Version " << haxbox_version_identifier << "\n";
    if(didCheck == false){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Haxbox Warning | Invalid Version", "Your Haxbox version is out of date\nplease update as soon as possible", NULL);
		//exit(-1);
	}
	if(didTF2Check == false){
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "Haxbox Warning | tf2 updated", "Haxbox has detected that tf2 has been updated\nthis may cause your current version of Haxbox to be detected\nplease stand by as we shuffle around some code and change the Shasum\n", NULL);
		exit(-1);
	}
	auto target_program_pid = connectToProgram("code"); //TODO: get actual tf2 filename
    auto current_program_pid = connectToProgram(argv[0]); //TODO: get actual tf2 filename
	cout << "current program PID: " << current_program_pid << "\n";
	cout << "target program PID: " << target_program_pid << "\n";
	if(target_program_pid == current_program_pid && debug==false){ //shouldn't happen, but there are rare edge cases
		cerr << "target program PID is equal to current program PID, exiting\n";
		return -1;
	}
	else if(target_program_pid == current_program_pid && debug==true){ //shouldn't happen, but there are rare edge cases
		cerr << "DEV NOTICE: you are injecting into this program, this is not tf2, you have been warned\npress any key to continue";
	}
	else{
		cout << "press enter to continue\n";
	}
	cin.get();
	//cout << "offset \"left\" is at: " << TF_offsets::left << "b into the binary" << "\n";
    return 0;
}