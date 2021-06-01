//Testbench.cpp
#include "mytestbench.h"

void Testbench::car_sim(){
	
	car->write(false);
	cout << sc_time_stamp() << " " << name() << ": no car" << endl;
	wait(12, SC_SEC);
	car->write(true);
	cout << sc_time_stamp() << " " << name() << ": a car arrives" << endl;
	wait(15, SC_SEC);
}

void Testbench::green_red_check(){
	
		if(main_road.read() != secondary_road.read())
			cout << name() << ": Correct color configuration" << endl;
		else cout << name() << ": Uncorrect color configuration" << endl;
			
}
void Testbench::green_light_time_saving(){
	
	if(main_road.read() == GREEN || secondary_road.read() == GREEN){
	
		tG = sc_time_stamp(); //saving the time @ green light appears 
		green_light.notify();
		last_G = main_road == 2 ? 'm' : 's'; //I know if the green light is on main or secondary road	
	
	}
}
void Testbench::Green_time_check(){
	
	
	while(1){
		wait(green_light);
		last_G == 'm' ? wait(main_road.value_changed_event()) : wait(secondary_road.value_changed_event());
		sc_time t = sc_time_stamp();
		sc_time duration = t - tG;
		
		if(duration < sc_time(10, SC_SEC)){
			
			if(last_G == 'm')
				cout << name() << ": MAIN ROAD ";
			else cout << name() << ": SECONDARY ROAD ";
			
			cout << "Green Light duration error: " << duration << endl;
		}
		
		else cout << name() << ": CORRECT ";
		if(last_G == 'm')
			cout << "MAIN ROAD ";
		else cout << "SECONDARY ROAD "; 
			
		cout << "Green Light duration: " << duration << endl;
		
	}
	
}
void Testbench::yellow_light_time_saving(){
	
	if(main_road.read() == YELLOW || secondary_road.read() == YELLOW){
		
		tY = sc_time_stamp(); //saving the time @ yellow light appears 
		yellow_light.notify();
		last_Y = main_road == 2 ? 'm' : 's'; //I know if the green light is on main or secondary road	
	
	}
	
}

void Testbench::Yellow_time_check(){
	
	while(1){
		wait(yellow_light);
		last_Y == 'm' ? wait(main_road.value_changed_event()) : wait(secondary_road.value_changed_event());
		sc_time t = sc_time_stamp();
		sc_time duration = t - tY;
		
		if(duration > sc_time(5, SC_SEC)){
			
			if(last_Y == 'm')
				cout << name() << ": MAIN ROAD ";
			else cout << name() << ": SECONDARY ROAD ";
			
			cout << "Yellow Light duration error: " << endl;
		}
		
		else cout << name() << ": CORRECT ";
		if(last_Y == 'm')
			cout << "MAIN ROAD ";
		else cout << "SECONDARY ROAD "; 
			
		cout << "Yellow Light duration: " << duration << endl;
		
	}

}

void Testbench::print_light_configuration(){
	
	cout << sc_time_stamp() << ": main: " << table[main_road.read()] << " sec: " << table[secondary_road.read()]  << endl;
	
}

