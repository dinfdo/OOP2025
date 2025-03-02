#include <iostream>
#include <cstring>
using namespace std;

void Words(char str[]){
    char v[101][101];

    char *p=strtok(str," ");
    int i=0;
    while(p) {
        strcpy(v[++i], p);
        p=strtok(NULL, " ");

    }
	char aux[101];
    for(int k=1; k<i; k++)
        for(int j=k+1; j<=i; j++)
            if(strlen(v[k])<strlen(v[j])){
                strcpy(aux,v[j]);
				strcpy(v[j],v[k]);
				strcpy(v[k],aux);
			}
			
    for(int k=1;k<i;k++)
        for(int j=k+1;j<=i;j++)
            if(strlen(v[k])==strlen(v[j])&&strcmp(v[k], v[j])>0){
                strcpy(aux,v[j]);
				strcpy(v[j],v[k]);
				strcpy(v[k],aux);
			}
                              
    for(int r=1; r<=i; r++)
        printf("%s\n",v[r]);

}

int main(){
    char str[101];
    FILE * openFile;

    openFile = fopen("in.txt", "r");

    if(fgets (str, 101, openFile) != NULL)
        Words(str);   

    fclose(openFile);
    return 0;
}