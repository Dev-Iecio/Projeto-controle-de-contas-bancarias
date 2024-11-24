#include "funcoes.h"



char *inverte_data(char *dt_data) {
    static char dt_data_inv[11];  
    char dia[3], mes[3], ano[5];

    
    strncpy(dia, dt_data, 2); 
    dia[2] = '\0';  

    strncpy(mes, dt_data + 3, 2);  
    mes[2] = '\0';

    strncpy(ano, dt_data + 6, 4);  
    ano[4] = '\0';  

    
    sprintf(dt_data_inv, "%s-%s-%s", ano, mes, dia);

    return dt_data_inv;  
}
