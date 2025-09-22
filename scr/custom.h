#include <stdio.h>

int admin_loging(const char *user);
//compenents
int E_seperator();
int D_seperator();
int time_delay();
int long_delay();
void pressEnterToContinue();
void color(int t);

//UI hass
int main_menu();
int admin_panel();

//PO hass
int UI_PO();
int PO_open_polling();
int PO_close_polling();

//poling hass
int polling_login();
int votting_casting();

// NOMINATOION LIST HASS
int public_nomination_list();
int election_results_menu();
int election_results_district_view();
int election_results_party_view();





int UI_RO();

int UI_PARTY_ADMIN();
int party_agent_observer();


int UI_party_admin();
int submit_nomination();
int voter_reg();
void candidate_registration();
void voter_registration();

//HIMANSANA.....................
int UI_election_admin();
int district_registration();
int add_new_district();
int display_all_districts();
int party_registration();
int display_registerd_parties();
int final_result_declaration();

//RO
int returnig_officer();
int review();
int accept_nomination_list();
int Public_nomination_list();
