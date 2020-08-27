/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <fstream>
#include <Find.hpp>
#include <sys/stat.h>
#include <dirent.h>

/* Color library */
#include <Colorized.hpp>


#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

std::string GetCurrentWorkingDir(void) {
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX); 
    std::string current_working_dir(buff); /* Copy */
    return current_working_dir;
}

std::string Directory(std::string name) { 
	return GetCurrentWorkingDir(); 
}

/* TODO: Add If-Else statement without only current working dir. */

void
FFind::Find(std::string name) {
    DIR *directory;
    struct dirent *entryname;
    struct stat filestat;
    directory = opendir(Directory(name).c_str());
    if(directory == NULL) {
        std::cout << "Error: Directory not found.\n";
        return;
    }

    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {
            // Null
            } else if(strstr(entryname->d_name, "..")){
	    // Null
	    } else if(strstr(entryname->d_name, name.c_str())) {  
            	printf("%4s: %s\n", "[Dir]", entryname->d_name);
            }
        } else if(strstr(entryname->d_name, "Elitefile")) {
	    if(strstr(entryname->d_name, name.c_str())) {
            	BOLD_BLUE_COLOR
            	printf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
	    }
        } else if(strstr(entryname->d_name, ".scrift_log")) {
	    if(strstr(entryname->d_name, name.c_str())) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printf("%4s: %s\n", "FeLog*", entryname->d_name);
	    }	
	} else if(strstr(entryname->d_name, ".scrift_ascii")) {
	    if(strstr(entryname->d_name, name.c_str())) {			    
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printf("%4s: %s\n", "Ascii Art*", entryname->d_name);	
	    }
	} else if(strstr(entryname->d_name, ".scrift_settings")) {
	    if(strstr(entryname->d_name, name.c_str())) {
            	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printf("%4s: %s\n", "Settings*", entryname->d_name);
	    }
        } else if(strstr(entryname->d_name, ".scrift_history")) {
	    if(strstr(entryname->d_name, name.c_str())) {
            	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
            	printf("%4s: %s\n", "History*", entryname->d_name);
	    }	
	} else if(strstr(entryname->d_name, ".scr")) {
            if(strstr(entryname->d_name, name.c_str())) {
            	BOLD_GREEN_COLOR
            	printf("%4s: %s\n", "[Scrift]", entryname->d_name);
	    }
        } else if(strstr(entryname->d_name, ".cpp") || strstr(entryname->d_name, ".hpp") || 
	strstr(entryname->d_name, ".cxx") || strstr(entryname->d_name, ".hxx") || strstr(entryname->d_name, ".cc") || strstr(entryname->d_name, ".hh")) {
            if(strstr(entryname->d_name, name.c_str())) {
		BOLD_CYAN_COLOR
            	printf("%4s: %s\n", "[C++]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".c") || strstr(entryname->d_name, ".h")) {
	    if(strstr(entryname->d_name, name.c_str())) {
	    	BOLD_BLUE_COLOR
            	printf("%4s: %s\n", "[C]", entryname->d_name);
	    }		
	} else if(strstr(entryname->d_name, "CMakeLists.txt")) {
	    if(strstr(entryname->d_name, name.c_str())) {
	    	BOLD_MAGENTA_COLOR
            	printf("%4s: %s\n", "[CMake]", entryname->d_name);
	    }	
	} else if(strstr(entryname->d_name, ".sh")) {
	    if(strstr(entryname->d_name, name.c_str())) {
	    	BOLD_GREEN_COLOR
            	printf("%4s: %s\n", "[Bash]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".py")) {
	    if(strstr(entryname->d_name, name.c_str())) {
	    	BOLD_BLUE_COLOR
            	printf("%4s: %s\n", "[Python]", entryname->d_name);
	    }	
	} else if(strstr(entryname->d_name, ".fls") || strstr(entryname->d_name, ".flsh")) {
	    if(strstr(entryname->d_name, name.c_str())) {
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
	    	printf("%4s: %s\n", "[FlaScript]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".md")) {
	    if(strstr(entryname->d_name, name.c_str())) {		    
		BOLD_YELLOW_COLOR
        	printf("%4s: %s\n", "[Markdown]", entryname->d_name);
	    }	
	} else if(strstr(entryname->d_name, ".frbr")) {
     	    if(strstr(entryname->d_name, name.c_str())) {
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_MAGENTA).c_str(), "");
           	printf("%4s: %s\n", "[FreeBrain]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".png")) {
	    if(strstr(entryname->d_name, name.c_str())) {
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
  	    	printf("%4s: %s\n", "[Png]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".jpg") || strstr(entryname->d_name, ".jpeg")) {
	    if(strstr(entryname->d_name, name.c_str())) {
	    	colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
	    	printf("%4s: %s\n", "[Jpg]", entryname->d_name);
	    }	
	} else if(strstr(entryname->d_name, ".gif")) {
	    if(strstr(entryname->d_name, name.c_str())) {	            
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLUE).c_str(), "");
	    	printf("%4s: %s\n", "[Gif]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".html") || strstr(entryname->d_name, ".htm")) {
	    if(strstr(entryname->d_name, name.c_str())) {		    
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_RED).c_str(), "");
            	printf("%4s: %s\n", "[Html]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".rs") || strstr(entryname->d_name, ".rslib")) {
	    if(strstr(entryname->d_name, name.c_str())) {		    
		colorized::PrintWhReset(colorized::Colorize(BOLD, YELLOW).c_str(), "");
	    	printf("%4s: %s\n", "[Rust]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".lua")) {
	    if(strstr(entryname->d_name, name.c_str())) {	  	    
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_BLACK).c_str(), "");
	    	printf("%4s: %s\n", "[Lua]", entryname->d_name);
	    }
	} else if(strstr(entryname->d_name, ".inclink")) {
	    if(strstr(entryname->d_name, name.c_str())) {		    
		colorized::PrintWhReset(colorized::Colorize(BOLD, LIGHT_YELLOW).c_str(), "");
		printf("%4s: %s\n", "[includeLink]", entryname->d_name);			
	    }		
	} else {
	    if(strstr(entryname->d_name, name.c_str())) {
            	BOLD_YELLOW_COLOR
	    	printf("%4s: %s\n", "[File]", entryname->d_name);
            }
	}
        BLACK_COLOR // Reset
    }
    closedir(directory);
}

void
FFind::FindWithoutCategorize(std::string name) {
    DIR *directory;
    struct dirent *entryname;
    struct stat filestat;
    directory = opendir(Directory(name).c_str());
    if(directory == NULL) {
        std::cout << "Error: Directory not found.\n";
        return;
    }
    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            BOLD_RED_COLOR
            if(strstr(entryname->d_name, ".")) {
            // Null
            } else if(strstr(entryname->d_name, "..")){
	    // Null
	    } else if(strstr(entryname->d_name, name.c_str())) {  
            	printf("%4s: %s\n", "[Dir]", entryname->d_name);
            }
        } 
        else if(strstr(entryname->d_name, name.c_str())){
            BOLD_YELLOW_COLOR
            printf("%4s: %s\n", "[File]", entryname->d_name);
        }
        BLACK_COLOR // Reset
    }
    closedir(directory);
}

void
FFind::FindWithoutColorize(std::string name) {
    DIR *directory;
    struct dirent *entryname;
    struct stat filestat;
    directory = opendir(Directory(name).c_str());
    if(directory == NULL) {
        std::cout << "Error: Directory not found.\n";
        return;
    }

    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {} else if(strstr(entryname->d_name, name.c_str())) {  
            	printf("%4s: %s\n", "[Dir]", entryname->d_name);
            }
        } else if(strstr(entryname->d_name, "Elitefile")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[Elitebuild]", entryname->d_name);
        } else if(strstr(entryname->d_name, ".scrift_log")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "FeLog*", entryname->d_name);	
	} else if(strstr(entryname->d_name, ".scrift_ascii")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "Ascii Art*", entryname->d_name);	
	} else if(strstr(entryname->d_name, ".scrift_settings")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "Settings*", entryname->d_name);
        } else if(strstr(entryname->d_name, ".scrift_history")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "History*", entryname->d_name);	
	} else if(strstr(entryname->d_name, ".scr")) {
            if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[Scrift]", entryname->d_name);
        } else if(strstr(entryname->d_name, ".cpp") || strstr(entryname->d_name, ".hpp") || 
	strstr(entryname->d_name, ".cxx") || strstr(entryname->d_name, ".hxx") || strstr(entryname->d_name, ".cc") || strstr(entryname->d_name, ".hh")) {
            if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[C++]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".c") || strstr(entryname->d_name, ".h")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[C]", entryname->d_name);	
	} else if(strstr(entryname->d_name, "CMakeLists.txt")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[CMake]", entryname->d_name);	
	} else if(strstr(entryname->d_name, ".sh")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[Bash]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".py")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[Python]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".fls") || strstr(entryname->d_name, ".flsh")) {
	    if(strstr(entryname->d_name, name.c_str()))
	    	printf("%4s: %s\n", "[FlaScript]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".md")) {
	    if(strstr(entryname->d_name, name.c_str()))
        	printf("%4s: %s\n", "[Markdown]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".frbr")) {
     	    if(strstr(entryname->d_name, name.c_str()))
           	printf("%4s: %s\n", "[FreeBrain]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".png")) {
	    if(strstr(entryname->d_name, name.c_str()))
  	    	printf("%4s: %s\n", "[Png]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".jpg") || strstr(entryname->d_name, ".jpeg")) {
	    if(strstr(entryname->d_name, name.c_str()))
	    	printf("%4s: %s\n", "[Jpg]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".gif")) {
	    if(strstr(entryname->d_name, name.c_str()))
	    	printf("%4s: %s\n", "[Gif]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".html") || strstr(entryname->d_name, ".htm")) {
	    if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[Html]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".rs") || strstr(entryname->d_name, ".rslib")) {
	    if(strstr(entryname->d_name, name.c_str()))
	    	printf("%4s: %s\n", "[Rust]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".lua")) {
	    if(strstr(entryname->d_name, name.c_str()))
	    	printf("%4s: %s\n", "[Lua]", entryname->d_name);
	} else if(strstr(entryname->d_name, ".inclink")) {
	    if(strstr(entryname->d_name, name.c_str()))
		printf("%4s: %s\n", "[includeLink]", entryname->d_name);					
	} else {
	    if(strstr(entryname->d_name, name.c_str()))
	    	printf("%4s: %s\n", "[File]", entryname->d_name);
	}
        BLACK_COLOR // Reset
    }
    closedir(directory);
}


void 
FFind::FindWithoutColorizeAndCategorize(std::string name) {
    DIR *directory;
    struct dirent *entryname;
    struct stat filestat;
    directory = opendir(Directory(name).c_str());
    if(directory == NULL) {
        std::cout << "Error: Directory not found.\n";
        return;
    }
    while ((entryname = readdir(directory))) {
        stat(entryname->d_name, &filestat);
        if(entryname->d_type == DT_DIR) {// DT_DIR -> directory
            if(strstr(entryname->d_name, ".")) {} else if(strstr(entryname->d_name, "..")) {} 
	    else if(strstr(entryname->d_name, name.c_str()))
            	printf("%4s: %s\n", "[Dir]", entryname->d_name);
        } 
        else if(strstr(entryname->d_name, name.c_str()))
            printf("%4s: %s\n", "[File]", entryname->d_name);
    }
    closedir(directory);
}
