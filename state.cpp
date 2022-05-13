#include<iostream>
using namespace std;
#include"state.h"
#include"message.h"
#include"/usr/local/cs/cs251/react.h"

void State::read_lab(char *mem){
    yourProfileLab = _get_tilde_terminated_string(mem);
    mem += 13;

    ageLab = _get_tilde_terminated_string(mem);
    mem += 5;

    matchPercentLab = _get_tilde_terminated_string(mem);
    mem += 8;

    bioLab = _get_tilde_terminated_string(mem);
    mem += 5;

    popUpLab = _get_tilde_terminated_string(mem);
    mem += 29;

    yesLab = _get_tilde_terminated_string(mem);
    mem += 4;

    noLab = _get_tilde_terminated_string(mem);
    mem += 3;

    chatLab = _get_tilde_terminated_string(mem);
    mem += 5;

    helloLab = _get_tilde_terminated_string(mem);
    mem += 25;
}
void State::read_messages(char *mem){
    //if(this->numMessages > 0){
    //    for (int i = 0; i< this->numMessages; i++)
     //   {}
   // }
}

void State::read_from(char *mem){
    pageTitle = _get_int(mem,1);
    mem += 1;

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

void State::write_to(char *mem){
    _put_int(pageTitle, mem, 1);
    mem += 1;

    _put_int(showPopUp, mem, 1);
    mem += 1;

    _put_int(getMatchAccount().get_age(), mem, 2);
    mem += 3; //plus an extra 1 so a ~ is written
        
    _put_int(percentMatch, mem, 2);
    mem += 3; //plus an extra 1 so a ~ is written
    
    _put_tilde_terminated_string(popUpText, mem);
    mem += (popUpText.size() + 1);
    
    _put_tilde_terminated_string(getMatchAccount().get_name(), mem);
    mem += (getMatchAccount().get_name().size() + 1);
    
    _put_tilde_terminated_string(getMatchAccount().get_bio(), mem);
    mem += (getMatchAccount().get_bio().size() + 1);

    _put_tilde_terminated_string(yourProfileLab, mem);
    mem += 13;

    _put_tilde_terminated_string(ageLab, mem);
    mem += 5;

    _put_tilde_terminated_string(matchPercentLab, mem);
    mem += 8;

    _put_tilde_terminated_string(bioLab, mem);
    mem += 5;

    _put_tilde_terminated_string(popUpLab, mem);
    mem += 29;

    _put_tilde_terminated_string(yesLab, mem);
    mem += 4;

    _put_tilde_terminated_string(noLab, mem);
    mem += 3;

    _put_tilde_terminated_string(chatLab, mem);
    mem += 5;

    _put_tilde_terminated_string(helloLab, mem);
    mem += 25;

    if(this->numMessages > 0){
        mem += 338;
        for (int i = 0; i< this->numMessages; i++){
            _put_tilde_terminated_string((*messages[i]).get_message(), mem);
            mem += ((*messages[i]).get_message().size());
        }
    }
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
        offset2 = offset("labelStart") + 13; //size of yourProfile lab +1
    }else if(text == "matchPercentLab"){ 
        offset2 = offset("ageLab") + 5; //size of ageLab +1
    }else if(text == "bioLab"){
        offset2 = offset("matchPercentLab") + 8; //size of matchPercentLab +1
    }else if(text == "popUpLab"){
        offset2 = offset("bioLab") + 5; //size of bioLab +1
    }else if(text == "yesLab"){
        offset2 = offset("popUpLab") + 29; //size of popUpLab +1
    }else if(text == "noLab"){
        offset2 = offset("yesLab") + 4; //size of yesLab +1
    }else if(text == "chatLab"){
        offset2 = offset("noLab") + 3; //size of noLb +1
    }else if(text == "helloLab"){
        offset2 = offset("chatLab") + 5;
    }else if(text == "endOfMem"){
        offset2 = offset("helloLab") + 25;
    }
    return offset2;
}


