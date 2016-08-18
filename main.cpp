
#include <iostream>

#include <alproxies/almotionproxy.h>
#include <alerror/alerror.h>
#include <alcommon/albroker.h>
#include <alproxies/alvideodeviceproxy.h>
#include <alproxies/almemoryproxy.h>
#include <alvision/alvisiondefinitions.h>
#include <alproxies/almotionproxy.h>
#include<opencv2/opencv.hpp>
#include<windows.h>

using namespace AL;
using namespace cv;
 
using namespace std;   
  
DWORD WINAPI Fun(LPVOID lpParamter)   
{  
	AL::ALMotionProxy motion("127.0.0.1", 9559);
      while(1) { 
	 
	  motion.moveTo(0.2,0,0);
	  }   
}   
  
int main(int argc, char* argv[]) {
	  HANDLE hThread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);   
      CloseHandle(hThread); 
	argc=2;
	argv[1]="127.0.0.1";
  if(argc != 2)
  {
    std::cerr << "Wrong number of arguments!" << std::endl;
    std::cerr << "Usage: movehead NAO_IP" << std::endl;
    exit(2);
  }
   

  const AL::ALValue jointName = "HeadYaw";


  try {
	  while(1)
	  {

    AL::ALMotionProxy motion(argv[1], 9559);


    AL::ALValue stiffness = 1.0f;

    AL::ALValue time = 1.0f;

    motion.stiffnessInterpolation(jointName, stiffness, time);

    AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);

    AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);

    bool isAbsolute = true;

    motion.angleInterpolation(jointName, targetAngles, targetTimes, isAbsolute);

    stiffness = 0.0f;
    time = 1.0f;
    motion.stiffnessInterpolation(jointName, stiffness, time);
	  }
  }
  catch (const AL::ALError& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    exit(1);
  }
  exit(0);
}













	

