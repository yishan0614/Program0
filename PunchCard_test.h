#include <iostream> 
#include <string> 
#include <vector>
#include <stdbool.h>

using namespace std; 

// Find all occurence of designated string
void findAllOccurances(std::vector<size_t> & vec, std::string data, std::string toSearch)
{
    // Get the first occurrence
    size_t pos = data.find(toSearch);
    // Repeat till end is reached
    while(pos != std::string::npos)
    {
        // Add position to the vector
        vec.push_back(pos);
        // Get the next occurrence from the current position
        pos =data.find(toSearch, pos + toSearch.size());
    }
}
 
// Check if current card is last card 
bool islastCard(string myCard)
{
    string detect_lastCard = "XXXXXXXXXXXX\n";
    size_t found = myCard.find(detect_lastCard);
    
    if (found != string::npos)
    {
       return true;
    }
    else
    {
        return false;
    }
}

// Convert punch readings to string
 /*
string toString(int position)
{
    
}
*/

int main(int argc, char * const argv[]) 
{ 
    // Sample input, scan by column
    string firstCard =  "            \n  X         \n   X        \n    X       \n     X      \n      X     \n       X    \n        X   \n         X  \n          X \n           X\n";  // 12 blanks as begining of new card "            "
    string secondCard = "            \nX  X        \nX   X       \nX    X      \nX     X     \nX      X    \nX       X   \nX        X  \nX         X \nX          X\n";  // ABCDEFGHI         "
    string lastCard =   "XXXXXXXXXXXX\nX  X        \nX   X       \nX    X      \nX     X     \nX      X    \nX       X   \nX        X  \nX         X \nX          X\n";  // ABCDEFGHI         "

    string threeCards = firstCard + secondCard + lastCard;
    cout << threeCards << endl;
    
    // Conditions to check
    string detect_newCard = "            \n";
    string detect_lastCard = "XXXXXXXXXXXX\n";
    string detect_Punch = "X"; 
    string nextColumn = "\n";
    
    
    // Detect islastCard
    bool test = islastCard(lastCard);
    if (test) 
    {
        printf("Last Card \n");
    }
    else
    {
        printf("Not Last Card \n");
    }


    // Get All occurrences of punch in the threeCards and put position into vec
    std::vector<size_t> vec;
    findAllOccurances(vec, threeCards , detect_Punch);
    std::cout<<"All Index Position of punches in given string are,"<<std::endl;
    for(size_t pos : vec)
        std::cout<<pos<<std::endl;
    return 0; 
} 