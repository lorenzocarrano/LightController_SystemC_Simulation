//Testbench.h

#include "systemc.h"
#include <iostream>
#include "colors.h"
using namespace std;
SC_MODULE(Testbench){
	
	public:
		
		sc_in<color> main_road, secondary_road;
		sc_out<bool> car;
	
		sc_event green_light;
	    sc_event yellow_light;
	
		sc_time tG; 
		sc_time tY;
	
		char last_G, last_Y; //'m' for main_road, 's' for secondary_road
		
		SC_CTOR(Testbench): car("car"), main_road("main"), secondary_road("secondary"){
			
				SC_THREAD(car_sim);
				
			    SC_METHOD(green_red_check); //if one is green, the other must be red
					sensitive << main_road << secondary_road;
				
				SC_METHOD(green_light_time_saving);  //saving the time @ a green light appears
					sensitive << main_road << secondary_road;
				
				SC_METHOD(yellow_light_time_saving); //saving the time @ a yellow light appears
					sensitive << main_road << secondary_road; 
			
				SC_THREAD(Green_time_check);  //minimum duration of any green light must be 10 seconds
			
				SC_THREAD(Yellow_time_check); //maximum duration of any yellow light is 5 seconds
			
				SC_METHOD(print_light_configuration);
					sensitive << main_road << secondary_road;
		
		}		
		
		void car_sim();
		void green_red_check();
		void green_light_time_saving();
		void yellow_light_time_saving();
		void Green_time_check();
		void Yellow_time_check();
		void print_light_configuration();
	
};
