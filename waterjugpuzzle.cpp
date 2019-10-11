/*******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Author      : Patrick Besser, Matthew Jacobsen
 * Date        : October 5, 2019 
 * Description : Solves the famous water jug puzzle using breadth-first search 
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Struct to represent state of water in the jugs.
struct State {
    int a, b, c;
    vector<string> directions;
    
    State(int _a, int _b, int _c) : a(_a), b(_b), c(_c) { }
    
    // String representation of state in tuple form.
    string to_string() {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }
};
/*
void bfs(int Ca, int Cb, int Cc, int Ga, int Gb, int Gc, int a, int b, int c){

*int Ca,Cb,Cc are the capacities of jugs a,b,c respectively.
*int Ga,Gb,Gc are the goals of jugs a,b,c respectively.
*int a,b,c are the states of jugs a,b,c respectively

    bool solution = false; //Value that determines if there is a solution.
    if(Ga==a && Gb==b && Gb==c){//if 
        solution = true;
    }
    else{
        //Pour c -> A

        //Pour B -> A

        //Pour C -> B

        //Pour A -> B

        //Pour B -> C

        //Pour A -> C

    }
    
    
}
*/

int main(int argc, char* const argv[]) { //MAIN METHOD
    istringstream iss; //initalize istringstream object
    int c1,c2,c3; //initalize comparison integer variables
    
    if (argc != 7) { //check for correct number of arguments
        cerr << "Usage: " << argv[0] << " <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>"
             << endl; //print the corresponding error message
        return 1; //return integer to satasify the definition of the main
    }
    //testing the validities of the capacities 
    //is it an integer? : istringsteam iss(argv[i])
    //if no: print error: invalid cap/invalid goal
    //
    iss.str(argv[1]); // update iss 
    if(!(iss >> c1)){ //make comparisons
         cerr<< "Error: Invalid capacity '"<< argv[1] <<"' for jug A." <<endl; //print appropriate message
         return 1; //return integer
    }
    iss.str(argv[2]); // update iss
    if(atoi(argv[2])<=0||(iss >> c2)){ // make comparison 
         cerr<< "Error: Invalid capacity '"<< argv[2] <<"' for jug B." <<endl; //print appropriate message
         return 1; //return integer
    }
    iss.str(argv[3]); //update iss
    if(atoi(argv[3])<=0||(iss >> c3)){ // make comparisons
         cerr<< "Error: Invalid capacity '"<< argv[3] <<"' for jug C." <<endl; //print appropriate message
         return 1; //return integer
    }
    //testing the validities of the goals
    iss.str(argv[4]); // update iss 
    if(atoi(argv[4])<=0||(iss >> c1)){ //make comparisons
         cerr<< "Error: Invalid Goal '"<< argv[4] <<"' for jug A." <<endl; //print appropriate message
         return 1; //return integer
    }
    if(atoi(argv[5])<=0||(iss >> c1))
    iss.str(argv[5]); // update iss
    if(atoi(argv[5])<=0||(iss >> c2)){ // make comparison 
         cerr<< "Error: Invalid Goal '"<< argv[5] <<"' for jug B." <<endl; //print appropriate message
         return 1; //return integer
    }
    iss.str(argv[6]); //update iss
    if(atoi(argv[6])<=0||(iss >> c3)){ // make comparisons
         cerr<< "Error: Invalid Goal '"<< argv[6] <<"' for jug C." <<endl; //print appropriate message
         return 1; //return integer
    }
    return 0;
}
