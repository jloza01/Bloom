#include"/usr/local/cs/cs251/react.h"
#include"State.h"
#include<iostream>
#include<fstream>
using namespace std;

void display(const State &state){
    string url1 = "https://img.buzzfeed.com/buzzfeed-static/static/2015-05/20/13/campaign_images/webdr01/what-your-favorite-stock-photo-spaghetti-person-s-2-7471-1432142821-2_dblbig.jpg";
    string url2 = "https://previews.123rf.com/images/kurhan/kurhan1103/kurhan110300100/9050894-hombre-feliz.jpg";

    if(state.getPageTitle == "Main Page"){
        _add_yaml("frame1.yaml", {{"profilePic", url1}, {"theirPic", url2}});
        if(state.getShowPopUp() == '0'){ //showPopUp is a char so that it can represent different pop up styles
            _add_yaml("popUp.yaml"); //the only thing that changes about this pop up is the text
        }
    }
}