#include<iostream>
using namespace std;
#include"state.h"
#include "user.h"
#include"/usr/local/cs/cs251/react.h"

void State::read_from(const char *mem){
    numFields = 0;
    pageTitle = _get_char(mem, 1);
    mem += 1;

    showPopUp = _get_char(mem, 1);
    mem += 1;

    getAccount().set_age(_get_int(mem, 2));
    mem += 2;

    percentMatch = _get_int(mem, 2);
    mem += 2;

    popUpText = _get_tilde_terminated_string(mem);
    mem += (popUpText.size() + 1);

    getAccount().set_name(_get_tilde_terminated_string(mem));
    mem += (getAccount().get_name().size() + 1);

    getAccount().set_bio(_get_tilde_terminated_string(mem));
    mem += (getAccount().get_bio().size() + 1);
}

void State::write_to(char *mem){
    _put_char(pageTitle, mem, 1);
    mem += 1;

    _put_char(showPopUp, mem, 1);
    mem += 1;

    _put_int(getAccount().get_age(), mem, 2);
    mem += 2;
        
    _put_int(percentMatch, mem, 2);
    mem += 2;
    
    _put_tilde_terminated_string(popUpText, mem);
    mem += (popUpText.size() + 1);
    
    _put_tilde_terminated_string(getAccount().get_name(), mem);
    mem += (getAccount().get_name().size() + 1);
    
    _put_tilde_terminated_string(getAccount().get_bio(), mem);
    mem += (getAccount().get_bio().size() + 1);
}


//Problems I need to fix still: 
//  text in header in reading from frame1.txt and not labels.txt
//  pageTitle is not being read in (is anything being read in correctly?)
//  fix the indexing of all text for yaml files

int State::offset(string text) const{
    int offset = 0;

    if(text == "popUpText"){
        offset = 6;
    }else if(text == "name"){
        offset = 6 + (popUpText.size() + 1);
    }else if(text == "bio"){
        offset = 6 + (popUpText.size() + 1) + (getAccount().get_name().size() + 1);
    }
    return offset;
}

void State::update(){
    Account test; //how do we get this to be the user they matched with
    if(showPopUp == '1' && pageTitle == 'M'){
        //how do we specify which button was pressed
        //if yes to match
        getAccount().add_match(test);

        //if no to match
        getAccount().add_to_blocked(test);
    }else if(showPopUp =='1' && pageTitle == 'C'){
        //if yes to block
        getAccount().add_to_blocked(test);
    }else if(showPopUp == '0' && pageTitle == 'M'){
        
    }

}

void display(const State &state){
    string url1 = "https://img.buzzfeed.com/buzzfeed-static/static/2015-05/20/13/campaign_images/webdr01/what-your-favorite-stock-photo-spaghetti-person-s-2-7471-1432142821-2_dblbig.jpg";
    string url2 = "https://previews.123rf.com/images/kurhan/kurhan1103/kurhan110300100/9050894-hombre-feliz.jpg";

    if(state.getPageTitle() == 'M'){
        _add_yaml("header.yaml",{{"picType", url1}});
        _add_yaml("mainPageBody.yaml", {{"othersPic", url2}, {"nameIndex", state.offset("name")}});
        _add_yaml("matchButtons.yaml");
        if(state.getShowPopUp() == '1'){
            _add_yaml("Y/NPopUp.yaml");
        }
    }
    if (state.getPageTitle() == "i"){ // chat inbox if statements
        _add_yaml("chatpagehome.yaml");
        int matches = this->getnumMatches();
        for (int i = 0; i<matches; i++){
            _add_yaml("messageButton.yaml");//eventually would have to add picture and name 
        }
    }
    if (State.getPageTitle() == "C"){//specific chat inbox 
        _add_yaml("chat.yaml");// have to figure out how to make this for a specific chat based on what you click on previously
        int messages;
        for (int i = 0; i<messages; i++){
            _add_yaml("message.yaml");
        }
    }
}