void State::update(){

    //main page match buttons
    if(_event_id_is("button_", 3)){ //decline red button pressed
        //getYourAccount().add_blocked(getMatchAccount());
    } else if(_event_id_is("button_", 2)) { //pink romance button pressed
        //check match function call here
        //if match presses the same button
        showPopUp = 1;
        popUpText = "You and Jake Matched!";
        write_to(_global_mem);
    } else if(_event_id_is("button_", 1)){ //green friend button pressed
        //check match function call here
        //if match presses the same button
        showPopUp = 1;
        popUpText = "You and Jake Matched!";
        write_to(_global_mem);
    }
    
    //Yes/No Button pop up 
    if(_event_id_is("button_", 5)){ //no button pressed
        showPopUp = 0;
        //getYourAccount().add_blocked(getMatchAccount());
        write_to(_global_mem);
    }else if(_event_id_is("button_", 4)){ //yes button pressed
        showPopUp = 0;
        pageTitle = 2;
        getYourAccount().add_match(getMatchAccount());
        write_to(_global_mem);
    }

    //chat inbox
    if(getPageTitle() == 2 && _event_id_is("button_", 6)){
        numMessages += 1;
        Message m(getYourAccount().get_email(), _get_tilde_terminated_string(_global_mem + offset("endOfMem")));
        if(numMessages == 1){
            messages = new Message*[numMessages];
            messages[0] = &m;
            /*messages[0].set_email(getYourAccount().get_email());
            messages[0].set_message(_get_tilde_terminated_string(_global_mem + offset("endOfMem")));*/
        }else{
            Message **tmp = new Message*[numMessages];
            for(int i = 0; i<numMessages-2; i++){
                tmp[i] = messages[i];
            }
            messages[numMessages-1] = &m;
        }
    }if(getPageTitle() ==2 && _received_event()){
        
    }

    
}

void display(State &state){
    string url1 = "https://img.buzzfeed.com/buzzfeed-static/static/2015-05/20/13/campaign_images/webdr01/what-your-favorite-stock-photo-spaghetti-person-s-2-7471-1432142821-2_dblbig.jpg";
    string url2 = "https://previews.123rf.com/images/kurhan/kurhan1103/kurhan110300100/9050894-hombre-feliz.jpg";

    if(state.getPageTitle() == 0){
        _add_yaml("header.yaml",{{"picType", url1}, {"yourProfileLab", state.offset("labelStart")}});
        _add_yaml("mainPageBody.yaml", {{"othersPic", url2}, {"nameIndex", state.offset("name")}, {"bioIndex", state.offset("bio")}, {"bioLab", state.offset("bioLab")}, {"ageLab", state.offset("ageLab")}, {"matchPercentLab", state.offset("matchPercentLab")}});
        _add_yaml("matchButtons.yaml");
        if(state.getShowPopUp() == 1){
            _add_yaml("YNPopUp.yaml", {{"popUpIndex", state.offset("popUpText")}, {"popUpLab", state.offset("popUpLab")}, {"yesIndex", state.offset("yesLab")}, {"noIndex", state.offset("noLab")}});
        }
    }
    /*if (state.getPageTitle() == 1){ // chat inbox if statements
        _add_yaml("chatpagehome.yaml",{{"yourPic", url1}, {"chat", 2}});
        int matches = state.getYourAccount().get_numMatches();
        state.getYourAccount().update_numMatches();
        cout<<state.getYourAccount().get_numMatches();
        //for (int i = 0; i<matches; i++){
        _add_yaml("addChat.yaml", {{"matchPic", url2},{"chatlab", 7},{"nameInd",29}});//eventually would have to add picture and name 
        //}
    }*/
    if(state.getPageTitle() == 2){ //specific chat inbox
        _add_yaml("header.yaml",{{"picType", url2}, {"yourProfileLab", state.offset("name")}});
        _add_yaml("chatbutton.yaml",{{"chatIndex", state.offset("endOfMem")}});
        if(state.numMessages > 0){
            _add_yaml("onechatbubble.yaml", {{"messageIndex", 500}});
       
        
    }
    }


   /* if (state.getPageTitle() == 2){//specific chat inbox 
        _add_yaml("addChat.yaml");// have to figure out how to make this for a specific chat based on what you click on previously
        int messages = 0; //temporary initilization
        for (int i = 0; i<messages; i++){
            _add_yaml("message.yaml");
        }
    }*/
}
