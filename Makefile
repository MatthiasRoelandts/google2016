all: main

main:
	g++ main.cpp ParseInput.cpp World.cpp Point.cpp Product.cpp Warehouse.cpp Drone.cpp 

clean:
	@rm -f a.out
