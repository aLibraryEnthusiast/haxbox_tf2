default: build file binwalk run

build:
	g++ ./src/main.cpp -o ./haxbox -std=c++20 -Wno-return-local-addr

file:
	@file haxbox

binwalk:
	@binwalk haxbox > binwalk.txt

run:
	./haxbox