default: build file binwalk run

gitPush: build stage pull push

build:
	@-mkdir ./bin
	g++ ./src/main.cpp -o ./bin/haxbox -std=c++20 -Wno-return-local-addr -lcurl -lSDL2

file:
	@file ./bin/haxbox

binwalk:
	@binwalk ./bin/haxbox > binwalk.txt

run:
	./bin/haxbox


stage:
	git add .

pull:
	@git pull

push:
	@git commit -m "message"
	@git push