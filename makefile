default: install build file binwalk run

gitPush: build stage pull push

release: build_release sha1sumit package

faketf2: build_idiot run_idiot

build_idiot:
	g++ ./hl2-tf2.cpp -o ./hl2_linux
run_idiot:
	./hl2_linux

install:
	@sudo apt-get install libcurl4-openssl-dev libsdl2-dev

build:
	@-mkdir ./bin
	g++ ./src/main.cpp -o ./bin/haxbox -std=c++20 -Wno-return-local-addr -lcurl -lSDL2

build_release:
	@-rm ./release.zip
	@-mkdir ./release
	g++ ./src/main.cpp -o ./release/haxbox -std=c++20 -Wno-return-local-addr -lcurl -lSDL2

sha1sumit:
	@sha1sum ./release/haxbox > ./release/SHA1SUM.txt

package:
	zip -r ./release.zip ./release

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