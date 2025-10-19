 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("..\\data\\pooling.txt", "r");  
    if (fp == NULL) {
        printf("Input file not found!\n");
        return 1;
    }

    FILE *out = fopen("..\\data\\calculation.txt", "w");  
    if (out == NULL) {
        printf("Cannot create output file!\n");
        fclose(fp);
        return 1;
    }

    char key[500][20];  
    int count[500];
    int total = 0;

    char D[10], P[10];
    int c3, c4, c5;
    char temp[20];

    while (fscanf(fp, "%[^|]|%[^|]|%d|%d|%d|\n", D, P, &c3, &c4, &c5) == 5) {
        int values[3] = {c3, c4, c5};

        for (int j = 0; j < 3; j++) {
            if (values[j] >= 101 && values[j] <= 130) { 
                sprintf(temp, "%s|%d", P, values[j]);
                int found = 0;

                for (int i = 0; i < total; i++) {
                    if (strcmp(key[i], temp) == 0) {
                        count[i]++;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(key[total], temp);
                    count[total] = 1;
                    total++;
                }
            }
        }
    }

    fclose(fp);

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            char p1[10], p2[10];
            int v1, v2;

            sscanf(key[j], "%[^|]|%d", p1, &v1);
            sscanf(key[j + 1], "%[^|]|%d", p2, &v2);

            if (strcmp(p1, p2) > 0 || (strcmp(p1, p2) == 0 && v1 > v2)) {
                char tempKey[20];
                int tempCount;

                strcpy(tempKey, key[j]);
                strcpy(key[j], key[j + 1]);
                strcpy(key[j + 1], tempKey);

                tempCount = count[j];
                count[j] = count[j + 1];
                count[j + 1] = tempCount;
            }
        }
    }

   
    for (int i = 0; i < total; i++) {
        char p[10];
        int val;
        sscanf(key[i], "%[^|]|%d", p, &val);
        fprintf(out, "%s|%d|%d\n", p, val, count[i]);
    }

    fclose(out);
    printf(" Output saved to calculation.txt successfully!\n");

    return 0;
}