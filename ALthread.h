#include <chrono>
#include <ctime>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;



struct ALthread
{

	
	
	
	
	
	private:
	int abc;
	int Distributed_write_threshhold;
	int thresh_lable_shadow;
	int thresh_lable_shadowT;
	int thread_checker = 0;
	public:
	int Index_of_threads = 0;
	int thread_id[8192];
	
	

	void initiate(int x)
	{
		Distributed_write_threshhold = x;
		thresh_lable_shadow = Distributed_write_threshhold;
		thresh_lable_shadowT = thresh_lable_shadow;
	}



	void booker()
	{

		if (Distributed_write_threshhold > 0)
		{
			if (thresh_lable_shadowT > 0)
			{
				Distributed_write_threshhold = Distributed_write_threshhold - 1;
				Index_of_threads = thresh_lable_shadow - thresh_lable_shadowT;//is example:50 if thresh_lable_shadowT is 0
				thread_id[Index_of_threads] = 0;
				//and the fact that thread available status is not reset to zero after a thread is done and set it to one just lets the program to spawn infinite threads after checking it is set to one, and therefore even without getting to the bug above where threads are unavailable and then you check and see if they are available but regarless of the checking results it just thinks it's available, in the first place spawning infinite threads to flood memory

				thresh_lable_shadowT = thresh_lable_shadowT - 1;
			}
		}
		else
		{
		check_againD:for (abc = thresh_lable_shadow - 1; abc >= 0; abc--)//check if a thread is ready to be reuse
		{
			if (thread_id[abc] == 1)
			{
				Index_of_threads = abc;
				thread_id[Index_of_threads] = 0;
				//and the fact that thread available status is not reset to zero after a thread is done and set it to one just lets the program to spawn infinite threads after checking it is set to one, and therefore even without getting to the bug above where threads are unavailable and then you check and see if they are available but regarless of the checking results it just thinks it's available, in the first place spawning infinite threads to flood memory
				thread_checker = 1;
				break;
			}

		}
					 if (thread_checker != 1)
					 {
						 sleep_for(10ns);
						 sleep_until(system_clock::now() + 1s);
						 goto check_againD;
					 }
					 thread_checker = 0;//reset thread_checker, if you dont do this you start making infinite threads like cancer codes that use up a lot and scales up to infinite memories
		}
	}
};
