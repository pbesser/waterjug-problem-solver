/*******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Author      : Patrick Besser, Matthew Jacobsen
 * Date        : October 11, 2019 
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

void waterjug(int c1, int c2, int c3,int g1,int g2,int g3){


    
}



int main(int argc, char* const argv[]) { //MAIN METHOD

    // //testing the validities of the capacities 
    // //are there 7 arguments?: if No:error
    // //is each argument an integer?: if no: print error: invalid cap/invalid goal 
    // //istringsteam iss(argv[i])
    // //is cap of C 0?: if yes: error
    // //if no: is |goal a,b,c| > |cap a,b,c| ?: if yes: error
    // //If no: is goal a + goal b + goal c + 

    istringstream iss; 
    int compare1, compare2, compare3, compare4, compare5, compare6;

    if (argc != 7) { //check for correct number of arguments
         cerr << "Usage: " << argv[0] << " <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>"
              << endl; //print the corresponding error message
         return 1; //return integer to satasify the definition of the main
    }
    //Is each argument an int?
    // for(int i=1; i <= 5;i++){
    //     iss.str(argv[i]);
    //     if(!(iss >> compare1)){
    //       cerr<< "Error: Invalid capacity '"<< argv[i] <<"' for jug A." <<endl; //print appropriate message
    //       return 1; //return integer
    //     }
    // }
    iss.str(argv[1]);
     if(!(iss >> compare1)){ //compares if the input is an integer 
           cerr<< "Error: Invalid capacity '"<< argv[1] <<"' for jug A." <<endl; //print appropriate message
      return 1; //return integer
    }
    iss.str(argv[2]);
     if(!(iss >> compare2)){ //compares if the input is an integer 
           cerr<< "Error: Invalid capacity '"<< argv[2] <<"' for jug B." <<endl; //print appropriate message
      return 1; //return integer
    }
    iss.str(argv[3]);
     if(!(iss >> compare3)){ //compares if the input is an integer 
           cerr<< "Error: Invalid capacity '"<< argv[3] <<"' for jug C." <<endl; //print appropriate message
      return 1; //return integer
    }
    iss.str(argv[4]);
     if(!(iss >> compare4)){ //compares if the input is an integer 
           cerr<< "Error: Invalid goal '"<< argv[4] <<"' for jug A." <<endl; //print appropriate message
      return 1; //return integer
    }
    iss.str(argv[5]);
     if(!(iss >> compare5)){ //compares if the input is an integer 
           cerr<< "Error: Invalid goal '"<< argv[5] <<"' for jug B." <<endl; //print appropriate message
      return 1; //return integer
    }
    iss.str(argv[6]);
     if(!(iss >> compare6)){ //compares if the input is an integer 
           cerr<< "Error: Invalid goal '"<< argv[6] <<"' for jug C." <<endl; //print appropriate message
      return 1; //return integer
    }

    //Is Cap of c = 0?
    if(argv[3] >= 0){
        cerr<< "Error: Invalid capacity '"<< argv[3] <<"' for jug C."<<endl;
        return 1; 
    }
    // is goal A/B/C > cap A/B/C
    if(argv[4] > argv[1]){
        cerr<< "Error: Error: Goal cannot exceed capacity of jug A." << endl;
        return 1;
    }
    if(argv[5] > argv[2]){
        cerr<< "Error: Error: Goal cannot exceed capacity of jug B." << endl;
        return 1;
    }
    if(argv[6] > argv[3]){
        cerr<< "Error: Error: Goal cannot exceed capacity of jug C." << endl;
        return 1;
    }
    
    

    // is goal A + goal B + goal C = Cap C 
    if((arv[4]+argv[5]+argv[6])==argv[3]){
        //call waterjug
        //waterjug(argv[1],argv[2],argv[3],argv[4],argv[5],argv[6])
        return 0;
    } else
    {
        cerr<<"Error: Total gallons in the goal state must be equal to the capacity of jug C."<<endl; 
        return 1;
    }
    


    




    // istringstream iss; //initalize istringstream object
    // int c1,c2,c3; //initalize comparison integer variables
    
    // if (argc != 7) { //check for correct number of arguments
    //     cerr << "Usage: " << argv[0] << " <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>"
    //          << endl; //print the corresponding error message
    //     return 1; //return integer to satasify the definition of the main
    // }
    // //testing the validities of the capacities 
    // //are there 7 arguments?: if No:error
    // //is each argument an integer?: if no: print error: invalid cap/invalid goal 
    // //istringsteam iss(argv[i])
    // //is cap of C 0?: if yes: error
    // //if no: is |goal a,b,c| > |cap a,b,c| ?: if yes: error
    // //If no: is goal a + goal b + goal c + = cap c

    
    // iss.str(argv[1]); // update iss 
    // if(!(iss >> c1)){ //make comparisons
    //      cerr<< "Error: Invalid capacity '"<< argv[1] <<"' for jug A." <<endl; //print appropriate message
    //      return 1; //return integer
    // }
    // iss.str(argv[2]); // update iss
    // if(atoi(argv[2])<=0||(iss >> c2)){ // make comparison 
    //      cerr<< "Error: Invalid capacity '"<< argv[2] <<"' for jug B." <<endl; //print appropriate message
    //      return 1; //return integer
    // }
    // iss.str(argv[3]); //update iss
    // if(atoi(argv[3])<=0||(iss >> c3)){ // make comparisons
    //      cerr<< "Error: Invalid capacity '"<< argv[3] <<"' for jug C." <<endl; //print appropriate message
    //      return 1; //return integer
    // }
    // //testing the validities of the goals
    // iss.str(argv[4]); // update iss 
    // if(atoi(argv[4])<=0||(iss >> c1)){ //make comparisons
    //      cerr<< "Error: Invalid Goal '"<< argv[4] <<"' for jug A." <<endl; //print appropriate message
    //      return 1; //return integer
    // }
    // if(atoi(argv[5])<=0||(iss >> c1))
    // iss.str(argv[5]); // update iss
    // if(atoi(argv[5])<=0||(iss >> c2)){ // make comparison 
    //      cerr<< "Error: Invalid Goal '"<< argv[5] <<"' for jug B." <<endl; //print appropriate message
    //      return 1; //return integer
    // }
    // iss.str(argv[6]); //update iss
    // if(atoi(argv[6])<=0||(iss >> c3)){ // make comparisons
    //      cerr<< "Error: Invalid Goal '"<< argv[6] <<"' for jug C." <<endl; //print appropriate message
    //      return 1; //return integer
    // }
    // return 0;
}


/*
Formatting for error messages 
run_test_args "" "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>"
run_test_args "1 2 3 4 5 6 7" "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>"
run_test_args "x 2 3 4 5 6" "Error: Invalid capacity 'x' for jug A."
run_test_args "1 -2 3 4 5 6" "Error: Invalid capacity '-2' for jug B."
run_test_args "1 2 0 4 5 6" "Error: Invalid capacity '0' for jug C."
run_test_args "1 2 3 y 5 6" "Error: Invalid goal 'y' for jug A."
run_test_args "1 2 3 4 -5 6" "Error: Invalid goal '-5' for jug B."
run_test_args "1 2 3 4 5 -1" "Error: Invalid goal '-1' for jug C."
run_test_args "3 5 8 4 0 4" "Error: Goal cannot exceed capacity of jug A."
run_test_args "3 5 8 0 6 2" "Error: Goal cannot exceed capacity of jug B."
run_test_args "3 5 8 0 0 9" "Error: Goal cannot exceed capacity of jug C."
run_test_args "3 5 8 2 1 4" "Error: Total gallons in goal state must be equal to the capacity of jug C."
run_test_args "6 7 10 5 5 0" "No solution."
run_test_args "30 45 50 25 25 0" "No solution."
run_test_args "3 5 8 2 1 5" "No solution."
run_test_args "5 7 10 3 3 4" "No solution."
run_test_args "6 7 10 0 0 10" "Initial state. (0, 0, 10)"
run_test_args "3 5 8 0 5 3" "Initial state. (0, 0, 8)"$'\n'"Pour 5 gallons from C to B. (0, 5, 3)"
run_test_args "3 5 8 0 3 5" "Initial state. (0, 0, 8)"$'\n'"Pour 3 gallons from C to A. (3, 0, 5)"$'\n'"Pour 3 gallons from A to B. (0, 3, 5)"
run_test_args "1 3 4 0 2 2" "Initial state. (0, 0, 4)"$'\n'"Pour 3 gallons from C to B. (0, 3, 1)"$'\n'"Pour 1 gallon from B to A. (1, 2, 1)"$'\n'"Pour 1 gallon from A to C. (0, 2, 2)"
run_test_args "3 5 8 0 2 6" "Initial state. (0, 0, 8)"$'\n'"Pour 5 gallons from C to B. (0, 5, 3)"$'\n'"Pour 3 gallons from B to A. (3, 2, 3)"$'\n'"Pour 3 gallons from A to C. (0, 2, 6)"
run_test_args "3 5 8 0 4 4" "Initial state. (0, 0, 8)"$'\n'"Pour 5 gallons from C to B. (0, 5, 3)"$'\n'"Pour 3 gallons from B to A. (3, 2, 3)"$'\n'"Pour 3 gallons from A to C. (0, 2, 6)"$'\n'"Pour 2 gallons from B to A. (2, 0, 6)"$'\n'"Pour 5 gallons from C to B. (2, 5, 1)"$'\n'"Pour 1 gallon from B to A. (3, 4, 1)"$'\n'"Pour 3 gallons from A to C. (0, 4, 4)"
run_test_args "4 7 10 0 5 5" "Initial state. (0, 0, 10)"$'\n'"Pour 4 gallons from C to A. (4, 0, 6)"$'\n'"Pour 4 gallons from A to B. (0, 4, 6)"$'\n'"Pour 4 gallons from C to A. (4, 4, 2)"$'\n'"Pour 3 gallons from A to B. (1, 7, 2)"$'\n'"Pour 7 gallons from B to C. (1, 0, 9)"$'\n'"Pour 1 gallon from A to B. (0, 1, 9)"$'\n'"Pour 4 gallons from C to A. (4, 1, 5)"$'\n'"Pour 4 gallons from A to B. (0, 5, 5)"
run_test_args "8 17 20 0 10 10" "Initial state. (0, 0, 20)"$'\n'"Pour 17 gallons from C to B. (0, 17, 3)"$'\n'"Pour 8 gallons from B to A. (8, 9, 3)"$'\n'"Pour 8 gallons from A to C. (0, 9, 11)"$'\n'"Pour 8 gallons from B to A. (8, 1, 11)"$'\n'"Pour 8 gallons from A to C. (0, 1, 19)"$'\n'"Pour 1 gallon from B to A. (1, 0, 19)"$'\n'"Pour 17 gallons from C to B. (1, 17, 2)"$'\n'"Pour 7 gallons from B to A. (8, 10, 2)"$'\n'"Pour 8 gallons from A to C. (0, 10, 10)"
run_test_args "4 17 22 2 5 15" "No solution."

*/
