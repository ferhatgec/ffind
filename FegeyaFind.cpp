/*# MIT License
#
# Copyright (c) 2020 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#include <iostream>
#include <cstring>
#include <FileSystemPlusPlus.h>
#include <FegeyaFind.hpp>
#include <Find.hpp>

void HelpFunction() {
	std::cout << "Fegeya Find Arguments\n" <<
	"ffind --a || --all <file> : Categorized and colorized\n" <<
	"ffind --whca || --withoutcategorize <file> : Uncategorized and colorized. Only [File] and [Dir]\n" <<
	"ffind -- whco || --withoutcolorize <file> : Categorized and uncolorized.\n";
}

void VersionFunction() {
	std::cout << "Fegeya Find - " << FEGEYA_FIND_VERSION << "\n";
}

/*
	type = 1 : Categorized and colorized.
	type = 2 : Uncategorized and colorized. Only [File] and [Dir]
	type = 3 : Categorized and uncolorized.	
	...
*/
void Categorize(std::string file, int type) {
	FFind find;
	if(type == 1)
		find.Find(file);
	else if(type == 2)
		find.FindWithoutCategorize(file);
	else if(type == 3)
		find.FindWithoutColorize(file);
	else
		std::cout << "Error: This type undefined.\n";
}

int main(int argc, char** argv) {
	std::string copy_arg, reg;
	if(argc > 1) {
        	for(int i = 1; i < argc; i++) {
			std::string arg(argv[i]);
			reg = argv[1];
			copy_arg = arg;
		}
	
        } else {
        	HelpFunction();
	}
	
        
	if(reg.substr(0, 2) == "--") {
	    if(reg == "--a" || reg == "--all") /* Standart. */
		Categorize(copy_arg, 1); /* type = 1 */
    	    else if(reg == "--whca" || reg == "--withoutcategorize")
    		Categorize(copy_arg, 2); /* type = 2 */
	    else if(reg == "--whco" || reg == "--withoutcolorize")
		Categorize(copy_arg, 3);
	    else if(reg == "--h" || reg == "--help")
		HelpFunction();
	    else if(reg == "--v" || reg == "--version")
		VersionFunction();
     	    else	
    		Categorize(copy_arg, 1); /* type = 1 */
	   /*else if(reg == "--h" || reg == "--help")
		// HelpFunction()
	   else if(reg == "--v" || reg == "--version")
		// VersionFunction()
	   else
	        // HelpFunction()*/
	} else Categorize(copy_arg, 1);
	return 0;
} 
