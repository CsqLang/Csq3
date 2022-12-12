#include "str.h"
#include "array.h"
//This function will tokenize the string using strtok a built-in function in C.
auto split(str ln,str tok_ = ","){
    array<str> s;
    
    // ln+=", ";
    char * token = strtok(ln.Str, tok_.Str);
    while(token != NULL){
        s.add(str(token));
        token = strtok(NULL, tok_.Str);
    }
    return s;
}
auto read(str filepath, int line_num = 10000){
    FILE * fo; 
    fo = fopen(filepath.Str,"r");
    str data;
    char ln[line_num];
    /*File is opened. Start reading the file line by line*/
    while ( fgets ( ln, 1000, fo) != NULL ){
        data += str(ln);
    }
    fclose(fo);
    return data;
}
auto write(str path,str data){
    FILE* file;
    file = fopen(path.Str, "w") ;
    // Write the dataToBeWritten into the file
    fputs(data.Str,file);
    fclose(file);
}

// This function will fnd the occurence of substr in the main string.
int find_str(char *string, char *substring)
{
    int i, j, l1, l2;
    int count = 0;
    l1 = strlen(string);
    l2 = strlen(substring);
    for (i = 0; i < l1 - l2 + 1; i++)
    {
        if (strstr(string + i, substring) == string + i)
        {
            count++;
            i = i + l2 - 1;
        }
    }
    return count;
}