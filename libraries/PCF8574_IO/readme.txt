Arduino Compatible Cross Platform C++ Library Project : For more information see http://www.visualmicro.com
This project works exactly the same way as an Arduino library. 
Add this project to any solution that contains an Arduino project and #include <headers.h> 
in code as you would any normal Arduino library headers. 
To enable intellisense and to support live build discovery outside of the "standard" Arduino library locations, 
ensure that the library is added as a shared project reference to the master Arduino project.
To do this, 

1. right click the master project "References" node and then click "Add Reference". 
2. A window will open and the library will appear on the "Shared Projects" tab. 
3. Click the checkbox next to the library name to add the reference.

**If this library is moved the shared referencemust be removed and re-added.**

**VS2017 has a bug, workround: After moving existing source code within a "library or shared project", close and re-open the solution.**
Visual Studio will display intellisense for libraries based on the platform/board that has been specified for the currently active "Startup Project" of the current solution.

IMPORTANT: The arduino.cc Library Rules must be followed when adding code or restructing libraries.
	
blog: http://www.visualmicro.com/post/2017/01/16/Arduino-Cross-Platform-Library-Development.aspx

About This Library 

This Library support IC PC8574/8574A for expand IO port up to 8 chips of PC8574 and 8 chips of PC8574A 
by edit line21: in PC8574_IO.h.  

#define Number_of_PC8574 5    //As follows means that there are 5 PC8574 pieces. And address 0-4. 

Support Address of PC8574 is 0-7 and PC8574A is 8-15. 