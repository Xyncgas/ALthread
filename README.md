# ALthread library
A limited threading space in c++


#what is it?
  A simple to use library which contains a class for bookeeping a multi-threading enviornment - ever wanted to spawn a lot of threads because it's how things are meant to be done but worry about the performance of multi-threading because the functions are taking a lot cpu time to get things done - with just a header file you can create a sort-of-imaginary space where you threads will be running in and anytime the number of running threads exceeds the number specified by the client it will wait untill a thread is available in the thresh hold again.
  
  
#how to implement>
  the header file provides two methods, initiate() and booker(). initiate takes an integer constant and set the thresh hold for the number of threads that is allow to use in the space spawned by booker(), the booker() after being called will set the Index_of_threads variable to a number as long there are free spots in the thresh hold.
  You will need to initiate the class first *do it in global to avoid stack overflow, and then set the threading space by calling initiate(int x) with int x being a constant integer that you want the limit to be (like initiate(42)), you should also initiate a std::thread class with an aray ( such as std::thread abc[1024] ) with the number to be whatever but must equal or larger to the value of the limit of space that you want to implement.
  then in the rest of your codes, whenever you want to spawn a thread, use the thread arays you created in global, with Index_of_threads to be the aray number, like abc[efghijk.Index_of_threads], then you will need to set a class variable in whatever function you want to do multi-threading to 1, like this : efghijk.thread_id[efghijk.Index_of_threads] = 1; //And now you can spawn threads whenever you feel like you want to multithread something knowing that it will always run at a limited number of threads at any given time.
  
  
  
  
  ~Example codes: (a.cpp)
      
    #include "ALthread.h"
    using namespace std;
   
    std:thread abc[8192];
    
    
    
    
     ALthread start_abc;
 
    
    void hello_world ()
    {
    //do soemthing
    start_abc.thread_id [start_abc.Index_of_threads] = 1;
    }
    
    int main()
    {
    
    
    start_abc.initiate(100)
    
    
    while (true)//normally without the libary it will spawn infinite threads to take a lots resources on the machine
    {
    
    efghijk.booker();
    
    abc[start_abc.Index_of_threads]=std::thread(hello_world);
    }
    

    }
