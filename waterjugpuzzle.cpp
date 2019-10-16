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
#include <stdlib.h>

using namespace std;

// Struct to represent state of water in the jugs.
struct State
{
    int a, b, c;
    vector<string> directions;

    State(int _a, int _b, int _c, vector<string> _directions) : a(_a), b(_b), c(_c), directions(_directions) {}

    // String representation of state in tuple form.
    string to_string()
    {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }
    // to compare different states to one another which will eventually be used to check if we have reached an asnwer
      int compareTo(State &temp){
          if(a == temp.a and  b == temp.b and c == temp.c){
                return 0;
      }
          else{
                return 1;
          }
      }
      int getA(){
            return a;
      }
      int getB(){
          return b; 
      }
      int getC(){
          return c; 
      }
};




bool** createGrid(int x, int y) {
    bool**visit = new bool*[a];

    for (int i = 0; i < x; i++){
        grid[i] = new bool[b];
        fill(grid[i], grid[i] + y,false);
    }
    return grid;
}

struct State paths(struct State* begin, struct State* currentCap, struct State* finish, vector<string> directions, bool ** visited){
// BFS for our 
queue<State> instructions; // initalize temp array(queue) to store instructions
begin.directions.push_back("Inital state. "+begin.to_string()); //put inital instruction in the directions vector
instructions.push(begin); // push initial state to the queue 
while(!(instructions.empty)){
    top = instructions.front();
    top.pop();

    if(top.compareTo(finish)==0){
        return top; // end condition 
    }
    //1) Pour from C to A
    if(top.c > 0 && (currentcap.a - top.a) > 0){
        state currentMove = top; //variable used to hold the current move, while we decide to push it, or get rid of it
        int drain = currentcap.a - currentMove.a; //drain is the difference between the current capacity of jug A - the state of jug A
        if(drain > currentMove.c){
            currentMove.a = (currentMove.a + top.c); // if the difference between the two jugs 
            currentMove.c = 0;
        }
    else{
        currentMove.c = (currentMove.c - drain); // actually make the move 
        currentMove.a = currentCap.a; 
    }
    // check if we have been here before 
    if(map[currentMove.a][currentMove.b] == false){
        map[currentMove.a][currentMove.b] == true;
        if(drain == 1 || top.c == 1){ // check if the move has one gallon 
            // add direction to our queue Condition: 1 gallon moving 
            currentMove.directions.push_back("Pour 1 gallon from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
        }
        else{
            // add direction to our queue, Condition : more than one gallon
            currentMove.directions.push_back("Pour " + to_string(min(drain, top.c)) + " gallons from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
    }
    }
} 


//2) Pour from B to A
    if(top.b > 0 && (currentcap.a - top.a) > 0){
        state currentMove = top; //variable used to hold the current move, while we decide to push it, or get rid of it
        int drain = currentcap.a - currentMove.a; //drain is the difference between the current capacity of jug A - the state of jug A
        if(drain > currentMove.b){
            currentMove.a = (currentMove.a + top.b); // if the difference between the two jugs
            currentMove.b = 0;
        }
    else{
        currentMove.b = (currentMove.b - drain); // actually make the move 
        currentMove.a = currentCap.a; 
    }
    // check if we have been here before 
    if(map[currentMove.a][currentMove.b] == false){
        map[currentMove.a][currentMove.b] == true;
        if(drain == 1 || top.b == 1){ // check if the move has one gallon 
            // add direction to our queue Condition: 1 gallon moving 
            currentMove.directions.push_back("Pour 1 gallon from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
        }
        else{
            // add direction to our queue, Condition : more than one gallon
            currentMove.directions.push_back("Pour " + to_string(min(drain, top.b)) + " gallons from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
    }
    }
}


//a=b
//keep c
//3) Pour from C to B
    if(top.c > 0 && (currentcap.b - top.b) > 0){
        state currentMove = top; //variable used to hold the current move, while we decide to push it, or get rid of it
        int drain = currentcap.b - currentMove.b; //drain is the difference between the current capacity of jug A - the state of jug A
        if(drain > currentMove.c){
            currentMove.b = (currentMove.b + top.c); // if the difference between the two jugs
            currentMove.c = 0;
        }
    else{
        currentMove.c = (currentMove.c - drain); // actually make the move 
        currentMove.b = currentCap.b; 
    }
    // check if we have been here before 
    if(map[currentMove.a][currentMove.b] == false){
        map[currentMove.a][currentMove.b] == true;
        if(drain == 1 || top.c == 1){ // check if the move has one gallon 
            // add direction to our queue Condition: 1 gallon moving 
            currentMove.directions.push_back("Pour 1 gallon from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
        }
        else{
            // add direction to our queue, Condition : more than one gallon
            currentMove.directions.push_back("Pour " + to_string(min(drain, top.c)) + " gallons from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
    }
    }

//C -> A    :   A -> B
//c=a
//a=b
//4) Pour from A to B
    if(top.c > 0 && (currentcap.b - top.b) > 0){
        state currentMove = top; //variable used to hold the current move, while we decide to push it, or get rid of it
        int drain = currentcap.b - currentMove.b; //drain is the difference between the current capacity of jug A - the state of jug A
        if(drain > currentMove.a){
            currentMove.b = (currentMove.b + top.a); // if the difference between the two jugs
            currentMove.a = 0;
        }
    else{
        currentMove.a = (currentMove.a - drain); // actually make the move 
        currentMove.b = currentCap.b; 
    }
    // check if we have been here before 
    if(map[currentMove.a][currentMove.b] == false){
        map[currentMove.a][currentMove.b] == true;
        if(drain == 1 || top.a == 1){ // check if the move has one gallon 
            // add direction to our queue Condition: 1 gallon moving 
            currentMove.directions.push_back("Pour 1 gallon from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
        }
        else{
            // add direction to our queue, Condition : more than one gallon
            currentMove.directions.push_back("Pour " + to_string(min(drain, top.a)) + " gallons from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
    }
    }
}
//C -> A    :   B -> C
//c=b
//a=c
//5) Pour from B to C
    if(top.b > 0 && (currentcap.c - top.c) > 0){
        state currentMove = top; //variable used to hold the current move, while we decide to push it, or get rid of it
        int drain = currentcap.c - currentMove.c; //drain is the difference between the current capacity of jug A - the state of jug A
        if(drain > currentMove.b){
            currentMove.c = (currentMove.c + top.b); // if the difference between the two jugs
            currentMove.b = 0;
        }
    else{
        currentMove.b = (currentMove.b - drain); // actually make the move 
        currentMove.a = currentCap.c; 
    }
    // check if we have been here before 
    if(map[currentMove.a][currentMove.b] == false){
        map[currentMove.a][currentMove.b] == true;
        if(drain == 1 || top.b == 1){ // check if the move has one gallon 
            // add direction to our queue Condition: 1 gallon moving 
            currentMove.directions.push_back("Pour 1 gallon from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
        }
        else{
            // add direction to our queue, Condition : more than one gallon
            currentMove.directions.push_back("Pour " + to_string(min(drain, top.b)) + " gallons from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
    }
    }
}
//B -> C    :   A -> C
//b=a
//c=c
//6) Pour from A to C
    if(top.a > 0 && (currentcap.c - top.c) > 0){
        state currentMove = top; //variable used to hold the current move, while we decide to push it, or get rid of it
        int drain = currentcap.c - currentMove.c; //drain is the difference between the current capacity of jug A - the state of jug A
        if(drain > currentMove.a){
            currentMove.c = (currentMove.c + top.a); // if the difference between the two jugs
            currentMove.a = 0;
        }
    else{
        currentMove.a = (currentMove.a - drain); // actually make the move 
        currentMove.a = currentCap.c; 
    }
    // check if we have been here before 
    if(map[currentMove.a][currentMove.b] == false){
        map[currentMove.a][currentMove.b] == true;
        if(drain == 1 || top.a == 1){ // check if the move has one gallon 
            // add direction to our queue Condition: 1 gallon moving 
            currentMove.directions.push_back("Pour 1 gallon from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
        }
        else{
            // add direction to our queue, Condition : more than one gallon
            currentMove.directions.push_back("Pour " + to_string(min(drain, top.a)) + " gallons from C to A. " + currentMove.to_string());
            instructions.push(currentMove);
    }
    }
}

}
else{cout << "No solution." << endl;} // final condition that returns no solution

}

void solve(struct State* currentCap, struct State* finish){
    vector<string> directions; // initalize directions
    State* start = new State(0,0, currentCap.getC()); // initalize instructions
    new bool** visited = createGrid(currentCap.getA()+1,currentCap.getB()+1);
    finish = paths(start,currentCap,finish,directions,visited);
    finish.print();
     for (int i = 0; i < capB; i++){ // when done delete the array to prevent memory leaks
        delete [] checked[i];
    }
    delete [] checked; // delete arrays
    // done   
}

int main(int argc, char *const argv[])
{ //MAIN METHOD

    int compare;

    if (argc != 7)
    { //check for correct number of arguments
        cerr << "Usage: " << argv[0] << " <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>"
             << endl; //print the corresponding error message
        return 1;     //return integer to satasify the definition of the main
    }

    istringstream iss; //define i string stream
    for (int i = 1; i < 7; i++)
    {
        iss.str(argv[i]); //update istringstream
        if (i >= 1 && i <= 3)
        { // capacity cases
            if (i == 1)
            { //jug A
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))
                {
                    cerr << "Error: Invalid capacity '" << argv[i] << "' for jug A." << endl;
                    return 1;
                }
            }
            if (i == 2)
            { //Jug B
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))
                {
                    cerr << "Error: Invalid capacity '" << argv[i] << "' for jug B." << endl;
                    return 1;
                }
            }
            if (i == 3)
            { //Jug C
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))
                {
                    cerr << "Error: Invalid capacity '" << argv[i] << "' for jug C." << endl;
                    return 1;
                }
            }
            iss.clear();
        }
        if (i > 3)
        { //goal cases
            if (i == 4)
            { //jug A
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))
                {
                    cerr << "Error: Invalid goal '" << argv[i] << "' for jug A." << endl;
                    return 1;
                }
            }
            if (i == 5)
            { //Jug B
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))
                {
                    cerr << "Error: Invalid goal '" << argv[i] << "' for jug B." << endl;
                    return 1;
                }
            }
            if (i == 6)
            { //Jug C
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))
                {
                    cerr << "Error: Invalid goal '" << argv[i] << "' for jug C." << endl;
                    return 1;
                }
            }
            iss.clear();
        }
    }

