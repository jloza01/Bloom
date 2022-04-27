#include<iostream>
using namespace std;
#include"state.h"
#include"/usr/local/cs/cs251/react.h"

void State::read_from(const char *mem){
    pageTitle = _get_tilde_terminated_string(mem);
    mem += (pageTitle.size() + 1);
    showPopUp = _get_char(mem, 1);
    mem += 1;
    popUpText = _get_tilde_terminated_string(mem);
    mem += (popUpText.size() + 1);
    name = _get_tilde_terminated_string(mem);
    mem += (name.size() + 1);
    age = _get_int(mem, 2);
    mem += 2;
    bio = _get_tilde_terminated_string(mem);
    mem += (bio.size() + 1);
    percentMatch = _get_int(mem, 2);
    mem += 2;
}

void State::write_to(char *mem){
    _put_tilde_terminated_string(pageTitle, mem);
    mem += (pageTitle.size() + 1);
    _put_char(showPopUp, mem, 1);
    mem += 1;
    _put_tilde_terminated_string(popUpText, mem);
    mem += (popUpText.size() + 1);
    _put_tilde_terminated_string(name, mem);
    mem += (name.size() + 1);
    _put_int(age, mem, 2);
    mem += 2;
    _put_tilde_terminated_string(bio, mem);
    mem += (bio.size() + 1);
    _put_int(percentMatch, mem, 2);
    mem += 2;
}

void display(const State &state){
    string url1 = "https://img.buzzfeed.com/buzzfeed-static/static/2015-05/20/13/campaign_images/webdr01/what-your-favorite-stock-photo-spaghetti-person-s-2-7471-1432142821-2_dblbig.jpg";
    string url2 = "https://previews.123rf.com/images/kurhan/kurhan1103/kurhan110300100/9050894-hombre-feliz.jpg";

    if(state.getPageTitle() == "Main Page"){
        _add_yaml("frame1.yaml", {{"profilePic", url1}, {"theirPic", url2}});
        if(state.getShowPopUp() == '0'){ //showPopUp is a char so that it can represent different pop up styles
            _add_yaml("popUp.yaml"); //the only thing that changes about this pop up is the text
        }
    }
}
