#ifndef TLM_TLC_H
#define TLM_TLC_H
// Here you must model the TLM TLC
#include "systemc.h"
#include <interfaces.h>
#include "colors.h"

SC_MODULE(TLM_TLC){
	sc_port<light_if> light;
	sc_port<timer_if> timer;
	sc_port<car_if> car;
	
	SC_CTOR(TLM_TLC){
		
		SC_THREAD(controller);
		
	}
	void controller();

	
};


#endif
