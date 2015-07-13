/*  
	Header file for the Stenographer object
	
	Author: Greg Stewart
	Started: 5/29/15
*/
#ifndef STENOGRAPHER_H
#define STENOGRAPHER_H

//includes
#include "StenographerException.h"//exceptions for the object

#include <string>//for strings
#include <algorithm>
//#include <sstream>//string stream
#include <iostream>//for outputs
#include <iomanip>//manipulate outputs
#include <sys/stat.h>//for checking filepaths

//usings
using std::string;
using namespace std;

class Stenographer{
	/*
		Private variables and methods
	*/
	private:
		//instance variables
		string stringToHide; // the string we are hiding in the image
        string origFilePath; // the image we are grabbing from
        string outputDir;    // the directory we are putting the finished images in
        const static bool debugging = true;//if we are debugging (outputs debug messages)

        /*
            Private functions
        */

        //checks if the filepath given is valid
        bool checkFilePath(string,bool);
        //checks if the extension of the filepath is valid
        bool checkFileType(string pathIn);
        //couts a debug message
        void sendDebugMsg(string);
	public:
		/*
			Constructors
		*/
		//empty constructor, inistalizes everything to nulls
		Stenographer();
        
        //sets up the object using the setup() functionws
        Stenographer(string,string,string);//stringToHide,origFilePath,outputDir
	    
		/*
			Setters
		*/
        
        /** sets up all the variables (stringToHide,origFilePath,outputDir)
            tests input/output places to make sure they work
            returns if it failed or not
        */
        bool setup(string,string,string);
        
		// sets the new string to hide	
		void setNewStrToHide(string);

	    /* sets the image to read from
           tests the path for an image file
        */
        bool setInputImage(string);
        
        /* sets the output directory
            tests to make sure it exists
        */
        bool setOutputDir(string);
		
		/*
			Getters
		*/
        
        //gets the input file path
        string getInputPath();

        //gets the output file path
        string getOutputPath();
        
        //gets the string that we are hiding
        string getStringToHide();

        //toString
        string toString();
        
        // returns if the object is ready to go or not
		bool ready();
	
};//class Stenographer
#endif
