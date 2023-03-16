# How to Compile

## prerequisites
to compile this you'll need the following
```text
g++
make
git
```

<br>

you'll also need one of the operating systems below
```text
chromeos (linux enabled) [CONFIRMED]
ubuntu [CONFIRMED]

OR

an operating system with apt/apt-get
```
<h2 style="color:red">warning: if you have a non-apt installed system, you may not be able to compile this, see the <a href="https://github.com/aLibraryEnthusiast/haxbox_tf2/blob/master/makefile" style="color:
#169468">makefile</a> on whats being installed</h2>

## building this stuff
once you've downloaded the prerequisites, you can start building, to start off, run this command (if you havent already)

```bash
git clone https://github.com/aLibraryEnthusiast/haxbox_tf2
```
this will clone the repository into a folder called haxbox_tf2

then what you need to do is CD into the folder, you can do it like this:
```bash
cd ./haxbox_tf2
```

now once your in the folder, its as simple as running this command

```bash
make
```

yes, its that simple, just running make will install required packages, build it, then run it, however you may need to use "```su```"/"```sudo su```" for it to work

<br>
<br>
as you probably know, this is nowhere near complete, and has some tweaks ahead of it, so i hope to see what you can do with the limited code here