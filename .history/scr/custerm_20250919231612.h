#include <stdio.h>

int admin_loging(const char *user);
//compenents
int E_seperator();
int D_seperator();

//UI
int main_menu();
int admin_panel();


int UI_ELECTION();

int UI_RO();

int UI_PARTY_ADMIN();
int party_agent_observer();

//PO
int UI_PO();
int PO_open_polling();
int PO_close_polling();

int polling_login();
int votting_casting();

int public_nomination_list();

int election_results_menu();
int election_results_district_view();
int election_results_party_view();
int election_results_rejected_party();
int NATIONAl_ELECTED();
int DISTRICT_ELECTED();
int PARTY_ELECTED();

int UI_election_admin();