    //convert inputs to ints bc we already know that they are valid, non-negative integers
    int cA = atoi(argv[1]);
    int cB = atoi(argv[2]);
    int cC = atoi(argv[3]);
    int gA = atoi(argv[4]);
    int gB = atoi(argv[5]);
    int gC = atoi(argv[6]);

    // compare 1 to 4 aka A to A
    if (cA < gA)
    {
        cerr << "Error: Goal cannot exceed capacity of jug A." << endl;
        return 1;
    }
    //compare 2 to 5 aka B to B
    if (cB < gB)
    {
        cerr << "Error: Goal cannot exceed capacity of jug B." << endl;
        return 1;
    }
    //compare 3 to 6 aka C to C
    if (cC < gC)
    {
        cerr << "Error: Goal cannot exceed capacity of jug C." << endl;
        return 1;
    }

    // is goal A + goal B + goal C = Cap C
    if ((gA + gB + gC) == cC)
    {
        //call waterjug
        //begin by initalizing our 3 states. Where we start. What our capacities are and our final goal to fulfill
        // State *begin = new State(0, 0, stoi(argv[3]));                              // begin
        struct State *currentCap = new struct State(stoi(argv[1]), stoi(argv[2]), stoi(argv[3])); //cap of jugs
        struct State *finish = new struct State(stoi(argv[4]), stoi(argv[5]), stoi(argv[6]));     // goals to find
        //call methods
        //as said in class we need to find all possible paths to find the answer and then BFS to get the solution
        solve(currentCap, finish);
        cout << "works" << endl;
        return 0;
    }
    else
    { // if not then the gal in state isnt equal to the capacity of jug C so throw error and return
        cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
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

// istringstream iss(argv[1]);
//  if(!(iss >> compare1)){ //compares if the input is an integer
//        cerr<< "Error: Invalid capacity '"<< argv[1] <<"' for jug A." <<endl; //print appropriate message
//   return 1; //return integer
// }
// istringstream iss(argv[2]);
//  if(!(iss >> compare2)){ //compares if the input is an integer
//        cerr<< "Error: Invalid capacity '"<< argv[2] <<"' for jug B." <<endl; //print appropriate message
//   return 1; //return integer
// }
// istringstream iss(argv[3]);
//  if(!(iss >> compare3)){ //compares if the input is an integer
//        cerr<< "Error: Invalid capacity '"<< argv[3] <<"' for jug C." <<endl; //print appropriate message
//   return 1; //return integer
// }
// istringstream iss(argv[4]);
//  if(!(iss >> compare4)){ //compares if the input is an integer
//        cerr<< "Error: Invalid goal '"<< argv[4] <<"' for jug A." <<endl; //print appropriate message
//   return 1; //return integer
// }
// istringstream iss(argv[5]);
//  if(!(iss >> compare5)){ //compares if the input is an integer
//        cerr<< "Error: Invalid goal '"<< argv[5] <<"' for jug B." <<endl; //print appropriate message
//   return 1; //return integer
// }
// istringstream iss(argv[6]);
//  if(!(iss >> compare6)){ //compares if the input is an integer
//        cerr<< "Error: Invalid goal '"<< argv[6] <<"' for jug C." <<endl; //print appropriate message
//   return 1; //return integer
// }

//Is each argument an int?
// for(int i=1; i <= 5;i++){
//     iss.str(argv[i]);
//     if(!(iss >> compare1)){
//       cerr<< "Error: Invalid capacity '"<< argv[i] <<"' for jug A." <<endl; //print appropriate message
//       return 1; //return integer
//     }
// }

// int cA = atoi(argv[1]);
// int cB = atoi(argv[2]);
// int cC = atoi(argv[3]);
// int gA = atoi(argv[4]);
// int gB = atoi(argv[5]);
// int gC = atoi(argv[6]);


/*
make queue, each pour is recorded in the queue need to try all 67 pours for each given state in our solution. 


// void bfs(int cA, int cB, int cC, int gA, int gB, int gC, int A, int B, int C)
// {}
*/    
/*
*int cA,cB,cC are the capacities of jugs a,b,c respectively.
*int gA,gB,gC are the goals of jugs a,b,c respectively.
*int A,B,C are the states of jugs a,b,c respectively

    bool solution = false; //Value that determines if there is a solution.
    visited = {};
    path = [];
    if(Ga==a && Gb==b && Gb==c){//if 
        solution = true;
    }
    else{
        //Pour c -> A
        if(A > 0){
            if((A + B) <= cC){
                
            }
        }
        //Pour B -> A

        //Pour C -> B

        //Pour A -> B

        //Pour B -> C

        //Pour A -> C

    }
    
    

*/

// bool**checked[i] = new bool*[cA + 1]; // initalize booleans to test for 'visited' for bfs 
// for(int A, int B, int C){  //fill with default falses
//     checked[i] = new bool*[cB + 1];
//     fill(checked[i], checked[i] + cB + 1, false);
// }


    // //testing the validities of the capacities
    // //are there 7 arguments?: if No:error
    // //is each argument an integer?: if no: print error: invalid cap/invalid goal
    // //istringsteam iss(argv[i])
    // //is cap of C 0?: if yes: error
    // //if no: is |goal a,b,c| > |cap a,b,c| ?: if yes: error
    // //If no: is goal a + goal b + goal c +


