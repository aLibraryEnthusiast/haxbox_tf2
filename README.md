# HAXBOX - a linux based external tf2 hack almost* undetectable

##### NOTICE: i, or any 3rd party, do not condone hacking, whilst yes i made this, it doesn't mean you should use it, i took a huge risk when making this so be careful

## features:
 - almost* undetectable
 - normal hacks (esp, tracers, aimbot, hide overlay, etc)
 - update notices
 - fast & reliable
 - haxbox exclusive hacks (TBD)

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