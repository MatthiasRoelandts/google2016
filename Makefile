all: main

main:
	g++ -Wall main.cpp ParseInput.cpp World.cpp Point.cpp Product.cpp Warehouse.cpp Drone.cpp Order.cpp

clean:
	@rm -f a.out
