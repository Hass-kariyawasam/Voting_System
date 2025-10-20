#include <stdio.h>

int main(); 
//compenents
int E_seperator();
int D_seperator();
int time_delay();
int long_delay();
void pressEnterToContinue();
void color(int t);
int A_delay();

//UI hass
int main_menu();

//admin login
int admin_loging(const char *user);

//admin hass
int admin_panel();

//PO hass
int UI_PO();
int PO_open_polling();
int PO_close_polling();

//Election Admin panel - HIMANSANA...
int UI_election_admin();
//district registration
int district_registration();
int add_new_district();
char add_district();
int display_all_districts();
//party registration
int party_registration();
char add_party();
int display_registerd_parties();
//final result declaration not finalized -------------
int final_result_declaration();

//party admin panel
int UI_party_admin();
int submit_nomination();

//returning officer panel
int UI_returning_officer();
int accept_nomination_list();
int district_result_generation(); //not ok
int review_nomination_list();

//voter and candidate registration
void voter_registration();
void candidate_registration();

//poling hass
int poling_Asccss();
char polling_login(); // done .
int votting_casting(char *logged_in_nic);


// NOMINATOIN LIST HASS
int public_nomination_list();

//ELECTION RESULT HASS
int election_results_menu();
int election_results_district_view();
int election_results_party_view();

//calculate HIMANSANA
int party_calculate();



int UI_RO();

int UI_PARTY_ADMIN();
int party_agent_observer();







