#ifndef HW_DRIVERS_H
#define HW_DRIVERS_H

#include "interfaces.h"
#include "systemc.h"
#include <iostream>

using namespace std;
SC_MODULE(HW_drivers), light_if, timer_if, car_if{
	
	sc_in<bool> car, clk; //assuming 1kHz clock
	sc_out<color> main_road, secondary_road;
	
	SC_CTOR(HW_drivers){}
	
	virtual void set_main(color c){
	
			main_road.write(c);
			
	
	} 
    virtual void set_sec(color c){
	
		secondary_road.write(c);
	
	}
	virtual void wait_for_sec(unsigned int s){
		const int CLK_PER_SEC = 1000;
		for(int i = 0; i < CLK_PER_SEC *s; i++)
			wait(clk.posedge_event());
			
	}
	virtual void wait_for_car(){
 
		wait(car.posedge_event());
	
	}

};



#endif