default: build file binwalk run

gitPush: build stage pull push

build:
	g++ ./src/main.cpp -o ./haxbox -std=c++20 -Wno-return-local-addr

file:
	@file haxbox

binwalk:
	@binwalk haxbox > binwalk.txt

run:
	./haxbox


stage:
	git add .

pull:
	@git pull

push:
	@git commit -m "message"
	@git push