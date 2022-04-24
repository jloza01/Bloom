#include<iostream>
using namespace std;
#include"/usr/local/cs/cs251/react.h"

int main() {
    string url1 = "https://img.buzzfeed.com/buzzfeed-static/static/2015-05/20/13/campaign_images/webdr01/what-your-favorite-stock-photo-spaghetti-person-s-2-7471-1432142821-2_dblbig.jpg";
    string url2 = "https://previews.123rf.com/images/kurhan/kurhan1103/kurhan110300100/9050894-hombre-feliz.jpg";
    
    _add_yaml("frame1.yaml", {{"profilePic", url1}, {"theirPic", url2}});
    _write_global_yaml_to_file("react.yaml");
}
