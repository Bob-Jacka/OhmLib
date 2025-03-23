/*
Library for arduino programming.
Include some useful functions for electro ~ things.

version - 0.0.1
*/

#ifndef OHMLIB_H
#define OHMLIB_H

#define _10_kOHM_resistor 10_000
#define _200_OHM_resistor 200
#define _100_OHM_resistor 100

#define OHM "ohm"
#define AMPER "amper"
#define VOLT "volt"

//Some materials resistance
#define ALUMINUM_res 0,028
#define GOLD_res 0,023 
#define COOPER_res 0,0175 
#define TITAN_res 0,6

typedef const double double_val;

//for the section of the chain

#define AMPERAGE "I"
#define VOlTAGE "U"
#define RESISTANCE "R" // outer res

inline double_val get_resistance(double_val voltage, double_val amperage) {
    return voltage / amperage;
}

/*
Function for getting amperage through ohm law.
A = V / R.
*/
inline double_val get_amperage(double_val resistance, double_val voltage) {
    return voltage / resistance;
}

/*
Function for getting voltage through ohm law.
V = R / A.
*/
inline double_val get_voltage(double_val resistance, double_val amperage) {
    return resistance * amperage;
}

/*
Function for getting resistance through ohm law.
R = r * (cond_len / cross_sectional_area).
*/
inline double_val get_res_by_lenght(double_val conductor_len, double_val cross_sectional_area, double_val resistivity) {
    return resistivity * (conductor_len / cross_sectional_area);
}

//END for the  SECTION OF THE CHAIN

//for the full section of the chain
#define ELECTROMOTIVE_FORCE "ε"
#define INNER_RES "r"

/*
Function for getting amperage.
*/
inline double_val get_amperage_fc(double_val electromotiv_force, double_val outer_res, double_val inner_res) {
    return electromotiv_force / (outer_res + inner_res);
}

/*
Only for the same resistors
*/
inline double_val infinityChain_res(double_val first_resistor_res, unsigned int res_count) {
    return first_resistor_res /res_count;
}

/*
Only for the different resistors
*/
template<class... Dif_res>
inline double_val infinityChain_res(double_val first_resistor_res, double_val args[]) {
    double_val to_return = 0.0;
    for (auto value : args) {
        to_return += 1 / value;
    }
    return 1.0 / to_return;
}

//END for the FULL SECTION OF THE CHAIN

//Colored resistors schema
#define BLACK_RING 1
#define BROWN_RING 10
#define RED_RING 100
#define ORANGE_RING 1_000
#define YELLOW_RING 10_000
#define GREEN_RING 100_000
#define BLUE_RING 1_000_000
#define VIOLET_RING 10_000_000
#define GRAY_RING 10_000_000
#define WHITE_RING 1_000_000_000
#define GOLDEN_RING 0,01
#define SIVERY_RING 0,1

#endif