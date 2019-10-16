//header
/*******************************************************************************
 * Name        : waterjugpuzzle.cpp
 * Author      : Patrick Besser, Matthew Jacobsen
 * Date        : October 11, 2019 
 * Description : Solves the famous water jug puzzle using breadth-first search 
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
// importss
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>

using namespace std;
using namespace std;

// state
struct State
{
    int a, b, c; // default 
    vector<string> direction; // added direction to store our instructions to get to the final answer 

    State(int _a, int _b, int _c, vector<string> _direction) : a(_a), b(_b), c(_c), direction(_direction) {}

    // String representation of state in tuple form.
    string to_string()
    {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";  
        return oss.str();
    }
    // to compare different states to one another which will eventually be used to check if we have reached an asnwer
      int compareTo(State &currentMove){
          if(a == currentMove.getA() &&  b == currentMove.getB() && c == currentMove.getC()){
                return 0; // if equal 
      }
          else{
                return 1; // if not 
          }
      }
      // made getters for A/B/C because there was difficulty with scope and accessing the variables when we used pointers 
      int getA(){
            return a;
      }
      int getB(){
          return b; 
      }
      int getC(){
          return c; 
      }
      
      void out(){ // output method to read our vector of directions giving us proper output and printing statements pringing one by one wont work also need unsigned int to itera
        for(unsigned int x = 0; x < direction.size();x++){
            cout << direction[x] << endl; 
        }
      }

};
// create paths 
State paths(State top, State currentCap, State finish, bool ** visit){
    queue<State> directions; // this will be the queue of instructions on how to get to our answer
    
    top.direction.push_back("Initial state. " + top.to_string()); // we start wth our inital state (begin )
    visit[top.a][top.b] = true; // set the Inital state to visted, in our visited variable in the appropriate location
    directions.push(top); // then we push it to the directions 
    
    while (!directions.empty()){ // while our directions is not empty  
        top = directions.front();
        directions.pop();
        
        if (top.a == finish.a && top.b == finish.b && top.c == finish.c){
            return top;
        }//checks if C can pour into A
        //1) Pour from C to A
        if(top.c > 0 && (currentCap.a - top.a) > 0){ // makes sure we can make the move 
            State currentMove = top; //temp array to store instructions 
            int drain = currentCap.a - currentMove.a; // the mov ewe will be making 
            if (drain >= currentMove.c){ // make the move 
                currentMove.a = (currentMove.a + top.c);
                currentMove.c = 0; // prevent negative numbers 
            }
            else {
                currentMove.c = (currentMove.c - drain); // make move 
                currentMove.a = currentCap.a;
            }
            // check if we have been here before 
            if (visit[currentMove.a][currentMove.b] == false){ // test for visited 
                
                visit[currentMove.a][currentMove.b] = true; // if not now set that we have arrived at this location  
                if (drain == 1 || top.c == 1){ // test for 1 galloon pour 
                    
                    currentMove.direction.push_back("Pour 1 gallon from C to A. " + currentMove.to_string()); // push the instruction
                    
                    directions.push(currentMove); // push the current move 
                }
                else{
                    currentMove.direction.push_back("Pour " + to_string(min(drain, top.c)) + " gallons from C to A. " + currentMove.to_string()); // push instruction
                    directions.push(currentMove); // push current move 
                }
            }
        }
        //2) Pour from B to A
        if ((currentCap.a - top.a) > 0 && top.b > 0){
            State currentMove = top;
            int drain = currentCap.a - currentMove.a;
            if (drain >= currentMove.b){
                currentMove.a = (currentMove.a + top.b);
                currentMove.b = 0;
            }
            else {
                currentMove.b = (currentMove.b - drain);
                currentMove.a = currentCap.a;
            }
            if (visit[currentMove.a][currentMove.b] == false){
                visit[currentMove.a][currentMove.b] = true;
                if (drain == 1 || top.b == 1){
                    currentMove.direction.push_back("Pour 1 gallon from B to A. " + currentMove.to_string());
                    directions.push(currentMove);
                }
                else{
                    currentMove.direction.push_back("Pour " + to_string(min(drain, top.b)) + " gallons from B to A. " + currentMove.to_string());
                    directions.push(currentMove);
                }
            }
        }
//a=b
//keep c
//3) Pour from C to B
        if ((currentCap.b - top.b) > 0 && top.c > 0){
            State currentMove = top;
            int drain = currentCap.b - currentMove.b;
            if (drain >= currentMove.c){
                currentMove.b = (currentMove.b + top.c);
                currentMove.c = 0;
            }
            else {
                currentMove.c = (currentMove.c - drain);
                currentMove.b = currentCap.b;
            }
            if (visit[currentMove.a][currentMove.b] == false){
                visit[currentMove.a][currentMove.b] = true;
                if (drain == 1 || top.c == 1){
                    // add direction to our queue Condition: 1 gallon moving 
                    currentMove.direction.push_back("Pour 1 gallon from C to B. " + currentMove.to_string());
                    directions.push(currentMove);
                }
                // add direction to our queue, Condition : more than one gallon
                else{
                    currentMove.direction.push_back("Pour " + to_string(min(drain, top.c)) + " gallons from C to B. " + currentMove.to_string());
                    directions.push(currentMove);
                }
            }
        }
//C.A    :   A.B
//c=a
//a=b
//4) Pour from A to B
        if ((currentCap.b - top.b) > 0 && top.a > 0){
            State currentMove = top;
            int drain = currentCap.b - currentMove.b;
            if (drain >= currentMove.a){
                 currentMove.b = (currentMove.b + top.a);
                currentMove.a = 0;
            }
            else {
                currentMove.a = (currentMove.a - drain);
                currentMove.b = currentCap.b;
            }
            if (visit[currentMove.a][currentMove.b] == false){
                visit[currentMove.a][currentMove.b] = true;
                if (drain == 1 || top.a == 1){
                    currentMove.direction.push_back("Pour 1 gallon from A to B. " + currentMove.to_string());
                    directions.push(currentMove);
                }
                else{
                    currentMove.direction.push_back("Pour " + to_string(min(drain, top.a)) + " gallons from A to B. " + currentMove.to_string());
                    directions.push(currentMove);
                }
            }
        }
//C.A    :   B.C
//c=b
//a=c
//5) Pour from B to C
        if ((currentCap.c - top.c) > 0 && top.b > 0){
            State currentMove = top;
            int drain = currentCap.c - currentMove.c;
            if (drain >= currentMove.b){
                currentMove.c = (currentMove.c + top.b); 
                currentMove.b = 0;
            }
            else {
                currentMove.b = (currentMove.b - drain); 
                currentMove.c = currentCap.c;
            }
            if (visit[currentMove.a][currentMove.b] == false){
                visit[currentMove.a][currentMove.b] = true;
                if (drain == 1 || top.b == 1){
                    currentMove.direction.push_back("Pour 1 gallon from B to C. " + currentMove.to_string());
                    directions.push(currentMove);
                }
                else{
                    currentMove.direction.push_back("Pour " + to_string(min(drain, top.b)) + " gallons from B to C. " + currentMove.to_string());
                    directions.push(currentMove);
                }
            }
        }
//B.C    :   A.C
//b=a
//c=c
//6) Pour from A to C
        if ((currentCap.c - top.c) > 0 && top.a > 0){
            State currentMove = top;
            int drain = currentCap.c - currentMove.c;
            if (drain >= currentMove.a){
                currentMove.c = (currentMove.c + top.a);
                currentMove.a = 0;
            }
            else {
                currentMove.a = (currentMove.a - drain);
                currentMove.c = currentCap.c;
            }
            if (visit[currentMove.a][currentMove.b] == false){
                visit[currentMove.a][currentMove.b] = true;
                if (drain == 1 || top.a == 1){
                    currentMove.direction.push_back("Pour 1 gallon from A to C. " + currentMove.to_string());
                    directions.push(currentMove);
                }
                else{
                    currentMove.direction.push_back("Pour " + to_string(min(drain, top.a)) + " gallons from A to C. " + currentMove.to_string());
                    directions.push(currentMove);
                }
            }
        }
    }
    
    top.direction.clear(); // clears the stack
    top.direction.push_back("No solution."); // then print no solution 
    return top; // return the state with our final answer of directions to be read by our print statement
}

//makes visited array
bool** generateVisit(int a, int b) { // makes the array of booleans to test for ' visited ' so we dont repeat 
    bool ** visit = new bool*[a]; // initalize a new boolean lists 
    for (int i = 0; i < a; i++){ // iter through each 
        visit[i] = new bool[b];
        fill(visit[i], visit[i] + b,false); // fill with the value false
    }
    return visit; // return the values 
}


//solves the problem
void solve(vector<int> input){ // tak in int arguments cant
//void solve(struct State begin,struct State* goal){}
    //temp vector to initalize each state 
    vector<string> directions;    
    // 3 Goal A
    // 4 Goal B 
    // 5 Goal C
    // end result
    State finish(input[3], input[4], input[5], directions);
    //starting
    State begin(0, 0, input[2], directions);
    //0 Cap A
    //1 Cap B
    //2 Cap C
    //cap for each jug 
    State currentCap(input[0], input[1], input[2], directions);
    // this will make the space that we will eventually check for 'visited or not'
    bool ** visit = generateVisit(input[0] + 1, input[1] + 1);
    //call BFS for all the given peramaters
    //then print the output;
    //error: could not convert ‘visit’ from ‘bool**’ to ‘std::vector<std::__cxx11::basic_string<char> >’  
    finish = paths(begin,currentCap,finish,visit); // call our pouring method to find paths with all of our proper iputs 
    finish.out(); // prints out answer 
    //deletes the visted array
    for(int i=0; i<currentCap.getB();i++){
        delete[] visit[i];
    }
    delete[] visit; 
}

//main method that does input validation, throws errors for invalid arguments or cases, and calls solution function
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
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3)) // make comparisons and test for int 
                {
                    cerr << "Error: Invalid capacity '" << argv[i] << "' for jug A." << endl; // print corresponding message 
                    return 1;
                }
            }
            if (i == 2)
            { //Jug B
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))// make comparisons and test for int 
                {
                    cerr << "Error: Invalid capacity '" << argv[i] << "' for jug B." << endl;// print corresponding message
                    return 1;
                }
            }
            if (i == 3)
            { //Jug C
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))// make comparisons and test for int 
                {
                    cerr << "Error: Invalid capacity '" << argv[i] << "' for jug C." << endl;// print corresponding message
                    return 1;
                }
            }
            iss.clear();
        }
        if (i > 3)
        { //goal cases
            if (i == 4)
            { //jug A
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))// make comparisons and test for int 
                {
                    cerr << "Error: Invalid goal '" << argv[i] << "' for jug A." << endl;// print corresponding message
                    return 1;
                }
            }
            if (i == 5)
            { //Jug B
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))// make comparisons and test for int 
                {
                    cerr << "Error: Invalid goal '" << argv[i] << "' for jug B." << endl;// print corresponding message
                    return 1;
                }
            }
            if (i == 6)
            { //Jug C
                if (!(iss >> compare) || (compare < 0) || (compare == 0 && i == 3))// make comparisons and test for int 
                {
                    cerr << "Error: Invalid goal '" << argv[i] << "' for jug C." << endl;// print corresponding message
                    return 1;
                }
            }
            iss.clear();
        }
    }

    //convert inputs to ints bc we already know that they are valid, non-negative integers
    //to fix error with passing in values into our function that calls our solving 
    int cA = atoi(argv[1]);
    int cB = atoi(argv[2]);
    int cC = atoi(argv[3]);
    int gA = atoi(argv[4]);
    int gB = atoi(argv[5]);
    int gC = atoi(argv[6]);

    // compare 1 to 4 aka A to A
    if (cA < gA)
    {
        cerr << "Error: Goal cannot exceed capacity of jug A." << endl; // print message 
        return 1;
    }
    //compare 2 to 5 aka B to B
    if (cB < gB)
    {
        cerr << "Error: Goal cannot exceed capacity of jug B." << endl;// print message
        return 1;
    }
    //compare 3 to 6 aka C to C
    if (cC < gC)
    {
        cerr << "Error: Goal cannot exceed capacity of jug C." << endl;// print message
        return 1;
    }

    // is goal A + goal B + goal C = Cap C
    if ((gA + gB + gC) == cC)
    {
        // vector<string> directs;
        //call waterjug
        //top by initalizing our 3 states. Where we start. What our capacities are and our final goal to fulfill
        // State *top = new State(0, 0, stoi(argv[3]));                              // top
        //  State currentCap = new  State(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]),directs); //cap of jugs
        //  State finish = new  State(stoi(argv[4]), stoi(argv[5]), stoi(argv[6]),directs);     // goals to find
        //call methods
        //as said in class we need to find all possible paths to find the answer and then BFS to get the solution
        vector<int> input = {cA,cB,cC,gA,gB,gC}; // inputs for answers 
        solve(input); // call method
        return 0;//end return 
    }
    else
    { // if not then the gal in state isnt equal to the capacity of jug C so throw error and return
        cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
        return 1; // return int to end
    } 
}





//  ********Old work********  
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

/*
Test cases and Formatting for error messages 
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