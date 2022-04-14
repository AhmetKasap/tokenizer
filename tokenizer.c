// AHMET KASAP 02205076032




#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>



Restrictive(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
	ch == '<' || ch == '=' || ch == '(' || ch == ')'  || ch == '{' || ch == '}')
        return (true);
    return (false);
}
  

Keyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") ||  !strcmp(str, "goto"))
        return (true);
    return (false);
}


Operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}
 
 
Descriptive(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || Restrictive(str[0]) == true)
        return (false);
    return (true);
}
 
 
char* String(char* str, int left, int right)
{
    int i;
    char* Str = (char*)malloc(
                  sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++)
         Str[i - left] = str[i];
    Str[right - left + 1] = '\0';
    return (Str);
}


Integer(char* str)
{
    int i, len = strlen(str);
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}
 
Number(char* str)
{
    int i, len = strlen(str);
    bool Decimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            Decimal = true;
    }
    return (Decimal);
}
 




void Parsing(char* str)
{
    int left = 0, right = 0;
    int len = strlen(str);
 
    while (right <= len && left <= right) {
        if (Restrictive(str[right]) == false)
            right++;
 
        if (Restrictive(str[right]) == true && left == right) {
            if (Operator(str[right]) == true)
                printf("%c,", str[right]);
 
            right++;
            left = right;
        } else if (Restrictive(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char* Str = String(str, left, right - 1);
 
            if (Keyword(Str) == true)
                printf("%s,", Str);
 
            else if (Integer(Str) == true)
                printf("%s,", Str);
 
            else if (Number(Str) == true)
                printf("%s,", Str);
 
            else if (Descriptive(Str) == true
                     && Restrictive(str[right - 1]) == false)
                printf("%s,", Str);
 
            else if (Descriptive(Str) == false
                     && Restrictive(str[right - 1]) == false)
                printf("%s,", Str);
            left = right;
        }
    }
    return;
}




int main(){
	
	
	char * data;
	int dataLength=2000;
	int read=0;
	char name[50];
	
	printf("Dosya isminizi giriniz : (ornek : deneme.txt) :");
	scanf("%s", &name);
	FILE *file = fopen(name, "r");
	const char * fileName=name;
	file=fopen(fileName,"r");

	if(file==NULL){
		printf("Dosya acilamadi.");
		return 0;
	}
	
	data=(char *)malloc(dataLength);

	if(data==NULL){
		printf("Bellek hatasý olustu.\n");
		fclose(file);
		return 0;
	}

	read=fread(data,1,dataLength,file);

	if(read>0){
		if(data[read-1]!=0){
			data[read-1]=0;
		}
	}

	printf("Dosyadan okunan kod : %s\n",data );

    printf("        TOKENIZER ISLEMI          \n\n");
  
    Parsing(data); 
    
  
    
 
    return (0);
}










 

