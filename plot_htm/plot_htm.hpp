#pragma once

#include <string>
#include <xtensor/xarray.hpp>
#include <chrono>
#include <thread>
#include <ncursesw/ncurses.h>
#include <locale.h>


namespace ph {


const std::string ACTIVE{"\u25A0"};
const std::string INACTIVE{"\u25A1"};



inline void printStatus(const int avrows, const int avcols) {
}	

inline void printSDR(const xt::xarray<bool> & sdr, const int maxrows, const int maxcols, const int xoff, const int yoff){
	int i; 
	int xi,yi;
	for(i = 0; i < sdr.size(); i++) {
                xi = (i << 1) % maxcols + xoff;
                yi = (i << 1) / maxcols + yoff;

                if(sdr[i]) {
                        mvprintw(yi,xi,ACTIVE.c_str());
                        mvaddch(yi,xi-1,' ');
                }
                else {
                        mvprintw(yi,xi,INACTIVE.c_str());
                        mvaddch(yi,xi-1,' ');
                }
	}	
}


}
