#include <iostream>
#include "capacitor.h"


int main(){
    Capacitor cap;
    //initialize the timestamps, delta_t and the resistance
    int n_timestamp = 50000;
    double delta_t = 1e-10;
    double resistance = 1e3;
    

    //allocate memory for time, voltage, and current
    cap.time = new double[n_timestamp];
    cap.voltage = new double[n_timestamp];
    cap.current = new double[n_timestamp];
    //capacitor value
    cap.C = 100e-12;

    //set the inital for current and voltage in constant current case
    cap.voltage[0] = 0.0;
    cap.current[0] = 1e-2;

    //update the time, current and voltage values 
        for(int i=1; i<n_timestamp; i++){
        cap.time[i] = i * delta_t;

        //solving in constant current case to must stay the same
        cap.current[i] = cap.current[0];
        cap.voltage[i] = cap.voltage[i-1] + cap.current[i-1] * delta_t / cap.C;

        //print the time, voltage and current at each timestamp in increments of 200
        if(i % 200 == 0){
            std::cout << "Timestamp-" << i << std::endl;
            std::cout << "Time: " << cap.time[i] << " Current: " << cap.current[i]
                        << " Voltage is: " << cap.voltage[i] << std::endl;
        }

    }

    //free the allocated memory
    delete[] cap.time;
    delete[] cap.voltage;
    delete[] cap.current;

    return 0;
}