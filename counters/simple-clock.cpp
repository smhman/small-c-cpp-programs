#include <iostream>

#ifdef _WIN32
	#include <Windows.h>
	#define sleep(x) Sleep(x / 1000)
#else
	#include <sys/linux.h>
#endif

#define UNIVERSAL 1
#ifdef UNIVERSAL
	#include <thread>
#endif

int main()
{
	size_t secs = 0;
	while (++secs)
	{
		std::cout << "seconds passed: " << secs << std::endl;
#ifdef UNIVERSAL
		std::this_thread::sleep_for(std::chrono::seconds(1));
#else
		sleep(1000);
#endif
	}
}
