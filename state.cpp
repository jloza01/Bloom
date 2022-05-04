#include<iostream>
using namespace std;
#include"state.h"
#include"/usr/local/cs/cs251/react.h"

void State::read_lab(char *mem){
    yourProfileLab = _get_tilde_terminated_string(mem);
    mem += (yourProfileLab.size() + 1);

    ageLab = _get_tilde_terminated_string(mem);
    mem += (ageLab.size() + 1);

    matchPercentLab = _get_tilde_terminated_string(mem);
    mem += (matchPercentLab.size() + 1);

    bioLab = _get_tilde_terminated_string(mem);
    mem += (bioLab.size() + 1);
}

void State::read_from(char *mem){
    pageTitle = _get_int(mem, 1);
    mem += 1;

    if (pageTitle== 0){
        showPopUp = _get_int(mem, 1);
        mem += 1;

        getMatchAccount().set_age(_get_int(mem, 2));
        mem += 3; //plus an extra one for the ~

        percentMatch = _get_int(mem, 2);
        mem += 3; //plus an extra one for the ~
 
        popUpText = _get_tilde_terminated_string(mem);
        mem += (popUpText.size() + 1);

        getMatchAccount().set_name(_get_tilde_terminated_string(mem));
        mem += (getMatchAccount().get_name().size() + 1);

        getMatchAccount().set_bio(_get_tilde_terminated_string(mem));
        mem += (getMatchAccount().get_bio().size() + 1);
    }
    else if (pageTitle == 1){
        getMatchAccount().set_name(_get_tilde_terminated_string(mem));
        mem+= (getMatchAccount().get_name().size() + 1);
    }
}

void State::write_to(char *mem){
    _put_int(pageTitle, mem, 1);
    mem += 1;

    _put_int(showPopUp, mem, 1);
    mem += 1;

    _put_int(getMatchAccount().get_age(), mem, 2);
    mem += 2;
        
    _put_int(percentMatch, mem, 2);
    mem += 2;
    
    _put_tilde_terminated_string(popUpText, mem);
    mem += (popUpText.size() + 1);
    
    _put_tilde_terminated_string(getMatchAccount().get_name(), mem);
    mem += (getMatchAccount().get_name().size() + 1);
    
    _put_tilde_terminated_string(getMatchAccount().get_bio(), mem);
    mem += (getMatchAccount().get_bio().size() + 1);
}

int State::offset(string text) {
    int offset2 = 0;

    if(text == "popUpText"){
        offset2 = 8;
    }else if(text == "name"){
        offset2 = offset("popUpText") + (popUpText.size() + 1);
    }else if(text == "bio"){
        offset2 = offset("name") + (getMatchAccount().get_name().size() + 1);
    }else if(text == "labelStart"){
        offset2 = offset("bio") + (getMatchAccount().get_bio().size() + 1);
    }else if(text == "ageLab"){
        offset2 = offset("labelStart") + (getYourProfileLab().size() +1);
    }else if(text == "matchPercentLab"){
        offset2 = offset("ageLab") + (getAgeLab().size() + 1);
    }else if(text == "bioLab"){
        offset2 = offset("matchPercentLab") + (getMatchPercentLab().size() + 1);
    }
    return offset2;
}


void State::update(){
    //Yes/No Button pop up    
    if(_event_id_is("button_", 0)){ //no button pressed
        showPopUp = 0;
        //getYourAccount().add_blocked(getMatchAccount());
        write_to(_global_mem);
    }else if(_event_id_is("button_", 1)){ //yes button pressed
        showPopUp = 0;
        pageTitle = 2;
        getYourAccount().add_match(getMatchAccount());
        write_to(_global_mem);
    }
}

void display(State &state){
    string url1 = "https://img.buzzfeed.com/buzzfeed-static/static/2015-05/20/13/campaign_images/webdr01/what-your-favorite-stock-photo-spaghetti-person-s-2-7471-1432142821-2_dblbig.jpg";
    string url2 = "https://previews.123rf.com/images/kurhan/kurhan1103/kurhan110300100/9050894-hombre-feliz.jpg";

    if(state.getPageTitle() == 0){
        _add_yaml("header.yaml",{{"picType", url1}, {"yourProfileLab", state.offset("labelStart")}});
        _add_yaml("mainPageBody.yaml", {{"othersPic", url2}, {"nameIndex", state.offset("name")}, {"bioIndex", state.offset("bio")}, {"bioLab", state.offset("bioLab")}, {"ageLab", state.offset("ageLab")}, {"matchPercentLab", state.offset("matchPercentLab")}});
        if(state.getShowPopUp() == 0){
            _add_yaml("matchButtons.yaml");
        }
        if(state.getShowPopUp() == 1){
            _add_yaml("YNPopUp.yaml", {{"popUpIndex", state.offset("popUpText")}});
        }
    }
    if (state.getPageTitle() == 1){ // chat inbox if statements
        _add_yaml("chatpagehome.yaml",{{"yourPic", url1}, {"chat", 2}});
        int matches = state.getYourAccount().get_numMatches();
        state.getYourAccount().update_numMatches();
        cout<<state.getYourAccount().get_numMatches();
        //for (int i = 0; i<matches; i++){
        _add_yaml("addChat.yaml", {{"matchPic", url2},{"chatlab", 7},{"nameInd",29}});//eventually would have to add picture and name 
        //}
    }
    if (state.getPageTitle() == 2){//specific chat inbox 
        _add_yaml("chat.yaml");// have to figure out how to make this for a specific chat based on what you click on previously
        int messages = 0; //temporary initilization
        for (int i = 0; i<messages; i++){
            _add_yaml("message.yaml");
        }
    }
}
