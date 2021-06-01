#include <systemc.h>
//#include "interfaces.h"
#include "tlm_tlc.h"
#include "hw_drivers.h"
#include "mytestbench.h"

int sc_main (int argc, char * argv[])
{ 
	sc_signal<color> main("main_sig"), sec("sec_sig");
	sc_signal<bool> car_sig("car_sig");
	
	TLM_TLC TLC("Controller") ;
	HW_drivers hw_drivers("OS_drivers");
	Testbench TB("TB");
	
	TLC.car(hw_drivers);
	TLC.light(hw_drivers);
	TLC.timer(hw_drivers);
	
	TB.main_road(main);
	TB.secondary_road(sec);
	TB.car(car_sig);
	
	sc_clock SIMclock("SIMclock", sc_time(1, SC_MS));
	hw_drivers.clk(SIMclock);
	hw_drivers.car(car_sig);
	hw_drivers.main_road(main);
	hw_drivers.secondary_road(sec);
	
	sc_start(100, SC_SEC);
	return 0;
}
