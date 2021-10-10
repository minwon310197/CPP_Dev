//finished - improved
 
#include <iostream>
#include "src/linked_list.h" 
#include "src/function.h"

int main()
{
    std::cout <<"data: " << std::endl;
 
    for(int i = 0 ; i < 5 ; i++)
    {
        int data;
        std::cin >> data;
        addNode(data);
    }
 
    display();
    int nodedeleted;
    std::cout << "choose value to delete: "; std::cin >> nodedeleted;
    //deleteNode(nodedeleted);
    deleteValue(nodedeleted);
    display();
    std::cout<< "start: " << start->data << std::endl;
    std::cout<< "enD: " << enD->data ;
    std::cout<< std::endl;
//    std::cout<< " \n delete all nodes processing \n" ;
//    deleteAllNodes();
//    std::cout<< "delete all nodes done : display() called :  \n" ;
//    display();
    return 0;
}
 

