# HAXBOX - a linux based external tf2 hack almost* undetectable

##### NOTICE: i, or any 3rd party, do not condone hacking, whilst yes i made this, it doesn't mean you should use it, i took a huge risk when making this so be careful

## features:
 - almost* undetectable
 - normal hacks (esp, tracers, aimbot, hide overlay, etc)
 - update notices
 - fast & reliable
 - haxbox exclusive hacks (Smooth Aimbot)

## how it works:
To be Written

## what is fuck_you_VAC.h?
fuck_you_VAC.h is a header file used by the main.cpp file to change it's sha256sum, so if valve blocks the sha256sum of "81999a70da6a506fcd718ba4170a271213dd4849f227da5f8f189a3f6d3f0053", we can add a line to the fuck_you_VAC.h to change it to "ab7575a4a405b4a265c093349156ba0b67fa4137106e74150af0dde8e12e2933"

## what is Vector3.h?
Vector3.h is made by the all holy [cazzwastaken](https://github.com/cazzwastaken/) i took it from his [CS:GO repo for external aimbot](https://github.com/cazzwastaken/external-aimbot/), if your to use it, get it [here](https://raw.githubusercontent.com/cazzwastaken/external-aimbot/main/vector.h)

## what is version_info.h?
version_info.h is where i store multiple things, here's a runthrough of whats stored in there:

 - name -> name of the program
 - version -> version of the program, compared to "tf2_updated.txt"
 - wlook_updated -> 0 if tf2 hasn't been updated, 1 if it has been updated
 - wlook_true/wlook_false -> just assisters for what's above
 - haxbox_version -> where to get "haxbox_version.txt"

## what is offsets.h?
offsets.h is a collection of all TF2 offsets, here's a runthrough on how to use them:
```c++
//rest of your code above...
#using ./header_files/offsets.h
//more code here...
std::cout << TF_offsets::iHealth << "\n"; //this prints out the offset for the health (read only)
//you get the idea
```

## why does almost have an asterisk
the reason almost has an asterist (*) is because it still can be detected, either by VAC or by any third party anti-exploit, however as it's external and not internal, it'll be more complex to detect

## issues and problems
if you, for any reason, have an issue with haxbox, for example (x) cheat isn't working or (y) crashed the game, please let me know, if i can reproduce it i'll get on and fixing it, however if it's a one-time thing, then i wont be able to reproduce it, as well as that, if you have mods installed (sound mods, etc) that may be the cause, look into your tft mods folder before filing an issue

## i want to make a fork of this, can i?
yes you can, just remember to update version_info or it'll break

##### NOTICE (again): i, or any 3rd party, do not condone hacking, whilst yes i made this, it doesn't mean you should use it, i took a huge risk when making this so be careful

# Make commands

#### to run these, you'll need either make or something similar

## make:
 - what it does: runs the default tree, which is building it, telling you what it does, binwalking and then executing
 - do you need it: yes and no, you *could* build it yourself but i dont recomend it

## make gitPush:
 - what it does: pulls/pushes to git
 - do you need it: no, it's just something i use


# list of all classes

## main.cpp (not finished)
entrypoint of this program
### what it does
 - gets its own PID and the PID of tf2
 - acts as a "bridge" between the program and tf2
 - _all_ commands go through main.cpp

## memory_manager.cpp (not finished)
reimplementation of [cazzwastaken's](https://github.com/cazzwastaken/) memory.h file
### what it does
 - provides read/write functionality to memory
 - gets PID from name

## updater.cpp (finished)
scans for updates and, if they're avalable, prompts you to download them


# what needs to be done

## important (will be done first)

### normal hacks
 - ESP (not done yet)
 - tracers (not done yet)
 - aimbot (not done yet)
 - hide overlay (not done yet)

### finish injector
#### what i need to do for that
 - learn name of tf2's executor on linux
 - profit

#### how im going to do that
idk